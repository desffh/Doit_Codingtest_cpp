#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 1427�� ���� ������������ �ڸ��� �����ϱ�

// ���������� �� ������� ������ ������ �˰� �Ѿ��

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;

	cin >> str;

	vector<int> A(str.size(), 0); // �Է¹��� ���ڿ� ���̸�ŭ ������ ���� �� 0���� �ʱ�ȭ

	for (int i = 0; i < str.size(); i++)
	{
		A[i] = stoi(str.substr(i, 1)); // i���� 1ũ���� ���ڿ��� ������ �迭�� ���
	}

	for (int i = 0; i < str.size(); i++)
	{
		int Max = i;

		for (int j = i + 1; j < str.size(); j++)
		{
			if (A[j] > A[Max]) // ���������̶� �ִ��� ã�´�.
			{
				Max = j;
			}
		}
		if (A[i] < A[Max]) // i�ڸ��� �ִ��� Max�ڸ��� ����
		{
			swap(A[i], A[Max]);
		}
	}

	for (int c : A)
	{
		cout << c;
	}
}


