#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// 2164�� ī��2 (queue)

int main()
{
	int N = 0;

	cin >> N;

	queue<int> myQueue;

	// 1���� N������ �� ���ʷ� �ֱ�
	for (int i = 1; i <= N; i++)
	{
		myQueue.push(i);
	}

	// ���� ������ ī�� 1���� ���� �� ����
	while (myQueue.size() > 1)
	{
		// ���� ó�� ī�� ������
		myQueue.pop();

		int topNum = myQueue.front();

		// ���� ���� ī�带 ���� �ڷ� �ű��
		myQueue.push(topNum);

		// ���� ���� ī��� �ڷ� �Ű����� ����
		myQueue.pop();
	}

	cout << myQueue.front();
}


