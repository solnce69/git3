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