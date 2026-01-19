#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

vector<vector<int>> dosi; // 도시 연결 인접 행렬
vector<int> parent;       // 대표 배열
vector<int> route;        // 여행 계획 도시 배열

void Union(int a, int b);
int Find(int a);


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1976번 여행 계획짜기

		인접행렬 + 유니온 파인드

		연결된 도시들의 대표 노드와 계획 도시의 대표 노드를 비교
	*/

	int N; // 도시의 수
	int M; // 여행 계획 도시 수

	cin >> N >> M;

	dosi.resize(N + 1);
	parent.resize(N + 1);
	route.resize(M + 1);

	// 도시 연결 인접행렬 저장
	for (int i = 1; i <= N; i++)
	{
		// push_back()으로 넣을 경우 [0]번째 부터 들어가는데, 
		// 인접행렬에서 [i][0]은 사용되지 않기 때문에 [i][0]에 값 미리 추가
		dosi[i].push_back(0);

		for (int j = 1; j <= N; j++)
		{
			int num;

			cin >> num;

			dosi[i].push_back(num);
		}
	}

	// 대표 배열 초기화
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	// 여행 계획 저장
	for (int i = 1; i <= M; i++)
	{
		int num;

		cin >> num;

		route[i] = num;
	}

	// 유니온 연산
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			// 도시가 연결되어 있다면
			if (dosi[i][j] == 1)
			{
				Union(i, j);
			}
		}
	}

	// 계획된 도시[1]의 대표 노드
	int index = Find(route[1]);
	bool connect = true;

	for (int i = 2; i <= M; i++)
	{
		// 나머지 계획된 도시들과 대표 노드 비교
		if (index != Find(route[i]))
		{
			connect = false;
			break;
		}
	}

	connect == true ? cout << "YES" << endl : cout << "NO" << endl;
}

void Union(int a, int b)
{
	// 두 도시의 대표 노드
	int findA = Find(a);
	int findB = Find(b);

	// 두 대표 노드가 다르다면 대표 노드 갱신
	if (findA != findB)
	{
		parent[findB] = findA;
	}
}

// 대표 노드 찾기
int Find(int a)
{
	if (parent[a] == a)
	{
		return a;
	}
	else
	{
		// 경로 압축
		return parent[a] = Find(parent[a]);
	}
}


