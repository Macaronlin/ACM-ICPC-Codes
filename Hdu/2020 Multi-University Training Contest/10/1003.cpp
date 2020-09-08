#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <cmath>
using namespace std;

int T,n;
char s[30][30];

void print_ans(int n,int m)
{
    cout<<n<<' '<<m<<'\n';
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cout<<s[i][j];
        }
        cout<<'\n';
    }
}

void get_ans(int x,int y)
{
    for (int i=1;i<=25;i++)
    {
        for (int j=1;j<=25;j++)
        {
            s[i][j]='.';
        }
    }
    int cnt1=0,cnt3=0;
    if (y==1) cnt1=1;
    else if (y==2) cnt1=2;
    else if (y==3) cnt3=1;
    else if (y==4) cnt1=1,cnt3=1;
    else if (y==5) cnt1=2,cnt3=1;
    else if (y==6) cnt3=2;
    else if (y==7) cnt1=1,cnt3=2;
    if (cnt1+cnt3>=1) s[1][1]='X';
    if (cnt1+cnt3>=2) s[1][25]='X';
    if (cnt1+cnt3>=3) s[25][25]='X';
    if (cnt1>=1) s[2][2]='X',x--;
    if (cnt1>=2) s[2][24]='X',x--;
    for (int i=4;i<=24;i+=2)
    {
        for (int j=2;j<=24;j+=2)
        {
            if (!x) break;
            s[i][j]='X';
            x--;
        }
        if (!x) break;
    }
}

int main()
{
    //ios::sync_with_stdio(0); cin.tie(0);
    freopen("1003.out", "w", stdout);
    for (int n = 0; n <= 1000; n++) {
        if (n<=24)
        {
            for (int i=1;i<=25;i++)
            {
                if (i&1) s[1][i]='.';
                else s[1][i]='X';
            }
            print_ans(1,n+1);
        }
        else
        {
            get_ans(n/8,n%8);
            print_ans(25,25);
        }
    }
    getchar(); getchar();
    return 0;
}
