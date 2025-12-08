#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>


using namespace std;

int GCD(int a, int b);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1934번 최소공배수

		최소공배수(LCM) = A * B / 최대공약수(GCD)

		최대공약수는 유클리드 호제법을 사용한다.
	*/

	int t; // 테스트 케이스

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int A;
		int B;

		cin >> A >> B;

		int result = (A * B) / GCD(A, B);

		cout << result << "\n";
	}
}

int GCD(int a, int b)
{
	// 두번째 수가 0이라면 (더 작은수가 0이라면)
	if (b == 0)
	{
		return a;
	}

	else
	{
		return GCD(b, a % b);
	}
}
