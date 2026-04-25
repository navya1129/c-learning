class Solution {
public:
    bool static comp(vector<string> &a,vector<string> &b){
        return a.size() < b.size();
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<string> copy = strs;
        for(int i = 0;i < strs.size();i++){
            sort(copy[i].begin(),copy[i].end());
        }
        map<string,vector<string>> m;
        for(int i = 0;i < strs.size();i++){
            m[copy[i]].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto i:m){
            ans.push_back(i.second);
        }
        sort(ans.begin(),ans.end(),comp);
        return ans;
    }
};