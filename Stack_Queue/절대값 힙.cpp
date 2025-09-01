#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// 11286번 문제 절대값 힙


// 사용자 정의 비교 타입
struct compare
{
	bool operator()(int a, int b)
	{
		int first_abs = abs(a);
		int second_abs = abs(b);

		// 두 절대값이 같다면 더 큰값이 우선순위가 낮다. 작은값이 우선순위 높다.
		if (first_abs == second_abs)
		{
			return a > b;
		}
		else // 절대값이 더 큰 값이 우선순위가 낮다. 절대값이 작은값이 우선순위 높다.
		{
			return first_abs > second_abs;
		}
	}
};

 
int main()
{
	// 1. 정수의 갯수 입력받기.
	// 2. 입력받은 정수가 0이라면 값을 추가하고, 0이라면 절대값이 가장 작은 값을 출력 후 제거 

	// 3. 우선순위 큐 priority_queue 사용

	// 4. 배열 내에서 절대값이 가장 작은 값을 출력하는 것이기 때문에 우선순위를
	//    정해서 정렬해둔다.

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, compare>p;

	int N = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;

		if (num == 0)
		{
			if (p.empty())
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << p.top() << '\n';
				p.pop();
			}
		}
		else
		{
			p.push(num);
		}
	}
}
