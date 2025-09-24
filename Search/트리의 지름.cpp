#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef pair<int, int> edge;

int N; // 노드의 개수
static vector<vector<edge>> A; // 인접 리스트
static vector<bool> visited;  // 방문 배열
static vector<int> m_distance;// 가중치 배열

void BFS(int start);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1167번 트리의 지름
	*/

	cin >> N;

	// 0번째 인덱스는 사용하지 않는다.
	A.resize(N + 1);
	visited = vector<bool>(N + 1, false);
	m_distance = vector<int>(N + 1, 0);

	for (int i = 0; i < N; i++)
	{
		int num;

		cin >> num;

		while (true)
		{
			int Node; // 이웃된 노드
			int distance; // 가중치

			cin >> Node;

			if (Node == -1)
			{
				break;
			}

			cin >> distance;

			A[num].push_back(edge(Node, distance));
		}
	}

	// 임의의 노드부터 탐색 시작
	BFS(1);

	int Max = 1; // 가중치가 가장 큰 노드

	for (int i = 2; i <= N; i++)
	{
		// 현재 Max보다 가중치가 크다면 갱신
		if (m_distance[Max] < m_distance[i])
		{
			Max = i;
		}
	}

	// 다시 채우기 -> 한번더 BFS를 실행하기 위함
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
			// 인접한 노드가 방문되지 않았다면 
			if (!visited[i.first])
			{
				myQueue.push(i.first);
				visited[i.first] = true;

				// 가중치 업데이트
				m_distance[i.first] = m_distance[node] + i.second;
			}
		}
	}
}
