#pragma once

#pragma warning(disable:4996) //返回值被忽略：xxx
#pragma warning(disable:6031) //xxx: The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: xxx. See online help for details.

//先来一堆头文件
#include <ctime>
#include <cstdio>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <algorithm>
#include <Windows.h>

using namespace std;

//定义变量
extern int coins;			//金币数
extern int score;			//分数
extern int doubles;			//翻倍卡
extern int shuffles;		//打乱卡
extern int disappears;		//消失卡
extern int maxscore;		//最高分
extern int arr[10][10];		//4 X 4
extern HANDLE stdhand;		//标准输出句柄
extern int fgcolor[100];	//不同数字前景色
extern int bgcolor[100];	//不同数字背景色

//函数
void newnum();
bool lose();
void out(int markx = -1, int marky = -1);
bool choose(int& x, int& y);
COORD pxy2coord(const pair<int, int> pxy);