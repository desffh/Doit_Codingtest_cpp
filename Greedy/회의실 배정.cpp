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
		1931번 회의실 배정하기

		겹치지 않게 한 개의 회의실에서 할 수 있는 회의의 최대 개수는
		회의시간이 짧은 순에서 겹치지 않게 짜면 된다.
	*/

	int N; // 회의의 개수
	int result = 0;
	int end = -1;

	cin >> N;

	// 회의 정보 : 시작 시간, 끝 시간
	vector <pair<int, int>> A;

	for (int i = 0; i < N; i++)
	{
		int start;
		int end;
		cin >> start >> end;

		// 종료 시간 정렬을 위해 종료시간을 first로 저장
		A.push_back(pair<int, int>(end, start));
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < N; i++)
	{
		// 현재 회의 시작 시간 >= 이전 회의 종료 시간 => 회의가 겹치지 않는다는 것
		if (A[i].second >= end)
		{
			//
			end = A[i].first; // 종료 시간 갱신
			result++; //  회의 카운트
		}
	}

	cout << result << '\n';
}



// 사용자 정의 비교 함수를 사용한 방식

/*
// 오름차순 정렬 (종료시간 second를 기준)
bool Calculate(pair<int, int>& first, pair<int, int>& second)
{
	// 종료 시간이 같다면 시작시간 기준으로 오름차순 정렬
	if (first.second == second.second)
	{
		return first.first < second.first;
	}
	// 종료 시간 오름차순 정렬
	return first.second < second.second;
}
*/

/*int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
		// 1931번 회의실 배정하기

		// 겹치지 않게 한 개의 회의실에서 할 수 있는 회의의 최대 개수는
		// 회의시간이 짧은 순에서 겹치지 않게 짜면 된다.
	
	int N; // 회의의 개수
	int result = 0;
	int end = -1;

	cin >> N;

	// 회의 정보 : 시작 시간, 끝 시간
	vector <pair<int, int>> A(N);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i].first;
		cin >> A[i].second;
	}

	// 사용자 정의 비교함수 사용
	sort(A.begin(), A.end(), Calculate);

	for (int i = 0; i < N; i++)
	{
		if (A[i].first >= end)
		{
			end = A[i].second;
			result++;
		}
	}
	cout << result << '\n';
}*/

