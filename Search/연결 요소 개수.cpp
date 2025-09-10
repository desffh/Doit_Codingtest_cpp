#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;

void DFS(int v);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		11724번 연결 요소의 개수 구하기

		1. 각 노드에 인접한 노드를 저장 할 2차원 배열 생성
		   -> 계산 용이를 위해 [0]는 사용하지 않는다.

		2. 노드의 1번째부터 N까지 DFS를 실행한다.
		   -> DFS내부에 방문 여부에 따라 실행하거나 탈출한다.

		   -> 재귀 함수는 스택과 같은 방식으로 처리되는 것

		3. DFS의 실행 횟수 == 연결 요소 개수
	*/

	int N = 0; // 노드 개수
	int M = 0; // 간선 개수

	cin >> N >> M;

	A.resize(N + 1); // [0]제외 입력받기 -> 계산 용이를 위함
	visited = vector<bool>(N + 1, false);

	for (int i = 0; i < M; i++)
	{
		int node1;
		int node2;

		cin >> node1 >> node2;

		A[node1].push_back(node2);
		A[node2].push_back(node1);
	}

	int count = 0;

	for (int i = 1; i < N + 1; i++) // [0]제외 DFS 실행
	{
		if (!visited[i]) // 방문되지 않았을때 DFS실행
		{
			count++;
			DFS(i);
		}
	}

	cout << count << '\n';
}

void DFS(int v)
{
	if (visited[v]) return; // 이미 방문체크가 되었으면 실행x

	visited[v] = true;

	for (int element : A[v])
	{
		if (visited[element] == false) // 인접리스트 요소가 방문되지 않았다면
		{
			DFS(element); // 탐색
		}
	}
}