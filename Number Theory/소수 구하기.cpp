#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath> // sqrt() ����ϱ� ���� ���� �ʼ�

using namespace std;

int main()

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1929�� �Ҽ� ���ϱ� - �ð����� 2�ʱ� ������ O(N��)�� Ǯ �� ����.
						 - Nlog(logN)���� Ǯ��� �Ѵ�.(�����佺�׳׽��� ü)
	*/

	int M; // ���� ��
	int N; // ���� ��

	cin >> M >> N;

	vector<int> A(N + 1, 0); // �Ҽ� �Ǻ� �迭 

	for (int i = 2; i <= N; i++)
	{
		A[i] = i;
	}

	// 2 ~ ������N���� �ݺ�
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (A[i] == 0)
		{
			continue;
		}

		// ��� ����
		for (int j = i + i; j <= N; j += i)
		{
			A[j] = 0;
		}
	}

	for (int i = M; i <= N; i++)
	{
		if (A[i] != 0)
		{
			cout << A[i] << endl;
		}
	}
}
