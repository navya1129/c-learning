class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> s;
        vector<int> ans(temp.size());
        for(int i = 0;i < temp.size();i++){
            while(!s.empty() && temp[s.top()] < temp[i]){
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};