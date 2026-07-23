class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        if(str.size() == 1) return str[0];
        int res = 0;
        int siz = str[0].size();
        for(int i = 1;i < str.size();i++){
            res = 0;
            for(int j = 0;j < str[i].size();j++){
                if(j >= siz){
                    break;
                }
                else if(str[0][j] != str[i][j]){
                    break;
                }
                res++;
            }
            siz = res;
        }
        cout << res;
        string s;
        for(int i = 0;i < res;i++){
            s.insert(s.begin() + i, str[0][i]);
            //s[i] = str[0][i];
        }
        return s;
    }
};