#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

// 물통 노드
int Sender[] = { 0, 0, 1, 1, 2, 2 };
int Receiver[] = { 1, 2, 0, 2, 0, 1 };

static bool visited[201][201]; // 방문 배열
static bool answer[201];       // 정답 배열
static int now[3];             // 현재 노드 배열

void BFS();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		2251번 물통(물의 양 구하기)

		정적과 간선이 명시적으로 주어지지 않는 그래프 문제

		- 각 상태가 그래프의 정점
		- 물을 붓는 행위가 간선
		- 한 상태에서 가능한 다음 상태는 직접 계산하기 때문에 인접그래프 사용X, BFS사용

		- A와 B의 물 양만 알면 C의 물 양은 자동으로 결정된다.
	*/


	cin >> now[0] >> now[1] >> now[2];

	BFS();

	for (int i = 0; i < 201; i++)
	{
		if (answer[i])
		{
			cout << i << " ";
		}
	}
}

void BFS()
{
	queue<pair<int, int>> Q;

	Q.push(make_pair(0, 0));
	visited[0][0] = true;   // A B 물통이 비어있다
	answer[now[2]] = true;  // C물통이 가득차있다

	while (!Q.empty())
	{
		pair<int, int> p = Q.front();

		Q.pop();

		int A = p.first;
		int B = p.second;
		int C = now[2] - A - B; // 물 뺴고 남은 양

		for (int i = 0; i < 6; i++)
		{
			int next[] = { A, B, C };

			// Sender -> Receiver로 물 옮기기
			next[Receiver[i]] += next[Sender[i]];

			next[Sender[i]] = 0; // 옮겨진 물 부분 비우기

			// 용량보다 넘친다면
			if (next[Receiver[i]] > now[Receiver[i]])
			{
				// 보내는 쪽 = 넘친 물통 - 넘친 물통의 용량
				next[Sender[i]] = next[Receiver[i]] - now[Receiver[i]];

				// 넘친 물통은 해당 물통의 최대 용량만큼 설정
				next[Receiver[i]] = now[Receiver[i]];
			}

			// 방문되지 않았다면
			if (!visited[next[0]][next[1]])
			{
				// 방문 체크
				visited[next[0]][next[1]] = true;

				Q.push(make_pair(next[0], next[1]));
			}

			// 첫번째 물통(A)이 비어있을 때의 C의 물의 양
			if (next[0] == 0)
			{
				answer[next[2]] = true;
			}
		}

	}
}



