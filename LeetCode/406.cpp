class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int>b) {
        if (a.first > b.first)
            return true;
        else if (a.first < b.first)
            return false;
        else {
            if (a.second < b.second)
                return true;
            return false;
        }
    }

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        if (people.empty())
            return people;
        
        vector<pair<int,int>>res;
        sort(people.begin(), people.end(), comp);
        
        stack<pair<int,int>> st;
        for (int i = 0; i < people.size(); i++) {
            if (people[i].second > res.size())
                res.push_back(people[i]);
            else {
                while (people[i].second < res.size()) {
                    st.push(res.back());
                    res.pop_back();
                }
                res.push_back(people[i]);
                while (!st.empty()) {
                    res.push_back(st.top());
                    st.pop();
                }
            }
        }
        
        return res;
    }
};
