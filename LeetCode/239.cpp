class Solution {
public:
    
    int Max(queue<int> q) {
    int max = INT_MIN;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur > max)
            max = cur;
    }
    return max;
    }
    

    vector<int> maxSlidingWindow(vector<int>& A, int w) {
        vector<int>ans;
    if (A.empty())
        return ans;

    if (w > A.size()) {
        int max = INT_MIN;
        for (int i = 0; i < A.size(); i++) {
            if (max < A[i])
                max = A[i];
        }
        return ans;
    }
    queue<int>q;
    int max = INT_MIN;
    for (int i = 0; i < A.size(); i++) {
        
        if (q.empty()) {
            //cout << "Q is empty \n";
            int j;
            for (j = i; j <= i + w - 1 && j < A.size(); j++) {
                //cout << "Pushing " << A[j] << "\n";
                q.push(A[j]);
            }
            max = Max(q);
            //cout << "Max is = " << max << "\n";
            i = i + w - 1;
        }
        else {
            //cout << "Q is not empty \n";
            int z = q.front();
            q.pop();
            //cout << "Pushing " << A[i] << "\n";
            q.push(A[i]);
            if (A[i] > max)
                max = A[i];
            else if (z == max)
                max = Max(q);
            
            //cout << "Max is = " << max << "\n";
        }
        
        ans.push_back(max);
    }
    return ans;
    }
};
