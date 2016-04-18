#include <stdio.h>
#include <math.h> 

long long *segmentTree;
long long *lazy;

long long query(int qLoww, int qHighgh, int low, int high, int root);

void update(int qLow, int qHigh, int low, int high, int root, long long val) {
    if (high < qLow || qHigh < low)return;

    if (lazy[root] != 0) {
        if (low == high) {
            segmentTree[root] += lazy[root];
        } else {
            segmentTree[root] += lazy[root]*(high - low + 1);
            lazy[root * 2 + 1] += lazy[root];
            lazy[root * 2 + 2] += lazy[root];
        }
        lazy[root] = 0;
    }

    if (qLow <= low && high <= qHigh) {
        if (low == high) {
            segmentTree[root] += val;
        } else {
            segmentTree[root] += val * (high - low + 1);
            lazy[root * 2 + 1] += val;
            lazy[root * 2 + 2] += val;
        }
        return;
    }

    int mid = (low + high) / 2;
    update(qLow, qHigh, low, mid, root * 2 + 1, val);
    update(qLow, qHigh, mid + 1, high, root * 2 + 2, val);
    int left = root * 2 + 1;
    int right = left + 1;
    segmentTree[root] = query(low, mid, low, mid, root * 2 + 1) + query(mid + 1, high, mid + 1, high, root * 2 + 2);
}

long long query(int qLow, int qHigh, int low, int high, int root) {
    if (high < qLow || qHigh < low)return 0;

    if (lazy[root] != 0) {
        if (low == high) {
            segmentTree[root] += lazy[root];
        } else {
            segmentTree[root] += lazy[root]*(high - low + 1);
            lazy[root * 2 + 1] += lazy[root];
            lazy[root * 2 + 2] += lazy[root];
        }
        lazy[root] = 0;
    }
    if (qLow <= low && high <= qHigh)return segmentTree[root];

    int mid = (low + high) / 2;
    long long left = query(qLow, qHigh, low, mid, root * 2 + 1);
    long long right = query(qLow, qHigh, mid + 1, high, root * 2 + 2);
    return left + right;
}

int segSize;

void build(int size) {
    int height = (int) ceil(log((double) size) / log((double) 2));
    segSize = (int) ceil(pow((double) 2, height + 1));
    segmentTree = new long long[segSize];
    lazy = new long long[segSize];
    for (int i = 0; i < segSize; ++i) {
        segmentTree[i] = 0;
        lazy[i] = 0;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int N, C;
        scanf("%d %d", &N, &C);
        build(N);
        for (int i = 0; i < C; ++i) {
            int type, p, q;
            long long v;
            scanf("%d", &type);
            if (type == 0) {
                scanf("%d %d %lld", &p, &q, &v);
                update(p - 1, q - 1, 0, N - 1, 0, v);
            } else {
                scanf("%d %d", &p, &q);
                printf("%lld\n", query(p - 1, q - 1, 0, N - 1, 0));
            }
        }
    }
}
