class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        deque<int> dq;
        int n = skills.size();
        if(k >= n) return distance(skills.begin(),max_element(skills.begin(),skills.end()));
        for(int i = n-1;i >= 0;i--) dq.push_front(i);
        map<int,int> m;
        while(true){
            int one = dq.front();
            dq.pop_front();
            int two = dq.front();
            dq.pop_front();
            if(skills[one] > skills[two]){
                while(skills[one] > skills[two]){
                    dq.push_back(two);
                    two = dq.front();
                    dq.pop_front();
                    m[one]++;
                    if(m[one] == k) return one;
                }
            }
            else{
                while(skills[one] < skills[two]){
                    dq.push_back(one);
                    one = dq.front();
                    dq.pop_front();
                    m[two]++;
                    if(m[two] == k) return two;
                }
            }
            dq.push_front(one);
            dq.push_front(two);
        }
        return -1;
    }
};