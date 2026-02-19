class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int one = 0,zero = 0;
        if(s[0] == '0') zero++;
        else one++;
        int cnt = 0;
        for(int i = 1;i < n;i++){
            if(s[i] != s[i-1]){
                if(one != 0 && zero != 0) {
                    cout << i << " ";
                    cnt += min(one,zero);
                    if(s[i-1] == '1') zero = 0;
                    else one = 0;
                }
                if(s[i] == '0') zero++;
                else one++;
            }
            else if(s[i] == '0') zero++;
            else one++;
        }
        cnt += min(one,zero);
        return cnt;
    }
};