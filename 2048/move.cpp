#include "move.h"
void turnright()
{
	int tmp[5][5]{};
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			tmp[i][j] = arr[i][j];
		}
	}
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			arr[j][4 - i + 1] = tmp[i][j];
		}
	}
}

string move(char ch)
{
	int pscore = 1, cnt = 0;
	switch (ch)
	{
	case 'U': turnright(); break;
	case 'L': turnright(); turnright(); break;
	case 'D': turnright(); turnright(); turnright(); break;
	}
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 4; j >= 1; j--)
		{
			if (arr[i][j])
			{
				if (arr[i][j + 1])
				{
					if (arr[i][j + 1] == arr[i][j])
					{
						arr[i][j + 1]++;
						pscore *= (1 << arr[i][j + 1]) / 3;
						if (arr[i][j + 1] == 2) pscore++;
						arr[i][j] = 0;
					}
					continue;
				}
				for (int k = j + 1; k <= 4; k++)
				{
					if (arr[i][k]) break;
					arr[i][k] = arr[i][k - 1];
					arr[i][k - 1] = 0;
				}
			}
		}
	}
	switch (ch)
	{
	case 'U': turnright(); turnright(); turnright(); break;
	case 'L': turnright(); turnright(); break;
	case 'D': turnright(); break;
	}
	pscore--;
	coins += pscore;
	score += pscore;
	if (pscore == score && score) return "First Kill!\n"s;
	if (pscore >= 10000) return			 "The Best In The World!\n"s;
	else if (pscore >= 5000) return		 "The Best In The Nation!\n"s;
	else if (pscore >= 2000) return		 "The Best In The Province!\n"s;
	else if (pscore >= 1000) return		 "Unbelievable!\n"s;
	else if (pscore >= 500) return		 "Best!\n"s;
	else if (pscore >= 200) return		 "Very Good!\n"s;
	else if (pscore >= 100) return		 "Great!\n"s;
	else if (pscore >= 50) return		 "Conbo!\n"s;
	return "";
}