#pragma once

#ifdef PL_PLATFORM_WINDOWS

extern Petalume::Application* Petalume::CreateApplication();

int main(int argc, char** argv)
{
	Petalume::Log::Init();
	PL_CORE_WARN("Initialized Log!");
	int a = 5;
	PL_INFO("Hello! Var={0}", a);

	auto app = Petalume::CreateApplication();
	app->Run();
	delete app;
}

#endif