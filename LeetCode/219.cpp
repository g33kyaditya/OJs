class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        multimap<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end())
                m.insert(make_pair(nums[i], i));
            else {
                int currentIndex = i;
                pair<multimap<int,int>::iterator, multimap<int,int>::iterator> p;
                p = m.equal_range(nums[i]);
                for (auto it = p.first; it != p.second; it++) {
                    int otherIndex = it->second;
                    if (abs(otherIndex - currentIndex) <= k)
                        return true;
                }
                m.insert(make_pair(nums[i], i));
            }
        }
        return false;
    }
};
