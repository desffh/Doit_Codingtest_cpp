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
		1920�� �� ã�� - ���� Ž��
	*/

	int N; // ���� ����
	int M; // ã���� �ϴ� ���� ����

	cin >> N;

	vector<int> A(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	// ���� Ž���� ���� �ʼ�
	sort(A.begin(), A.end());

	cin >> M;

	// stl�� ����� ���
	/*
		for (int i = 0; i < M; i++)
	{
		int target;
		cin >> target;

		bool result = binary_search(A.begin(), A.end(), target);

		cout << result << '\n';
	}

	*/



	for (int i = 0; i < M; i++)
	{
		int target;
		cin >> target;

		// ����, �� �ε���
		int start = 0;
		int end = N - 1;

		bool isFind = false;

		while (start <= end)
		{
			int middle = (start + end) / 2;
			int mididx = A[middle];

			if (mididx > target)
			{
				end = middle - 1;
			}
			else if (mididx < target)
			{
				start = middle + 1;
			}
			else
			{
				isFind = true;
				break;
			}
		}

		if (isFind == true)
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}
}

