class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> pq;
        int res =0;
        for(int i = 0;i < n;i++){
            pq.push(piles[i]);
        }
        while(k--){
            int temp = pq.top();
            pq.pop();
            pq.push(temp - floor(temp/2));
        }
        while(!pq.empty()){
            cout << pq.top() << " ";
            res+=pq.top();
            pq.pop();
        }
        return res;
    }
};