/*
 * PoopJump
 * Copyright (C) 2026 WKf-0000
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#include <bits/stdc++.h>
#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
    #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
using namespace std;
struct coords
{
    int x, y;
};
void waitForAnyKey()
{
    cout << "\nPress any key to continue...";
    cout.flush();
    #ifdef _WIN32
        while (_kbhit()) _getch();
        _getch();
    #else
        cin.get();
    #endif
}
void forceEnglishInput()
{
    keybd_event(VK_SHIFT, 0, 0, 0);
    Sleep(50);
    keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
}
bool init() 
{
    srand(time(0));
    forceEnglishInput();
    #ifdef _WIN32
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut == INVALID_HANDLE_VALUE) return false;
        DWORD dwMode = 0;
        if (!GetConsoleMode(hOut, &dwMode)) return false;
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
        return SetConsoleMode(hOut, dwMode) != 0;
    #else
        return true;
    #endif
}
vector <string> mp;// 地图
bool isFly = 0;// 飞起来!!
int flyHigh = 0;// 飞起来的高度
int flybeginY = 0;// 飞起来的起始高度
coords player = {10 , 0};
int left_x = 0 , right_x = 0;
int mayi = 0;
void getMap(string file/*地图的文件名*/)
{
    ifstream in(file);
    if(!in.is_open())
    {
        cerr << "地图文件打开失败!" << endl;
        return;
    }
    string mapp = "";
    while(getline(in , mapp))
    {
        mp.push_back(mapp);
    }
}
void drawMap()
{
    cout << "Gold coin count : " << mayi << "\n";
    for(int i = 0; i < mp.size(); i++)
    {
        for(int j = left_x; j <= right_x; j++)
        {
            if(i == player.y && j == player.x)
            {
                cout << "\033[36mP\033[0m";
            }
            else if(mp[i][j] == '$') cout << "\033[33m$\033[0m";
            else
            {
                cout << mp[i][j];
            }
        }
        cout << '\n';
    }
}
bool canStandAt(int x, int y)
{
    if(y < 0 || y >= mp.size()) return false;
    if(x < 0 || x >= mp[y].size()) return false;
    return mp[y][x] != '#';
}
void beginGame(string mapPath)
{
    cout << "\033[2J\033[H" << flush;
    getMap(mapPath);
    right_x = player.x + 20;
    while(1)
    {
        if(mp[player.y][player.x] == '$')
        {
	    mayi ++;
 	    mp[player.y][player.x] = ' ';
	}
        if(isFly)
        {
            if(player.y > flybeginY - flyHigh && canStandAt(player.x, player.y - 1))
            {
                player.y --;
            }
            else
            {
                isFly = false;
            }
        }
        if(!isFly && canStandAt(player.x, player.y + 1))
        {
            player.y++;
        }
        if(GetAsyncKeyState('Q') & 0x8000)
        {
            cout << "\033[?25h";
            waitForAnyKey();
            break;
        }
        if (!isFly && (GetAsyncKeyState(VK_UP) & 0x8000))
        {
            bool onGround = player.y + 1 < static_cast<int>(mp.size()) && player.x >= 0 && player.x < static_cast<int>(mp[player.y + 1].size()) && mp[player.y + 1][player.x] == '#';
            if(onGround)
            {
                isFly = true;
                flyHigh = rand() % 3 + 3;
                flybeginY = player.y;
            }
        }
        if((GetAsyncKeyState(VK_LEFT) & 0x8000) && canStandAt(player.x - 1 , player.y) && player.x - 1 >= left_x)
        {
            player.x --;
        }
        if((GetAsyncKeyState(VK_RIGHT) & 0x8000) && canStandAt(player.x + 1 , player.y))
        {
            player.x ++;
            if(player.x > right_x - 5)
            {
            	if(right_x + 1 <= mp[0].size()) right_x ++ , left_x ++;
            }
        }
        cout << "\033[?25l";
        cout << "\033[H";
        drawMap();
        #ifdef _WIN32
        	Sleep(30);
        #endif
    }
}
int main()
{
    cout << R"(PoopJump
Copyright (C) 2026 WKf-0000

Disclaimer:
This program is provided for learning and research purposes only.
The author shall not be liable for any direct or indirect damages
caused by the use of this program.

This program is distributed under the GPL-2.0-or-later license.

)";
    waitForAnyKey();
    if(!init())
    {
        cout << "Can not Using VT Output!!!\n";
        waitForAnyKey();
        return 0;
    }
    beginGame("maps/test.txt");
    return 0;
}
