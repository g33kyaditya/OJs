class Solution {
public:
    
    Solution() {
        m.insert(std::make_pair(1000, "M"));
        m.insert(std::make_pair(900, "CM"));
        m.insert(std::make_pair(500, "D"));
        m.insert(std::make_pair(400, "CD"));
        m.insert(std::make_pair(100, "C"));
        m.insert(std::make_pair(90, "XC"));
        m.insert(std::make_pair(50, "L"));
        m.insert(std::make_pair(40, "XL"));
        m.insert(std::make_pair(10, "X"));
        m.insert(std::make_pair(9, "IX"));
        m.insert(std::make_pair(5, "V"));
        m.insert(std::make_pair(4, "IV"));
        m.insert(std::make_pair(1, "I"));
    }


    void foo(int num, string& ans) {
        auto it = m.lower_bound(num);
        if (it->first == num)
            ans = ans + it->second;
        else {
            it--;
            ans = ans + it->second + intToRoman(num - it->first);
        }
    }

    string intToRoman(int num) {
        string ans = "";
        foo(num, ans);
        return ans;
    }
private:
    map<int, string> m;
};
