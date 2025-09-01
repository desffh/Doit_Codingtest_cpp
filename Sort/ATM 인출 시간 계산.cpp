#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 11399번 문제 ATM인출 시간 계산하기

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 각 사람이 돈을 인출하는 데 필요한 시간의 합의 최솟값은 시간이 오름차순 정렬일때다.
	// 1. 오름차순 정렬
	// 2. 합배열 만들기
	// 3. 합 출력


	int sum = 0;
	int N = 0;

	cin >> N;

	vector<int>A(N, 0); // ATM 시간 배열

	vector<int>S(N, 0); // 합 배열

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	// [삽입 정렬]
	for (int i = 1; i < N; i++)
	{
		int insert_pos = i;      // 삽입 위치
		int insert_value = A[i]; // 삽입 값


		// 오름차순 정렬이기 때문에 현재 삽입값이 정렬된 범위의 값보다 크다면 
		// 삽입 위치를 [j + 1]로 갱신

		for (int j = i - 1; j >= 0; j--)
		{
			if (A[j] < A[i])
			{
				insert_pos = j + 1;
				break;
			}
			if (j == 0) // 현재 삽입값이 작아서 j == 0까지 도달했다면 삽입 위치는 [0]
			{
				insert_pos = 0;
			}
		}

		// 삽입 위치의 앞부분 값들을 갱신한다.

		for (int j = i; j > insert_pos; j--)
		{
			A[j] = A[j - 1];
		}
		A[insert_pos] = insert_value;
	}

	S[0] = A[0];

	// 합 배열 생성
	for (int i = 1; i < N; i++)
	{
		S[i] = S[i - 1] + A[i];
	}

	for (int s : S)
	{
		sum += s;
	}

	cout << sum;
}