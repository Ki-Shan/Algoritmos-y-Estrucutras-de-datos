#pragma once

#include <iostream>


int max(int a, int b) {
	if (a <= b)
		return b;
	else
		return a;
}

int MaxTeilsum4(int a[], int f, int l) {
	int n = l - f + 1;
	if (n == 1) 
		return a[f];
	else {
		int newn = (n % 2 == 0 ? n / 2 : n / 2 + 1);
		int MaxBorderSum1 = a[f + newn - 1], i = f + newn - 2, currVal = MaxBorderSum1;
		while (i >= f) {
			currVal += a[i];
			if (currVal>MaxBorderSum1)
				MaxBorderSum1 = currVal;
			i--;
		}
		int MaxBorderSum2 = a[f + newn], i = f + newn + 1, currVal = MaxBorderSum2;
		while (i <= l) {
			currVal += a[i];
			if (currVal>MaxBorderSum2)
				MaxBorderSum2 = currVal;
			i++;
		}
		return max(MaxTeilsum4(a, f, f + newn - 1),
			max(MaxTeilsum4(a, f + newn, l), MaxBorderSum1 + MaxBorderSum2));
	}
}