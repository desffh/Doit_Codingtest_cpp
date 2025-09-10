#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N = 0; // 노드
int M = 0; // 간선
int Start = 0; // 시작점

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
		1260번 DFS와 BFS
	*/

	cin >> N >> M >> Start;

	A.resize(N + 1); // 노드가 1부터 시작하기 때문에 맞춰주기 (0번째는 사용x)

	for (int i = 0; i < M; i++)
	{
		int num1;
		int num2;
		cin >> num1 >> num2;

		A[num1].push_back(num2);
		A[num2].push_back(num1);
	}

	// 인접리스트 내의 원소 정렬
	for (int i = 1; i <= N; i++)
	{
		sort(A[i].begin(), A[i].end());
	}

	visited = vector<bool>(N + 1, false);

	DFS(Start);

	cout << '\n';

	// 반복자 구간 내 원소를 false로 덮어씌우기
	fill(visited.begin(), visited.end(), false);

	BFS(Start);

	cout << '\n';
}

void DFS(int start)
{
	// LIFO 방식의 재귀 구현
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
	queue<int>myQueue; // FIFO방식

	myQueue.push(start);
	visited[start] = true;

	while (!myQueue.empty())
	{
		int node = myQueue.front();
		myQueue.pop();

		cout << node << " ";

		// 인접한 노드들 모두 큐에 넣기 & 방문 체크
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

