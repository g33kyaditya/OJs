class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        unordered_map<int, int> m;
        m.clear();
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        
        unordered_map<int, int>::iterator it = m.begin();
        for(it; it != m.end(); it++) {
            if (it->second != 2)
                return it->first;
        }
        
        return -1;
    }
};
