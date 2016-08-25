class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        std::unordered_map<long long int, long long int> m;
        
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        
        std::unordered_map<long long int, long long int>::iterator it = m.begin();
        for (it; it != m.end(); it++) {
            long long int key = it->first;
            if (m[key] == 1)
                ans.push_back(key);
        }
        return ans;
    }
private:
    vector<int> ans;
};
