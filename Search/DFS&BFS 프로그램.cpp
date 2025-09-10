#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N = 0; // ���
int M = 0; // ����
int Start = 0; // ������

static vector<vector<int>>A;
static vector<bool>visited;

void DFS(int start);

void BFS(int start);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1260�� DFS�� BFS
	*/

	cin >> N >> M >> Start;

	A.resize(N + 1); // ��尡 1���� �����ϱ� ������ �����ֱ� (0��°�� ���x)

	for (int i = 0; i < M; i++)
	{
		int num1;
		int num2;
		cin >> num1 >> num2;

		A[num1].push_back(num2);
		A[num2].push_back(num1);
	}

	// ��������Ʈ ���� ���� ����
	for (int i = 1; i <= N; i++)
	{
		sort(A[i].begin(), A[i].end());
	}

	visited = vector<bool>(N + 1, false);

	DFS(Start);

	cout << '\n';

	// �ݺ��� ���� �� ���Ҹ� false�� ������
	fill(visited.begin(), visited.end(), false);

	BFS(Start);

	cout << '\n';
}

void DFS(int start)
{
	// LIFO ����� ��� ����
	cout << start << " ";
	visited[start] = true;

	for (int i : A[start])
	{
		if (!visited[i])
		{
			DFS(i);
		}
	}
}

void BFS(int start)
{
	queue<int>myQueue; // FIFO���

	myQueue.push(start);
	visited[start] = true;

	while (!myQueue.empty())
	{
		int node = myQueue.front();
		myQueue.pop();

		cout << node << " ";

		// ������ ���� ��� ť�� �ֱ� & �湮 üũ
		for (int i : A[node])
		{
			if (!visited[i])
			{
				myQueue.push(i);
				visited[i] = true;
			}
		}
	}
}

