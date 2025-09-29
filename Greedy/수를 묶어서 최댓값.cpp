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
		1744�� ���� ��� �ִ� �����
	*/

	int N; // ������ ũ��

	cin >> N;

	priority_queue<int, vector<int>, less<int>> A; // ��� ���� - ��������
	priority_queue<int, vector<int>, greater<int>> B; // ���� ���� - ��������
	int one = 0; // 1�� ����
	int zero = 0; // 0�� ����
	int result = 0;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		// �������� �Է¹ޱ�

		if (num == 0) // 0�̶��
		{
			zero++;
		}
		else if (num == 1) // 1�̶��
		{
			one++;
		}
		else if (num > 1) // ������
		{
			A.push(num);
		}
		else if (num < 0) // �������
		{
			B.push(num);
		}
	}

	// ���
	while (A.size() > 1)
	{
		int num1 = A.top();
		A.pop();
		int num2 = A.top();
		A.pop();

		result += num1 * num2;
	}

	// ����� �����Ͱ� �����ִٸ� 
	if (A.size() >= 1)
	{
		result += A.top();
	}

	// ����
	while (B.size() > 1)
	{
		int num1 = B.top();
		B.pop();
		int num2 = B.top();
		B.pop();

		result += num1 * num2;
	}

	// ������ �����Ͱ� �����ִٸ� 
	if (B.size() >= 1)
	{
		// 0�� �ϳ��� ���ٸ� �״�� ���ϱ�
		if (zero == 0)
		{
			result += B.top();
		}
		// 0�� �ִٸ� B.top() * 0 == 0 �̱� ������ �ƹ��͵� ������ �ʴ´�.
	}

	result += one;

	cout << result << '\n';
}