#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

// ���ڿ��� char a�������� �ڸ��� �ڸ� ���ڿ��� ������ ���͹迭�� ��ȯ
vector<string> Split(string str, char a)
{
	vector<string> A;

	stringstream stream(str); // ��Ʈ������ ��ȯ
	string words;
	while (getline(stream, words, a))
	{
		A.push_back(words);
	}

	return A;
}

// ��ȣ ���� �հ�
int mySum(string s)
{
	int sum = 0;

	vector<string> B = Split(s, '+');

	for (int i = 0; i < B.size(); i++)
	{
		sum += stoi(B[i]);
	}
	return sum;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1541�� - �ּڰ��� ����� ��ȣ ��ġ ã��

		���� �ּҷ� ����� ���ؼ��� ū ���� ���� �ȴ�.
		-> ��, + ������ ��� �� �� - ������ �ϸ� Ŀ�ٶ� ������ ���� �Ǿ� �ּҰ� �ȴ�.
	*/

	int answer = 0;
	string str = "";

	cin >> str;

	vector<string> strA = Split(str, '-');

	for (int i = 0; i < strA.size(); i++)
	{
		int result = mySum(strA[i]);

		// ���� ���� ���� ���� ���
		if (i == 0)
		{
			answer += result;
		}
		else
		{
			answer -= result;
		}
	}

	cout << answer << '\n';
}
