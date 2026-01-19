#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<vector<int>> A; // 인접 리스트
vector<int> indegree;  // 진입 차수 배열
vector<int> selfBuild; // 건물 짓는 시간 배열 
vector<int> result;    // 결과 배열

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1516번 게임 개발 - 위상 정렬

		선행 -> 후행 구분

	*/

	int N; // 건물 종류

	cin >> N;

	A.resize(N + 1);
	indegree.resize(N + 1);
	selfBuild.resize(N + 1);
	result.resize(N + 1);

	// 인접 리스트 저장
	for (int i = 1; i <= N; i++)
	{
		cin >> selfBuild[i];

		while (true)
		{
			int temp;

			cin >> temp;

			if (temp == -1)
			{
				break;
			}

			// temp건물 짓기전에 i건물 먼저 지어야함.
			A[temp].push_back(i);
			indegree[i]++;
		}
	}

	queue<int>queue;

	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			queue.push(i);
		}
	}

	// 위상정렬 수행
	while (!queue.empty())
	{
		int temp = queue.front();

		queue.pop();

		for (int element : A[temp])
		{
			// 진입차수 감소
			indegree[element]--;

			// 건물을 짓기 시작 전까지 기다려야 하는 선행 건물들의 총 시간 
			result[element] = max(result[element], result[temp] + selfBuild[temp]);

			if (indegree[element] == 0)
			{
				queue.push(element);
			}
		}
	}

	// 결과 출력
	for (int i = 1; i <= N; i++)
	{
		cout << result[i] + selfBuild[i] << endl;
	}
}


