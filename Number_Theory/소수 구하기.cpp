#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath> // sqrt() 사용하기 위해 선언 필수

using namespace std;

int main()

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1929번 소수 구하기 - 시간제한 2초기 때문에 O(N²)로 풀 수 없다.
						 - Nlog(logN)으로 풀어야 한다.(에라토스테네스의 체)
	*/

	int M; // 시작 수
	int N; // 종료 수

	cin >> M >> N;

	vector<int> A(N + 1, 0); // 소수 판별 배열 

	for (int i = 2; i <= N; i++)
	{
		A[i] = i;
	}

	// 2 ~ 제곱근N까지 반복
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (A[i] == 0)
		{
			continue;
		}

		// 배수 삭제
		for (int j = i + i; j <= N; j += i)
		{
			A[j] = 0;
		}
	}

	for (int i = M; i <= N; i++)
	{
		if (A[i] != 0)
		{
			cout << A[i] << endl;
		}
	}
}
