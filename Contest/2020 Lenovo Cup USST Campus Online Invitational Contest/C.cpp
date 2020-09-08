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

const int N=1010;

int n,m;
string s[N];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>s[i];
    sort(s+1,s+m+1,[&](string a,string b){if (a.size()==b.size()) return a<b; return a.size()<b.size();});
    m=unique(s+1,s+m+1)-(s+1);
    int now=0,ans=0;
    for (int i=1;i<=m;i++)
    {
        if (now+(int)s[i].size()>n) break;
        now+=s[i].size()+1;
        ans++;
    }
    cout<<ans;
    getchar(); getchar();
    return 0;
}