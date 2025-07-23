#include <iostream>
#include <algorithm>
using namespace std;

/// <summary>
/// 슬라이딩 윈도우 - DNA 비밀번호
/// </summary>

int checkArr[4]; // 각 문자의 최소 요구 개수 배열
int myArr[4];    // 현재 상태 배열
int checkSecret = 0; // 최소 요구 수치 확인용

void Add(char& c) // 부분 문자열 추가 (A C G T)
{
    switch (c)
    {
    case 'A':
        myArr[0]++; // 들어온 문자열 카운팅 & 최소 요구 개수와 같다면 checkSecret++
        if (myArr[0] == checkArr[0])
        {
            checkSecret++;
        }
        break;

    case 'C':
        myArr[1]++;
        if (myArr[1] == checkArr[1])
        {
            checkSecret++;
        }
        break;

    case 'G':
        myArr[2]++;
        if (myArr[2] == checkArr[2])
        {
            checkSecret++;
        }
        break;

    case 'T':
        myArr[3]++;
        if (myArr[3] == checkArr[3])
        {
            checkSecret++;
        }
        break;
    }
}

void Remove(char& c) // 부분 문자열 제거 (A C G T)
{
    switch (c)
    {
    case 'A': // 최소 요구 개수와 같다면 checkSecret-- & 들어온 문자열 카운팅 감소
        if (myArr[0] == checkArr[0])
        {
            checkSecret--;
        }
        myArr[0]--;
        break;

    case 'C':
        if (myArr[1] == checkArr[1])
        {
            checkSecret--;
        }
        myArr[1]--;
        break;

    case 'G':
        if (myArr[2] == checkArr[2])
        {
            checkSecret--;
        }
        myArr[2]--;
        break;

    case 'T':
        if (myArr[3] == checkArr[3])
        {
            checkSecret--;
        }
        myArr[3]--;
        break;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int S; int P; // 문자열 & 부분 문자열 크기
    string A;     // 문자열 데이터
    int Result = 0;   // 결과값

    cin >> S >> P >> A;

    for (int i = 0; i < 4; i++)
    {
        cin >> checkArr[i];

        if (checkArr[i] == 0) // 최소 요구 개수가 0이라면 
        {
            checkSecret++;
        }
    }

    // 초기 부분 문자열을 하나씩 추가
    for (int i = 0; i < P; i++) Add(A[i]);

    // 슬라이딩 윈도우 시작
    for (int i = P; i < S; i++)
    {
        int j = i - P; // 제거 할 인덱스
        Remove(A[j]);
        Add(A[i]);

        if (checkSecret == 4)
        {
            Result++;
        }
    }

    cout << Result << "\n";
}


