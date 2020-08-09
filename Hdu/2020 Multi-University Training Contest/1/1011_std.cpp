#include <bits/stdc++.h>

using namespace std;


template<size_t size>
struct SuffixArray {
    bool type[size << 1];
    int bucket[size], bucket1[size];
    int sa[size], rk[size], ht[size];
    bool isLMS(const int i, const bool *type) { return i > 0 && type[i] && !type[i - 1]; }
    template<class T>
    void inducedSort(T s, int *sa, const int len, const int sigma, const int bucketSize, bool *type, int *bucket, int *cntbuf, int *p) {
        memset(bucket, 0, sizeof(int) * sigma);
        memset(sa, -1, sizeof(int) * len);
        for (int i = 0; i < len; i++) bucket[s[i]]++;
        cntbuf[0] = bucket[0];
        for (int i = 1; i < sigma; i++) cntbuf[i] = cntbuf[i - 1] + bucket[i];
        for (int i = bucketSize - 1; i >= 0; i--) sa[--cntbuf[s[p[i]]]] = p[i];
        for (int i = 1; i < sigma; i++) cntbuf[i] = cntbuf[i - 1] + bucket[i - 1];
        for (int i = 0; i < len; i++) if (sa[i] > 0 && !type[sa[i] - 1]) sa[(cntbuf[s[sa[i] - 1]]++)] = sa[i] - 1;
        cntbuf[0] = bucket[0];
        for (int i = 1; i < sigma; i++) cntbuf[i] = cntbuf[i - 1] + bucket[i];
        for (int i = len - 1; i >= 0; i--) if (sa[i] > 0 && type[sa[i] - 1]) sa[--cntbuf[s[sa[i] - 1]]] = sa[i] - 1;
    }
    template<typename T>
    void sais(T s, int *sa, int len, bool *type, int *bucket, int *bucket1, int sigma) {
        int i, j, bucketSize = 0, cnt = 0, p = -1, x, *cntbuf = bucket + sigma;
        type[len - 1] = 1;
        for (i = len - 2; i >= 0; i--) type[i] = s[i] < s[i + 1] || (s[i] == s[i + 1] && type[i + 1]);
        for (i = 1; i < len; i++) if (type[i] && !type[i - 1]) bucket1[bucketSize++] = i;
        inducedSort(s, sa, len, sigma, bucketSize, type, bucket, cntbuf, bucket1);
        for (i = bucketSize = 0; i < len; i++) if (isLMS(sa[i], type)) sa[bucketSize++] = sa[i];
        for (i = bucketSize; i < len; i++) sa[i] = -1;
        for (i = 0; i < bucketSize; i++) {
            x = sa[i];
            for (j = 0; j < len; j++) {
                if (p == -1 || s[x + j] != s[p + j] || type[x + j] != type[p + j]) { cnt++, p = x; break; }
                else if (j > 0 && (isLMS(x + j, type) || isLMS(p + j, type))) break;
            }
            x = (~x & 1 ? x >> 1 : (x - 1) >> 1), sa[bucketSize + x] = cnt - 1;
        }
        for (i = j = len - 1; i >= bucketSize; i--) if (sa[i] >= 0) sa[j--] = sa[i];
        int *s1 = sa + len - bucketSize, *bucket2 = bucket1 + bucketSize;
        if (cnt < bucketSize) sais(s1, sa, bucketSize, type + len, bucket, bucket1 + bucketSize, cnt);
        else for (i = 0; i < bucketSize; i++) sa[s1[i]] = i;
        for (i = 0; i < bucketSize; i++) bucket2[i] = bucket1[sa[i]];
        inducedSort(s, sa, len, sigma, bucketSize, type, bucket, cntbuf, bucket2);
    }
    void getHeight(const char *s, const int len, const int *sa) {
        for (int i = 0, k = 0; i < len; i++) {
            if (rk[i] == 0) k = 0;
            else {
                if (k > 0) k--;
                int j = sa[rk[i] - 1];
                while (i + k < len && j + k < len && s[i + k] == s[j + k]) k++;
            }
            ht[rk[i]] = k;
        }
    }
    template<class T>
    void init(T s, const int len, const int sigma) {
        sais(s, sa, len, type, bucket, bucket1, sigma);
        for (int i = 1; i < len; i++) sa[i]++;
        for (int i = 1; i < len; i++) rk[sa[i]] = i;
        getHeight(s, len, sa);
    }
};
SuffixArray <1000> sf;
// sf.sa[1~n]
// sf.rk[1~n]
// sf.ht[1~n] lcp(sa[i-1], sa[i])

char s[100];

int main() {
    srand(time(0));
    // int n = 6;
    // bool type[size << 1];
    // int bucket[size], bucket1[size];
    // int sa[size], rk[size], ht[size];
    // for (int i = 1; i <= n; i++)   s[i] = rand() % 4 + 'a';
    cin >> (s + 1);
    int n = strlen(s + 1);
    s[n + 1] = 0;
    printf("%s\n", s + 1);
    sf.init(s + 1, n + 1, 256);
    printf("sa : ");
    for (int i = 1; i <= n; i++) {
        cout << sf.sa[i] << ' ';
    } cout << endl;
    printf("rk : ");
    for (int i = 1; i <= n; i++) {
        cout << sf.rk[i] << ' ';
    } cout << endl;
    for (int i = 1; i <= n; i++) {
        // printf("________________\n");
        s[n - i + 2] = 0;
        printf("%s\n", s + 1);
        sf.init(s + 1, n - i + 2, 256);
        // printf("sa : ");
        // for (int j = 1; j < n - i + 2; j++) {
        //     cout << sf.sa[j] << ' ';
        // } cout << endl;
        // printf("rk : ");
        // for (int j = 1; j < n - i + 2; j++) {
        //     cout << sf.rk[j] << ' ';
        // } cout << endl;
        printf("%d\n", sf.sa[1]);
    }
    system("pause");
    return 0;
}