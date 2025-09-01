#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/* 10989�� ���� �� �����ϱ�3 - ��� ���� */

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// N�� �ʹ� ū ��� NlogN���� ���� �˰����� ����ؾ��Ѵ�.
	// ������� �ð����⵵ O(k + N)

	int N = 0;
	cin >> N;

	vector<int> count(10001, 0); // N�� �ִ� ũ�� + 1 �迭

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
