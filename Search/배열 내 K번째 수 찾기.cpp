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
		1300�� �迭���� K��° �� ã�� - ���� Ž��

		1. �߾Ӱ��� ����Ͽ� k��°���� �� ���� ���� ������ Ž���Ѵ�.
		2. �߾Ӱ����� ���� ���� ���� >= K�� �Ǿ������� ���䰪�� �߾Ӱ����� �����Ѵ�.
	*/

	long N; // �迭�� ũ��
	long K; // ���ϰ��� �ϴ� �ε��� ����
	cin >> N >> K;

	long start = 1;
	long end = K;

	long result = 0;

	while (start <= end)
	{
		long middle = (start + end) / 2;

		int cnt = 0; // �߾Ӱ����� ���� ��

		// ���� ��ȸ�Ͽ� �߾Ӱ����� ���� �� ī����
		for (int i = 1; i <= N; i++)
		{
			cnt += min(middle / i, N);
		}
		if (cnt < K)
		{
			start = middle + 1;
		}
		else
		{
			end = middle - 1;
			result = middle;
		}
	}

	cout << result << '\n';
}
