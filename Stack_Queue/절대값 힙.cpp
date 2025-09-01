#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// 11286�� ���� ���밪 ��


// ����� ���� �� Ÿ��
struct compare
{
	bool operator()(int a, int b)
	{
		int first_abs = abs(a);
		int second_abs = abs(b);

		// �� ���밪�� ���ٸ� �� ū���� �켱������ ����. �������� �켱���� ����.
		if (first_abs == second_abs)
		{
			return a > b;
		}
		else // ���밪�� �� ū ���� �켱������ ����. ���밪�� �������� �켱���� ����.
		{
			return first_abs > second_abs;
		}
	}
};

 
int main()
{
	// 1. ������ ���� �Է¹ޱ�.
	// 2. �Է¹��� ������ 0�̶�� ���� �߰��ϰ�, 0�̶�� ���밪�� ���� ���� ���� ��� �� ���� 

	// 3. �켱���� ť priority_queue ���

	// 4. �迭 ������ ���밪�� ���� ���� ���� ����ϴ� ���̱� ������ �켱������
	//    ���ؼ� �����صд�.

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
