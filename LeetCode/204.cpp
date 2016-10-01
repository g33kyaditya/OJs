class Solution {
public:
    int countPrimes(int n) {
        bool * arr = new bool[n];
        for (int i = 2; i < n; i++)
            arr[i] = true;
        arr[0] = arr[1] = false;
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (arr[i] == false)
                continue;
            
            for (int j = 2; i*j < n; j++)
                arr[i*j] = false;
        }
        
        for (int i = 2; i < n; i++) {
            if (arr[i])
                count++;
        }
        
        return count;
    }
};
