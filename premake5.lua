workspace "Petalume"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
-- IncludeDir = {}
-- IncludeDir["GLFW"] = "Petalume/vendor/GLFW/include"
-- IncludeDir["Glad"] = "Petalume/vendor/Glad/include"
-- IncludeDir["ImGui"] = "Petalume/vendor/imgui"

-- include "Petalume/vendor/GLFW"
-- include "Petalume/vendor/Glad"
-- include "Petalume/vendor/imgui"

project "Petalume"
    location "Petalume"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    -- pchheader "plpch.h"
    -- pchsource "Petalume/src/plpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        -- "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        -- "%{IncludeDir.GLFW}",
        -- "%{IncludeDir.Glad}",
        -- "%{IncludeDir.ImGui}"
    }

    -- links{
    --     "GLFW",
    --     "Glad",
    --     "ImGui",
    --     "opengl32.lib"
    -- }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions { "/utf-8" }

        defines
        {
            "PL_PLATFORM_WINDOWS",
            "PL_BUILD_DLL",
            -- "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{MKDIR} ../bin/" .. outputdir .. "/Sandbox"),
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
        

    filter "configurations:Debug"
        defines "PL_DEBUG"
        -- buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "PL_RELEASE"
        -- buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "PL_DIST"
        -- buildoptions "/MD"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Petalume/vendor/spdlog/include",
        "Petalume/src"
    }

    links
    {
        "Petalume"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions { "/utf-8" }

        defines
        {
            "PL_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "PL_DEBUG"
        -- buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "PL_RELEASE"
        -- buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "PL_DIST"
        -- buildoptions "/MD"
        optimize "On"

    