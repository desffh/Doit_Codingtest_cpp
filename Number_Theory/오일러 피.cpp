#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		11689번 오일러 피 함수 구현하기

		입력받는 n의 최대 범위는 10^12
	*/

	long n; // 소인수 표현
	cin >> n;

	long result = n; // 결과값 = 서로소 후보 갯수


	for (int i = 2; i <= sqrt(n); i++)
	{
		// 현재 i값이 소인수라면 나누어 떨어짐 
		if (n % i == 0)
		{
			// 후보 갯수 줄이기
			result -= result / i;

			// n안에 들어있는 소인수i를 모두 제거
			while (n % i == 0)
			{
				n /= i;
			}
		}
	}

	// 제곱근까지만 탐색하기 때문에 소인수 누락 가능성이 있다.
	// n이 소수라면 for문을 다 통과해도 나누어지지 않고 남아있다.
	if (n > 1)
	{
		result -= result / n;
	}

	cout << result << "\n";
}
