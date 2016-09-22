class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        if (gas.empty() || cost.empty())
            return -1;

        int index = 0;
        int sum = 0;
        int total = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            
            sum = sum + (gas[i] - cost[i]);
            total = total + (gas[i] - cost[i]);
            
            if (sum < 0) {
                sum = 0;
                index = i+1;
            }
        }
        
        if (total >= 0)
            return index%(gas.size());
        else
            return -1;
    }
};
