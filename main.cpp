#include "stdafx.h"
#include <stdio.h>
#include <cstring>
#include <sstream>
#include <iostream>
#include <utility>

using namespace std;

bool read(double *array, unsigned int size)
{
	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);
	for (unsigned int i = 0; i < size; ++i)
	{
		if (!(stream >> array[i]))
		{
			cout << "An error has occured while reading input data." << endl;
			return false;
		}
	}
	return true;
}

void insertionSort(double *arr, int n)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		for (j = (i - 1); j >= 0; j--)
			if (arr[j + 1] < arr[j])
			{
				swap(arr[j], arr[j + 1]);
			}
	}
}

void printArray(double arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << ' ';
}

int main()
{
	unsigned int size;
	cin >> size;
	cin.get();
	double *arr = new double[size];
	if (read(arr, size))
	{
		insertionSort(arr, size);
		cout << "Sorted array: \n";
		printArray(arr, size);
	}

	cin.get();
	return 0;
}
