class Solution {
public:
    bool wordBreak(string s, vector<string>& word) {
        int n = s.size();
        unordered_set<string> st(word.begin(),word.end());
        vector<bool> dp(n+1,false);
        dp[0] = true;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j < i;j++){
                string word1 = s.substr(j,i-j);
                if(dp[j] && st.count(word1)){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};