#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void DFS(int num, int digits);

bool IsPrime(int num); // �Ҽ� �Ǻ�

static int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		2023�� �ű��� �Ҽ�
	*/

	cin >> N;

	// 1�� �ڸ� ���� DFS ����
	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);
}

void DFS(int num, int digits)
{
	if (digits == N)
	{
		if (IsPrime(num))
		{
			cout << num << '\n';
		}
		return;
	}

	// ���� �ڸ��� 1~9 / Ȧ���鼭 �Ҽ���� DFS ����
	for (int i = 1; i <= 9; i++)
	{
		if (i % 2 != 0 && IsPrime(num * 10 + i))
		{
			DFS(num * 10 + i, digits + 1);
		}
	}
}

bool IsPrime(int num)
{
	for (int i = 2; i <= num / 2; i++)
	{
		// �Ҽ��� 1�� �ڱ��ڽŸ� ����. 
		// 2���� ���밪num���� �������� ������ �������� �Ҽ�x
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}