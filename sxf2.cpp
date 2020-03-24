# include <iostream>
# include <list>
using namespace std;

int getSum(int A[], int len,int j)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (i == j) continue;
        sum += A[i];
    }
    return sum;
}

bool foo(int A[], int len, int curSum, int defSum, int B[], int curPos)
{
    if (curSum == defSum)
    {
        return true;
    }

    if (len == 0)
        return false;

    bool bFound = false;
    for (int i = 0; i < len; i++)
    {
        if (curSum + A[i] <= defSum)
        {
            B[curPos++] = A[i];
            if (foo(&A[i+1], len - 1, curSum + A[i], defSum, B, curPos))
            {
                bFound = true;
                break;
            }
            B[curPos] = 0;
            curPos--;
        }
    }

    return bFound;
}

int main()
{
    int Array[1000]; 
    int n,m;
    while (cin >> n >> m)
    {
        int length = n + 1;
        for (int i = 0; i < length; i++)
        {
            cin >> Array[i];
        }
        int j;
        for(j = 0; j < length; j ++){
        int B[500];
        int sum = getSum(Array, length, j);
        if (sum % 3 == 0)
        {
            bool JudgeSuccess = foo(Array, length, 0, sum / 3, B, 0);
            if (JudgeSuccess)
            {cout << Array[j] << endl;
                 break;}
        
        }
        else
        {cout << "NO" << endl;
         break;}
    }
        if (j == length)
            cout << "NO" << endl;
    }
return 0;
}
