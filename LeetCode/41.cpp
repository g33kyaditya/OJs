class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int arr[1000000] = {0};
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                arr[nums[i]]++;
        }
        
        for (int i = 1; i < 1000000; i++) {
            if (arr[i] == 0)
                return i;
        }
        
        return 1;
    }
};
