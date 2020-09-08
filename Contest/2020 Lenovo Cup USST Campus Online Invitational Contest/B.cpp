#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 1e6 + 7;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const int mod = 998244353;

int n;
double ans = llINF;

double dis(long long x,long long y,long long z){
	return sqrt(x*x+y*y+z*z);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		long long x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		ans = min(ans,dis(x,y,z));
	}
	printf("%.3lf\n",ans);
	return 0;
}
