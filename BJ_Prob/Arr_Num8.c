#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // 케이스의 개수
    int N = 0;
    scanf("%d", &N);

    // 케이스별 학생 수
    int* Student_Num = (int*)calloc(N, sizeof(int));
    // 케이스별 평균 이상자 비율
    double* Over_Mean_Rate = (double*)calloc(N, sizeof(double));

    for (int i = 0; i < N; i++)
    {
        // 케이스별 학생 수 입력
        scanf("%d", &Student_Num[i]);

        // 학생 수에 따른 점수 배열
        int* Scores = (int*)calloc(Student_Num[i], sizeof(int));
        int Sum = 0;    // 점수의 합계
        double Mean = 0.0; // 점수의 평균
        for (int j = 0; j < Student_Num[i]; j++)
        {
            // 점수 입력
            scanf("%d", &Scores[j]);

            // 합계 계산
            Sum += Scores[j];
        }
        // 평균 계산
        Mean = (double)Sum / (double)Student_Num[i];

        int Over_Mean_Count = 0;
        // 점수를 순회하며 평균보다 높은 점수 검사
        for (int j = 0; j < Student_Num[i]; j++)
            if (Mean < (double)Scores[j])
                Over_Mean_Count++;
        
        // 평균을 넘은 학생의 비율
        Over_Mean_Rate[i] = (double)Over_Mean_Count / (double)Student_Num[i] * 100;

        // 메모리 해제
        free (Scores);
    }

    for(int i = 0; i < N; i++)
        printf("%.3lf%\n", Over_Mean_Rate[i]);

    return 0;
}