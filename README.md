本项目是一个采用openGL实现的2D游戏引擎，采用了批处理渲染和ECS组件化架构。除了脚本支持以外，项目具备2D引擎所需的大部分功能。项目实现了用户友好的操作界面，可以方便地编译运行。本项目主要参考Youtube博主The Cherno的Game Engine Series实现。

## 基本功能

1. 新建场景、保存场景、加载场景。

2. 新建实体、删除实体。

3. 为实体添加组件，使其成为一个摄像机、矩形或圆。

4. 调整实体的位置、旋转、缩放（点击实体后分别按下W、E、R键实现）。

5. 为实体添加纹理，支持文件拖拽导入。

6. 调整实体色调。

7. 为实体添加刚体和碰撞器，包括矩形碰撞器和圆形碰撞器，碰撞器可以设置摩擦力和恢复系数等。

8. 基础的物理模拟，运行和关闭模拟。

## 操作指南

1. 运行程序后，先点击左上角的"File"->"New"新建场景。

2. 在左上方"Scene Hierarchy"面板内按下右键可以新建Entity。

3. 点击Entity，左下方的"Properties"面板可以添加Component和编辑相应属性。

4. 在中间的显示面板中左键选中Entity，按下"W""E""R"键可以分别唤起平移、旋转、缩放组件。

5. 上方的两个按钮中，第一个按钮是以场景中的摄像机视角开启模拟（需要先在场景内创建带Camera Component的Entity）；第二个按钮是以默认摄像机视角开启模拟。

6. 点击"File"中的"Save"和"Open"可以保存和打开文件，只支持mge为后缀名的文件。

## 设备要求

仅支持Windows操作系统，要求Windows系统下已安装Visual Studio。

## 如何运行

1、通过git拉取仓库：https://github.com/ZJU-Lv/MiniGameEngine.git

2、初始化子模块：git submodule update --init

3、更改GenerateProjects.bat文件，将里面的vs版本修改为本地电脑上安装的版本。

4、运行GenerateProjects.bat。

5、打开MiniGameEngine.sln项目，直接编译即可运行。

## 场景演示

（由于演示的gif文件较大，浏览器加载可能需要较长时间，可以直接点开Demo1.gif和Demo2.gif观看）

![Demo1](https://github.com/ZJU-Lv/MiniGameEngine/blob/main/Demo1.gif)

![Demo2](https://github.com/ZJU-Lv/MiniGameEngine/blob/main/Demo2.gif)
