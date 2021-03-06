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

void func1(int *a, int n)
{
	int *p = a;
	
	for (p = a; p < a+n; p++)
	{
		if (*p < 0) *p = 0;
		cout << *p << " ";
	}
	cout << endl;
}

void func2(int *a, int n)
{
	int *p = a;
	for (p = a; p < a + n; p++)
	{
		if (*p % 2 == 0)*p = -1;
		cout << *p << " ";
	}
	cout << endl;
}

void func3(int *a, int n)
{
	int *p = a;
	for (p = a; p < a + n; p++)
	{
		if (*p % 4 == 0) *p = 999;
		cout << *p << " ";
	}
	cout << endl;
}

bool prime(int n)
{
	bool result(true);

	if ((n == 2) || (n == 3))
		result = true;
	else 
	{
		for (int i = 2; i <= (sqrt(n)); ++i)
			if (n % i == 0)
			{
				result = false;
				break;
			}
	}
	return (result && (n != 1));
}

int* proverca(int* A, int size) {

	int count = 0;
	for (int i = 0; i < size; ++i) {
		if (!prime(A[i]))
			++count;
	}

	int* B = new int[count];

	int j = 0;
	for (int i = 0; i < size; ++i)
		if (!prime(A[i]))
			B[j++] = A[i];

	for (int j = 0; j < count; j++)
		cout << B[j] << " ";
	return B;
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

	else if (n==5)
	{
		//Написать программу, которая содержит функцию, принимающую в качестве аргумента, указатель на массив и размер массива, и заменяет все отрицательные элементы на 0.
		int a[5] = { -1,2,-3,4,-5 };

		func1(a, 5);
	}

	else if (n==6)
	{
		//Написать программу, которая содержит функцию, принимающую в качестве аргумента, указатель на массив и размер массива, и заменяет все четные элементы на -1

		int a[5] = { 1,2,4,5,9 };
		func2(a, 5);
	}

	else if (n==7)
	{
		//Написать программу, которая содержит функцию, принимающую в качестве аргумента, указатель на массив и размер массива, и заменяет все кратные 4 элементы на 999.
		int a[6] = { 4,8,1,1,2,3 };
		func3(a, 6);
	}

	else if (n==8)
	{
		//Написать функцию, которая получает указатель на динамический массив и его размер. Функция должна удалить из массива все простые числа и вернуть указатель на новый динамический массив.
		int size;
		cout << "Size: ";
		cin >> size;
		int* A = new int[size];
		
		for (int i = 0; i < size; i++)
		{
			A[i] = 1 + rand()%10;
			cout << A[i] << " ";
		}
		cout << endl;
		int* res = proverca(A, size);

		delete[]A;
		delete[]res;
		
	}

	return 0;
}

