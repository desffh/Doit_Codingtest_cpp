#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1016�� ������ �ƴ� �� ã��
	*/

	long Min; // �Է¹޴� ���� �ִ� ������ 10^12
	long Max;

	int count = 0;

	cin >> Min >> Max;

	vector<bool> Check(Max - Min + 1);

	for (long i = 2; i * i <= Max; i++)
	{
		long pow = i * i; // ���� ��

		// ���� �ε��� ���� -> ���� ���� ù �������� ������� �����ϱ� ����
		long start_index = Min / pow;

		// �������� 0�� �ƴ϶�� + 1
		if (Min % pow != 0)
		{
			start_index++;
		}

		for (long j = start_index; pow * j <= Max; j++)
		{
			// �迭�� ������ [Min, Max]�� �Ǿ��ֱ� ������ ��ġ�� �����ؾ��Ѵ�.
			// j * pow�� ���� ���� �ε����� �迭�� �ֱ� ����.
			Check[(int)((j * pow) - Min)] = true;
		}
	}

	for (int i = 0; i < Max - Min + 1; i++)
	{
		if (Check[i] != true)
		{
			count++;
		}
	}
	cout << count << "\n";
}
