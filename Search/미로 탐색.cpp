#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

static int N;
static int M;

static int A[101][101]; // 2���� �̷� �迭
static bool visited[101][101]; // �湮 �迭

// �����¿� ��ǥ Ž�� 
static int dx[] = { 0, 1, 0, -1 };
static int dy[] = { 1, 0, -1, 0 };

void BFS(int i, int j);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		2178�� �̷� Ž�� - BFS
	*/


	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < M; j++)
		{
			A[i][j] = s[j] - '0';
		}
	}

	BFS(0, 0);

	cout << A[N - 1][M - 1] << '\n';
}

void BFS(int i, int j)
{
	queue<pair<int, int>>myQueue;

	myQueue.push(pair<int, int>(i, j));


	while (!myQueue.empty())
	{
		auto num = myQueue.front();

		myQueue.pop();

		visited[i][j] = true;

		// �����¿� Ž��
		for (int i = 0; i < 4; i++)
		{
			int num1 = num.first + dx[i];
			int num2 = num.second + dy[i];

			// ���� Ȯ�� (N, M)�� �Ǿ��ٸ� ���ǹ� ����x
			if (num1 >= 0 && num2 >= 0 && num1 < N && num2 < M)
			{
				// 0�� �ƴϰ� �湮���� �ʾҴٸ�
				if (A[num1][num2] != 0 && !visited[num1][num2])
				{
					visited[num1][num2] = true;

					// ���� ���� = ���� ���� + 1�� ������Ʈ
					A[num1][num2] = A[num.first][num.second] + 1;

					myQueue.push(pair<int, int>(num1, num2));
				}
			}
		}
	}
}