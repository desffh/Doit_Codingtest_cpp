#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		11689�� ���Ϸ� �� �Լ� �����ϱ�

		�Է¹޴� n�� �ִ� ������ 10^12
	*/

	long n; // ���μ� ǥ��
	cin >> n;

	long result = n; // ����� = ���μ� �ĺ� ����


	for (int i = 2; i <= sqrt(n); i++)
	{
		// ���� i���� ���μ���� ������ ������ 
		if (n % i == 0)
		{
			// �ĺ� ���� ���̱�
			result -= result / i;

			// n�ȿ� ����ִ� ���μ�i�� ��� ����
			while (n % i == 0)
			{
				n /= i;
			}
		}
	}

	// �����ٱ����� Ž���ϱ� ������ ���μ� ���� ���ɼ��� �ִ�.
	// n�� �Ҽ���� for���� �� ����ص� ���������� �ʰ� �����ִ�.
	if (n > 1)
	{
		result -= result / n;
	}

	cout << result << "\n";
}
