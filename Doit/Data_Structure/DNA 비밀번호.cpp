#include <iostream>
#include <algorithm>
using namespace std;

/// <summary>
/// �����̵� ������ - DNA ��й�ȣ
/// </summary>

int checkArr[4]; // �� ������ �ּ� �䱸 ���� �迭
int myArr[4];    // ���� ���� �迭
int checkSecret = 0; // �ּ� �䱸 ��ġ Ȯ�ο�

void Add(char& c) // �κ� ���ڿ� �߰� (A C G T)
{
    switch (c)
    {
    case 'A':
        myArr[0]++; // ���� ���ڿ� ī���� & �ּ� �䱸 ������ ���ٸ� checkSecret++
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

void Remove(char& c) // �κ� ���ڿ� ���� (A C G T)
{
    switch (c)
    {
    case 'A': // �ּ� �䱸 ������ ���ٸ� checkSecret-- & ���� ���ڿ� ī���� ����
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


    int S; int P; // ���ڿ� & �κ� ���ڿ� ũ��
    string A;     // ���ڿ� ������
    int Result = 0;   // �����

    cin >> S >> P >> A;

    for (int i = 0; i < 4; i++)
    {
        cin >> checkArr[i];

        if (checkArr[i] == 0) // �ּ� �䱸 ������ 0�̶�� 
        {
            checkSecret++;
        }
    }

    // �ʱ� �κ� ���ڿ��� �ϳ��� �߰�
    for (int i = 0; i < P; i++) Add(A[i]);

    // �����̵� ������ ����
    for (int i = P; i < S; i++)
    {
        int j = i - P; // ���� �� �ε���
        Remove(A[j]);
        Add(A[i]);

        if (checkSecret == 4)
        {
            Result++;
        }
    }

    cout << Result << "\n";
}


