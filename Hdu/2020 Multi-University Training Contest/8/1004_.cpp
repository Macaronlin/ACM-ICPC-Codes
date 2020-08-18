#include <bits/stdc++.h>
#define sz(v) ((lint)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
typedef pair<int, int> pi;
const int MAXL = 18;
const int MAXN = 100005;

struct node {
    node *l, *r, *p;
    int x, y, subSize;
    int insVal, gphVal;
    int insSum, gphSum;
    node() {
        l = r = p = NULL;
        x = y = subSize = 0;
        insVal = gphVal = 0;
        insSum = gphSum = 0;
    }
    node(int _x, int _y) {
        x = _x;
        y = _y;
        subSize = (x == y);
        insVal = gphVal = 0;
        insSum = gphSum = 0;
        l = r = p = NULL;
    }
    void clear(int _x, int _y) {
        x = _x;
        y = _y;
        subSize = (x == y);
        insVal = gphVal = 0;
        insSum = gphSum = 0;
        l = r = p = NULL;
    }

    void push() {}
    void pull() {
        subSize = (x == y);
        insSum = insVal;
        gphSum = gphVal;
        if (l) {
            subSize += l->subSize;
            insSum += l->insSum;
            gphSum += l->gphSum;
        }
        if (r) {
            subSize += r->subSize;
            insSum += r->insSum;
            gphSum += r->gphSum;
        }
    }
    void rotate() {
        node *x = this;
        if (!x->p)
            return;
        x->p->push();
        x->push();
        node *p = x->p;
        bool is_left = (p->l == x);
        node *b = (is_left ? x->r : x->l);
        x->p = p->p;
        if (x->p && x->p->l == p)
            x->p->l = x;
        if (x->p && x->p->r == p)
            x->p->r = x;
        if (is_left) {
            if (b)
                b->p = p;
            p->l = b;
            p->p = x;
            x->r = p;
        } else {
            if (b)
                b->p = p;
            p->r = b;
            p->p = x;
            x->l = p;
        }
        p->pull();
        x->pull();
    }
    void splay() {
        node *x = this;
        while (x->p) {
            node *p = x->p;
            node *g = p->p;
            if (g) {
                if ((p->l == x) ^ (g->l == p))
                    x->rotate();
                else
                    p->rotate();
            }
            x->rotate();
        }
    }
    node *prev() {
        splay();
        if (!l)
            return NULL;
        auto prv = l;
        while (prv->r) prv = prv->r;
        prv->splay();
        return prv;
    }
    node *next() {
        splay();
        if (!r)
            return NULL;
        auto nxt = r;
        while (nxt->l) nxt = nxt->l;
        nxt->splay();
        return nxt;
    }
    void inorder() {
        if (l)
            l->inorder();
        printf("[(%d, %d)]", x, y);
        if (r)
            r->inorder();
    }
};

namespace HDLT {  // does not support duplicate edges
struct ETT {
    set<int> gph[MAXN], insec[MAXN];
    map<pi, node *> mp;
    node *vertexNode[MAXN];
    queue<node *> que;
    void init(int n) {
        for (int i = 1; i <= n; i++) {
            vertexNode[i] = new node(i, i);
        }
    }
    void charge(int v, int w1, int w2) {
        vertexNode[v]->splay();
        vertexNode[v]->gphVal += w1;
        vertexNode[v]->insVal += w2;
        vertexNode[v]->pull();
    }
    void gph_add(int s, int e) {
        gph[s].insert(e);
        gph[e].insert(s);
        charge(s, 1, 0);
        charge(e, 1, 0);
    }
    void gph_del(int s, int e) {
        gph[s].erase(e);
        gph[e].erase(s);
        charge(s, -1, 0);
        charge(e, -1, 0);
    }
    bool gph_find(int s, int e) { return gph[s].find(e) != gph[s].end(); }
    void insec_add(int s, int e) {
        insec[s].insert(e);
        insec[e].insert(s);
        charge(s, 0, 1);
        charge(e, 0, 1);
    }
    void insec_del(int s, int e) {
        insec[s].erase(e);
        insec[e].erase(s);
        charge(s, 0, -1);
        charge(e, 0, -1);
    }
    node *get_root(node *p) {
        p->splay();
        while (p->l) p = p->l;
        p->splay();
        return p;
    }
    void reroot(node *p) {
        p->splay();
        if (!p->l)
            return;
        auto pos = p->l;
        pos->p = NULL;
        p->l = NULL;
        p->pull();

        while (pos->l) pos = pos->l;
        pos->splay();
        p->p = pos;
        pos->l = p;
        pos->pull();
    }
    void add_edge(pi p) {
        int x = p.first, y = p.second;
        node *up, *dn;
        while (sz(que) < 2) que.push(new node(69, 420));
        up = mp[pi(y, x)] = que.front();
        que.pop();
        dn = mp[pi(x, y)] = que.front();
        que.pop();
        up->clear(y, x);
        dn->clear(x, y);
        reroot(vertexNode[x]);
        reroot(vertexNode[y]);

        vertexNode[y]->splay();
        up->l = vertexNode[y];
        vertexNode[y]->p = up;
        up->pull();
        dn->r = up;
        up->p = dn;
        dn->pull();
        vertexNode[x]->l = dn;
        dn->p = vertexNode[x];
        vertexNode[x]->pull();
    }
    void remove_edge(pi p) {
        int x = p.first, y = p.second;
        node *dn = mp[pi(x, y)];
        node *up = mp[pi(y, x)];
        que.push(dn);
        que.push(up);
        reroot(vertexNode[x]);
        mp.erase(pi(x, y));
        mp.erase(pi(y, x));

        node *pdn = dn->prev();
        pdn->splay();
        pdn->r->p = NULL;
        pdn->r = NULL;

        up->splay();
        pdn->r = up->r;
        if (pdn->r)
            pdn->r->p = pdn;
        pdn->pull();

        up->l->p = NULL;
        up->l = NULL;
        dn->splay();
        dn->r->p = NULL;
    }
    bool has_edge(int x, int y) { return mp.find(pi(x, y)) != mp.end(); }
    bool has_path(int x, int y) { return get_root(vertexNode[x]) == get_root(vertexNode[y]); }
    int get_size(int x) {
        vertexNode[x]->splay();
        return vertexNode[x]->subSize;
    }

    void deal_ins(node *p, vector<pi> &toAdd) {
        auto w = insec[p->x];
        for (auto &v : w) {
            toAdd.emplace_back(p->x, v);
            gph_del(p->x, v);
            insec_del(p->x, v);
        }
    }

    void deal_gph(node *p, vector<pi> &toAdd) {
        while (sz(gph[p->x])) {
            auto v = *gph[p->x].begin();
            gph_del(p->x, v);
            if (has_path(p->x, v)) {
                toAdd.emplace_back(p->x, v);
            } else {
                throw pi(p->x, v);
            }
        }
    }

    void gogogo1(int x, vector<pi> &ret) {
        reroot(vertexNode[x]);
        vertexNode[x]->splay();
        auto p = vertexNode[x];
        while (p->insSum) {
            while (true) {
                if (p->insVal)
                    break;
                else if (p->l && p->l->insSum)
                    p = p->l;
                else
                    p = p->r;
            }
            p->splay();
            deal_ins(p, ret);
            p->splay();
        };
    }

    pi gogogo2(int x, vector<pi> &ret) {
        reroot(vertexNode[x]);
        vertexNode[x]->splay();
        auto p = vertexNode[x];
        try {
            while (p->gphSum) {
                while (true) {
                    if (p->gphVal)
                        break;
                    else if (p->l && p->l->gphSum)
                        p = p->l;
                    else
                        p = p->r;
                }
                p->splay();
                deal_gph(p, ret);
                p->splay();
            };
        } catch (pi p) {
            return p;
        }
        return pi(-1, -1);
    }
} tree[MAXL];

int lvl, n;

void init(int _n) {
    n = _n;
    while ((1 << lvl) < n) lvl++;
    for (int i = 0; i <= lvl; i++) tree[i].init(n);
}

int level(int s, int e) {
    for (int i = lvl; i >= 0; i--) {
        if (tree[i].gph_find(s, e))
            return i;
    }
    assert(0);
}

bool add_edge(int s, int e, int l = lvl) {
    if (s == e)
        return 0;
    if (s > e)
        swap(s, e);
    int ret = 0;
    if (!tree[l].has_path(s, e)) {
        //	printf("tree add %d %d %d\n", l, s, e);
        tree[l].add_edge(pi(s, e));
        tree[l].insec_add(s, e);
        ret = 1;
    }
    tree[l].gph_add(s, e);
    return ret;
}
bool del_edge(int s, int e) {
    if (s == e)
        return 0;
    if (s > e)
        swap(s, e);
    int l = level(s, e);
    tree[l].gph_del(s, e);
    if (!tree[lvl].has_edge(s, e))
        return 0;
    tree[l].insec_del(s, e);
    for (int j = l; j <= lvl; j++) {
        tree[j].remove_edge(pi(s, e));
    }
    for (int j = l; j <= lvl; j++) {
        int szs = tree[j].get_size(s);
        int sze = tree[j].get_size(e);
        int prom = (szs <= sze ? s : e);  // which side to kill

        vector<pi> promote;
        tree[j].gogogo1(prom, promote);
        pi found_edge = tree[j].gogogo2(prom, promote);

        for (auto &[u, v] : promote) {
            add_edge(u, v, j - 1);
        }

        if (~found_edge.first) {
            add_edge(found_edge.first, found_edge.second, j);
            for (int k = j + 1; k <= lvl; k++) {
                tree[k].add_edge(found_edge);
            }
            return 0;
        }
    }
    return 1;
}
bool is_conn(int s, int e) { return tree[lvl].has_path(s, e); }
}  // namespace HDLT


int main() { 
    int n, m;
    scanf("%d %d", &n, &m);
    HDLT::init(n);
    int lastans = 0;
    vector<pi> v;
    while (m--) {
        int t, x, y;
        scanf("%d %d %d", &t, &x, &y);
        x ^= lastans;
        y ^= lastans;
        if (t == 0)
            HDLT::add_edge(x, y);
        if (t == 1)
            HDLT::del_edge(x, y);
        if (t == 2) {
            bool dap = HDLT::is_conn(x, y);
            if (dap)
                lastans = x, puts("Y");
            else
                lastans = y, puts("N");
        }
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}