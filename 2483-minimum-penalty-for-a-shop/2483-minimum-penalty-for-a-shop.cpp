class Solution {
public:
    int bestClosingTime(string customers) {
         int n = customers.size(); 
         vector<int> yes(n,0);
         vector<int> no(n,0);
         int ans = INT_MAX;
         int cal = 0;
         for(int i = 0;i < n;i++){
            if(customers[i] == 'N'){
                if(i == 0) no[i] = 1;
                else no[i] += no[i-1]+1;
            }
            else if(i != 0) no[i] = no[i-1];
            if(customers[i] == 'Y'){
                if(i == 0) yes[i] = 1;
                else yes[i] += yes[i-1]+1;
            }
            else if(i != 0) yes[i] = yes[i-1];
            cout << yes[i] << " " << no[i] <<"\n";
         }
         int res = 0;
         for(int i = 0;i < n;i++){
            if(i == 0) cal = yes[n-1];
            else{
                cal = no[i-1] + yes[n-1] - yes[i-1];
            }
            if(ans > cal){
                res = i;
                ans = cal;
            }
         }
         if(ans > no[n-1]){
            res = n;
            ans = no[n-1];
         }
         return res;
    }
};