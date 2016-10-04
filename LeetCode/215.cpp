class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        std::priority_queue<int, std::vector<int>, std::greater<int> > heap;
        for (int i = 0; i < nums.size(); i++)
            heap.push(nums[i]);
        
        int ans;
        int c = nums.size()-k+1;
        while ( c--) {
            ans = heap.top();
            heap.pop();
        }
        return ans;
    }
};
