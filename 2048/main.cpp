#include "defines.h"
#include "shop.h"
#include "move.h"
#include "cards.h"

using namespace std;

void myshow()
{
	printf("building...\n");
}

int main()
{
	int rd = 0;
	while (++rd)
	{
		iakioi:
		memset(arr, 0, sizeof arr);
		srand((unsigned)time(NULL));
		score = 0;
		string said;
		while (true)
		{
			newnum();
		et:
			system("cls");
			int rs = to_string(rd).size(), ln = (25-rs-6)/2, rn = (26-rs-6)/2;
			printf("%sRound %d%s\n", string(ln, '-').c_str(), rd, string(rn, '-').c_str());
			out();
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 30, 13 });
			printf("������%d��\n", score);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 30, 5 });
			printf("%s\n", said.c_str());
			if (score > maxscore)
			{
				maxscore = score;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 60, 9 });
				printf("�¼�¼��\n");
			}
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{30, 9});
			printf("��߷֣�%d�֣�\n", maxscore);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 18 });
			printf("���ҿ���%d��\t��ʧ����%d��\t��������%d��\n", shuffles, disappears, doubles);
			printf("���������ƶ���s�����̳ǣ�r������aʹ�ô��ҿ���bʹ����ʧ����cʹ�÷�������m������Ի���\n");
			if (lose()) break;
			char ch = 0;
			while ((ch = getch()) != -32 && ch != 's' && ch != 'a' && ch != 'b' && ch != 'c' && ch != 'r' && ch != 'm');
			if (ch == 'r')
			{
				printf("ȷ����[Y]es/[N]o");
				ch = getch();
				if (ch == 'Y' || ch == 'y') goto iakioi;
			}
			if (ch == 's')
			{
				shopmain();
				goto et;
			}
			if (ch == 'a')
			{
				callshuffle();
				getch();
				goto et;
			}
			if (ch == 'b')
			{
				calldisappear();
				//getch();
				goto et;
			}
			if (ch == 'c')
			{
				calldouble();
				goto et;
			}
			if (ch == 'm')
			{
				myshow();
				goto et;
			}
			ch = getch();
			said = "";
			switch (ch)
			{
			case 'H': said = move('U'); break;
			case 'P': said = move('D'); break;
			case 'K': said = move('L'); break;
			case 'M': said = move('R'); break;
			}
		}
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 22 });
		printf("Lose!\n");
		Sleep(1000);
		while (_kbhit()) getch();
		if (shuffles || disappears || doubles)
		{
			printf(R"(Ҫ��Ҫʹ�ô���/��ʧ��/�������أ�
1.���ҿ������ܴ��Һ����޽⣬��������
2.��ʧ�������Ƽ������������������������
3.�����������û�а��գ������飩
����.����)");
			char ch = getch();
			if (ch == '1')
			{
				system("cls");
				if (callshuffle()) goto et;
			}
			if (ch == '2')
			{
				if (calldisappear()) goto et;
			}
			if (ch == '3')
			{
				if (calldouble()) goto et;
			}
		}
		getch();
	}
	return 0;
}
