/*
TODO:�����ɫ&�������
*/
#include "defines.h"
int coins = 0;		//�����
int shuffles = 0;	//���ҿ�
int disappears = 0;	//��ʧ��
int doubles = 0;	//������
int score = 0;		//����
int maxscore = 0;	//��߷�
int arr[10][10] {}; //4 X 4
int fgcolor[100] = {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15};
int bgcolor[100] {};
HANDLE stdhand = GetStdHandle(STD_OUTPUT_HANDLE);

void newnum()
{
	int nullcnt = 0;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			if (arr[i][j] == 0) nullcnt++;
		}
	}
	if (nullcnt == 0) return; //û��
	int nullpos = rand() % nullcnt;
	
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			if (arr[i][j] == 0 && !nullpos--)
			{
				arr[i][j] = rand() % 2 + 1;
				return;
			}
		}
	}
}
bool lose()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			if (arr[i][j] == 0) return false;
		}
	}
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			if (arr[i][j] == arr[i - 1][j] ||
				arr[i][j] == arr[i][j + 1] ||
				arr[i][j] == arr[i + 1][j] ||
				arr[i][j] == arr[i][j - 1]) return false;
		}
	}
	return true;
}
void out(int markx, int marky)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(stdhand, &csbi);
	int kx = csbi.dwCursorPosition.X, ky = csbi.dwCursorPosition.Y;
	auto getvxy = [ky](int x, int y) -> pair<int, int> { return { y * 6 - 5, ky + x * 4 - 2 }; };
	printf(R"(+-----+-----+-----+-----+
|     |     |     |     |
|     |     |     |     |
|     |     |     |     |
+-----+-----+-----+-----+
|     |     |     |     |
|     |     |     |     |
|     |     |     |     |
+-----+-----+-----+-----+
|     |     |     |     |
|     |     |     |     |
|     |     |     |     |
+-----+-----+-----+-----+
|     |     |     |     |
|     |     |     |     |
|     |     |     |     |
+-----+-----+-----+-----+
)");
	if (markx != -1 && marky != -1)
	{
		int begint = getvxy(markx, marky).second - 1, 
			  endt = begint + 3, 
			  bgy = getvxy(markx, marky).first;
		SetConsoleTextAttribute(stdhand, BACKGROUND_RED);
		for (int i = begint; i < endt; i++)
		{
			SetConsoleCursorPosition(stdhand, { short(bgy), short(i)});
			printf("     ");
		}
		SetConsoleCursorPosition(stdhand, { (short)kx, (short)ky });
	}
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			if (arr[i][j] == 0) continue;
			int vnum = 1 << arr[i][j];
			int vsize = to_string(vnum).size();
			int vls = (5 - vsize) / 2, vrs = 5 - vsize - vls;
			COORD pspos = pxy2coord(getvxy(i, j));
			SetConsoleCursorPosition(stdhand, { short(pspos.X + vls), short(pspos.Y) });
			SetConsoleTextAttribute(stdhand, (bgcolor[arr[i][j]] << 0x10) + fgcolor[arr[i][j]]);
			printf("%d", vnum);
		}
	}
	SetConsoleCursorPosition(stdhand, { 0, short(ky + 17) });
}
bool choose(int& x, int& y)
{
	x = y = 1;
	while (true)
	{
		char ch;
		system("cls");
		out(x, y);
		printf("���������ƶ����ո�ѡ�С�\n");
		printf("��Ҫȡ��������ѡ��һ���ո���Ȼ���¿ո�Ҳ���԰�λ���Ƶ���ͼ֮�⡣\n");
		while ((ch = getch()) != -32 && ch != ' ');
		if (ch == ' ')
		{
			if (arr[x][y] == 0)
			{
				printf("ȡ���ɹ���\n");
				return false;
			}
			printf("�ɹ���\n");
			return true;
		}
		ch = getch();
		switch (ch)
		{
		case 'H': x--; break;
		case 'P': x++; break;
		case 'K': y--; break;
		case 'M': y++; break;
		}
		if (x <= 0 || x >= 5 || y <= 0 || y >= 5)
		{
			printf("ȡ���ɹ���\n");
			return false;
		}
	}
}

COORD pxy2coord(const pair<int, int> pxy)
{
	return { (short)pxy.first, (short)pxy.second };
}
