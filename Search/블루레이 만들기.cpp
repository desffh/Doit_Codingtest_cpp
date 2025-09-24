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
		2606�� ��緹�� ����� - ���� Ž��
	*/

	int N; // ���� �� �ִ밪
	int M; // ���� �� ��

	int start = 0;
	int end = 0;

	cin >> N >> M;

	vector<int>A(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];

		if (start < A[i])
		{
			start = A[i];
		}
		end += A[i];
	}

	while (start <= end)
	{
		int middle = (start + end) / 2;
		int sum = 0; // ���� ������
		int count = 0; // ����� ��緹�� ����

		for (int i = 0; i < N; i++)
		{
			// ��緹�� �� á�ٴ� �ǹ�
			if (sum + A[i] > middle)
			{
				count++;
				sum = 0;
			}

			sum += A[i];
		}

		// sum�� 0�� �ƴ�ä�� �����ٴ� �� ������ ��緹�̸� �ǹ�
		if (sum != 0) count++;

		if (count > M)
		{
			start = middle + 1;
		}
		else
		{
			end = middle - 1;
		}
	}

	cout << start << '\n';
}
