#include <iostream>
#include <cstdio>

#define INT_MIN -999999999 
using namespace std;

int segment[4*1000001];
int arr[1000002];
long long int ans[1000002];

void build(int low, int high, int root) {
    if (low == high) {
        segment[root] = arr[low];
        return;
    }

    int mid = (low + high)/2;
    build(low, mid, 2*root+1);
    build(mid+1, high, 2*root+2);
    segment[root] = max(segment[2*root+1], segment[2*root+2]);
}

long long int query(int low, int high, int qlow, int qhigh, int root) {
    
    if (qlow > high || qhigh < low) {
        return INT_MIN;
    }
    if (qlow <= low && qhigh >= high) {
        return segment[root];
    }
    
    int mid = (low + high)/2;
    
    if (qlow > mid)
        return query(mid+1, high, qlow, qhigh, 2*root+2);
    if (qhigh <= mid)
        return query(low, mid, qlow, qhigh, 2*root+1);

    long long int left = query(low, mid, qlow, qhigh, 2*root+1); 
    long long int right = query(mid+1, high, qlow, qhigh, 2*root+2);
    return max(left, right);
}

int main() {
    int n;
    cin >> n;
    char ch = getchar();
    int k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ans[i] = -1;
    }
    cin >> k;
    build(0,n-1,0);
    //cout << "Built\n";
    
    /*
    for (int i = 0; i < 2*n; i++)
        cout << segment[i] << " ";
    */
    
    for (int i = 0, j = i+k; j <= n; i++, j++) {
        ans[i] = query(0, n-1, i, j-1, 0);
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] >= 0)
            cout << ans[i] << " ";
    }   
}
