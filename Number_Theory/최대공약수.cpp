#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>


using namespace std;

int GCD(long a, long b);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1850번 최대공약수


		수의 길이를 나타내는 A와 B의 최대 공약수는
		A와 B의 최대공약수 길이로 나타난다.
	*/

	long A;
	long B;

	cin >> A >> B;

	long result = GCD(A, B);

	for (int i = 0; i < result; i++)
	{
		cout << 1;
	}
}

int GCD(long a, long b)
{
	if (b == 0)
	{
		return a;
	}

	else
	{
		return GCD(b, a % b);
	}
}

