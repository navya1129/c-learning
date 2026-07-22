class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        // int m = people.size();
        map<int,int> m;
        for(int i = 0;i < n;i++){
            m[flowers[i][0]]++;
            m[flowers[i][1]+1]--;
        }
        int cnt = 0;
        for(auto& [time,no_flo]:m){
            cnt += no_flo;
            no_flo = cnt;
        }
        vector<int> res;
        for(auto i:people){
            auto it = m.upper_bound(i);
            if(it == m.begin()){
                res.push_back(0);
            }
            else{
                res.push_back(prev(it)->second);
            }
        }
        return res;
    }
};