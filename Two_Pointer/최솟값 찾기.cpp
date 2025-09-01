#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

typedef pair<int, int> Node; // <숫자, 인덱스>

/// <summary>
/// 슬라이딩 윈도우 - 최솟값 찾기 1
/// </summary>

int main()
{
	// 제한 시간 2.4초 -> 2.4 x 10^8

	// N의 최대가 5 x 10^6 이라서 최대 O(N)밖에 사용할 수 없다.
	// -> 정렬(NlogN)을 사용할 수 없는 것.
	// -> deque을 사용하여 정렬을 구현할 수 있다.

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int L = 0;

	cin >> N >> L;

	deque <Node> mydeque;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		// 현재 들어온 값 보다 마지막 값이 더 크다면 제거
		while (mydeque.size() && mydeque.back().first > temp)
		{
			mydeque.pop_back();
		}

		mydeque.push_back(Node(temp, i));

		// 윈도우의 범위를 벗어난다면
		if (mydeque.back().second - L >= mydeque.front().second)
		{
			mydeque.pop_front();
		}

		// 최소값 출력
		cout << mydeque.front().first << " ";
	}
}


