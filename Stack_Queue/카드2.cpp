#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// 2164번 카드2 (queue)

int main()
{
	int N = 0;

	cin >> N;

	queue<int> myQueue;

	// 1부터 N까지의 수 차례로 넣기
	for (int i = 1; i <= N; i++)
	{
		myQueue.push(i);
	}

	// 제일 마지막 카드 1장이 남을 때 까지
	while (myQueue.size() > 1)
	{
		// 가장 처음 카드 버리기
		myQueue.pop();

		int topNum = myQueue.front();

		// 제일 앞의 카드를 제일 뒤로 옮기기
		myQueue.push(topNum);

		// 제일 앞의 카드는 뒤로 옮겼으니 삭제
		myQueue.pop();
	}

	cout << myQueue.front();
}


