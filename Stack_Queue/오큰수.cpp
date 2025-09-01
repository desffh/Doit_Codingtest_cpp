#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

// 17298번 문제 오큰수 구하기

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; // 수열 개수

	cin >> N;

	vector <int> A(N, 0);  // 크기가 N인 수열 배열
	vector <int> ans(N, 0);// 크기가 N인 정답 배열

	stack<int> idxStack;   // 인덱스를 담음 
	idxStack.push(0);

	// 수열 배열 입력받기
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 1; i < N; i++)
	{
		// 스택이 비지 않았고, 들어오는 값이 top보다 크다면 반복
		// -> 여러 인덱스가 동일한 오큰수를 가질 수 있기 때문이다.
		while (!idxStack.empty() && A[idxStack.top()] < A[i])
		{
			// top 인덱스에 오큰수 A[i] 저장
			ans[idxStack.top()] = A[i];

			idxStack.pop();
		}
		idxStack.push(i);
	}

	// 위의 반복문을 다 돌았는데도 스택에 원소가 남았다면
	while (!idxStack.empty())
	{
		ans[idxStack.top()] = -1;
		idxStack.pop();
	}

	// 정답 배열 출력
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
}