#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
int checkNumber(int temp, int* p, int n);
int main()
{
	char ch=' ';
	int n;
	int round =0;
	printf("Random number from 1 to .... ");
	scanf("%d",&n);
	printf("Press N to continue\nPress X to exit");
	if (n < 1)
	{
		printf("Error");
		return 0;
	}
	printf("\n");
	int* p = (int*)calloc(n, sizeof(int));
	do
	{
		if (_kbhit())
		{
			ch = _getch();
			time_t t;
			srand((unsigned)time(&t));
			int temp;
			if (ch == 'n')
			{
			repeat :
				temp = rand() % (n+1);
				if (checkNumber(temp,p,n)==1)
				{
					goto repeat;
				}
				printf("%d\n", temp);
				round++;
				*(p + (round-1)) = temp;
			}
			else if (ch == 'x')
			{
				break;
			}
			fflush(stdin);
		}
		Sleep(100);
	} while (round<n);
	printf("\n----------BINGO!!!----------\n");
	return 0;
}
int checkNumber(int temp, int* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (temp == *(p + i) || temp == 0)
		{
			return 1;
		}
	}
	return 0;
}