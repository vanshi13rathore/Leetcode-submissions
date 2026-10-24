class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        vector<int> daysInMonth = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        auto dayNumber = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            for(int i=0; i<month-1; i++) {
                day += daysInMonth[i];
            }
            return day;
        };

        int aStart = dayNumber(arriveAlice);
        int aEnd = dayNumber(leaveAlice);
        int bStart = dayNumber(arriveBob);
        int bEnd = dayNumber(leaveBob);

        int start = max(aStart, bStart);
        int end = min(aEnd , bEnd);

        if(start > end) {
            return 0;
        }
        return end - start + 1;
    }
};