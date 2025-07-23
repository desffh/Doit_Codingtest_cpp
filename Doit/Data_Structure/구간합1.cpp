#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// <summary>
/// 구간 합 - 1차원 배열 구간 합 구하기
/// </summary>

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int suNo = 0;   // 숫자 갯수
	int quizNo = 0; // 질의 갯수

	int S[100001] = {};  // 합 배열

	cin >> suNo >> quizNo;

	// 구간합의 범위가 S[i] = S[i - 1] + A[i] 기 때문에 1부터 시작 
	for (int i = 1; i <= suNo; i++)
	{
		int temp = 0;

		cin >> temp;

		S[i] = S[i - 1] + temp;
	}

	for (int i = 0; i < quizNo; i++)
	{
		int start;
		int end;

		cin >> start >> end;

		cout << S[end] - S[start - 1] << "\n";
	}
}