class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1) return s;
        n = n-1;
        long long ans = s + (long long)((n+1)/2)*m - (n/2);
        if(n%2 == 0){
            return ans + 1;
        }
        return ans;
    }
};