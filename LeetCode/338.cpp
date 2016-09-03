class Solution {
public:
    int countOnes(int num) {
        
        int power = floor(log2(num));
        int closest = pow(2, power);
        int diff = num - closest;
        int ret = 0;
        if (closest != 0)
            ret++;
        
        int ctr = 0;
        while(diff!=0) {
            if (diff%2 == 1)
                ctr++;
            
            diff = diff/2;
        }
        
        ret = ret + ctr;
        return ret;
    }

    vector<int> countBits(int num) {
        vector<int> ans;
        for (int i = 0; i <= num; i++) {
            int r = countOnes(i);
            ans.push_back(r);
        }
        
        return ans;
    }
};
