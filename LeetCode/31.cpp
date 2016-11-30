class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int lastI = -1;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] < nums[i+1])
                lastI = i;
        }
        
        if (lastI == -1) {
            std::reverse(nums.begin(), nums.end());
            return;
        }
        
        int lastJ = -1;
        for (int j = lastI+1; j < nums.size(); j++) {
            if (nums[j] > nums[lastI])
                lastJ = j;
        }
        
        int temp = nums[lastI];
        nums[lastI] = nums[lastJ];
        nums[lastJ] = temp;
        
        int i = lastI + 1;
        int j = nums.size() - 1;
        while (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
        
    }
};
