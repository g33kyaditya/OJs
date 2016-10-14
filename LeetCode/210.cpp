class Solution {
public:
    vector<int> findOrder(int n, vector<pair<int, int>>& pre) {
        vector<int> ans;
        if (n == 0)
            return ans;
        
        int incoming[n] = {0};
        
        for (int i = 0; i < pre.size(); i++) {
            pair<int, int> cur = pre[i];
            incoming[cur.first]++;
        }
        bool visited[n] = {false};
        for (int i = 0; i < n; i++) {
            if (incoming[i] == 0 && !visited[i]) {
                ans.push_back(i);
                visited[i] = true;
                int next = i;
                for (int j = 0; j < pre.size(); j++) {
                    pair<int, int> cur = pre[j];
                    if (cur.second == i) {
                        incoming[cur.first]--;
                        if (incoming[cur.first] == 0) {
                            next = min(next, cur.first);
                        }
                    }
                }
                if (next != i)
                    i = next - 1;
            }
        }
        
        if (ans.size() != n)
            ans.clear();

        return ans;
    }
};
