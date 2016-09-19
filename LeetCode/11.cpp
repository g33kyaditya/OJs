class Solution {
public:
    int maxArea(vector<int>& height) {
    
        int lo = 0;
        int hi = height.size()-1;
        
        int maxArea = (hi - lo)*(std::min(height[lo], height[hi]));
        int curArea;
        while (lo <= hi) {
            curArea = (hi - lo)*(std::min(height[lo], height[hi]));;
            if (curArea > maxArea) {
                maxArea = curArea;
            }
            
            if (height[lo] < height[hi])
                lo++;
            else
                hi--;
        }
        
        return maxArea;
    }
};
