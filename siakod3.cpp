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
