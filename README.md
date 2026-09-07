# Petalume

从零手写的轻量级 C++ 游戏引擎（个人长期项目，早期开发中）

A lightweight C++ game engine written from scratch. My own long-term project, early stage.

## 简介

Petalume 是一款自研的 2D OpenGL 引擎，目前处于早期开发阶段，未来规划将支持 3D 功能。项目重心在于渲染管线、引擎架构以及底层图形技术，后续会逐步补充场景管理、资源加载与物理系统。本项目仅作个人学习用途，非商业性质，全部代码开放以供参考。

Petalume is a self-developed 2D OpenGL engine in early development, with a future roadmap to support 3D. It focuses on rendering pipelines, engine architecture, and low-level graphics, and will gradually add scene management, asset loading, and physics. Purely for personal learning, non‑commercial, all code open for reference.

**项目状态：开发早期（应用骨架已完成）**

## 当前进度

- [x] 解决方案骨架（`Petalume/` 引擎库 + `Sandbox/` 示例应用）
- [x] `Application` 应用基类与主循环
- [x] `EntryPoint` 入口封装 —— 客户端只需继承 `Application` 即可启动
- [x] 平台与导出宏（`Core.h`，当前仅支持 Windows）
- [ ] 日志系统（spdlog）
- [ ] 事件系统
- [ ] 窗口抽象（GLFW）
- [ ] 渲染管线（OpenGL）
- [ ] 场景与实体系统
- [ ] 编辑器（ImGui）

## 项目结构

```
Petalume/
├── Petalume/                 # 引擎核心库
│   └── src/
│       ├── Petalume.h        # 引擎统一入口头文件
│       └── Petalume/
│           ├── Application.h/cpp   # 应用基类与主循环
│           ├── Core.h               # 平台宏 / 导出宏
│           └── EntryPoint.h         # 客户端入口
├── Sandbox/                  # 示例应用
│   └── src/SandboxApp.cpp
├── LICENSE                   # GPL-3.0
└── README.md
```

## 构建

尚未接入构建系统（规划使用 Premake5，配置将复用 MyOpenGLGameEngine 的踩坑经验）。当前直接用 Visual Studio 打开 `Petalume.sln` 即可构建。

## 相关项目

- [MyOpenGLGameEngine](https://github.com/MomokaChen/MyOpenGLGameEngine) —— 此前的引擎练习项目，为 Petalume 提供了架构与工程经验。

## 许可证

[GPL-3.0](LICENSE)
