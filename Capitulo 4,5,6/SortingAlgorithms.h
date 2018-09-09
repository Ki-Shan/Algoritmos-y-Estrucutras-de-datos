#pragma once
#include <iostream>

namespace Basics {
	void Insertionsort(int a[], int n) {
		int i, j, key;
		for (j = 1; j < n; j++) {
			key = a[j]; // Element to insert in a already sort. list
			i = j - 1; // Index of the last already sorted value
			while (i >= 0 && a[i] > key) { // Element move
				a[i + 1] = a[i];
				i = i - 1;
			}
			a[i + 1] = key; // Element to insert on the correct place
		}
	}

	void Bubblesort(int a[], int n) {
		for (int i = 0; i < n; i++) {
			for (int j = n - 2; j >= i; j--) {
				if (a[j] > a[j + 1]) {
					int h = a[j];
					a[j] = a[j + 1];
					a[j + 1] = h;
				}
			}
		}
	}

	void Selectionsort(int a[], int n) {
		int i, j, min;
		for (i = 0; i < n; i++) {
			min = i;
			// search current min value
			for (j = i; j < n; j++) {
				if (a[j] < a[min])
					min = j;
			}
			// swap with first element of the unsorted list
			int h = a[i];
			a[i] = a[min];
			a[min] = h;
		}
	}
}

namespace Advanced {
	namespace QuickSort {
		void swap(int& a, int& b) {
			int h = b;
			b = a;
			a = h;
		}

		void preparePartition(int a[], int f, int l, int& p) {
			// Pivot-Element
			int pivot = a[f]; p = f - 1;
			for (int i = f; i <= l; i++) {
				if (a[i] <= pivot) {
					p++;
					swap(a[i], a[p]);
				}
			}
			// Pivot on the rigth Pos.
			swap(a[f], a[p]);
		}

		void quicksort(int a[], int f, int l) {
			int part;
			if (f < l) {
				preparePartition(a, f, l, part);
				quicksort(a, f, part - 1);
				quicksort(a, part + 1, l);
			}
		}
	}

	namespace MergeSort {
		void merge(int a[], int f, int l, int m) {
			int i, n = l - f + 1;
			int a1f = f, a1l = m - 1;
			int a2f = m, a2l = l;
			int*anew = new int[n];
			for (i = 0; i < n; i++) {
				if (a1f <= a1l) {
					if (a2f <= a2l) {
						if (a[a1f] <= a[a2f])
							anew[i] = a[a1f++];
						else anew[i] = a[a2f++];
					}else anew[i] = a[a1f++];
				}else anew[i] = a[a2f++];
			}
			for (i = 0; i<n; i++)
				a[f + i] = anew[i];
			delete[] anew;
		}

		void mergesort(int a[], int f, int l) {
			if (f < l) {
				int m = (f + l + 1) / 2;
				mergesort(a, f, m - 1);
				mergesort(a, m, l);
				merge(a, f, l, m);
			}
		}
	}

	namespace HeapSort {

		void swap(int& a, int& b) {
			int h = b;
			b = a;
			a = h;
		}

		void Heapify(int a[], int l, int root) {
			int largest, left = (root) * 2 + 1, right = (root) * 2 + 2;
			if (left <= l && a[left]>a[root])
				largest = left;
			else largest = root;
			if (right <= l && a[right]>a[largest])
				largest = right;
			if (largest != root) {
				swap(a[root], a[largest]);
				Heapify(a, l, largest);
			}
		}

		void BuildMaxHeap(int a[], int l) {
			for (int i = (l - 1) / 2; i >= 0; i--)
				Heapify(a, l, i);
		}

		void Heapsort(int a[], int f, int l) {
			BuildMaxHeap(a, l);
			for (int i = l; i>0; i--) {
				swap(a[0], a[i]);
				Heapify(a, i - 1, 0);
			}
		}
	}
}

namespace Specials {

	namespace CountSort {
		void Countsort(int a[], int n, int k) {
			int i, j = 0, *bin = new int[k + 1];
			for (i = 0; i <= k; i++) bin[i] = 0;
			for (i = 0; i<n; i++) bin[a[i]]++;
			for (i = 0; i<n; i++) {
				while (bin[j] == 0)
					j++;
				a[i] = j;
				bin[j]--;
			}
			delete[] bin;
		}
	}

	namespace MapSort {
		void swap(int& a, int& b) {
			int h = b;
			b = a;
			a = h;
		}

		void Mapsort(int a[], int n, double c) {
			int newn = (int)((double)n*c), i, j = 0;
			int*bin = new int[newn], max = INT_MIN, min = INT_MAX;// create array bin : size newn
			for (i = 0; i < newn; i++) 
				bin[i] = -1;	// initialize array bin 
			for (i = 0; i < n; i++)// calcule min, max 
				if (a[i]<min) min = a[i];
			else 
				if(a[i]>max) max = a[i];
			double dist = (double)(max - min) / (double)(newn - 1);// calcule distance 
			for (i = 0; i < n; i++) {// load element from a in bin .
				int t = (int)((double)(a[i] - min) / dist), insert = a[i], left = 0;
				if (bin[t] != -1 && insert <= bin[t]) 
					left = 1;
				while (bin[t] != -1) {
					if (left == 1) {
						if (insert>bin[t]) swap(bin[t], insert);
						if (t>0) t--; else left = 0;
					}
					else {
						if (insert <= bin[t]) swap(bin[t], insert);
						if (t<newn - 1) t++; else left = 1;
					}
				}
				bin[t] = insert;
			}
			for (i = 0; i<newn; i++) 
				if (bin[i] != -1) 
					a[j++] = bin[i];// insert it again in a 
			delete[] bin;// clean
		}
	}
}