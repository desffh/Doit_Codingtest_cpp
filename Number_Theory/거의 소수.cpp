#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1456�� ���� �Ҽ� ���ϱ�

		1. �־��� ���������� �����ϴ� ��� �Ҽ� ���ϱ�.

		2. �Ҽ��� N �������� ������ �����ϸ� ī���� (N >= 2)

		3. ������ �־��� ������ �����Ͽ� �ڷ����� �����Ѵ�.

		4. ���� �Ҽ� �Ǻ� �� ���� ǥ�� ������ �Ѿ �� �ֱ⿡ ���������� ǥ��
	*/

	long Min;
	long Max;
	int A[10000001]; // �Ҽ� �迭

	int count = 0; // ���� ����

	cin >> Min >> Max;

	for (int i = 2; i < 10000001; i++)
	{
		A[i] = i;
	}

	// �ִ���� ������ 10^7 ���� �ݺ� 
	for (int i = 2; i <= sqrt(10000001); i++)
	{
		// �Ҽ���� �ǳʶٱ�
		if (A[i] == 0)
		{
			continue;
		}

		// �Ҽ��� ����� ��� ����
		for (int j = i + i; j < 10000001; j += i)
		{
			A[j] = 0;
		}
	}

	for (int i = 2; i < 10000001; i++)
	{
		// �迭 �� ���Ұ� �Ҽ��� ���
		if (A[i] != 0)
		{
			long temp = A[i];

			// ���� �Ҽ��� Max�������� Ŀ���� ����
			while ((double)A[i] <= (double)Max / (double)temp)
			{
				// ���� �Ҽ��� Min �������� ũ�ٸ� ī����
				if ((double)A[i] >= (double)Min / (double)temp)
				{
					count++;
				}

				temp *= A[i];
			}
		}
	}

	cout << count << '\n';
}
