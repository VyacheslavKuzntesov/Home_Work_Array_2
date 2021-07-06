#include<iostream>
#include<conio.h>

using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
#define Escape 27

void main()
{
	setlocale(LC_ALL, "Rus");
	const int n = 10;
	const int m = 3;
	int arr[m][n];
	int table;
	int minRand, maxRand;
	int stepl;
	int povtorpred = 0;
	int povtoreniya = 1;
	char nomer_programmu;
	do
	{
		cout << "Введите номер программы" << endl << "1 - Массив из 30 элементов заполнить УНИКАЛЬНЫМИ случайными числами (Диапозон в 30 чисел не меньше)" << endl << "2 - Сортировка массива" << endl << "3 - Нахождение повторяющихся значений в массиве" << endl << "Escape - для выхода" << endl << "Введите номер программы : "; nomer_programmu = _getch();
		if (nomer_programmu != 27)
		{
			cout << nomer_programmu << endl << endl;
		}
		else
		{
			cout << "Escape" << endl;
		}
		switch (nomer_programmu)
		{
		case '1':	
			cout << "Введите минимальное случайное число: "; cin >> minRand;
			cout << "Введите максимальное случайное число: "; cin >> maxRand;

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					arr[i][j] = rand() % (maxRand - minRand) + minRand;

					for (int k = 0; k <= i; k++)
					{
						if (k == i)
						{
							for (int l = 0; l < j; l++)
							{
								if (arr[i][j] == arr[k][l])
								{
									j--;
									break;
								}
							}
						}
						else
						{
							for (int l = 0; l < n; l++)
							{
								if (arr[i][j] == arr[k][l] && j == 0)
								{
									i--;
									j = n-1;
									break;
								}
								else if (arr[i][j] == arr[k][l])
								{
									j--;
									break;
								}
							}

						}
					}
				}
			}

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cout << arr[i][j] << tab;
				}
				cout << endl;
			}
			cout << endl;
			break;
		case '2':
			cout << "Введите минимальное случайное число: "; cin >> minRand;
			cout << "Введите максимальное случайное число: "; cin >> maxRand;

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					arr[i][j] = rand() % (maxRand - minRand) + minRand;
				}
			}

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					stepl = j;
					for (int k = 0 + i; k < m; k++)
					{
						for (int l = stepl; l < n; l++)
						{
							if (arr[i][j] > arr[k][l])
							{
								table = arr[i][j];
								arr[i][j] = arr[k][l];
								arr[k][l] = table;
							}
						}
						stepl = 0;
					}
				}
			}

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cout << arr[i][j] << tab;
				}
				cout << endl;
			}
			break;
		case '3':
			cout << "Введите минимальное случайное число: "; cin >> minRand;
			cout << "Введите максимальное случайное число: "; cin >> maxRand;

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					arr[i][j] = rand() % (maxRand - minRand) + minRand;
				}
			}

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cout << arr[i][j] << tab;
				}
				cout << endl;
			}
			cout << endl;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					stepl = j + 1;
					if (i == 0 && j == 0)
					{
						for (int k = i; k < m; k++)
						{
							for (int l = stepl; l < n; l++)
							{
								if (arr[i][j] == arr[k][l])
								{
									povtoreniya++;
								}
							}
							stepl = 0;
						}
					}
					else
					{
						for (int o = 0; o < i; o++)
						{
							for (int p = 0; p < j; p++)
							{
								if (arr[i][j] == arr[o][p])
								{
									break;
								}
							}
						}
						if (povtorpred == 0)
						{
							for (int k = i; k < m; k++)
							{
								for (int l = stepl; l < n; l++)
								{
									if (arr[i][j] == arr[k][l])
									{
										povtoreniya++;
									}
								}
								stepl = 0;
							}
						}
					}

					if (povtoreniya > 1)
					{
						cout << arr[i][j] << " повторяется " << povtoreniya << endl << endl;
						povtoreniya = 1;
					}
					povtoreniya = 0;
					povtorpred = 0;
				}
			}
			break;
		default:
			if (nomer_programmu != '1' && nomer_programmu != '2' && nomer_programmu != '3' && nomer_programmu != Escape)
			{
				cout << "Нет такой программы" << endl << endl;
			}
			break;
		}
	} while (nomer_programmu != Escape);
}