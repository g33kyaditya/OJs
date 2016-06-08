class Solution {
public:
    vector<int> res;
    void moveZeroes(vector<int>& nums) {
           int count = 0;
            for(int i = 0; i < nums.size(); i++) {
                if (nums[i] != 0)
                    res.push_back(nums[i]);
                else 
                    count++;
           }
           
            while(count--)
                res.push_back(0);
            
            nums = res;
    }
};
