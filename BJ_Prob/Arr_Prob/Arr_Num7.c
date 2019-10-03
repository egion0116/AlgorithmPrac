#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// 테스트 개수
	int N = 0;
	scanf("%d", &N);

	// 정답지
	char Answer[80] = { 0 };
	// 점수 결과
	int* Score = (int*)calloc(N, sizeof(int));      // 주의하라... 초기화를 안할시 동작을 보장 할 수 없다.. 따라서 calloc권장

	// 한 줄씩 읽어낸다.
	for (int i = 0; i < N; i++)
	{
		scanf("%s", Answer);
		/*
			주어진 알고리즘

			1. 한줄씩 널문자가 나올때 까지 읽는다.
			2. 가중치 계수를 1부터 시작하여 연속 정답이면 가중시킨다.
			 -> 다음이 O가 아니면 1로 초기화 한다.
			3. 가중치를 계속하여 더한다.
		*/
    
	    int Weigh = 1;      // 가중치
		for (int j = 0; Answer[j] != '\0'; j++)
		{
			// 가중치 덧셈
			if (Answer[j] == 'O')
			{
				Score[i] += Weigh;
				if (Answer[j + 1] == 'O') // 그 다음값이 O이면 가중치 증가
					Weigh++;
			}
			else
				// X이면 아무것도 안하고 가중치 초기화
				Weigh = 1;
		}
	}

    for (int i = 0; i < N; i++)
	    printf("%d\n", Score[i]);

	return 0;
}