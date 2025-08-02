#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

// 1874번 문제 스택으로 수열 만들기

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	vector<int> A(N, 0); // 수열 저장
	vector<char> result; // 결과 저장 배열 (+ -)


	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	stack <int> mystack;
	int num = 1;

	for (int i = 0; i < A.size(); i++)
	{
		// 현재 입력받은 수열이 더 크다면
		if (A[i] >= num)
		{
			while (A[i] >= num)
			{
				mystack.push(num++);
				result.push_back('+');
			}
			mystack.pop();
			result.push_back('-');
		}
		else
		{
			// 스택의 가장 위의 값 pop
			int topnum = mystack.top();
			mystack.pop();

			if (topnum > A[i])
			{
				cout << "NO";
				return 0;
			}
			else
			{
				result.push_back('-');
			}
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << '\n';
	}

}


