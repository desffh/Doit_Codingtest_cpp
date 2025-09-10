#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

static int N = 0; // ���
static int M = 0; // ����
static bool arrive;

static vector<bool> visited;
static vector<vector<int>>A;

void DFS(int now, int depth);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		13023�� ABCDE ģ������ �ľ��ϱ�
	*/

	cin >> N >> M;

	A.resize(N); // �� ũ�� N 
	visited = vector<bool>(N, false);
	arrive = false;

	for (int i = 0; i < M; i++)
	{
		int num1;
		int num2;

		cin >> num1 >> num2;

		A[num1].push_back(num2);
		A[num2].push_back(num1);
	}

	for (int i = 0; i < N; i++)
	{
		// ��� ��忡 ���Ͽ� DFS����
		DFS(i, 1);

		if (arrive)
		{
			break;
		}
	}

	if (arrive) cout << 1 << '\n';
	else cout << 0 << '\n';
}

void DFS(int now, int depth)
{
	if (depth == 5 || arrive)
	{
		arrive = true;
		return;
	}

	visited[now] = true; // �湮 ��� ���

	// �� ���� ����� ��� �� �湮���� ���� ��带 DFS ����
	for (int i : A[now])
	{
		if (!visited[i])
		{
			DFS(i, depth + 1);
		}
	}

	visited[now] = false; // �湮 ��� ����
}


