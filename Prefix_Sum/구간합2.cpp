#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// <summary>
/// ���� �� - 2���� �迭 ���� �� ���ϱ�
/// </summary>

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; // �迭 ũ��
	int M = 0; // ���� �� 

	cin >> N >> M;

	// ũ��� N + 1
	vector<vector<int>> A(N + 1, vector<int>(N + 1, 0)); // ���� �迭
	vector<vector<int>> D(N + 1, vector<int>(N + 1, 0)); // �� �迭

	// ���� �迭 �Է¹ް� ���� & �� �迭 ����
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];

			D[i][j] = D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1] + A[i][j];
		}
	}

	// ���� ��� & ���
	for (int i = 0; i < M; i++)
	{
		int x1, x2, y1, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		int result = D[x2][y2] - D[x1 - 1][y2] - D[x2][y1 - 1] + D[x1 - 1][y1 - 1];

		cout << result << endl;
	}
}