class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        
        std::sort(citations.begin(), citations.end());
        std::reverse(citations.begin(), citations.end());
        int i;
        for (i = 0; i < citations.size(); i++) {
            if (i + 1 > citations[i])
                return i;
        }
         
        return i;
    }
};
