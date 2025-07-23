#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

typedef pair<int, int> Node; // 노드 쌍

/// <summary>
/// 슬라이딩 윈도우 - 최솟값 찾기 1
/// </summary>

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque <Node> mydeque; // 현재 수와 인덱스 저장
	int N; int L;         // 데이터 개수, 최솟값을 구하는 범위

	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		int now; // 현재 입력받은 값
		cin >> now;

		// 현재 들어온 값보다 뒤의 값들이 크다면
		while (mydeque.size() && mydeque.back().first > now)
		{
			mydeque.pop_back(); // 제거
		}

		mydeque.push_back(Node(now, i)); // 숫자 & 인덱스

		// 맨 처음 인덱스 값이 i - L보다 작거나 같다면 (윈도우 범위 초과)
		if (mydeque.front().second <= i - L)
		{
			mydeque.pop_front();
		}

		// 가장 첫번째 숫자 출력
		cout << mydeque.front().first << " ";
	}
}


