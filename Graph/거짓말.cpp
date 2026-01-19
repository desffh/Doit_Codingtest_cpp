#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector<int> trueP; // 진실을 아는 사람 데이터
vector<vector<int>> party; // 파티 데이터
vector<int> parent;// 대표 노드 저장 배열

void Union(int a, int b);
int Find(int a);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1043번 거짓말 - 유니온파인드

		진실을 아는 사람과 그 파티의 사람들이 같은 집합이 아닐 경우에만
		과장된 이야기가 가능하다. (대표 노드가 다를 경우)
	*/

	int N; // 사람의 수
	int M; // 파티의 수
	int T; // 진실을 아는 사람 수

	cin >> N >> M >> T;

	parent.resize(N + 1);
	trueP.resize(T);
	party.resize(M);

	for (int i = 0; i < T; i++)
	{
		cin >> trueP[i];
	}


	// 대표 노드 초기화
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	// 파티 데이터 세팅
	for (int i = 0; i < M; i++)
	{
		int partySize;
		cin >> partySize;

		for (int j = 0; j < partySize; j++)
		{
			int temp;
			cin >> temp;

			party[i].push_back(temp);
		}
	}

	for (int i = 0; i < M; i++)
	{
		int firstPeople = party[i][0];

		// 각 파티별로 Union 진행
		for (int j = 1; j < party[i].size(); j++)
		{
			Union(firstPeople, party[i][j]);
		}
	}

	int count = 0; // 과장을 할 수 있는 횟수

	// 모든 파티에서 과장을 할 수 있는 횟수 카운팅
	for (int i = 0; i < M; i++)
	{
		bool isPossible = true;
		int index = party[i][0];

		for (int i = 0; i < T; i++)
		{
			// 대표노드가 같다면 -> 과장 불가
			if (Find(trueP[i]) == Find(index))
			{
				isPossible = false;
				break;
			}
		}

		// 대표노드가 같지 않았다면 과장 가능 count++
		if (isPossible == true)
		{
			count++;
		}
	}

	cout << count << endl;
}

void Union(int a, int b)
{
	int findA = Find(a);
	int findB = Find(b);

	if (findA != findB)
	{
		parent[findB] = findA;
	}
}

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

