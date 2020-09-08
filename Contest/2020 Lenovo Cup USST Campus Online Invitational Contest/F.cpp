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

int k;
bool not_pri[1000010];
vector<long long> pri;

void euler_sieve(int lim)
{
    for (int i=2;i<=lim;i++)
    {
        if (!not_pri[i]) pri.push_back(i);
        for (int j:pri)
        {
            if ((long long)i*j>lim) break;
            not_pri[i*j]=true;
            if (i%j==0) break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    euler_sieve(100000);
    cin>>k;
    cout<<(k+1)*(k+1)<<' '<<k+1<<'\n';
    for (int i=0;i<=k;i++)
    {
        if (i<k)
        {
            for (int j=0;j<=k;j++)
            {
                long long now=1;
                for (int t=0;t<=i;t++)
                {
                    now*=pri[j+t*(k+1)];
                }
                cout<<now<<' ';
            }   
        }
        else
        {
            for (int j=0;j<=k;j++)
            {
                cout<<pri[j]*pri[1000]<<' ';
            }
        }
    }
    cout<<'\n';
    for (int i=0;i<=k;i++)
    {
        for (int j=0;j<=k;j++)
        {
            cout<<(i+j)%(k+1)+1<<' ';
        }
    }
    getchar(); getchar();
    return 0;
}