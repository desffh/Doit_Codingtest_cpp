#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

long N; // 도시 갯수 (노드)
long M; // 도로 갯수 (간선)
long K; // 거리 정보
long X; // 출발 도시 번호

vector<vector<int>> A;   // 인접 리스트
vector<int> visited; // 방문 배열
vector<int> Answer;

void BFS(int X);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		18352번 특정 거리의 도시 찾기

		모든 도로의 거리가 1이므로 가중치가 없는 인접리스트를 사용한다.

		BFS를 사용한 최단거리 문제

	*/

	cin >> N >> M >> K >> X;

	// 크기 잡아주기
	A.resize(N + 1);
	visited.resize(N + 1, -1);

	// 인접리스트 생성 (간선 횟수만큼 입력받기)
	for (int i = 0; i < M; i++)
	{
		int num1;
		int num2;

		cin >> num1 >> num2;

		A[num1].push_back(num2);
	}

	// 너비 우선 탐색 진행
	BFS(X);

	// 방문 배열 탐색 후 최단거리 K와 동일한 노드를 정답 배열에 추가
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == K)
		{
			Answer.push_back(i);
		}
	}

	// 정답 배열이 비었다면 -1 출력
	if (Answer.empty())
	{
		cout << -1 << endl;
	}
	else
	{
		sort(Answer.begin(), Answer.end());

		for (int i = 0; i < Answer.size(); i++)
		{
			cout << Answer[i] << endl;
		}
	}
}

// 너비 우선 탐색
void BFS(int X)
{
	queue<int> Q;

	Q.push(X); // 시작 노드 추가

	visited[X]++;

	while (!Q.empty())
	{
		int temp = Q.front();
		Q.pop();

		for (int i : A[temp])
		{
			// 방문되지 않았다면
			if (visited[i] == -1)
			{
				visited[i] = visited[temp] + 1;
				Q.push(i); // 다음 노드 추가
			}
		}
	}
}


