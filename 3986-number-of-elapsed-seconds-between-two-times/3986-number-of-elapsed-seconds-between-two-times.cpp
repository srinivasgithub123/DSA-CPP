class Solution {
public:

    int timeToSeconds(string time){
        int hh= stoi(time.substr(0, 2));
        int mm= stoi(time.substr(3, 2));
        int ss= stoi(time.substr(6, 2));
        int totalsec= (hh*3600)+(mm*60)+ss;
        return totalsec;
    }

    int secondsBetweenTimes(string startTime, string endTime) {
        int start= timeToSeconds(startTime);
        int end= timeToSeconds(endTime);

     return end-start;        
    }
};