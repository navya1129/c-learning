class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long low = min(a,b);
        long long high = n* 1LL * min(a,b);
        long long ans = LLONG_MAX;
        long long mod = 1e9+7;
        while(low <= high){
            long long mid = low + (high-low)/2;
            long long div_a = mid/a;
            long long div_b = mid/b;
            long long lcm = a*b/__gcd(a,b);
            long long inter = mid/lcm;
            long long cnt = div_a + div_b - inter;
            if(n <= cnt) {
                ans = mid%mod;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans%mod;
    }
};