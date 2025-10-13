#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

bool isPalindrome(int target)
{
	string str = to_string(target);

	char const* temp = str.c_str();

	int s = 0; // ���� 
	int e = str.size() - 1; // ��

	while (s < e)
	{
		// �ϳ��� �ٸ��� �Ӹ������ �ƴϴ�
		if (temp[s] != temp[e])
		{
			return false;
		}

		s++;
		e--;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1747�� �Ҽ� & �Ӹ���� �� �߿��� �ּڰ� ã��
	*/

	long N;
	long A[10000001];

	cin >> N;

	for (int i = 2; i < 10000001; i++)
	{
		A[i] = i;
	}

	for (int i = 2; i <= sqrt(10000001); i++)
	{
		if (A[i] == 0)
		{
			continue;
		}

		// �Ҽ��� ��� ����
		for (int j = i + i; j < 10000001; j += i)
		{
			A[j] = 0;
		}
	}

	long i = N; // ���� N���� �Ӹ���� ã�� ����

	while (true)
	{
		// �Ҽ����
		if (A[i] != 0)
		{
			int result = A[i];

			// �Ӹ�����̶��
			if (isPalindrome(result))
			{
				cout << result << endl;
				break;
			}
		}
		// �Ӹ������ �ƴ϶�� ���� �Ҽ� Ȯ��
		i++;
	}

}

