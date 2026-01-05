class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        int cnt = 0;
        vector<vector<char>>res(m,vector<char>(n));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                res[j][i] = '.';
                if(boxGrid[i][j] == '#') cnt++;
                else if(boxGrid[i][j] == '*') {
                    res[j][i] = '*';
                    int temp = j-1;
                    while(cnt--){
                        res[temp][i] = '#';
                        temp--;
                    }
                    cnt = 0;
                }
                if(j+1 == m){
                    int temp = j;
                    while(cnt--){
                        res[temp][i] = '#';
                        temp--;
                    }
                    cnt = 0;
                }
            }
        }
        vector<vector<char>>ans(m,vector<char>(n));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                ans[i][n-1-j] = res[i][j];
            }
        }
        return ans;
    }
};