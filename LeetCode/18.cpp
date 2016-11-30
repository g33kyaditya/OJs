class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        if (nums.empty())
            return ans;

        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            int a = nums[i];
            
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            for (int j = i+1; j < n - 2; j++) {
                int b = nums[j];
                
                if (j > i + 1 && nums[j] == nums[j-1])
                    continue;
                
                int left = j+1, right = n-1;
                while (left < right) {
                    if (left > j+1 && nums[left] == nums[left-1]) {
                        left++;
                        continue;
                    }
                    int sum = a + b + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> vec;
                        vec.push_back(a);
                        vec.push_back(b);
                        vec.push_back(nums[left]);
                        vec.push_back(nums[right]);
                        ans.push_back(vec);
                        left++;
                        right--;
                    }
                    else if (sum < target)
                        left++;
                    else
                        right--;
                }
                
            }
        }
        return ans;
    }
};
