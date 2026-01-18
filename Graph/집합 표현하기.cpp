#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

vector<int> parent;

void Union(int x, int y);
int Find(int a);
bool checkSame(int a, int b);


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1717번 집합의 표현 - 유니온 파인드

		endl 사용 시 시간초과
	*/

	int N; // 원소 개수
	int M; // 질의 개수

	cin >> N >> M;

	parent.resize(N + 1, 0);

	// 대표노드 초기화
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int A;
		int B;
		int C;

		cin >> A >> B >> C;

		if (A == 0)
		{
			Union(B, C);
		}
		else
		{
			if (checkSame(B, C))
			{
				cout << "YES" << "\n";
			}
			else
			{
				cout << "NO" << "\n";
			}
		}
	}
}

void Union(int x, int y)
{
	// 각 노드의 대표노드
	int findX = Find(x);
	int findY = Find(y);

	// 대표노드 즉, 집합이 다르다면
	if (findX != findY)
	{
		// 대표 노드의 값만 변경
		parent[findY] = findX;
	}
}

// 대표노드를 찾는 함수
int Find(int a)
{
	if (parent[a] == a)
	{
		return a;
	}
	else
	{
		return parent[a] = Find(parent[a]);
	}

}

bool checkSame(int a, int b)
{
	int findA = Find(a);
	int findB = Find(b);

	// 두 집합이 같다면 true
	if (findA == findB)
	{
		return true;
	}
	else
	{
		return false;
	}
}



