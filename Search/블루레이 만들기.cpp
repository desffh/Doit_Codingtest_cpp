#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		2606번 블루레이 만들기 - 이진 탐색
	*/

	int N; // 레슨 중 최대값
	int M; // 레슨 총 합

	int start = 0;
	int end = 0;

	cin >> N >> M;

	vector<int>A(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];

		if (start < A[i])
		{
			start = A[i];
		}
		end += A[i];
	}

	while (start <= end)
	{
		int middle = (start + end) / 2;
		int sum = 0; // 현재 레슨합
		int count = 0; // 사용한 블루레이 개수

		for (int i = 0; i < N; i++)
		{
			// 블루레이 꽉 찼다는 의미
			if (sum + A[i] > middle)
			{
				count++;
				sum = 0;
			}

			sum += A[i];
		}

		// sum이 0이 아닌채로 끝났다는 건 마지막 블루레이를 의미
		if (sum != 0) count++;

		if (count > M)
		{
			start = middle + 1;
		}
		else
		{
			end = middle - 1;
		}
	}

	cout << start << '\n';
}
