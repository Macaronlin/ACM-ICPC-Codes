#include <bits/stdc++.h>

using namespace std; 

int dx[] = {0, 0, -1, 1, 0};
int dy[] = {0, 1, 0, 0, -1};
// int dc[] = {}

int main() {
    int n;  scanf("%d", &n);
    vector <pair<pair<int, int>, int>> ans;
    set <pair<pair<int, int>, int>> st[2];
    st[0].insert({{0, 0}, n});
    for (int _ = 1, now = 0, nxt = 1; _ <= n; _++, swap(now, nxt)) {
        st[nxt].clear();
        for (auto it : st[now]) {
            int x = it.first.first, y = it.first.second, c = it.second;
            for (int i = 1; i <= 4; i++) {
                int tx = x + dx[i], ty = y + dy[i], tc = max(0, c - i);
                if (tc > 0) {
                    st[nxt].insert({{tx, ty}, tc});
                }
            }
            ans.push_back(it);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto it : ans) {
        printf("%d %d %d\n", it.first.first, it.first.second, it.second);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}