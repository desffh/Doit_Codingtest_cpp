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
		1920번 수 찾기 - 이진 탐색
	*/

	int N; // 정수 갯수
	int M; // 찾고자 하는 정수 갯수

	cin >> N;

	vector<int> A(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	// 이진 탐색은 정렬 필수
	sort(A.begin(), A.end());

	cin >> M;

	// stl을 사용한 방법
	/*
		for (int i = 0; i < M; i++)
	{
		int target;
		cin >> target;

		bool result = binary_search(A.begin(), A.end(), target);

		cout << result << '\n';
	}

	*/



	for (int i = 0; i < M; i++)
	{
		int target;
		cin >> target;

		// 시작, 끝 인덱스
		int start = 0;
		int end = N - 1;

		bool isFind = false;

		while (start <= end)
		{
			int middle = (start + end) / 2;
			int mididx = A[middle];

			if (mididx > target)
			{
				end = middle - 1;
			}
			else if (mididx < target)
			{
				start = middle + 1;
			}
			else
			{
				isFind = true;
				break;
			}
		}

		if (isFind == true)
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}
}

