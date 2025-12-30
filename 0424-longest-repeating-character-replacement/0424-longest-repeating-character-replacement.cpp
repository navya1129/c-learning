class Solution {
public:
    int fun(map<char,int> m){
        int maxi = 0;
        for(auto i:m){
            maxi = max(maxi,i.second);
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int n = s.size();
        map<char,int> m;
        int maxi = 0;
        char chr;
        int ans = 0;
        while(j < n){
            m[s[j]]++;
            maxi = fun(m);
            if(j-i+1 - maxi > k) {
                ans = max(ans,j-i);
                cout << ans << "\n";
                while(j-i+1 - maxi > k && i < j){
                    m[s[i]]--;
                    maxi = fun(m);
                    i++;
                }
            }
            j++;
        }
        ans = max(ans,j-i);
        return ans;
    }
};