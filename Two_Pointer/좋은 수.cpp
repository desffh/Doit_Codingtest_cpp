#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/// <summary>
/// 투 포인터 - '좋은 수' 구하기
/// </summary>


int main()
{
	// 1. 시간 제한 2초 2x10^8
	// 2. N의 범위는 2000까지, 시간 복잡도 O(NlogN)이하로 가능 

	// - 정렬 (NlogN)
	// - 좋은 수를 구하는 과정 O(N)
	// - 그 과정을 N번 (배열의 모든 수에 대하여 반복해야 하니까) O(N)
	// [최종 시간 복잡도 O(N^2)

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int  count = 0;
	cin >> N;

	vector<int> result(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> result[i];
	}

	sort(result.begin(), result.end());

	// 투 포인터 시작
	for (int i = 0; i < N; i++)
	{
		// result의 i번째를 매 회 찾아야함
		long find = result[i];

		int start = 0;
		int end = N - 1;

		while (start < end)
		{
			if (result[start] + result[end] == find)
			{
				// 자신이 포함되지 않아야함
				if (start != i && end != i)
				{
					count++;
					break;
				}
				else if (start == i)
				{
					start++;
				}
				else if (end == i)
				{
					end--;
				}
			}
			else if (result[start] + result[end] < find)
			{
				start++;
			}
			else
			{
				end--;
			}
		}
	}

	cout << count << '\n';
}