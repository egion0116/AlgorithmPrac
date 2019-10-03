#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// 시험본 과목의 개수 N
	int N = 0;
	scanf("%d", &N);

	// 현재 성적
	unsigned int* Current_Scores = (unsigned int*)malloc(sizeof(unsigned int) * N);
	for (int i = 0; i < N; i++)
	{
		scanf("%u", &Current_Scores[i]);
	}

	/*
		주어진 알고리즘

		1. 자기 점수중에 최댓값 고르기
		2. 점수 / M * 100
	*/
	// 최댓값 구하기
	unsigned int Max = Current_Scores[0];
	for (int i = 1; i < N; i++)
		Max = Max < Current_Scores[i] ? Current_Scores[i] : Max;

	// 바뀐 점수들의 배열
	double* Changed_Scores = (double*)malloc(sizeof(double) * N);
	for (int i = 0; i < N; i++)
		Changed_Scores[i] = (double)Current_Scores[i] / (double)Max * 100.0;

	// 바뀐 점수들의 평균 구하기
	double NewSum = 0;
	double NewMean = 0.0;
	for (int i = 0; i < N; i++)
		NewSum += Changed_Scores[i];

	NewMean = NewSum / (double)N;

	// 평균 소수점 둘째 자리까지 출력
	printf("%.3lf\n", NewMean);

	return 0;
}