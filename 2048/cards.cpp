#include "cards.h"

bool callshuffle()
{
	if (shuffles <= 0)
	{
		printf("û�д��ҿ���\n");
		return false;
	}
	printf("ȷ�ϣ�[Y]es��[N]o");
	char ch = getch();
	if (ch != 'y' && ch != 'Y')
	{
		printf("\nȡ���ɹ���\n");
		return false;
	}
	shuffles--;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			int x = rand() % 4 + 1, y = rand() % 4 + 1;
			swap(arr[i][j], arr[x][y]);
		}
	}
	printf("\n���ҳɹ���\n");
	return true;
}

bool calldisappear()
{
	if (disappears <= 0)
	{
		printf("û����ʧ����\n");
		return false;
	}
	disappears--;
	int mx = 1, my = 1;
	if (choose(mx, my)) arr[mx][my] = 0;
	else return false;
	return true;
}

bool calldouble()
{
	if (doubles <= 0)
	{
		printf("û�з�������\n");
		return false;
	}
	doubles--;
	int mx = 1, my = 1;
	if (choose(mx, my)) arr[mx][my] *= 2;
	else return false;
	return true;
}