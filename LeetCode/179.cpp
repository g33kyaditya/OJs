class Solution {
public:
    static bool comp(int a, int b) {
        if (a == b)
            return true;
        
        string str1 = "";
        string str2 = "";
        
        str1 = std::to_string(a) + std::to_string(b);
        str2 = std::to_string(b) + std::to_string(b);
        
        if (str1 < str2)
            return true;
        
        return false;
    }
    string largestNumber(vector<int>& nums) {
        bool stat = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                stat = true;
            }
        }
        if (!stat) {
            string str = "0";
            return str;
        }
        sort(nums.begin(), nums.end(), comp);   
        string str = "";
        for (int i = nums.size()-1; i >= 0; i--)
            str = str + std::to_string(nums[i]);
        
        return str;
    }
};
