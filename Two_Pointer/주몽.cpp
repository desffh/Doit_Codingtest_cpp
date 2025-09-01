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

	while (start_index < end_index)
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



// 2번째 풀이 (push_back() & start < end 일때 반복

int main2()
{
	// 0. 두 수의 합을 이용해서 구하기 때문에 양 사이드 부터 출발
	// 1. start는 처음 인덱스, end는 마지막 인덱스
	// 2. 입력받은 숫자를 정렬 -> 시간복잡도 상 NlogN까지 사용가능
	// 3. 투 포인터 진행

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int M = 0; // 얻고자 하는 값 M

	cin >> N >> M;

	int count = 0;
	vector<int>result;


	int start = 0;
	int end = N - 1;

	for (int i = 0; i < N; i++)
	{
		int temp;

		cin >> temp;

		result.push_back(temp);
	}

	sort(result.begin(), result.end());

	while (start < end)
	{
		if (result[start] + result[end] == M)
		{
			count++;
			start++;
			end--;
		}
		else if (result[start] + result[end] < M)
		{
			start++;
		}
		else
		{
			end--;
		}
	}
	cout << count << '\n';
}