#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int a[4000],b[4000],c[4000],d[4000];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int v;
    for (int i=0;i<n;i++) { 
	cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    
    long xi=0,yi=0;
    vector<int> X(n*n),Y(n*n);
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            X[xi++] = a[i] + b[j];
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            Y[yi++] = c[i] + d[j];
	    
	    }
    }
    
    sort(Y.begin(),Y.end());
    int count=0;
    for (int i=0;i<xi;i++) {
        int x = X[i];
	    if (binary_search(Y.begin(),Y.end(),-x)) {
	    int low = 0;
            int high = yi-1;
            int mid;
            while (low <= high) {
                mid = (high+low)/2;
                if (Y[mid] == -x) {
                    count++;
		    int index = mid-1;
                    while (Y[index] == (-x)) {
                        count++;
                        index--;
                    }
                    index = mid+1;
                    while (Y[index] == (-x)) {
                        count++;
                        index++;
                    }
                
		    break;
		}

                else if (Y[mid] < -x)
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
    }
    cout << count << endl;
}
