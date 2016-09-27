class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    
        vector<int> ans;
        if (nums1.empty() || nums2.empty())
            return ans;
        
        unordered_map<int, int> m1;
        for (int i = 0; i < nums1.size(); i++)
            m1[nums1[i]]++;
        
        for (int i = 0; i < nums2.size(); i++) {
            if (m1[nums2[i]] > 0) {
                m1[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }
        
        return ans;
    }
};
