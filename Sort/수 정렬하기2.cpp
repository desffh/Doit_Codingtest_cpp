#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// 2751�� ���� �� �����ϱ�2 

void Merge(int start, int end); // ����
void MergeSort(int start, int end, int middle); // ����
static vector<int>A;   // ���� �迭
static vector<int>tmp; // �ӽ� �迭

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	A = vector<int>(N + 1, 0); // ���� �� [0]�ε����� �����ϰ� [1]���� �����Ѵ�.
	tmp = vector<int>(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	Merge(1, N);

	for (int i = 1; i <= N; i++)
	{
		cout << A[i] << '\n';
	}
}

void Merge(int start, int end)
{
	// �� �̻� �ɰ��� �� ���ٸ� return
	if (end - start < 1)
	{
		return;
	}

	int middle = (end + start) / 2; // == start + (end - start) / 2

	Merge(start, middle);
	Merge(middle + 1, end);

	MergeSort(start, end, middle);
}

void MergeSort(int start, int end, int middle)
{
	for (int i = start; i <= end; i++)
	{
		tmp[i] = A[i];
	}

	int k = start; // A�迭�� �ֱ����� ��ġ
	int index1 = start;
	int index2 = middle + 1;

	// ���� ���Ͽ� ���� �迭 A�� �־��ֱ� -> �������� �����̶� �� ���� ���� A�迭�� �ִ´�.
	while (index1 <= middle && index2 <= end)
	{
		if (tmp[index1] > tmp[index2])
		{
			A[k++] = tmp[index2++];
		}
		else
		{
			A[k++] = tmp[index1++];
		}
	}

	// ���� ���� ���� �����ϱ�

	while (index1 <= middle)
	{
		A[k++] = tmp[index1++];
	}
	while (index2 <= end)
	{
		A[k++] = tmp[index2++];
	}
}