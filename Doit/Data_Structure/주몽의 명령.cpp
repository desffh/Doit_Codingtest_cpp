#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// <summary>
/// 투 포인터 - 주몽의 멍령
/// </summary>

int main()
{
	int N; // 재료의 개수
	int M; // 갑옷이 완성되는 번호의 합
	cin >> N >> M;

	vector <int> A(N, 0); // 재료들을 담을 배열 (크기 N, 0으로 모두 초기화)
	int count = 0;


	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	sort(A.begin(), A.end()); // 오름차순 정렬

	int start_index = 0;
	int end_index = N - 1;

	while (start_index <= end_index)
	{
		// 만약 2개의 재료 == 고유 번호
		if (A[start_index] + A[end_index] == M)
		{
			count++;
			start_index++;
			end_index--;
		}
		// 고유 번호가 더 크다면 -> 작은 번호 이동
		else if (A[start_index] + A[end_index] < M)
		{
			start_index++;
		}
		// 고유 번호가 더 작다면 -> 큰 번호 이동
		else
		{
			end_index--;
		}
	}

	cout << count << endl;
}