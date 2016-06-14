class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = 1;
            }
            else {
                mp[nums[i]] += 1;
                if (mp[nums[i]] > 1)
                    return true;
            }
        }
        return false;
    }
};
