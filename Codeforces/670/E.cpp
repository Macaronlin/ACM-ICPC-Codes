#include <bits/stdc++.h>

using namespace std;

int _[1000000];

const int N = 100000 + 10;
int vis[N], prime[N], cnt;
vector <int> p1, p2;

void Pre(int n = N - 10) {
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            prime[cnt++] = i;
            if (1LL * i * i <= n) p1.push_back(i);
            else    p2.push_back(i);
        }
        for (int j = 0; j < cnt && prime[j] * i <= n; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}

int n;

int work(int op, int x) {
    printf("%c %d\n", " ABC"[op], x);   fflush(stdout);
#ifndef ONLINE_JUDGE
    if (op <= 2) {
        int res = 0;
        for (int i = 1; 1LL * i * x <= n; i++) {
            if (_[i * x] == 0) {
                res++;
                if (op == 2 && i * x != 99991)    _[i * x] = 1;
            }
        }
        cout << res << '\n';
        return res;
    }
#endif
    if (op != 3) {
        int res;    scanf("%d", &res);
        return res;
    }
    return 0;
}

int calc() {
    int nres = work(1, 1);
    int L = 0, R = p2.size() - 1;
    while (L <= R) {
        int M = (L + R) >> 1;
        for (int i = M; i <= R; i++) {
            if (work(2, p2[i]) > 1) {
                return p2[i];
            }
        }
        int mres = work(1, 1);
        // printf("________ L = %d, M = %d, R = %d, (%d, %d, %d)\n", L, M, R, p2[L], p2[M], p2[R]);
        // printf("%d %d %d\n", nres, mres, p2.size() - M);   getchar();
        if (nres - mres == (int)p2.size() - M) {
            R = M - 1;
        }
        else {
            for (int i = M; i <= R; i++) {
                int res = work(1, p2[i]);
                if (res) {
                    return p2[i];
                }
            }
            return 0;
        }
    }
    return 1;
}

int main() {
    scanf("%d", &n);
#ifndef ONLINE_JUDGE
    getchar();getchar();
#endif
    Pre(n);
    int ans = 1;
    for (auto x : p1) {
        work(2, x);
        int res = work(1, x);
        if (res) {
            ans *= x;
            for (long long y = x * x; y <= n; y *= x) {
                res = work(1, y);
                if (res)    ans *= x;
                else    break;
            }
        }
    }
    while (!p2.empty() && p2.back() * ans > n)  p2.pop_back();
    ans *= calc();
    work(3, ans);
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}