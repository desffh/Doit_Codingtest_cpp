#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/// <summary>
/// 투 포인터 - '좋은 수' 구하기
/// </summary>


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; // 배열의 데이터 갯수
	int count = 0;
	cin >> N;
	vector<int> A(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < N; i++)
	{
		int start = 0;
		int end = N - 1;
		long find = A[i]; // 찾고자 하는 값

		while (start < end)
		{
			if (A[start] + A[end] == find)
			{
				if (start != i || end != i)
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
			else if (A[start] + A[end] < find)
			{
				start++;
			}
			else
			{
				end--;
			}
		}
	}
	cout << count;
}