#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

bool isPalindrome(int target)
{
	string str = to_string(target);

	char const* temp = str.c_str();

	int s = 0; // 시작 
	int e = str.size() - 1; // 끝

	while (s < e)
	{
		// 하나라도 다르면 팰린드롬이 아니다
		if (temp[s] != temp[e])
		{
			return false;
		}

		s++;
		e--;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1747번 소수 & 팰린드롬 수 중에서 최솟값 찾기
	*/

	long N;
	long A[10000001];

	cin >> N;

	for (int i = 2; i < 10000001; i++)
	{
		A[i] = i;
	}

	for (int i = 2; i <= sqrt(10000001); i++)
	{
		if (A[i] == 0)
		{
			continue;
		}

		// 소수의 배수 제거
		for (int j = i + i; j < 10000001; j += i)
		{
			A[j] = 0;
		}
	}

	long i = N; // 범위 N부터 팰린드롬 찾기 시작

	while (true)
	{
		// 소수라면
		if (A[i] != 0)
		{
			int result = A[i];

			// 팰린드롬이라면
			if (isPalindrome(result))
			{
				cout << result << endl;
				break;
			}
		}
		// 팰린드롬이 아니라면 다음 소수 확인
		i++;
	}

}

