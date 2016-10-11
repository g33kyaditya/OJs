class Solution {
public:
    bool isOperator(char ch) {
        if (ch == '+' || ch == '-' || ch == '*')
            return true;
        
        return false;
    }
    
    int cal(int num1, int num2, char op) {
        
        switch (op) {
            case '+' : return num1 + num2;
            case '-' : return num1 - num2;
            case '*' : return num1 * num2;
        }
        return -1;
         
    }
    
    vector<int> diffWaysToCompute(string input) {
        
        vector<int> res;
        if (input.empty())
            return res;

        for (int i = 0; i < input.length(); i++) {
            
            if (!isOperator(input[i]))
                continue;
            
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i+1));
            
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    int val = cal(left[j], right[k], input[i]);
                    res.push_back(val);
                }
            }
        }
        if (res.empty())
            res.push_back(atoi(input.c_str()));

        return res;
    }
};
