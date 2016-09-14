class Solution {
public:
    vector<pair<int, int> > twoSum(vector<int> num, int target, int low, int high)
    {
        vector<pair<int,int> > ans;
        while (low != high)
        {
            if (low > high)
                break;
            if (num[low]+num[high] == target)
            {
                ans.push_back(make_pair(num[low], num[high]));
                do{
                    high--;
                }while (num[high] == num[high+1]);
                do{
                    low++;
                }while (num[low] == num[low-1]);
            }
            else if (num[low] + num[high] > target)
                high--;
            else
                low++;
        }
        return ans;
    }

    vector<vector<int> > threeSum(vector<int> &num)
    {
        vector<vector<int> > ans;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++)
        {
            vector<pair<int, int> > temp = twoSum(num, 0 - num[i], i+1, num.size() - 1);
            while (num[i] == num[i+1])
            {
                if (i == (int)num.size() - 1)
                    break;
                i++;
            }
            if (temp.size() != 0)
            {
                for (int j = 0; j < temp.size(); j++)
                {
                    vector<int> to_push;
                    to_push.push_back(num[i]);
                    to_push.push_back(temp[j].first);
                    to_push.push_back(temp[j].second);
                    ans.push_back(to_push);
                }
            }
        }
        for (int i = 1; i < ans.size(); i++)
            if (ans[i] == ans[i-1])
            {
                ans.erase(ans.begin()+i);
                i--;
            }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
