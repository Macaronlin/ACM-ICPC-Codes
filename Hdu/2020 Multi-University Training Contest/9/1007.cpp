#include <bits/stdc++.h>
using namespace std;
const int N = 350000 + 10;
// #define int long long
mt19937 myrand(time(0));
int rt, n, q;
inline int read()
{
    char c=0; int re=0;
    while (!isdigit(c)) c=getchar();
    while (isdigit(c)) {re=re*10+c-'0'; c=getchar();}
    return re;
}

template<typename T> void write(T x){
    if (x < 0){ putchar('-'); x = -x; }
    if (x > 9) write(x/10);
    putchar(x%10 + '0');
}
struct Treap {
    int pro[N], siz[N], w[N], tot, id[N];
    int son[2][N];
    int *ls = son[0], *rs = son[1];
    long long sum[N], minv[N];
    void init(int n) {
        rt = tot = 0;
        memset(son[0], 0, sizeof(int) * (n + 5));
        memset(son[1], 0, sizeof(int) * (n + 5));
        memset(sum, 0, sizeof(long long) * (n + 5));
    }
    void push_up(int x) {
        // printf("push_up %lld\n", x);
        sum[x] = sum[ls[x]] + sum[rs[x]] + w[x];
        minv[x] = w[x];
        if (ls[x])  minv[x] = min(minv[x], minv[ls[x]]);
        if (rs[x])  minv[x] = min(minv[x], minv[rs[x]]);
        siz[x] = siz[ls[x]] + siz[rs[x]] + 1;
    }
    void Update(int x, int v, int opt) {
        if (x == 0) return;
        if (opt == 1) {
            w[x] += v;
        }
        else {
            w[x] = v;
        }
        push_up(x);
    }
    int build(int x, int v) {
        w[++tot] = v, siz[tot] = 1, pro[tot] = myrand(), id[tot] = x;
        sum[tot] = minv[tot] = v;
        return tot;
    }
    int merge(int x, int y) {
        if (!x || !y)   return x + y;
        if (pro[x] < pro[y]) {
            rs[x] = merge(rs[x], y);
            push_up(x);
            return x;
        }
        ls[y] = merge(x, ls[y]);
        push_up(y);
        return y;
    }
    int find_pos(int now, int k) {
        if (siz[ls[now]] >= k) return find_pos(ls[now], k);
        else if (siz[ls[now]] + 1 >= k)   return id[now];
        else    return find_pos(rs[now], k - siz[ls[now]] - 1);
    }
    void get_pre(int k, int v, int now, int &ans) {
        if (rs[k] && minv[rs[k]] < v) {
            get_pre(rs[k], v, now + siz[ls[k]] + 1, ans);
        }
        else if (w[k] < v) {
            ans = now + siz[ls[k]] + 1;
        }
        else if (ls[k] && minv[ls[k]] < v) {
            get_pre(ls[k], v, now, ans);
        }
    }
    void split(int i, int k, int &x, int &y) {
        if (!i) {
            x = y = 0;
            return;
        }
        if (siz[ls[i]] < k) {x = i; split(rs[i], k - siz[ls[i]] - 1, rs[i], y);  }
        else {y = i; split(ls[i], k, x, ls[i]); }
        push_up(i);
    }
} Tree;

int a[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("1007.in", "r", stdin);
    freopen("1007.out", "w", stdout);
    clock_t _s = clock();
#endif
    int T;  scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        Tree.init(n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            rt = Tree.merge(rt, Tree.build(i, a[i]));
        }
        for (int i = 1; i <= q; i++) {
            int opt;    scanf("%d", &opt);
            if (opt == 1) {
                int x, y;   scanf("%d %d", &x, &y);
                int _D  = Tree.find_pos(rt, x);
                if (Tree.w[_D] <= y) {
                    puts("0");
                    continue;
                }
                int A, B, C, D, E;
                
                Tree.split(rt, x, D, E);
                int pos = 0;
                Tree.get_pre(D, y, 0, pos);
                if (pos) {
                    Tree.split(D, pos - 1, A, D);
                    Tree.split(D, 1, B, D);

                    long long ans = Tree.sum[D] - 1LL * (y - 1) * (x - pos);
                    // write(ans); puts("");
                    printf("%lld\n", ans);

                    Tree.split(D, 1, C, D);
                    Tree.Update(B, Tree.w[C] - (y - 1), 1);
                    Tree.Update(C, y - 1, 2);

                    rt = Tree.merge(A, Tree.merge(B, Tree.merge(D, Tree.merge(C, E))));
                }
                else {
                    puts("0");
                    rt = Tree.merge(D, E);
                }
                
            }
            else {
                int x;  scanf("%d", &x);
                write(Tree.w[Tree.find_pos(rt, x)]); puts("");
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%d%c", Tree.w[Tree.find_pos(rt, i)], " \n"[i == n]);
        }
    }
#ifndef ONLINE_JUDGE
    clock_t _t = clock();
    printf("%.6lf s\n", 1.0 * (_t - _s) / CLOCKS_PER_SEC);
    system("pause");
#endif
    return 0;
}