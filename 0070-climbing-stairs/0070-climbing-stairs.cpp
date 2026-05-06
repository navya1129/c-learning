class Solution {
public:
    int climbStairs(int n) {
        if(n < 4) return n;
        int x = 1;
        int y = 2;
        int z = 3;
        for(int i = 4;i <= n;i++){
            x = y;
            y = z;
            z = x+y;
        }
        return z;
    }
};