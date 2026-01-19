#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<vector<int>> A; // 인접 리스트
vector<int> indegree;  // 진입 차수 배열

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		2252번 줄 세우기 - 위상정렬

		사이클X 방향 그래프에서 사용가능하다.

		위상 정렬 특성 상 결과값이 항상 유일하지 않다.
	 => 답이 여러가지면 아무거나 출력
	*/

	int N; // 학생 수
	int M; // 비교 횟수

	cin >> N >> M;

	A.resize(N + 1);
	indegree.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int num1;
		int num2;

		cin >> num1 >> num2;

		// 방향 그래프
		A[num1].push_back(num2);

		// 진입 차수 데이터 저장
		indegree[num2]++;
	}

	queue<int> queue;

	for (int i = 1; i <= N; i++)
	{
		// 진입차수가 0인 노드 삽입
		if (indegree[i] == 0)
		{
			queue.push(i);
		}
	}

	while (!queue.empty())
	{
		int temp = queue.front();

		cout << temp << " ";

		queue.pop();

		for (int i = 0; i < A[temp].size(); i++)
		{
			// 연결된 노드의 진입 차수 감소
			indegree[A[temp][i]]--;

			// 진입 차수가 0이라면 노드 추가
			if (indegree[A[temp][i]] == 0)
			{
				queue.push(A[temp][i]);
			}
		}
	}
}
