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
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;

const int N=1000010;

int n;
int a[N],ans[N],cnt[N];
vector<int> p;

int read_int()
{
    char c=0; int re=0;
    while (!isdigit(c)) c=getchar();
    while (isdigit(c)) {re=re*10+c-'0'; c=getchar();}
    return re;
}

bool work(int x)
{
    int p=ans[x];
    int q=0;
    if (ans[x]!=x) q=x;
    else q=(x==n?1:x+1);
    if (a[p]*(cnt[q]+1)<a[q]*cnt[p])
    {
        cnt[p]--;
        cnt[q]++;
        ans[x]=q;
        return true;
    }
    return false;
}

bool check()
{
    for (int i=1;i<=n;i++)
    {
        if (work(i)) return true;
    }
    return false;
}

void print(int x)
{
    if (!x) return;
    print(x/10);
    putchar('0'+x%10);
}

int main()
{
    //ios::sync_with_stdio(0); cin.tie(0);
    mt19937 myrand(time(0));
    n=read_int();
    for (int i=1;i<=n;i++) a[i]=read_int();
    for (int i=1;i<=n;i++)
    {
        int j=(i==n?1:i+1);
        if (a[i]>a[j]+a[j])
        {
            ans[i]=i;
            cnt[i]++;
        }
        else if (a[j]>a[i]+a[i])
        {
            ans[i]=j;
            cnt[j]++;
        }
        else if (a[j] > a[i]) {
            ans[i]=j;
            cnt[j]++;
            p.push_back(i);
        }
        else {
            ans[i]=i;
            cnt[i]++;
            p.push_back(i);
        }
    }
    while (check())
    {
        //shuffle(p.begin(),p.end(),myrand);
        for (int i:p) work(i);
    }
    for (int i=1;i<=n;i++)
    {
        print(ans[i]);
        if (i<n) putchar(' ');
    }
    getchar(); getchar();
    return 0;
}