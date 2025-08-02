#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/// <summary>
/// �� ������ - '���� ��' ���ϱ�
/// </summary>


int main()
{
	// 1. �ð� ���� 2�� 2x10^8
	// 2. N�� ������ 2000����, �ð� ���⵵ O(NlogN)���Ϸ� ���� 

	// - ���� (NlogN)
	// - ���� ���� ���ϴ� ���� O(N)
	// - �� ������ N�� (�迭�� ��� ���� ���Ͽ� �ݺ��ؾ� �ϴϱ�) O(N)
	// [���� �ð� ���⵵ O(N^2)

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

	// �� ������ ����
	for (int i = 0; i < N; i++)
	{
		// result�� i��°�� �� ȸ ã�ƾ���
		long find = result[i];

		int start = 0;
		int end = N - 1;

		while (start < end)
		{
			if (result[start] + result[end] == find)
			{
				// �ڽ��� ���Ե��� �ʾƾ���
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