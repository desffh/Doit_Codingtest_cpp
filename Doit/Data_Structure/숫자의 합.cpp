#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// <summary>
/// ���� �� - ������ �� ���ϱ�
/// </summary>

int main()
{
	int N = 0;
	int sum = 0;
	string st;

	cin >> N; // ������ ����
	cin >> st; // ���ڿ� ���ڵ�


	for (int i = 0; i < st.length(); i++)
	{
		sum += st[i] - '0';
	}

	cout << sum;
}