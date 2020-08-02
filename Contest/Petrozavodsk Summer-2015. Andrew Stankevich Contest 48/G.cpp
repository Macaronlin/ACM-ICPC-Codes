#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int N = 500010;

int ans[15][N];
gp_hash_table<int, bool> vis[N];
list<int> d;
gp_hash_table<int, bool> used;
int x, y;

int main() {
    //ios::sync_with_stdio(0); cin.tie(0);
    
    freopen("grundy.in", "r", stdin);
    freopen("grundy.out", "w", stdout);
    memset(ans, -1, sizeof(ans));
    for (int g = 0; g <= 10; g++) {
        //cerr<<g<<'\n';
        d.clear();
        used.clear();
        for (int i = 0; i < N + N; i++) d.push_back(i);
        for (int i = 0; i < N; i++) {
            if (ans[g][i] != -1) continue;
            for (list<int>::iterator it = d.begin(); it != d.end(); it++) {
                if (vis[i][i + (*it)] || used[i + (*it)]) continue;
                used[i + (*it)] = true;
                ans[g][i] = i + (*it);
                vis[i][i + (*it)] = true;
                if (i + (*it) < N) {
                    ans[g][i + (*it)] = i;
                    vis[i + (*it)][i] = true;
                    used[i] = true;
                }
                d.erase(it);
                break;
            }
        }
    }
    while (1) {
        scanf("%d%d", &x, &y);
        if (!x && !y) break;
        //cout << y - 1 << ' ' << ans[x][y - 1] << '\n';
        printf("%d %d\n", y - 1, ans[x][y - 1]);
    }
    //getchar(); getchar();
    return 0;
}