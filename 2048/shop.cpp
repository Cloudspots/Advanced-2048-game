#include "shop.h"
void shopmain()
{
	while (true)
	{
		system("cls");
		printf("要进入商店吗？（输入Y或N，[Y]es, [N]o）");
		char ch = getch();
		if (ch == 'y' || ch == 'Y')
		{
			while (true)
			{
				system("cls");
				printf(R"(剩余%d积分
要买什么呢？
输入1：打乱卡，随机打乱场上的所有数字，请注意，是纯随机打乱，如果场上数字已满，有可能打乱后成为失败状态。500积分一张。
输入2：消失卡，可以选择一个数字，使其消失，100积分一张。
输入3：翻倍卡，可以选择一个数字，使其翻倍，不加得分/积分，100积分一张。
输入其他：退出
)", coins);
				ch = getch();
				if (ch == '1')
				{
					if (coins < 500)
					{
						printf("积分不足！\n");
						getch();
						continue;
					}
					coins -= 500;
					shuffles++;
				}
				else if (ch == '2')
				{
					if (coins < 100)
					{
						printf("积分不足！\n");
						getch();
						continue;
					}
					coins -= 100;
					disappears++;
				}
				else if (ch == '3')
				{
					if (coins < 100)
					{
						printf("积分不足！\n");
						getch();
						continue;
					}
					coins -= 100;
					doubles++;
				}
				else break;
			}
		}
		if (ch == 'n' || ch == 'N') return;
	}
}