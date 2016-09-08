class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>m;
        int first, last;
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(target-nums[i]) == 1) {
                first = m[target - nums[i]];
                last = i;
                break;
            }
            else {
                m[nums[i]] = i;
            }
        }
        
        vector<int> ans;
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};
