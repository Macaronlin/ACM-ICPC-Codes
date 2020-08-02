#include <bits/stdc++.h>

using namespace std;

vector <int> ans;

void Solve(int n, int m) {
    if (n == 0 || m == 0)   return;
    if (n > m)  swap(n, m);
    if (n == 1) {
        for (int i = 1; i <= m; i++)    ans.push_back(1);
        return;
    }
    for (int i = 1; i <= n; i++)    ans.push_back(n);
    Solve(m - n, n);
}

int main() {
    int T;  scanf("%d", &T);
    while (T--) {
        int n, m;   scanf("%d %d", &n, &m);
        ans.clear();
        Solve(n, m);
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        printf("%d\n", (int)ans.size());
        for (auto x : ans)  printf("%d ", x);
        puts("");
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}