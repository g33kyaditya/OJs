#include <iostream>
#include <vector>
using namespace std;

int search(int val, vector<int>arr) {
    int beg = 0;
    int end = arr.size()-1;
    int mid;
    while(beg <= end) {
        mid = (beg+end)/2;

        if (arr[mid] == val)
            return 1;

        else if (val > arr[mid])
            beg = mid+1;
        else
            end = mid-1;
    }
    return (-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    while (1) {
        int n1, n2;
        cin >> n1;
        if (n1 == 0)
            return 0;

        vector<int> a(n1);
        for (int i = 0; i < n1; i++)
            cin >> a[i];
        
        cin >> n2;
        vector<int> b(n2);
        for (int i = 0; i < n2; i++)
            cin >> b[i];
        
        vector<int> index2(n2);
        vector<int> index1(n1);

        for (int i = 0; i < n2; i++) {
            int ret = search(b[i], a);
            index2[i] = ret;
            //cout << "Ret = " << ret << " Index = " << i << "\n";
        }
        
        for (int i = 0; i < n1; i++) {
            int ret = search(a[i], b);
            index1[i] = ret;
            //cout << "Ret = " << ret << " Index = " << i << "\n";
        }
        
        //Index1 has points of interest in arr a
        //Index2 has points of interest in arr b
        

        vector<int> dp1;
        int k1 = 0;
        for (int i = n1-1; i >= 0; i--) {
            k1 = 0;
            int j = i;
            while (j >= 0 && index1[j] != 1) {
                k1 += a[j];
                j--;
            }
            if (index1[j] == 1)
                k1 += a[j];
            i = j;
            
            dp1.push_back(k1);
        }
        k1 = 0;
        vector<int> dp2;
        for (int i = n2-1; i >= 0; i--) {
            k1 = 0;
            int j = i;
            while (j >= 0 && index2[j] != 1) {
                k1 += b[j];
                j--;
            }
            if (index2[j] == 1)
                k1 += b[j];
            
            i = j;
            dp2.push_back(k1);
        }

        /*for(int i = 0; i < dp1.size(); i++)
            cout << dp1[i] << " ";
        cout << "\n";
        for (int j = 0; j < dp2.size(); j++)
            cout << dp2[j] << " ";
        cout << "\n";
        */

        if (dp1.size() < dp2.size()) {
            while (dp1.size() < dp2.size())
                dp1.push_back(0);
        }
       
        if (dp2.size() < dp1.size()) {
            while (dp2.size() < dp1.size())
                dp2.push_back(0);
        }


        int ans = 0;
        for (int i = 0; i < dp1.size(); i++) {
            ans += max(dp1[i], dp2[i]);
        }
        cout << ans << "\n";
    }
}
