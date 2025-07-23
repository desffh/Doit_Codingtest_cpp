#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

typedef pair<int, int> Node; // ��� ��

/// <summary>
/// �����̵� ������ - �ּڰ� ã�� 1
/// </summary>

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque <Node> mydeque; // ���� ���� �ε��� ����
	int N; int L;         // ������ ����, �ּڰ��� ���ϴ� ����

	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		int now; // ���� �Է¹��� ��
		cin >> now;

		// ���� ���� ������ ���� ������ ũ�ٸ�
		while (mydeque.size() && mydeque.back().first > now)
		{
			mydeque.pop_back(); // ����
		}

		mydeque.push_back(Node(now, i)); // ���� & �ε���

		// �� ó�� �ε��� ���� i - L���� �۰ų� ���ٸ� (������ ���� �ʰ�)
		if (mydeque.front().second <= i - L)
		{
			mydeque.pop_front();
		}

		// ���� ù��° ���� ���
		cout << mydeque.front().first << " ";
	}
}


