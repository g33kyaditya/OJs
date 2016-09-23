class Solution {
public:
    Solution(vector<int> nums) {
        orig = nums;
        shuff = orig;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        if (orig.empty())
            return orig;

        shuff = orig;
        return shuff;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if (orig.empty())
            return orig;

        int tot = orig.size();
        for (int i = 0; i < tot; i++) {
            int swapIndex = rand()%tot;
            shuff[i] = shuff[i] + shuff[swapIndex] - (shuff[swapIndex] = shuff[i]);
        }
        return shuff;
    }
private:
    vector<int> orig;
    vector<int> shuff;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
