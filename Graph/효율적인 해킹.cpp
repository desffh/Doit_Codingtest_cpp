#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

vector<vector<int>> A; // 인접 리스트
vector<bool> visited;   // 방문 배열
vector<int> Answer;    // 정답 배열

void BFS(int x);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1325번 효율적인 해킹

		BFS를 사용한 최대방문 횟수 구하기

		많이 방문한 노드일수록 신뢰도 증가 => 매 노드마다 BFS 실행
	*/

	int N; // 노드
	int M; // 간선

	cin >> N >> M;

	// 크기 지정
	A.resize(N + 1);
	visited.resize(N + 1, false);
	Answer.resize(N + 1, 0);

	// 인접리스트 생성 
	for (int i = 0; i < M; i++)
	{
		int num1;
		int num2;

		cin >> num1 >> num2;

		A[num1].push_back(num2);
	}

	for (int i = 1; i <= N; i++)
	{
		fill(visited.begin(), visited.end(), false); // 방문 배열 매 노드마다 초기화
		BFS(i); // 모든 노드 BFS탐색 
	}

	int maxNum = 0;

	for (int i : Answer)
	{
		if (maxNum < i)
		{
			maxNum = i;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (maxNum == Answer[i])
		{
			cout << i << endl;
		}
	}
}

// 너비 우선 탐색
void BFS(int x)
{
	queue<int> Q;

	Q.push(x);
	visited[x] = true;

	while (!Q.empty())
	{
		int temp = Q.front();
		Q.pop();

		// 현재 노드와 인접한 노드 탐색
		for (int i : A[temp])
		{
			// 인접 노드가 방문되지 않았다면 
			if (visited[i] == false)
			{
				Answer[i]++;
				visited[i] = true;
				Q.push(i);
			}
		}
	}
}



