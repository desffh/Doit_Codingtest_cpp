#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

static int N = 0; // 노드
static int M = 0; // 간선
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
		13023번 ABCDE 친구관계 파악하기
	*/

	cin >> N >> M;

	A.resize(N); // 행 크기 N 
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
		// 모든 노드에 대하여 DFS실행
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

	visited[now] = true; // 방문 노드 기록

	// 각 노드와 연결된 노드 중 방문되지 않은 노드를 DFS 실행
	for (int i : A[now])
	{
		if (!visited[i])
		{
			DFS(i, depth + 1);
		}
	}

	visited[now] = false; // 방문 노드 삭제
}


