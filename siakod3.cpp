#include "pch.h"
#include <iostream>
#include "math.h"

using namespace std;
int Count, key, maxL = 0, maxBL = 0, maxBIN = 0, maxBLOCK = 0, crL = 0, crBL = 0, crBIN = 0, crBLOCK = 0;

const int n = 450;
int A[n];

void start1() {
	int j;
	for (j = 0; j < n; j++) {
		A[j] = j;
	}
}
void start2() {
	int j;
	for (j = 0; j < n; j++) {
		A[j] = n - j;
	}
}

//Линейный поиск
int LineSearch()
{
	Count = 1;
	int i = 0;
	for (i = 0;  i < n && ++Count; i++) {
		if (++Count && A[i] == key) {
			Count--;
			return i;
		}
	}
	Count--;
	return -1;
}

//Линейный поиск с барьером
int LinearSearchWithBarrier() {
	Count = 1;
	int i;
	int *B = new int[n + 1];
	for (i = 0; i < n + 1; i++) {
		B[i] = A[i];
	}
	B[n] = key;
	i = 0;
	while (++Count && B[i] != key)
		i++;
	delete B;
	if (++Count && i < n) {
		Count--;
		return i;
	}
	else {
		Count--;
		return -1;
	}
}

//Двоичный поиск
int BinarySearch()
{
	Count = 1;
	int left = 0, right = n, mid;
	while (++Count && left <= right)
	{
		mid = left + (right - left) / 2;
		if (++Count && key < A[mid]) right = mid - 1;
		else if (++Count && key > A[mid]) left = mid + 1;
		else {
			Count--;
			return mid;
		}
	}
	Count--;
	return -1;
}



//Блочный поиск
int Search(int a, int b)
{
	int i;
	for (i = a; i <= b && ++Count; i++) {
		if (++Count && A[i] == key) {
			Count--;
			return i;
		}
	}
	Count--;
	return -1;
}

int blockSearch() {
	Count = 1;
	int h = abs(pow(n, 0.5));
	int i = h;
	int p;
	bool flag = true;
	while (Count++ && flag && i < n) {
		if (Count++ &&  key <= A[i-1]) {
			flag = false;
			
			p = Search(i - h, i - 1);
		}
		i += h;
	}
	if (Count++ &&  flag) {
		if (Count++ &&  key <= A[n - 1]) {
			
			p = Search(i - h - 1, n - 1);
		}
		else {
			
			p = -1;
		}
	}
	Count--;
	return p;
}

int main()
{
	setlocale(0, "");
	int m, num;
	start2();
	cout << "ДЛЯ НЕУПОРЯДОЧЕННОГО МАССИВА" << endl;
	cout << endl << "Массив размером в " << n << " элементов: ";
	for (num = 0; num < n; num++) {
		cout << A[num] << " ";
	}
	for (m = 0; m < n; m++) {
		key = m;
		cout << endl << endl << "Элемент " << key;
		cout << endl << endl << "Линейный поиск: " << endl << "индекс элемента: " << LineSearch() << endl << "количество сравнений: " ;
		cout << Count;
		if (maxL < Count) maxL = Count;
		crL += Count;
		cout << endl << endl << "Быстрый линейный поиск: " << endl << "индекс элемента: " << LinearSearchWithBarrier() << endl << "количество сравнений: ";
		cout << Count;
		if (maxBL < Count) maxBL = Count;
		crBL += Count;
		
	}
	key = n;
	cout << endl << endl << "Элемент " << key;
	cout << endl << "Линейный поиск: " << endl << "индекс элемента: " << LineSearch() << endl << "количество сравнений: ";
	cout << Count;
	if (maxL < Count) maxL = Count;
	crL += Count;
	cout << endl << endl << "Быстрый линейный поиск: " << endl << "индекс элемента: " << LinearSearchWithBarrier() << endl << "количество сравнений: ";
	cout << Count;
	if (maxBL < Count) maxBL = Count;
	crBL += Count;

	start1();
	cout << endl << endl << "ДЛЯ УПОРЯДОЧЕННОГО МАССИВА" << endl;
	cout << endl << "Массив размером в " << n << " элементов: ";
	for (num = 0; num < n; num++) {
		cout << A[num] << " ";
	}
	for (m = 0; m < n; m++) {
		key = m;
		cout << endl << endl << "Элемент " << key;
		cout << endl << "Быстрый линейный поиск: " << endl << "индекс элемента: " << LinearSearchWithBarrier() << endl << "количество сравнений: ";
		cout << Count;
	
		cout << endl << "Бинарный поиск: " << endl << "индекс элемента: " << BinarySearch() << endl << "количество сравнений: ";
		cout << Count;
		if (maxBIN < Count) maxBIN = Count;
		crBIN += Count;
		cout << endl << "Блочный поиск: " << endl << "индекс элемента: " << blockSearch() << endl << "количество сравнений: ";
		cout << Count;
		if (maxBLOCK < Count) maxBLOCK = Count;
		crBLOCK += Count;
	}
	key = n;
	cout << endl << endl << "Элемент " << key;
	cout << endl << "Быстрый линейный поиск: " << endl << "индекс элемента: " << LinearSearchWithBarrier() << endl << "количество сравнений: ";
	cout << Count;
	
	cout << endl << "Бинарный поиск: " << endl << "индекс элемента: " << BinarySearch() << endl << "количество сравнений: ";
	cout << Count;
	if (maxBIN < Count) maxBIN = Count;
	crBIN += Count;
	cout << endl << "Блочный поиск: " << endl << "индекс элемента: " << blockSearch() << endl << "количество сравнений: ";
	cout << Count;
	if (maxBLOCK < Count) maxBLOCK = Count;
	crBLOCK += Count;
	cout << endl << endl << "Максимальное количество операций сравнения";
	cout << endl << "Линейный поиск: " << maxL;
	cout << endl << "Быстрый линейный поиск: " << maxBL;
	cout << endl << "Бинарный поиск: " << maxBIN;
	cout << endl << "Блочный поиск: " << maxBLOCK;
	cout << endl << endl << "Среднее количество операций сравнения";
	cout << endl << "Линейный поиск: " << crL / (n + 1);
	cout << endl << "Быстрый линейный поиск: " << crBL / (n + 1);
	cout << endl << "Бинарный поиск: " << crBIN / (n + 1);
	cout << endl << "Блочный поиск: " << crBLOCK / (n + 1);
	return 0;
}