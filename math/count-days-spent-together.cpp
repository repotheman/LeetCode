class Solution {
public:
    int calculateDays(string s) {
        int month = stoi(s.substr(0, 2));
        int day = stoi(s.substr(3, 2));

        return (275 * month) / 9
               - 2 * ((month + 9) / 12)
               + day - 30;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int start = max(calculateDays(arriveAlice),
                        calculateDays(arriveBob));

        int end = min(calculateDays(leaveAlice),
                      calculateDays(leaveBob));

        return max(0, end - start + 1);
    }
};