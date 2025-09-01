#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 1377번 문제 버블 정렬 프로그램1

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	// 문제에서 swap이 일어나지 않았다는 건, 이미 모든 데이터가 정렬되었다는 것
	// 즉, 몇 번의 패스(i)를 반복해야 정렬이 완료되는지 종료 시점을 예측하는 것이다.


	int N = 0;

	cin >> N;

	vector<pair<int, int>> A(N); // first : 데이터 second : 정렬 전 인덱스

	for (int i = 0; i < N; i++)
	{
		cin >> A[i].first; // 데이터
		A[i].second = i;   // 정렬 전 인덱스 
	}

	sort(A.begin(), A.end()); // first 우선으로 정렬

	int Max = 0;

	for (int i = 0; i < N; i++)
	{
		if (Max < A[i].second - i)
		{
			Max = A[i].second - i; // 정렬 전 인덱스 - 정렬 후 인덱스
		}
	}

	cout << Max + 1 << '\n';
}


