#include "shop.h"
void shopmain()
{
	while (true)
	{
		system("cls");
		printf("Ҫ�����̵��𣿣�����Y��N��[Y]es, [N]o��");
		char ch = getch();
		if (ch == 'y' || ch == 'Y')
		{
			while (true)
			{
				system("cls");
				printf(R"(ʣ��%d����
Ҫ��ʲô�أ�
����1�����ҿ���������ҳ��ϵ��������֣���ע�⣬�Ǵ�������ң�������������������п��ܴ��Һ��Ϊʧ��״̬��500����һ�š�
����2����ʧ��������ѡ��һ�����֣�ʹ����ʧ��100����һ�š�
����3��������������ѡ��һ�����֣�ʹ�䷭�������ӵ÷�/���֣�100����һ�š�
�����������˳�
)", coins);
				ch = getch();
				if (ch == '1')
				{
					if (coins < 500)
					{
						printf("���ֲ��㣡\n");
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
						printf("���ֲ��㣡\n");
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
						printf("���ֲ��㣡\n");
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