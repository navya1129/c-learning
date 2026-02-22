class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int cnt = 0;
        int one = 0;
        while(n > 0){
            if(n%2 == 0) cnt++;
            else{
                if(one >= 1) ans=  max(ans,cnt);
                one++;
                cnt = 0;
            }
            n = n/2;
        }

        if(ans == 0 && one <= 1) return ans;
        return ans+1;
    }
};