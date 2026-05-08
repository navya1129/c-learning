class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> m;
        int n = s.size();
        for(int i =0 ;i < n;i++){
            m[s[i]]++;
        }
        map<char,int> m1;
        int j = 0;
        vector<int> ans;
        for(int i = 0;i < n;i++){
            m1[s[i]]++;
            if(m[s[i]] == m1[s[i]]) m1.erase(s[i]);
            if(m1.size() == 0) {
                ans.push_back(i-j+1);
                j = i+1;
            }
        }
        return ans;
    }
};