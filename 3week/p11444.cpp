#include <iostream>

using namespace std;

const long long mod = 1000000007;

void multiply(long long int a[2][2], long long int b[2][2], long long int ans[2][2])
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            long long int save = 0;
            for(int k = 0; k < 2; k++)
                save += (a[i][k] * b[k][j]);
            ans[i][j] = save % mod;
        }
    }
}

void copyArr(long long int a[2][2], long long int b[2][2])
{
    for(int i = 0; i < 2; i++)
    {
        for(int k = 0; k < 2; k++)
        {
            b[i][k] = a[i][k];
        }
    }
}

void conq(long long int a[2][2], long long int tmp[2][2], long long int ans[2][2], long long int n)
{
    if (n == 1)
    {
        copyArr(a,ans);
        return;
    }

    conq(a,tmp,ans,n/2);

    copyArr(ans, tmp);
    multiply(tmp,tmp,ans);

    if(n % 2 == 1)
    {
        copyArr(ans, tmp);
        multiply(tmp,a,ans);
    }

    copyArr(ans, tmp);
}

int main()
{
    long long int n;
    cin >> n;

    long long int A[2][2] = {{1,1},{1,0}}, tmp[2][2], ans[2][2];
    fill(tmp[0],tmp[0] + 4, 1);

    conq(A,tmp,ans,n);

    cout << ans[0][1] << endl;

    return 0;
}