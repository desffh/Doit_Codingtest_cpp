#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void DFS(int num, int digits);

bool IsPrime(int num); // 소수 판별

static int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		2023번 신기한 소수
	*/

	cin >> N;

	// 1의 자리 숫자 DFS 실행
	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);
}

void DFS(int num, int digits)
{
	if (digits == N)
	{
		if (IsPrime(num))
		{
			cout << num << '\n';
		}
		return;
	}

	// 일의 자리가 1~9 / 홀수면서 소수라면 DFS 실행
	for (int i = 1; i <= 9; i++)
	{
		if (i % 2 != 0 && IsPrime(num * 10 + i))
		{
			DFS(num * 10 + i, digits + 1);
		}
	}
}

bool IsPrime(int num)
{
	for (int i = 2; i <= num / 2; i++)
	{
		// 소수는 1과 자기자신만 포함. 
		// 2부터 절대값num까지 나눴을때 나누어 떨어지면 소수x
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}