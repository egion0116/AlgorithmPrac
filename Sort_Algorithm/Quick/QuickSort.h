#pragma once

void Swap(int* Left, int* Right);
int Another_Partition(int Arr[], int Left, int Right);
int Partition(int Arr[], int Left, int Right);
void QuickSort(int Arr[], int Left, int Right, int(*partition)(int*, int, int));

void RandomSet(int Arr[], int Length);
void Print(int Arr[], int Length);