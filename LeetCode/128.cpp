class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
            s.insert(nums[i]);
        
        int max = 0;
        int cur = 0;
        for (int num : nums) {
            if (s.find(num - 1) == s.end()) {
                int next = num + 1;
                cur = 1;
                while (s.find(next) != s.end()) {
                    cur++;
                    next++;
                }
            }
            
            max = std::max(max, cur);
        }
        
        return max;
    }
};
