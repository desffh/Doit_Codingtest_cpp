#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

vector<tuple<int, int, int>> A[10];
long lcm; // 최소 공배수
long D[10]; //  각 노드 값 저장 배열
bool visited[10];

long GCD(long a, long b);
void DFS(int node);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1033번 칵테일

		재료 N개 = 노드 N개
		N-1개의 재료쌍 = N-1개의 간선

		=> 사이클이 없는 트리구조


		재료 i와 재료 j가 p : q 비율로 연결되어 있다.

		=> 그래프 문제라고 유추 가능
	*/

	int N; // 재료의 갯수

	cin >> N;

	lcm = 1;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, p, q;

		cin >> a >> b >> p >> q;

		A[a].push_back(make_tuple(b, p, q));
		A[b].push_back(make_tuple(a, q, p));

		// 최소 공배수 업데이트
		lcm *= (p * q / GCD(p, q));
	}

	D[0] = lcm;

	DFS(0); // 탐색 시작

	long mgcd = D[0];

	// 최대공약수로 나눠 최소정수 비율로 출력하기
	for (int i = 1; i < N; i++)
	{
		mgcd = GCD(mgcd, D[i]); // 여러개의 gcd를 차례로 진행
	}
	for (int i = 0; i < N; i++)
	{
		cout << D[i] / mgcd << ' ';
	}
}


long GCD(long a, long b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return GCD(b, a % b);  // 작은수를 나머지로 계속 나누는 방식
	}
}

// DFS (깊이 우선 탐색)
void DFS(int node)
{
	visited[node] = true;

	// 노드에 연결된 다른 노드 탐색
	for (tuple<int, int, int> i : A[node])
	{
		int next = get<0>(i); // tuple의 0번째 요소 가져오기

		if (!visited[next])
		{
			// 다음 노드(j) = i * (q / p)
			D[next] = D[node] * get<2>(i) / get<1>(i);

			DFS(next);
		}
	}
}

