#include <bits/stdc++.h>
//#include <bits/extc++.h>

using namespace std;
//using namespace __gnu_pbds;

const int maxn = 1e6 + 7;
const int maxm = 1e7 + 7;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const long long mod = 998244353;
const double pi = acos(-1.0);

int T;
int n;
int fa[maxn], depth[maxn], sz[maxn];
long long sum[maxn];
vector<int> G[maxn];

void dfs(int cur, int pre) {
    depth[cur] = depth[pre] + 1;
    sz[cur] = 1;
    for (int x:G[cur]) {
        dfs(x, cur);
        sz[cur] += sz[x];
    }
}

void calc(int cur, int pre) {
    sum[cur] = sum[pre] + sz[cur];
    for (int x:G[cur]) {
        calc(x, cur);
    }
}

void init() {
    for (int i = 0; i <= n + 5; i++) {
        fa[i] = 0;
        depth[i] = 0;
        sz[i] = 0;
        sum[i] = 0;
        G[i].clear();
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        init();
        for (int i = 2; i <= n; i++) {
            int pre;
            scanf("%d", &pre);
            fa[i] = pre;
            G[pre].push_back(i);
        }
        dfs(1, 0);
        calc(1, 0);
        long long ans = 0, res = 0;
        for (int i = 1; i <= n; i++) {
            res += sz[i];
        }

        for (int i = 1; i <= n; i++) {
            ans = max(ans, res + 1ll * depth[i] * n - sum[i]);
        }
        /*
        for (int i = 1; i <= n; i++) {
            cout << sz[i] << " ";
        }
        cout << endl;
        for (int i = 1; i <= n; i++) {
            cout << sum[i] << " ";
        }
        cout << endl;
         */
        printf("%lld\n", ans);
    }
    return 0;
}