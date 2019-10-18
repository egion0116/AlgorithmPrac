#pragma once

void Swap(int* Left, int* Right);
int Another_Partition(int Arr[], int Left, int Right);
int Partition(int Arr[], int Left, int Right);
void QuickSort(int Arr[], int Left, int Right, int(*partition)(int*, int, int));
void QuickSort_Optimized(int Arr[], int Left, int Right, int(*partition)(int*, int, int));

int Comparison(const void* _elem1, const void* _elem2);