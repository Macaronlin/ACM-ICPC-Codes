#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;  scanf("%d", &T);
    while (T--) {
        int n;  scanf("%d", &n);
        int cnt = 0;
        vector <int> a;
        for (int i = 1; i <= n; i++) {
            int x;  scanf("%d", &x);
            if (!x) cnt++;
            else    a.push_back(x);
        }
        sort(a.begin(), a.end());
        vector <int> b;
        for (int i = (int)a.size() - 1; i > 1; i--) {
            b.push_back(a[i]);
        }
        while (cnt--)   b.push_back(0);
        b.push_back(a[1]);
        b.push_back(0); b.push_back(0);
        for (int i = 0, tmp = 0; i < (int)b.size(); i++) {
            b[i] = b[i] * a[0] + tmp;
            tmp = 0;
            if (b[i] >= 10) {
                tmp = b[i] / 10;
                b[i] %= 10;
            }
        }
        while (b.back() == 0)   b.pop_back();
        reverse(b.begin(), b.end());
        for (auto x : b)    printf("%d", x);
        puts("");
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}