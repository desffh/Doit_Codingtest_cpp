#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 11399�� ���� ATM���� �ð� ����ϱ�

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �� ����� ���� �����ϴ� �� �ʿ��� �ð��� ���� �ּڰ��� �ð��� �������� �����϶���.
	// 1. �������� ����
	// 2. �չ迭 �����
	// 3. �� ���


	int sum = 0;
	int N = 0;

	cin >> N;

	vector<int>A(N, 0); // ATM �ð� �迭

	vector<int>S(N, 0); // �� �迭

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	// [���� ����]
	for (int i = 1; i < N; i++)
	{
		int insert_pos = i;      // ���� ��ġ
		int insert_value = A[i]; // ���� ��


		// �������� �����̱� ������ ���� ���԰��� ���ĵ� ������ ������ ũ�ٸ� 
		// ���� ��ġ�� [j + 1]�� ����

		for (int j = i - 1; j >= 0; j--)
		{
			if (A[j] < A[i])
			{
				insert_pos = j + 1;
				break;
			}
			if (j == 0) // ���� ���԰��� �۾Ƽ� j == 0���� �����ߴٸ� ���� ��ġ�� [0]
			{
				insert_pos = 0;
			}
		}

		// ���� ��ġ�� �պκ� ������ �����Ѵ�.

		for (int j = i; j > insert_pos; j--)
		{
			A[j] = A[j - 1];
		}
		A[insert_pos] = insert_value;
	}

	S[0] = A[0];

	// �� �迭 ����
	for (int i = 1; i < N; i++)
	{
		S[i] = S[i - 1] + A[i];
	}

	for (int s : S)
	{
		sum += s;
	}

	cout << sum;
}