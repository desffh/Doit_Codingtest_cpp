#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/* 10989번 문제 수 정렬하기3 - 계수 정렬 */

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// N이 너무 큰 경우 NlogN보다 빠른 알고리즘을 사용해야한다.
	// 계수정렬 시간복잡도 O(k + N)

	int N = 0;
	cin >> N;

	vector<int> count(10001, 0); // N의 최대 크기 + 1 배열

	for (int i = 1; i <= N; i++)
	{
		int num = 0;
		cin >> num;
		count[num]++;
	}

	for (int i = 1; i <= count.size(); i++)
	{
		if (count[i] != 0)
		{
			for (int j = 0; j < count[i]; j++)
			{
				cout << i << '\n';
			}
		}
	}
}
