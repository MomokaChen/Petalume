# Petalume

从零手写的轻量级 C++ 游戏引擎（个人长期项目，早期开发中）

A lightweight C++ game engine written from scratch. My own long-term project, early stage.

## 简介

Petalume 是一个自研 C++ 游戏引擎，目前处于早期开发阶段，已搭好引擎基础框架：解决方案骨架、`Application` 应用基类与入口封装、Windows 平台导出宏、基于 spdlog 的日志系统，以及 Premake5 构建配置。渲染、窗口、事件等系统将在后续逐步补充。本项目仅作个人学习用途，非商业性质，全部代码开放以供参考。

Petalume is a self-developed C++ game engine in early development. The engine foundation is already in place: the solution skeleton, an `Application` base class with entry-point abstraction, Windows export macros, an spdlog-based logging system, and a Premake5 build setup. Rendering, windowing, events and other systems will be added later. Purely for personal learning, non‑commercial, all code open for reference.

**项目状态：开发早期（引擎基础框架：应用骨架 + 日志系统 + Premake5 构建）**

## 当前进度

- [x] 解决方案骨架（`Petalume/` 引擎 DLL + `Sandbox/` 示例控制台应用）
- [x] `Application` 应用基类与主循环骨架（`Run()`）
- [x] `EntryPoint` 入口封装 —— 客户端只需继承 `Application` 并实现 `CreateApplication()` 即可启动
- [x] 平台与导出宏（`Core.h`，当前仅支持 Windows）
- [x] 日志系统（基于 spdlog：核心 / 客户端双 logger，`PL_CORE_*` 与 `PL_*` 日志宏，入口处自动初始化）
- [x] Premake5 构建配置（x64，Debug / Release / Dist 三种配置；引擎构建为 DLL 后自动拷贝到 Sandbox 输出目录）

## 项目结构

```
Petalume/
├── Petalume/                 # 引擎核心库（SharedLib / DLL）
│   ├── src/
│   │   ├── Petalume.h        # 引擎统一入口头文件
│   │   └── Petalume/
│   │       ├── Application.h/cpp   # 应用基类与主循环
│   │       ├── Core.h              # 平台宏 / 导出宏
│   │       ├── EntryPoint.h        # 客户端入口（main）
│   │       └── Log.h/cpp           # 日志系统（spdlog 封装）
│   └── vendor/
│       └── spdlog/           # 第三方日志库（git submodule）
├── Sandbox/                  # 示例应用（ConsoleApp）
│   └── src/SandboxApp.cpp
├── premake5.lua              # Premake5 构建配置
├── GenerateProject.bat       # 生成 VS2022 工程脚本
├── LICENSE                   # GPL-3.0
└── README.md
```

## 构建

仓库使用 Premake5 管理构建（`premake5.lua`），提供 Debug / Release / Dist 三种 x64 配置：引擎 `Petalume` 编译为 DLL，构建后会自动拷贝到 `Sandbox` 的输出目录。

- 生成 Visual Studio 2022 工程：运行 `GenerateProject.bat`（脚本调用 `vendor/bin/premake/premake5.exe vs2022`，需自行将 premake5 可执行文件放置到该路径）。
- 也可以直接用 Visual Studio 打开仓库内已生成的 `Petalume.sln` 构建。
- spdlog 以 git submodule 形式引入，克隆仓库时请使用 `git clone --recursive`，或执行 `git submodule update --init`。

## 相关项目

- [MyOpenGLGameEngine](https://github.com/MomokaChen/MyOpenGLGameEngine) —— 此前的引擎练习项目，为 Petalume 提供了架构与工程经验。

## 许可证

[GPL-3.0](LICENSE)
