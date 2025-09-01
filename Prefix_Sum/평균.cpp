#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// <summary>
/// 구간 합 - 평균 구하기
/// </summary>

int main()
{
	int N = 0;
	cin >> N; // 과목의 개수

	int list[1000];

	for (int i = 0; i < N; i++)
	{
		cin >> list[i]; // 과목의 점수들 저장
	}

	long maxnum = 0;
	long sum = 0;

	for (int i = 0; i < N; i++)
	{
		sum += list[i];

		if (maxnum < list[i])
		{
			maxnum = list[i];
		}
	}

	// 소수점 출력
	double result = sum * 100.0 / maxnum / N;

	cout << result;
}