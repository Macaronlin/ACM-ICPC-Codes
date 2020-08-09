#include <bits/stdc++.h>

using namespace std; 

const int N = 1000000 + 10;
int head[N], to[N << 1], nxt[N << 1], tot;
void AddEdge(int u, int v) {
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}

multiset <pair<int, int>> st;

int d[1010][210], id[1010], cnt[1010];

int main() {
    int n, m;   scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &d[i][j]);
        }
    }
    vector <int> dot(1);
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == -1) {
            cnt[i] = 0;
            continue;
        }
        dot.push_back(i);
        cnt[i] = 1;
        for (int j = i + 1; j <= n; j++) {
            bool flag = true;
            for (int k = 1; k <= m; k++) {
                if (d[i][k] != d[j][k]) {
                    flag = false;
                    break;
                }
            }
            cnt[i] += flag;
        }
    }
    for (auto u : dot) {
        for (auto v : dot) {
            if (u != v) {
                for (int i = 1; i <= m; i++) {
                    if (d[u][i] >= d[v][i] && d[u][i] - d[v][i] <= 1) {
                        AddEdge(u, v);
                    }
                }
            }
        }
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}