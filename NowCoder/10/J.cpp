#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;

struct Graph {
	int n, rt;
	int head[maxn], to[maxn << 1], nxt[maxn << 1], tot;
	void AddEdge(int u, int v) {
		to[++tot] = v;
		nxt[tot] = head[u];
		head[u] = tot;
	}
	unsigned long long Hash[maxn];
	const static unsigned long long Origin = 233;
	const static unsigned long long BASE = 233333333;
	void Get_Hash(int u, int fath) {
		static unsigned long long sta[maxn];
		int top = 0;
		for (int i = head[u]; i; i = nxt[i]) {
			int v = to[i];
			if (v != fath) {
				Get_Hash(v, u);
			}
		}
		for (int i = head[u]; i; i = nxt[i]) {
			int v = to[i];
			if (v != fath) {
				sta[++top] = Hash[v];
			}
		}
		sort(sta + 1, sta + top + 1);
		Hash[u] = Origin;
		for (int i = 1; i <= top; i++) {
			Hash[u] *= BASE;
			Hash[u] ^= sta[i];
			Hash[u] += sta[i];
			Hash[u] ^= sta[i];
		}
	}
}g[2];

const int INF = 1000;
int KM(vector <vector<int>> &A, int n, int m, bool opt) {
    // opt == 0 最大费用  opt == 1 最小费用
    // a是代价矩阵 1~n 1~m
	vector <int> u(n + 1), v(m + 1), p(m + 1), way(m + 1);
	for (int i = 1; i <= n; i++) {
		p[0] = i;
		int j0 = 0;
		vector <int> minv (m + 1, INF);
		vector <bool> used (m + 1, false);
        while (p[j0]) {
            used[j0] = true;
			int i0 = p[j0], delta = INF, j1;
            for (int j = 1; j <= m; j++) {
				if (!used[j]) {
                    int cur = (2 * opt - 1) * A[i0][j] - u[i0] - v[j];
					if (cur < minv[j])  {minv[j] = cur; way[j] = j0; }
					if (minv[j] < delta)    {delta = minv[j],  j1 = j; }
				}
            }
            for (int j = 0; j <= m; j++) {
                if (used[j]) { u[p[j]] += delta; v[j] -= delta; }
                else { minv[j] -= delta; }
            }
            j0 = j1;
        }
        while (j0) {
            int j1 = way[j0];
			p[j0] = p[j1];
			j0 = j1;
        }
	}
    return (2 * !opt - 1) * v[0];
}

int n;

int Solve(int u1, int u2) {
    unordered_map <unsigned long long, vector<int>> ump[2];
    for (int i = g[0].head[u1]; i; i = g[0].nxt[i]) {
        int v1 = g[0].to[i];
        ump[0][g[0].Hash[v1]].push_back(v1);
    }
    for (int i = g[1].head[u2]; i; i = g[1].nxt[i]) {
        int v2 = g[1].to[i];
        ump[1][g[1].Hash[v2]].push_back(v2);
    }
    int res = u1 != u2;
    for (auto it : ump[0]) {
        int tot = it.second.size();
        vector <int> node[2];
        vector <vector<int>> A;
        for (auto a : it.second)    node[0].push_back(a);
        for (auto b : ump[1][it.first]) node[1].push_back(b);
        vector <int> _;
        A.push_back(_);
        for (int i = 0; i < (int)node[0].size(); i++) {
            vector <int> AA(tot + 1);
            for (int j = 0; j < (int)node[1].size(); j++) {
                AA[j + 1] = Solve(node[0][i], node[1][j]);
            }
            A.push_back(AA);
        }
        res += KM(A, tot, tot, 1);

        // if (u1 == 1 && u2 == 3) {
        //     cout << "(a ";    for (auto a : it.second)    cout << a << ',';   cout << "), ";
        //     cout << "(b ";    for (auto a : ump[1][it.first])    cout << a << ',';   cout << ") : ";
        //     cout << "maxFlow = " << mcmf.maxFlow << ", ";
        //     cout << "minCost = " << mcmf.minCost << '\n';
        //     for (auto a : it.second) {
        //         for (auto b : ump[1][it.first]) {
        //             cout << Solve(a, b) << ' ';
        //         } cout << '\n';
        //     } cout << '\n';
        // }
    }
    // printf("ans : (%d -> %d) : %d\n", u1, u2, res);
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 2; i++) {
        g[i].n = n;
        for (int j = 1; j <= n; j++) {
            int p;  scanf("%d", &p);
            if (!p) g[i].rt = j;
            g[i].AddEdge(p, j);
        }
    }
    for (int i = 0; i < 2; i++) g[i].Get_Hash(g[i].rt, 0);
    
    // for (int i = 0; i < 2; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << g[i].Hash[j] << ' ';
    //     } cout << '\n';
    // }
    
    printf("%d\n", Solve(g[0].rt, g[1].rt));
	// int m;	scanf("%d", &m);
	// for (int i = 1; i <= m; i++) {
	// 	int n;	scanf("%d", &n);
	// 	g[i].n = n;
	// 	for (int j = 1; j <= n; j++) {
	// 		int fath;	scanf("%d", &fath);
	// 		if (fath) {
	// 			g[i].AddEdge(j, fath);
	// 			g[i].AddEdge(fath, j);
	// 		}
	// 		else {
	// 			g[i].rt = j;
	// 		}
	// 	}
	// }
	
	// map <vector <vector <unsigned long long> > , int> mp;
	// for (int i = 1; i <= m; i++) {
	// 	vector <vector <unsigned long long> > VEC;
	// 	for (int j = 1; j <= g[i].n; j++) {
	// 		g[i].Get_Hash(j, 0);
	// 		vector <unsigned long long> vec;
	// 		for (int k = 1; k <= g[i].n; k++) {
	// 			vec.push_back(g[i].Hash[k]);
	// 		}
	// 		sort(vec.begin(), vec.end());
	// 		VEC.push_back(vec);
	// 	}
	// 	sort(VEC.begin(), VEC.end());
	// 	printf("%d\n", mp[VEC] ? mp[VEC] : mp[VEC] = i);
	// }
    getchar(); getchar();
	return 0;
}
