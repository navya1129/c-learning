class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        map<char,char>m;
        int n = s1.size();
        for(int i = 0;i < n;i++){
            if(m[s1[i]] == 0){
                m[s1[i]] = min(s1[i],s2[i]);
            }
            else {
                m[s1[i]] = min(m[s1[i]],s2[i]);
            }
        }
        for(int i = 0;i < n;i++){
            if(m[s2[i]] == 0){
                m[s2[i]] = min(s1[i],s2[i]);
            }
            else {
                m[s2[i]] = min(m[s2[i]],s1[i]);
            }
            cout << m[s2[i]] << " ";
        }
        for(int i = 0;i < n;i++){
            m[s1[i]] = min({m[m[s1[i]]],m[s1[i]],m[m[s2[i]]]});
        }
        for(int i = 0;i < n;i++){
            m[s2[i]] = min({m[m[s1[i]]],m[s2[i]],m[m[s2[i]]]});
        }
        for(int i = 0;i < n;i++){
            m[s1[i]] = min({m[m[s1[i]]],m[s1[i]],m[m[s2[i]]]});
        }
        for(int i = 0;i < n;i++){
            m[s2[i]] = min({m[m[s1[i]]],m[s2[i]],m[m[s2[i]]]});
        }
        for(int i = 0;i < n;i++){
            m[s1[i]] = min({m[m[s1[i]]],m[s1[i]],m[m[s2[i]]]});
        }
        string s = "";
        for(int i = 0;i < baseStr.size();i++){
            if(!(m.find(baseStr[i]) != m.end())) s+= baseStr[i];
            else s+=m[baseStr[i]];
        }
        return s;
        
    }
};