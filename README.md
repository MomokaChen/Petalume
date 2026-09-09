# Petalume

从零手写的轻量级 C++ 游戏引擎（个人长期项目，早期开发中）

A lightweight C++ game engine written from scratch. My own long-term project, early stage.

## 简介

Petalume 是一个自研 C++ 游戏引擎，目前处于早期开发阶段，已搭好引擎基础框架：解决方案骨架、`Application` 应用基类与入口封装、Windows 平台导出宏、基于 spdlog 的日志系统、事件系统（事件基类 / 分发器 / 应用·键盘·鼠标事件）、预编译头，以及 Premake5 构建配置。窗口、渲染等系统将在后续逐步补充。本项目仅作个人学习用途，非商业性质，全部代码开放以供参考。

Petalume is a self-developed C++ game engine in early development. The engine foundation is already in place: the solution skeleton, an `Application` base class with entry-point abstraction, Windows export macros, an spdlog-based logging system, an event system (event base / dispatcher / application·keyboard·mouse events), a precompiled header, and a Premake5 build setup. Windowing, rendering and other systems will be added later. Purely for personal learning, non‑commercial, all code open for reference.

**项目状态：开发早期（应用骨架 + 日志系统 + 事件系统 + Premake5 构建）**

## 当前进度

- [x] 解决方案骨架（`Petalume/` 引擎 DLL + `Sandbox/` 示例控制台应用）
- [x] `Application` 应用基类与主循环骨架（`Run()`）
- [x] `EntryPoint` 入口封装 —— 客户端只需继承 `Application` 并实现 `CreateApplication()` 即可启动
- [x] 平台与导出宏（`Core.h`，当前仅支持 Windows）
- [x] 日志系统（基于 spdlog：核心 / 客户端双 logger，`PL_CORE_*` 与 `PL_*` 日志宏，入口处自动初始化）
- [x] 事件系统：`Event` 基类与 `EventDispatcher` 事件分发器、事件类型 / 分类位标记、`EVENT_CLASS_TYPE` / `EVENT_CLASS_CATEGORY` 宏，以及应用事件（窗口关闭 / 缩放、AppTick / AppUpdate / AppRender）、键盘事件（按下 / 释放）、鼠标事件（移动 / 滚动 / 按钮按下 / 释放）；当前为阻塞式立即分发
- [x] 预编译头 `plpch.h`（常用标准库头文件 + Windows.h），已在 Premake5 中启用
- [x] Premake5 构建配置（x64，Debug / Release / Dist 三种配置；引擎构建为 DLL 后自动拷贝到 Sandbox 输出目录）

## 项目结构

```
Petalume/
├── Petalume/                 # 引擎核心库（SharedLib / DLL）
│   ├── src/
│   │   ├── plpch.h / plpch.cpp     # 预编译头（标准库 + Windows.h）
│   │   ├── Petalume.h        # 引擎统一入口头文件
│   │   └── Petalume/
│   │       ├── Application.h/cpp   # 应用基类与主循环
│   │       ├── Core.h              # 平台宏 / 导出宏
│   │       ├── EntryPoint.h        # 客户端入口（main）
│   │       ├── Log.h/cpp           # 日志系统（spdlog 封装）
│   │       └── Events/             # 事件系统
│   │           ├── Event.h              # Event 基类 / EventDispatcher / 事件类型与分类
│   │           ├── ApplicationEvent.h   # 窗口与应用事件
│   │           ├── KeyEvent.h           # 键盘事件
│   │           └── MouseEvent.h         # 鼠标事件
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

仓库使用 Premake5 管理构建（`premake5.lua`），提供 Debug / Release / Dist 三种 x64 配置：引擎 `Petalume` 编译为 DLL，构建后会自动拷贝到 `Sandbox` 的输出目录；引擎工程已启用预编译头 `plpch.h`。

- 生成 Visual Studio 2022 工程：运行 `GenerateProject.bat`（脚本调用仓库内自带的 `vendor/bin/premake/premake5.exe vs2022`）。
- 也可以直接用 Visual Studio 打开仓库内已生成的 `Petalume.sln` 构建。
- spdlog 以 git submodule 形式引入，克隆仓库时请使用 `git clone --recursive`，或执行 `git submodule update --init`。

## 相关项目

- [MyOpenGLGameEngine](https://github.com/MomokaChen/MyOpenGLGameEngine) —— 此前的引擎练习项目，为 Petalume 提供了架构与工程经验。

## 许可证

[GPL-3.0](LICENSE)
