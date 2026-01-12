#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

vector<vector<int>> A; // 인접 리스트
vector<bool> visited;  // 방문 배열
vector<int> check;     // 이분 그래프 체크 배열

void DFS(int x);

bool isEven;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1707번 이분 그래프

		DFS를 사용하며, 방문했는데 서로 같은 집합이면 이분 그래프 false

		DFS는 무방향 그래프에서 사용
	*/

	int N; // 노드 갯수
	int M; // 간선 갯수
	int T; // 테스트 케이스

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;

		A.resize(N + 1);
		visited.resize(N + 1, false);
		check.resize(N + 1, 0);

		isEven = true;

		for (int i = 0; i < M; i++)
		{
			int num1;
			int num2;

			cin >> num1 >> num2;

			A[num1].push_back(num2);
			A[num2].push_back(num1);
		}

		// 모든 노드 실행 => 이분 그래프 아닐 시 바로 탈출
		for (int i = 1; i <= N; i++)
		{
			if (isEven)
			{
				DFS(i);
			}
			else
			{
				break;
			}
		}

		isEven == true ? cout << "YES" << endl : cout << "NO" << endl;

		// 인접 그래프, 방문 배열, 체크 배열 초기화
		for (int i = 0; i <= N; i++)
		{
			A[i].clear();
			visited[i] = false;
			check[i] = 0;
		}
	}
}

// 재귀 형태의 DFS
void DFS(int x)
{
	visited[x] = true;

	// 인접한 노드 방문
	for (int i : A[x])
	{
		// 방문 되지 않았다면 서로 다른 집합 처리
		if (!visited[i])
		{
			check[i] = (check[x] + 1) % 2;
			DFS(i);
		}
		// 방문 했는데 집합이 같다면
		else if (check[i] == check[x])
		{
			isEven = false;
		}
	}
}


