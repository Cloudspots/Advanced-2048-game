#pragma once

#pragma warning(disable:4996) //����ֵ�����ԣ�xxx
#pragma warning(disable:6031) //xxx: The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: xxx. See online help for details.

//����һ��ͷ�ļ�
#include <ctime>
#include <cstdio>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <algorithm>
#include <Windows.h>

using namespace std;

//�������
extern int coins;			//�����
extern int score;			//����
extern int doubles;			//������
extern int shuffles;		//���ҿ�
extern int disappears;		//��ʧ��
extern int maxscore;		//��߷�
extern int arr[10][10];		//4 X 4
extern HANDLE stdhand;		//��׼������
extern int fgcolor[100];	//��ͬ����ǰ��ɫ
extern int bgcolor[100];	//��ͬ���ֱ���ɫ

//����
void newnum();
bool lose();
void out(int markx = -1, int marky = -1);
bool choose(int& x, int& y);
COORD pxy2coord(const pair<int, int> pxy);