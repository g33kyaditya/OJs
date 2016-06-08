class Solution {
public:
    vector<int> res;
    bool search(int val, vector<int>& arr) {
        int start = 0;
        int end = arr.size()-1;
        int mid;
        
        while (start <= end) {
            mid = (start+end)/2;
            if (arr[mid] == val)
                return true;
            else if (arr[mid] < val)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        if (nums1.size() < nums2.size()) {
            for (int i = 0; i < nums2.size(); i++) {
                if (search(nums2[i], nums1)) {
                    if(!search(nums2[i],res))
                        res.push_back(nums2[i]);
                }
            } 
        }
        else {
            std::sort(nums2.begin(), nums2.end());
            for (int i = 0; i < nums1.size(); i++) {
                if (search(nums1[i], nums2)) {
                    if (!search(nums1[i], res))
                        res.push_back(nums1[i]);
                }
            } 
        }
        
        return res;   
    }
    
};
