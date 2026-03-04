class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int r  = mat.size();
        int c = mat[0].size();
        int ans = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(mat[i][j] == 1){
                    int flag = 1;
                    for(int k = 0; k < c; k++) {
                        if(mat[i][k] == 1 && k != j) {
                            flag = 0;
                            break;
                        }
                    }
                    for(int k = 0; k < r; k++) {
                        if(mat[k][j] == 1 && k != i) {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag) ans++;
                }
            }
        }
        return ans;
    }
};