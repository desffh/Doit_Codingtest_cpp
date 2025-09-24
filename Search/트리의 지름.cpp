#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef pair<int, int> edge;

int N; // ����� ����
static vector<vector<edge>> A; // ���� ����Ʈ
static vector<bool> visited;  // �湮 �迭
static vector<int> m_distance;// ����ġ �迭

void BFS(int start);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1167�� Ʈ���� ����
	*/

	cin >> N;

	// 0��° �ε����� ������� �ʴ´�.
	A.resize(N + 1);
	visited = vector<bool>(N + 1, false);
	m_distance = vector<int>(N + 1, 0);

	for (int i = 0; i < N; i++)
	{
		int num;

		cin >> num;

		while (true)
		{
			int Node; // �̿��� ���
			int distance; // ����ġ

			cin >> Node;

			if (Node == -1)
			{
				break;
			}

			cin >> distance;

			A[num].push_back(edge(Node, distance));
		}
	}

	// ������ ������ Ž�� ����
	BFS(1);

	int Max = 1; // ����ġ�� ���� ū ���

	for (int i = 2; i <= N; i++)
	{
		// ���� Max���� ����ġ�� ũ�ٸ� ����
		if (m_distance[Max] < m_distance[i])
		{
			Max = i;
		}
	}

	// �ٽ� ä��� -> �ѹ��� BFS�� �����ϱ� ����
	fill(visited.begin(), visited.end(), false);
	fill(m_distance.begin(), m_distance.end(), 0);

	BFS(Max);

	sort(m_distance.begin(), m_distance.end());

	cout << m_distance[N];
}

void BFS(int start)
{
	queue<int> myQueue;

	myQueue.push(start);

	visited[start] = true;

	while (!myQueue.empty())
	{
		int node = myQueue.front();
		myQueue.pop();

		for (edge i : A[node])
		{
			// ������ ��尡 �湮���� �ʾҴٸ� 
			if (!visited[i.first])
			{
				myQueue.push(i.first);
				visited[i.first] = true;

				// ����ġ ������Ʈ
				m_distance[i.first] = m_distance[node] + i.second;
			}
		}
	}
}
