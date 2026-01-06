class Solution {
public:
    double angleClock(int hour, int minutes) {
        int temp = minutes;
        hour = (hour+1)%12;
        int rem_min = minutes%5;
        minutes = minutes/5;
        double ans = 0;
        if(hour > minutes){
            hour--;
            ans = (hour-minutes)*30;
            ans -= rem_min*6;
            ans += ((temp/12)*6 + (temp%12)*0.5);
        }
        else if(hour <= minutes){
            ans = (minutes-hour)*30;
            ans += rem_min*6;
            ans += (30 - (((temp/12)*6) + (temp%12)*0.5));
        }
        ans = abs(ans);
        return min(360-ans,ans);
    }
};