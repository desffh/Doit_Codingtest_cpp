#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1744번 수를 묶어서 최댓값 만들기
	*/

	int N; // 수열의 크기

	cin >> N;

	priority_queue<int, vector<int>, less<int>> A; // 양수 저장 - 내림차순
	priority_queue<int, vector<int>, greater<int>> B; // 음수 저장 - 오름차순
	int one = 0; // 1의 개수
	int zero = 0; // 0의 개수
	int result = 0;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		// 종류별로 입력받기

		if (num == 0) // 0이라면
		{
			zero++;
		}
		else if (num == 1) // 1이라면
		{
			one++;
		}
		else if (num > 1) // 양수라면
		{
			A.push(num);
		}
		else if (num < 0) // 음수라면
		{
			B.push(num);
		}
	}

	// 양수
	while (A.size() > 1)
	{
		int num1 = A.top();
		A.pop();
		int num2 = A.top();
		A.pop();

		result += num1 * num2;
	}

	// 양수에 데이터가 남아있다면 
	if (A.size() >= 1)
	{
		result += A.top();
	}

	// 음수
	while (B.size() > 1)
	{
		int num1 = B.top();
		B.pop();
		int num2 = B.top();
		B.pop();

		result += num1 * num2;
	}

	// 음수에 데이터가 남아있다면 
	if (B.size() >= 1)
	{
		// 0이 하나도 없다면 그대로 더하기
		if (zero == 0)
		{
			result += B.top();
		}
		// 0이 있다면 B.top() * 0 == 0 이기 때문에 아무것도 더하지 않는다.
	}

	result += one;

	cout << result << '\n';
}
