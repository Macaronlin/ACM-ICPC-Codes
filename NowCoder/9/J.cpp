#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 500 + 7;
const int maxm = 1e7 + 7;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const long long mod = 998244353;
const double pi = acos(-1.0);

int n, m;
int pic[maxn][maxn];
int pre[maxn][maxn];
long long ans;
int _cnt[2000000];
int *cnt = _cnt + 1000000;
vector<int> v;

void clear() {
    for (int x:v) {
        cnt[x]--;
    }
    v.clear();
}

void solve(int l, int r) {
    clear();
    //memset(cnt, 0, sizeof(cnt));
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        int val = pre[r - 1][i] - pre[l][i];
        //cout << val << " ";
        if ((!pic[l][i]) || (!pic[r][i])) {
            //memset(cnt, 0, sizeof(cnt));
            clear();
        } else {
            if (pre[r][i] - pre[l - 1][i] == r - l + 1) {
                for (int k = -1; k <= 1; k++) {
                    ans += cnt[sum + k];
                }
                cnt[sum + val]++;
                v.push_back(sum + val);
            }
        }
        sum += val;
    }
    clear();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &pic[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pre[i][j] = pre[i - 1][j] + (pic[i][j] ? 1 : -1);
        }
    }
    for (int up = 1; up <= n; up++) {
        for (int down = up + 1; down <= n; down++) {
            solve(up, down);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
