class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k) return false; 
        map<string,int>m;
        string temp = "";
        for(int i = 0;i < k;i++){
            temp+=s[i];
        }
        m[temp]++;
        for(int i = k;i < s.size();i++){
            temp.erase(0,1);
            temp += s[i];
            m[temp]++;
        }
        if(m.size() == pow(2,k)) return true;
        return false;
    }
};