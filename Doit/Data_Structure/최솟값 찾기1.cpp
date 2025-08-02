#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

typedef pair<int, int> Node; // <����, �ε���>

/// <summary>
/// �����̵� ������ - �ּڰ� ã�� 1
/// </summary>

int main()
{
	// ���� �ð� 2.4�� -> 2.4 x 10^8

	// N�� �ִ밡 5 x 10^6 �̶� �ִ� O(N)�ۿ� ����� �� ����.
	// -> ����(NlogN)�� ����� �� ���� ��.
	// -> deque�� ����Ͽ� ������ ������ �� �ִ�.

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int L = 0;

	cin >> N >> L;

	deque <Node> mydeque;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		// ���� ���� �� ���� ������ ���� �� ũ�ٸ� ����
		while (mydeque.size() && mydeque.back().first > temp)
		{
			mydeque.pop_back();
		}

		mydeque.push_back(Node(temp, i));

		// �������� ������ ����ٸ�
		if (mydeque.back().second - L >= mydeque.front().second)
		{
			mydeque.pop_front();
		}

		// �ּҰ� ���
		cout << mydeque.front().first << " ";
	}
}


