# smart-car-coconut
智能小车 - STM32F103ZET6 循迹+语音控制
# 椰椰杯智能小车 (Smart Car for Coconut Cup)

## 项目简介
深圳大学电子与信息工程学院"中国电信杯"椰椰杯智能小车设计竞赛参赛作品。
基于STM32F103ZET6的自动循迹小车，集成语音交互功能。

## 硬件平台
- **主控**: STM32F103ZET6（正点原子精英版）
- **电机驱动**: TB6612
- **传感器**: 8路红外阵列 + OpenMV视觉模块
- **语音模块**: SU-03T（识别）+ SYN6288（播报）
- **电源**: 7.4V锂电池 + DC-DC降压

## 软件架构
- **User/**: 主程序、中断处理
- **BSP/**: 板级驱动（LED、按键、定时器、电机）
- **Projects/**: Keil MDK-ARM工程配置

## 功能特性
- [x] 红外循迹（PD控制算法）
- [x] 语音控制（启动、接管、加速、减速）
- [x] 锐角弯减速（OpenMV预判）
- [ ] 编码器闭环（待实现）

## 作者
- 深圳大学 电子信息工程 2026级 黎
- GitHub: [@embedded-li](https://github.com/embedded-li)
