#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1456번 거의 소수 구하기

		1. 주어진 범위까지에 존재하는 모든 소수 구하기.

		2. 소수의 N 제곱값이 범위에 존재하면 카운팅 (N >= 2)

		3. 문제에 주어진 범위를 생각하여 자료형을 지정한다.

		4. 제곱 소수 판별 시 변수 표현 범위를 넘어갈 수 있기에 이항정리로 표현
	*/

	long Min;
	long Max;
	int A[10000001]; // 소수 배열

	int count = 0; // 정답 갯수

	cin >> Min >> Max;

	for (int i = 2; i < 10000001; i++)
	{
		A[i] = i;
	}

	// 최대범위 제곱근 10^7 까지 반복 
	for (int i = 2; i <= sqrt(10000001); i++)
	{
		// 소수라면 건너뛰기
		if (A[i] == 0)
		{
			continue;
		}

		// 소수의 배수들 모두 삭제
		for (int j = i + i; j < 10000001; j += i)
		{
			A[j] = 0;
		}
	}

	for (int i = 2; i < 10000001; i++)
	{
		// 배열 내 원소가 소수인 경우
		if (A[i] != 0)
		{
			long temp = A[i];

			// 제곱 소수가 Max범위보다 커지면 종료
			while ((double)A[i] <= (double)Max / (double)temp)
			{
				// 현재 소수가 Min 범위보다 크다면 카운팅
				if ((double)A[i] >= (double)Min / (double)temp)
				{
					count++;
				}

				temp *= A[i];
			}
		}
	}

	cout << count << '\n';
}
