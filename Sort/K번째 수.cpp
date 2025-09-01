#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 11004번 문제 k번째 수 구하기 

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
	// 값이 2개 뿐이라면 정렬만 진행
	if (start + 1 == end)
	{
		if (A[start] > A[end])
		{
			swap(A, start, end);
		}
		return end;
	}

	int middle = (start + end) / 2;

	swap(A, start, middle); // 중앙값을 1번째 요소로 이동 -> 계산 편하게 하기 위함

	int pivot = A[start]; // pivot을 시작 위치값으로 지정

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
		if (i <= j) // 위치가 같아졌다면
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
