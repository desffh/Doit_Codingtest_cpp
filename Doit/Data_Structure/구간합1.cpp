#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// <summary>
/// ���� �� - 1���� �迭 ���� �� ���ϱ�
/// </summary>

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int suNo = 0;   // ���� ����
	int quizNo = 0; // ���� ����

	int S[100001] = {};  // �� �迭

	cin >> suNo >> quizNo;

	// �������� ������ S[i] = S[i - 1] + A[i] �� ������ 1���� ���� 
	for (int i = 1; i <= suNo; i++)
	{
		int temp = 0;

		cin >> temp;

		S[i] = S[i - 1] + temp;
	}

	for (int i = 0; i < quizNo; i++)
	{
		int start;
		int end;

		cin >> start >> end;

		cout << S[end] - S[start - 1] << "\n";
	}
}