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
		1300번 배열에서 K번째 수 찾기 - 이진 탐색

		1. 중앙값을 사용하여 k번째보다 더 작은 값의 갯수를 탐색한다.
		2. 중앙값보다 작은 값의 갯수 >= K가 되었을때의 정답값을 중앙값으로 갱신한다.
	*/

	long N; // 배열의 크기
	long K; // 구하고자 하는 인덱스 숫자
	cin >> N >> K;

	long start = 1;
	long end = K;

	long result = 0;

	while (start <= end)
	{
		long middle = (start + end) / 2;

		int cnt = 0; // 중앙값보다 작은 수

		// 행을 순회하여 중앙값보다 작은 수 카운팅
		for (int i = 1; i <= N; i++)
		{
			cnt += min(middle / i, N);
		}
		if (cnt < K)
		{
			start = middle + 1;
		}
		else
		{
			end = middle - 1;
			result = middle;
		}
	}

	cout << result << '\n';
}
