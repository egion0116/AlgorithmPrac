#pragma once

void Swap(int* Left, int* Right);

// 버블소트 알고리즘 정의

void BubbleSort_Asc(int Arr[], int Arr_Size);

// 삽입정렬 알고리즘 정의

void Insertion_Sort_Asc(int* Arr, int Arr_Size);

// 퀵소트 알고리즘 정의

int Partition(int Arr[], int Left, int Right);
void QuickSort(int Arr[], int Left, int Right);