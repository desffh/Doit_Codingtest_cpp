#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// <summary>
/// ���� �� - ��� ���ϱ�
/// </summary>

int main()
{
	int N = 0;
	cin >> N; // ������ ����

	int list[1000];

	for (int i = 0; i < N; i++)
	{
		cin >> list[i]; // ������ ������ ����
	}

	long maxnum = 0;
	long sum = 0;

	for (int i = 0; i < N; i++)
	{
		sum += list[i];

		if (maxnum < list[i])
		{
			maxnum = list[i];
		}
	}

	// �Ҽ��� ���
	double result = sum * 100.0 / maxnum / N;

	cout << result;
}