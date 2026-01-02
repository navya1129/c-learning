class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0;
        int j = 0;
        vector<string>v;
        int wc = 0;
        int len = 0;
        while(j < words.size()){
            if(len+wc+words[j].size() <= maxWidth){
                len += words[j].size();
                wc++;
            }
            else{
                string s = words[i];
                if(wc > 1){
                    int space = (maxWidth - (len)) / (wc-1);
                    int rem = 0;
                    if((maxWidth-len) % (wc-1) != 0) rem = ((maxWidth-len) % (wc-1));
                    i++;
                    while(i < j && wc-1 != 0){
                        if(rem >0){
                            int temp = space+1;
                            while(temp--){
                                s += ' ';
                            }
                            rem--;
                        }
                        else{
                            int temp = space;
                            while(temp--){
                                s += ' ';
                            }
                        }
                        s += words[i];
                        i++;
                    }
                }
                else{
                    i++;
                    int space = maxWidth - len;
                    while(space--) s += ' ';
                }
                v.push_back(s);
                j--;
                wc = 0;
                len = 0;
            }
            j++;
        }
        string s = "";
        while(i < words.size()){
            s += words[i];
            if(i != words.size()-1) s += ' ';
            i++;
        }
        len = maxWidth - (len+wc-1);
        while(len--){
            s += ' ';
        }
        v.push_back(s);
        return v;
    }
};