# PoopJump

PoopJump 是一个使用 C++ 编写的 Windows 控制台平台跳跃小游戏。玩家可以在文字地图中移动、跳跃，并避开 `#` 地形。

## 功能

- 在控制台中显示地图和角色
- 支持左右移动
- 支持随机高度跳跃和重力下落
- 支持从 `maps/` 目录加载文字地图
- 使用青色字符表示玩家
- 支持中文 UTF-8 控制台编码

## 操作

| 按键 | 操作 |
|---|---|
| `←` | 向左移动 |
| `→` | 向右移动 |
| `↑` | 跳跃 |
| `Q` | 退出游戏 |

## 编译环境

- Windows
- MinGW-w64 / 支持 C++14 的 GCC
- 命令提示符或支持 ANSI 转义序列的终端

## 编译与运行

在项目根目录打开终端：

```powershell
cd C:\Users\Administrator\Desktop\yx
g++ -g -Wl,--stack=0x10000000 -std=c++14 -finput-charset=UTF-8 -fexec-charset=UTF-8 Untitled-1.cpp -o Untitled-1.exe
.\Untitled-1.exe
```

运行前请确认地图文件位于：

```text
maps/test.txt
```

## 地图格式

地图是纯文本文件：

- `#`：障碍或平台
- 空格：可通行区域
- 字符中的列表示横坐标 `x`
- 文件中的行表示纵坐标 `y`

项目目前使用的测试地图位于 `maps/test.txt`。

## 免责声明

本程序仅供学习和研究使用。作者不对使用本程序造成的任何直接或间接损失承担责任。

## 许可证

本项目的源代码按 GNU General Public License v2 许可证发布，详情请参阅 `LICENSE` 文件。

Copyright (C) 2026 WKf-0000

---

# PoopJump (English)

PoopJump is a Windows console platform-jumping game written in C++. The player can move and jump through a text-based map and avoid `#` terrain.

## Features

- Displays the map and player in the console
- Supports left and right movement
- Supports randomized jump height and gravity
- Loads text maps from the `maps/` directory
- Uses cyan characters to represent the player
- Supports UTF-8 console encoding for Chinese text

## Controls

| Key | Action |
|---|---|
| `←` | Move left |
| `→` | Move right |
| `↑` | Jump |
| `Q` | Exit |

## Requirements

- Windows
- MinGW-w64 or another GCC compiler with C++14 support
- Command Prompt or a terminal that supports ANSI escape sequences

## Build and Run

Open a terminal in the project directory:

```powershell
cd C:\Users\Administrator\Desktop\yx
g++ -g -Wl,--stack=0x10000000 -std=c++14 -finput-charset=UTF-8 -fexec-charset=UTF-8 Untitled-1.cpp -o Untitled-1.exe
.\Untitled-1.exe
```

Make sure the map file is located at:

```text
maps/test.txt
```

## Map Format

The map is a plain text file:

- `#`: obstacle or platform
- Space: walkable area
- Columns represent the horizontal coordinate `x`
- Rows represent the vertical coordinate `y`

The test map is located at `maps/test.txt`.

## Disclaimer

This program is provided for learning and research purposes only. The author shall not be liable for any direct or indirect damages caused by using this program.

## License

This project's source code is distributed under the GNU General Public License v2. See the `LICENSE` file for details.

Copyright (C) 2026 WKf-0000
