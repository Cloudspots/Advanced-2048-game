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
			printf("分数：%d分\n", score);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 30, 5 });
			printf("%s\n", said.c_str());
			if (score > maxscore)
			{
				maxscore = score;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 60, 9 });
				printf("新纪录！\n");
			}
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{30, 9});
			printf("最高分：%d分！\n", maxscore);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 18 });
			printf("打乱卡：%d张\t消失卡：%d张\t翻倍卡：%d张\n", shuffles, disappears, doubles);
			printf("↑↓←→移动，s进入商城，r重来，a使用打乱卡，b使用消失卡，c使用翻倍卡，m进入个性化。\n");
			if (lose()) break;
			char ch = 0;
			while ((ch = getch()) != -32 && ch != 's' && ch != 'a' && ch != 'b' && ch != 'c' && ch != 'r' && ch != 'm');
			if (ch == 'r')
			{
				printf("确定吗？[Y]es/[N]o");
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
			printf(R"(要不要使用打乱/消失卡/翻倍卡呢？
1.打乱卡（可能打乱后还是无解，看运气）
2.消失卡（最推荐，在这种情况下物美价廉）
3.翻倍卡（如果没有把握，不建议）
其他.不用)");
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
