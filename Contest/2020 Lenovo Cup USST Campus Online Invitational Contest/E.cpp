#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 4e5 + 7;
const int maxm = 1e6 + 7;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const long long mod = 998244353;
const double pi = acos(-1.0);

int n;
int s[maxn];
long long p[10][10], inv[10][10];//(i->j)对
long long cnt[10];
long long c[10][10];
vector<int> v;
long long ans = llINF;

long long my_hash(vector<int> original) {
    long long res = 0;
    for (int x:original) {
        res = res * 10 + x;
    }
    return res;
}

vector<int> convert(long long val) {
    vector<int> res;
    res.clear();
    while (val) {
        res.push_back(val % 10);
        val /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

map<long long, long long> dis;
map<long long, bool> vis;
std::priority_queue<pair<long long, long long> > Q;

void Dijkstra() {
    vector<int> tmp;
    tmp.clear();
    for (int i = 1; i <= 8; i++) {
        tmp.push_back(i);
    }
    do {
        dis[my_hash(tmp)] = 1e18;
        vis[my_hash(tmp)] = false;
    } while (next_permutation(tmp.begin(), tmp.end()));
    tmp.clear();
    for (int i = 1; i <= 8; i++) {
        tmp.push_back(i);
    }
    dis[my_hash(tmp)] = 0;
    Q.push(make_pair(0, my_hash(tmp)));

    while (!Q.empty()) {
        long long cur = Q.top().second;
        Q.pop();
        if (vis[cur]) {
            continue;
        }
        vis[cur] = true;

        for (int i = 0; i < 8; i++) {
            for (int j = i + 1; j < 8; j++) {
                vector<int> nxt = convert(cur);
                swap(nxt[i], nxt[j]);
                long long nxt_val = my_hash(nxt);
                if (dis[nxt_val] > dis[cur] + c[nxt[i]][nxt[j]]) {
                    dis[nxt_val] = dis[cur] + c[nxt[i]][nxt[j]];
                    Q.push(make_pair(-dis[nxt_val], nxt_val));
                }
            }
        }

    }

}


void solve() {
    long long res = dis[my_hash(v)];
    //cout << res << endl;
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            //inv[i][j]
            int x = v[i - 1], y = v[j - 1];
            //x在y前
            if (x > y) {
                res += 1ll * p[x][y] * inv[i][j];
            }
        }
    }
    //cout << res << endl;
    ans = min(ans, res);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
#endif
    for (int i = 1; i <= 8; i++) {
        v.push_back(i);
    }

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%1d", &s[i]);
    }

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            scanf("%lld", &p[i][j]);
        }
    }
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            scanf("%lld", &c[i][j]);
        }
    }
    Dijkstra();
    for (int i = n; i >= 1; i--) {
        int val = s[i];
        for (int j = 1; j <= 8; j++) {
            inv[s[i]][j] += cnt[j];
        }
        cnt[val]++;
    }

    do {
        solve();
    } while (next_permutation(v.begin(), v.end()));

    printf("%lld\n", ans);

    return 0;
}