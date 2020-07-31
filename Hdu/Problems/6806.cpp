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

const int N=100010;
const long long M=1000000007;

int T,n;
string s[N];
bool flag[N];
long long dp[N][2];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>T;
    while (T--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            cin>>s[i];
            if (s[i]==s[i-1]) flag[i]=true;
            else flag[i]=false;
        }
        dp[0][0]=1; dp[0][1]=0;
        dp[1][0]=1; dp[1][1]=0;
        for (int i=2;i<=n;i++)
        {
            if (flag[i])
            {
                dp[i][0]=(dp[i-1][0]+dp[i-1][1])%M;
                dp[i][1]=0;
            }
            else
            {
                dp[i][0]=(dp[i-1][0]+dp[i-1][1])%M;
                dp[i][1]=(dp[i-2][0]+dp[i-2][1])%M;
            }
        }
        cout<<(dp[n][0]+dp[n][1])%M<<'\n';
    }
    getchar(); getchar();
    return 0;
}