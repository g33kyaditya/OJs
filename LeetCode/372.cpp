class Solution {
public:

    int myPow( int x, int y ){
        int ans = 1;
        while(y-- )
            ans = ans * x % 1337;
        return ans;
    }


    int superPow(int a, vector<int>& b) {
        a = a % 1337;
        long long int ans = 1;
        while( b.size() ){
            ans = ans * myPow(a, b.back()) % 1337;
            b.pop_back();
            a = myPow( a, 10 );
        }
        return ans;
    }
};
