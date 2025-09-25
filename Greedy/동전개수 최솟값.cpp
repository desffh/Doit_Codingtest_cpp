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
		11047번 잔돈 갯수 구하기
	*/

	int N; // 동전의 갯수
	int K; // 만들어야 할 금액
	vector<int>A;

	int coins = 0;

	cin >> N >> K;

	A.resize(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	// 내림차순 정렬 후 순회 방식
	/*
	sort(A.begin(), A.end(), greater<int>());

	for (int i = 0; i < A.size(); i++)
	{
		if (K >= A[i])
		{
			coins += K / A[i];
			K %= A[i];
		}
	}
	*/

	// 오름차순으로 입력받았기 때문에 큰 수부터 카운팅 하려면 뒤에서 부터 진행
	for (int i = N - 1; i >= 0; i--)
	{
		if (K >= A[i])
		{
			coins += K / A[i];
			K %= A[i];
		}
	}
	cout << coins << '\n';
}
