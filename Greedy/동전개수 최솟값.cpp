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
		11047�� �ܵ� ���� ���ϱ�
	*/

	int N; // ������ ����
	int K; // ������ �� �ݾ�
	vector<int>A;

	int coins = 0;

	cin >> N >> K;

	A.resize(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	// �������� ���� �� ��ȸ ���
	/*
	sort(A.begin(), A.end(), greater<int>());

	for (int i = 0; i < A.size(); i++)
	{
		if (K >= A[i])
		{
			coins += K / A[i];
			K %= A[i];
		}
	}
	*/

	// ������������ �Է¹޾ұ� ������ ū ������ ī���� �Ϸ��� �ڿ��� ���� ����
	for (int i = N - 1; i >= 0; i--)
	{
		if (K >= A[i])
		{
			coins += K / A[i];
			K %= A[i];
		}
	}
	cout << coins << '\n';
}
