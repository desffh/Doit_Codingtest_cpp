#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// <summary>
/// 구간 합 - 2차원 배열 구간 합 구하기
/// </summary>

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; // 배열 크기
	int M = 0; // 질의 수 

	cin >> N >> M;

	// 크기는 N + 1
	vector<vector<int>> A(N + 1, vector<int>(N + 1, 0)); // 원본 배열
	vector<vector<int>> D(N + 1, vector<int>(N + 1, 0)); // 합 배열

	// 원본 배열 입력받고 저장 & 합 배열 저장
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];

			D[i][j] = D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1] + A[i][j];
		}
	}

	// 질의 계산 & 출력
	for (int i = 0; i < M; i++)
	{
		int x1, x2, y1, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		int result = D[x2][y2] - D[x1 - 1][y2] - D[x2][y1 - 1] + D[x1 - 1][y1 - 1];

		cout << result << endl;
	}
}