#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// <summary>
/// 구간 합 - 나머지 합 구하기
/// </summary>

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N = 0; // 수열의 개수
	int M = 0; // 나누어 떨어져야 하는 수

	cin >> N >> M;

	// 사이즈 N, 0으로 초기화 
	vector<long> S(N, 0);  // 합 배열
	vector<long> C(M, 0);  // 나머지 배열

	long answer = 0;

	cin >> S[0]; // 0번째 입력받기

	for (int i = 1; i < N; i++)
	{
		int temp = 0;
		cin >> temp;       //숫자배열 입력받기

		S[i] = S[i - 1] + temp; // 합 배열 저장
	}

	for (int i = 0; i < N; i++)
	{
		int remainer = S[i] % M;

		if (remainer == 0) answer++; // 합 배열의 나머지가 0이면 그 자체로 정답에 추가

		C[remainer]++; // 나머지 배열에 카운팅
	}

	for (int i = 0; i < M; i++)
	{
		// 나머지가 같은 인덱스 중2개를 뽑는 경우의 수 -> 경우가 2이상이어야함
		if (C[i] > 1) answer += C[i] * (C[i] - 1) / 2;
	}

	cout << answer << endl;
}