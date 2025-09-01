#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// 버블 정렬을 사용한 방식

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	vector<int>A(N, 0); // 크기 N, 모두 0으로 초기화

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - 1 - i; j++)
		{
			// 앞의 원소가 더 크다면 
			if (A[j] > A[j + 1])
			{
				swap(A[j], A[j + 1]);
			}
		}
	}

	for (int element : A)
	{
		cout << element << '\n';
	}
}


