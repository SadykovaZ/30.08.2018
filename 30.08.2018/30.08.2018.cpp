// 30.08.2018.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<iomanip>
using namespace std;

void add(int *&a, int &n, int value)
{
	int *p, *p1;
	int *tmp = new int[n + 1];

	for (p = a, p1 = tmp; p < a + n; p++, p1++)
	{
		*p1 = *p;
	}
	/*for (int i = 0; i < n; i++)
	{
		tmp[i] = a[i];
	}*/
	//tmp[n] = value;
	*p1 = value;
	if (n != 0) delete[]a;
	a = tmp;
	n++;
}

void erase(int *&a, int &n, int value)
{
	int k = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == value) k = i;
	}
	if (k < 0) return;
	int *tmp;
	int j = 0;
	tmp = new int[n - 1];
	for (int i = 0; i < n; i++)
	{
		if (a[i] != value)
			tmp[j++] = a[i];
	}
	delete[]a;
	a = tmp;
	n = j;

}
void search(int *a, int n, int v)
{
	int z = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == v)
		{
			z = 1;
		}

	}
	if (z == 1) cout << "true" << endl; else cout << "false" << endl;
}

bool asc(int a, int b)
{
	return (a > b);
}
bool desc(int a, int b)
{
	return (a < b);
}
void sort_array(int *a, int n, bool(*f)(int, int))
{
	for (int pass = 0; pass < n - 1; pass++)
	{

		for (int i = 0; i < n-1; i++)
		{
			if (f(a[i], a[i + 1]))
				swap(a[i], a[i + 1]);
		}
	}
}
int main()
{
	srand(time(NULL));
	int n = 0;
	cin >> n;
	if (n == 1)
	{
		int n, m;
		int **a;
		cin >> n >> m;
		a = new int*[n];

		for (int i = 0; i < n; i++)
		{
			a[i] = new int[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				a[i][j] = rand() % 26;
				cout << setw(5) << a[i][j];
			}
			cout << endl;
		}
		for (int i = 0; i < n; i++)
		{
			delete[] a[i];
		}
		delete[] a;
	}
	else if (n == 2)
	{
		//Напишите программу, которая создает массив указателей. Каждый из которых ссылается на динамический массив из 10 элементов. Каждый из этих массивов заполняется случайным образом в диапазоне от 1 до 12. Каждое число – это оценка по 12 системе. Необходимо посчитать для каждой строки массива указателей количество пятерок. Пятерка от 10 до 12 включительно.
		int **a;
		int n, m;
		int c = 0;
		cin >> n >> m;
		a = new int*[n];
		for (int i = 0; i < n; i++)
		{
			a[i] = new int[m];
		}
		for (int i = 0; i < n; i++)
		{
			c = 0;
			for (int j = 0; j < m; j++)
			{
				a[i][j] = 1 + rand() % 12;
				if (a[i][j] >= 10)c++;
				cout << setw(5) << a[i][j];
			}
			cout << " " << "Count five = " << c << endl;
			//cout << endl;
		}
	}
	else if (n == 3)
	{
		//Написать программу «телефонный справочник». Создайте массив целых чисел, каждое число – это номер телефона. Напишите функции для добавления нового телефона в массив, для удаления указанного телефона из справочника, поиск телефона по номеру. Создайте меню для пользователя. 
		int *a;
		int n = 0;
		add(a, n, 5);
		add(a, n, 5);
		add(a, n, 6);
		add(a, n, 12);
		search(a, n, 6);
		erase(a, n, 5);

		for (int i = 0; i < n; i++)
		{
			cout << a[i] << endl;
		}


	}

	else if (n == 4)
	{
		int *a;
		int n = 12;
		a = new int[n];
		bool(*fs[2])(int, int) = { asc,desc };

		for (int i = 0; i < n; i++)
		{
			a[i] = rand() % 12;
			cout << a[i] << " ";
		}
		sort_array(a, n, desc);
		cout << endl;

		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}


	return 0;
}

