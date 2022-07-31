#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define x 9
#define y (x+1)
#define d (y/2)
#define itr y*y

void exibe(int m[x][y])
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 1; j < y; j++)
		{
			switch (m[i][j])
			{
				case 2:
					printf("T ");
					break;
				case 1:
					printf("- ");
					break;
				case -1:
				case -2:
					printf("x ");
					break;
					break;
				case 0:
					printf("0 ");
					break;
			}
		}
		printf("\n");
	}
}

void exibev(int m[x][y])
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 1; j < y; j++)
		{
			if (m[i][j] == 1)
			{
				printf("%d ",m[i][j]);
			}
			else
			{
				if (m[i][j] == 2)
				{
					printf("%T ", m[i][j]);
				}
				else
				{
					printf("%d ", m[i][j]);
				}
			}
		}
		printf("\n");
	}
}

int pr(int m, int i, int j)
{
	if (j == 1 || j == y - 1 || i == 0 || i == x - 1)
	{
		m = 1;
	}
	else
	{
		if (i == (d - 1) && j == d)
		{
			m = 2;
		}
		else
		{
			m = 0;
		}
	}
	return m;
}

int r(int m, int i, int j)
{
	if (i == (d - 1) && j == d)
	{
		m = 2;
	}
	else
	{
		m = rand() %2;
	}
	return m;
}

int main()
{
	int m[x][y];
	srand((unsigned)time(NULL));
	for (int i = 0; i < x; i++)
	{
		for (int j = 1; j < y; j++)
		{
			//m[i][j] = pr(m[i][j], i, j);
			m[i][j] = r(m[i][j],i,j);
		}
	}
	exibe(m);
	//mov(0 = nenhum,1 = direita,-1 = esquerda,2 = cima, -2 = baixo)
	int px, py,mov=0,dir,a;
	for (int k = 1; k <= itr; k++)
	{
		px = -1;
		mov = 0;
		for (int i = 0; i < x; i++)
		{
			for (int j = 1; j < y; j++)
			{
				if (m[i][j] == 2)
				{
					px = i;
					py = j;
					break;
				}
			}
			if (px != -1)
			{
				break;
			}
		}
		if (px > 0 && mov == 0)
		{
			if (m[(px - 1)][(py)] == 1)
			{
				m[px][py] = -1;
				m[(px - 1)][(py)] = 2;
				mov = 2;
			}
		}
		if (py < y && mov == 0)
		{
			if (m[(px)][(py + 1)] == 1)
			{
				m[px][py] = -1;
				m[(px)][(py + 1)] = 2;
				mov = 1;
			}
		}
		if (px < x && mov == 0)
		{
			if (m[(px + 1)][(py)] == 1)
			{
				m[px][py] = -1;
				m[(px + 1)][(py)] = 2;
				mov = -2;
			}
		}
		if (py > 1 && mov == 0)
		{
			if (m[(px)][(py - 1)] == 1)
			{
				m[px][py] = -1;
				m[(px)][(py - 1)] = 2;
				mov = -1;
			}
		}
		if (mov == 0)
		{
			if (px > 0 && mov == 0)
			{
				if (m[(px - 1)][(py)] == 0)
				{
					m[px][py] = -2;
					m[(px - 1)][(py)] = 2;
					mov = 2;
				}
			}
			if (py < y && mov == 0)
			{
				if (m[(px)][(py + 1)] == 0)
				{
					m[px][py] = -2;
					m[(px)][(py + 1)] = 2;
					mov = 1;
				}
			}
			if (px < x && mov == 0)
			{
				if (m[(px + 1)][(py)] == 0)
				{
					m[px][py] = -2;
					m[(px + 1)][(py)] = 2;
					mov = -2;
				}
			}
			if (py > 1 && mov == 0)
			{
				if (m[(px)][(py - 1)] == 0)
				{
					m[px][py] = -2;
					m[(px)][(py - 1)] = 2;
					mov = -1;
				}
			}
		}
		system("PAUSE");
		system("cls");
		printf("%d° iteracao(de %d)\n", k, itr);
		exibe(m);
	}
	system("PAUSE");
	system("cls");
	exibe(m);
	system("PAUSE");
	return 0;
}
