class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        m.clear();
        
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        
        vector<int> ans;
        
        
        multimap<int, int>p;
        p.clear();
        
        map<int,int>::iterator it;
        for (it = m.begin(); it != m.end(); it++) {
            int val = it->first;
            int numOfTimes = it->second;
            
            p.insert(std::make_pair(numOfTimes, val));
        }
        multimap<int, int>::reverse_iterator pt;
        int c = 0;
        for (pt = p.rbegin(); pt != p.rend(); pt++) {
            if (c >= k)
                break;
            
            ans.push_back(pt->second);
            c++;
        }
        
        return ans;
    }
};
