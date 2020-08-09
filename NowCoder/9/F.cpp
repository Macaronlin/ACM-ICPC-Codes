#include <bits/stdc++.h>

using namespace std;

const int N = 2000000 + 10;
struct Node {
    int a, id;
    bool operator < (const Node &tmp) const { return a < tmp.a; }
};
int cnt[N], tot;
int main() {
    int n, m;   scanf("%d %d", &n, &m);
    vector <Node> vec;
    for (int i = 1; i <= n; i++) {
        int k;  scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            int a;  scanf("%d", &a);
            vec.push_back((Node){a, i});
        }
    }
    sort(vec.begin(), vec.end());
    int p = 0, q = -1, ans = INT_MAX;
    while (p <= q + 1 && q + 1 < (int)vec.size()) {
        if (tot >= m) {
            ans = min(ans, vec[q].a - vec[p].a);
            cnt[vec[p].id]--;
            if (cnt[vec[p].id] == 0)    tot--;
            p++;
        }
        else {
            ++q;
            if (cnt[vec[q].id] == 0)    tot++;
            cnt[vec[q].id]++;
        }
    }
    printf("%d\n", ans);
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}