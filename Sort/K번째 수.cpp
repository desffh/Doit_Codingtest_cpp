#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 11004�� ���� k��° �� ���ϱ� 

void QuickSort(vector<int>& A, int start, int end, int k);
int Partition(vector<int>& A, int start, int end);
void swap(vector<int>& A, int i, int j);


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int K = 0;
	cin >> N >> K;
	vector<int>A(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	QuickSort(A, 0, N - 1, K - 1);
	cout << A[K - 1];
}

void QuickSort(vector<int>& A, int start, int end, int k)
{
	int pivot = Partition(A, start, end);

	if (pivot == k)
	{
		return;
	}
	else if (k < pivot)
	{
		QuickSort(A, start, pivot - 1, k);
	}
	else
	{
		QuickSort(A, pivot + 1, end, k);
	}
}

int Partition(vector<int>& A, int start, int end)
{
	// ���� 2�� ���̶�� ���ĸ� ����
	if (start + 1 == end)
	{
		if (A[start] > A[end])
		{
			swap(A, start, end);
		}
		return end;
	}

	int middle = (start + end) / 2;

	swap(A, start, middle); // �߾Ӱ��� 1��° ��ҷ� �̵� -> ��� ���ϰ� �ϱ� ����

	int pivot = A[start]; // pivot�� ���� ��ġ������ ����

	int i = start + 1;
	int j = end;

	while (i <= j)
	{
		while (pivot < A[j] && j > start)
		{
			j--;
		}
		while (pivot > A[i] && i <= end)
		{
			i++;
		}
		if (i <= j) // ��ġ�� �������ٸ�
		{
			swap(A, i++, j--);
		}
	}

	A[start] = A[j];
	A[j] = pivot;

	return j;
}

void swap(vector<int>& A, int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
