class Solution {
public:
    Solution(vector<int> nums) {
       arr = nums;
    }
    
    int pick(int target) {
        long long int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == target)
                count++;
        }
        
        int index = rand()%count + 1;
        count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (target == arr[i])
                count++;
            
            if (count == index)
                return i;
        }
        return 0;
    }
private:
    vector<int>arr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
