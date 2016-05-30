#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)

struct node {
    int sum;
    int leftSum;
    int rightSum;
    int maxSum;
};

bool isPowerOfTwo(int n) {
    
    if (n == 0)
        return true;
    while (n != 1) {
        if (n%2 != 0)
            return false;
        n = n/2;
    }
    return true;
}
int arr[50005];
vector<node> segment(4*50005);
void formSegmentTree(int low, int high, int root) {
    
    if (low == high) {
        segment[root].sum = arr[low];
        segment[root].leftSum = arr[low];
        segment[root].rightSum = arr[low];
        segment[root].maxSum = arr[low];
        return;
    }
    
    int mid = (low + high) / 2;
    
    formSegmentTree(low, mid, 2*root + 1);
    formSegmentTree(mid + 1, high, 2*root + 2);
   
    segment[root].sum = segment[2*root +1].sum + segment[2*root + 2].sum;
    segment[root].leftSum = max(segment[2*root +1].leftSum, segment[2*root + 2].leftSum + segment[2*root + 1].sum);
    segment[root].rightSum = max(segment[2*root + 2].rightSum, segment[2*root + 2].sum + segment[2*root +1].rightSum);
    
    segment[root].maxSum = max(segment[root].leftSum, 
                                max(segment[root].rightSum,
                                    max(segment[2*root +1].maxSum,
                                        max(segment[2*root+2].maxSum,
                                                segment[2*root+1].rightSum +
                                                segment[2*root+2].leftSum
                                            )
                                    )    
                                )
                            );

}

node query(int low, int high, int qlow, int qhigh, int root) {
    
    node res;
    res.sum = INT_MIN;
    res.leftSum = INT_MIN;
    res.rightSum = INT_MIN;
    res.maxSum = INT_MIN;
    
    // No overlap
    if (qlow > high || qhigh < low)
        return res;
    
    // Total Overlap
    if (qlow <= low && qhigh >= high)
        return segment[root];

    // Partial Overlap
    int mid = (low + high)/2;
    
    if (qlow > mid)
        return query(mid+1, high, qlow, qhigh, 2*root+2);
    if (qhigh <= mid)
        return query(low, mid, qlow, qhigh, 2*root + 1);

    node left = query(low, mid, qlow, qhigh, 2*root+1);
    node right = query(mid+1, high, qlow, qhigh, 2*root+2);

    res.sum = left.sum + right.sum;
    res.leftSum = max(left.leftSum, right.leftSum + left.sum);
    res.rightSum = max(right.rightSum, right.sum + left.rightSum);

    res.maxSum = max(res.leftSum,
                    max(res.rightSum,
                        max(left.maxSum,
                            max(right.maxSum,
                                left.rightSum + right.leftSum
                                )
                            )
                        )
                    );

    return res;

}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int m;
    scanf("%d", &m);
    
    formSegmentTree(0, n-1, 0);
    
    while (m--) {
        int qlow, qhigh;
        scanf("%d %d", &qlow, &qhigh);
        node ans = query(0, n-1, qlow-1, qhigh-1, 0);
        printf("%d\n", ans.maxSum);
    }
}
