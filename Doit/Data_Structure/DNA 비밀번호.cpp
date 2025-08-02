#include <iostream>
#include <algorithm>
using namespace std;

/// <summary>
/// �����̵� ������ - DNA ��й�ȣ
/// </summary>

int checkarr[4]; // üũ �迭 (A C G T)
int myarr[4];    // ���� �迭 (A C G T)
int checkcount = 0; // �κ� ���ڿ��� �ּҰ����� �����ϴ� �� Ȯ���ϴ� ����

// ���ڿ� �߰��ϱ�
void Add(char& a)
{
	switch (a)
	{
	case 'A': // ���� ���ڿ� ī���� & �ּ� �䱸 ������ ���ٸ� checkcount++
		myarr[0]++;
		if (myarr[0] == checkarr[0])
		{
			checkcount++;
		}
		break;
	case 'C':
		myarr[1]++;
		if (myarr[1] == checkarr[1])
		{
			checkcount++;
		}
		break;
	case 'G':
		myarr[2]++;
		if (myarr[2] == checkarr[2])
		{
			checkcount++;
		}
		break;
	case 'T':
		myarr[3]++;
		if (myarr[3] == checkarr[3])
		{
			checkcount++;
		}
		break;
	}
}

// ���ڿ� �����ϱ�
void Remove(char& a)
{
	switch (a)
	{
	case 'A':
		if (myarr[0] == checkarr[0])
		{
			checkcount--;
		}
		myarr[0]--;
		break;
	case 'C':
		if (myarr[1] == checkarr[1])
		{
			checkcount--;
		}
		myarr[1]--;
		break;
	case 'G':
		if (myarr[2] == checkarr[2])
		{
			checkcount--;
		}
		myarr[2]--;
		break;
	case 'T':
		if (myarr[3] == checkarr[3])
		{
			checkcount--;
		}
		myarr[3]--;
		break;
	}
}


int main()
{
	// ���� �ð� 2�� = 2 x 10^8
	// ���ڿ��� �κ� ���ڿ� ���� �ִ� 10^6
	// [���� �ð� ���⵵ -> O(N) ���Ϸ� ����

	// [�����̵� ������]
	// - �κ� ���ڿ��� �̵��� �� ���� �տ� ���Ҵ� �����ϰ� ���� ���Ҵ� �߰��ؾ���.
	// - ��ȿ�� ��й�ȣ�� �˻��� �� ���� �˻� ����� ���� ���� ���ڿ�
	// ���ŵǴ� ���ڿ��� �ݿ��Ͽ� Ȯ���ϴ� ���� �ٽ��̴�.

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S = 0;
	int P = 0;
	string A; // �Է¹��� ���ڿ�
	int Result = 0;

	cin >> S >> P >> A;

	// üũ �迭 �Է¹ޱ�
	for (int i = 0; i < 4; i++)
	{
		cin >> checkarr[i];

		if (checkarr[i] == 0)
		{
			checkcount++;
		}
	}

	// �ʱ� P�迭 ����
	for (int i = 0; i < P; i++)
	{
		// ���ڿ��� P�迭 ũ�⸸ŭ myarr�� �߰�
		Add(A[i]);
	}

	// �ּ� ������ �����Ѵٸ� -> 4�� A C G T ������ �ǹ�
	if (checkcount == 4)
	{
		Result++;
	}

	// �����̵� ������
	for (int i = P; i < S; i++)
	{
		int add = i;
		int remove = i - P;

		Add(A[add]);
		Remove(A[remove]);

		if (checkcount == 4)
		{
			Result++;
		}
	}

	cout << Result << '\n';
}


