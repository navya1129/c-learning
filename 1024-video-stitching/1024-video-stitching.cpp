class Solution {
public:

    static bool comp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), comp);
        int n = clips.size();
        int cnt = 0;
        int mini = 0;
        int maxi = 0;
        int i = 0;
        while(maxi < time) {
            int temp_maxi = maxi;
            int temp_mini = mini;
            while(i < n && clips[i][0] <= maxi) {
                if(clips[i][1] > temp_maxi) {
                    temp_maxi = clips[i][1];
                    temp_mini = clips[i][0];
                }
                i++;
            }
            if(temp_maxi == maxi) {
                return -1;
            }
            cnt++;
            maxi = temp_maxi;
            mini = temp_mini;
        }

        return cnt;
    }
};