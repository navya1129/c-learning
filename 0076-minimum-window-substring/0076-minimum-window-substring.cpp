class Solution {
public:
    string minWindow(string s, string t) {
        map<int,int> mt;
        map<int,int> ms;
        int ans = INT_MAX,index = 0;
        for(int i = 0;i < t.size();i++) mt[t[i]]++;
        int i =0 ,j = 0,n = s.size();
        int cnt = 0;
        while(j < n){
            ms[s[j]]++;
            if(mt.find(s[j]) != mt.end() && ms[s[j]] == mt[s[j]]) cnt++;
            if(mt.size() == cnt){
                if(ans > j-i+1){
                    ans = j-i+1;
                    index = i;
                }
                while(mt.size() == cnt && i < j){
                    if(ms[s[i]] == 1) ms.erase(s[i]);
                    else ms[s[i]]--;
                    if(mt.find(s[i]) != mt.end() && mt[s[i]] > ms[s[i]]) cnt--;
                    if(ans > j-i && mt.size() == cnt){
                    ans = j-i;
                    index = i+1;
                    }
                    i++;
                }
            }
            j++;
        }
        if(ans == INT_MAX) return "";
        string res = "";
        for(int x = index;x < index + ans;x++) if(x < s.size()) res += s[x];
        return res;
    }
};