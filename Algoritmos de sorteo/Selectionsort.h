//============================================================================
// Name        : Selectionsort.h
// Author      : Cristian Sanchez
// Version     : 1.0
// Copyright   : Cristian Sanchez copyright 2018
//============================================================================

#pragma once

void Selectionsort(int a[], int n) {
	int i, j, min;
	for (i = 0; i < n; i++) {
		min = i;
		// search the minimum
		for (j = i; j < n; j++) {
			if (a[j] < a[min])
				min = j;
		}
		// swap with the first element 
		int h = a[i];
		a[i] = a[min];
		a[min] = h;
	}
}