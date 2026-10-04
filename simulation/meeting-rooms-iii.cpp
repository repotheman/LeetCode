class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; ++i)
            available.push(i);

        // {endTime, room}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

        vector<int> count(n, 0);

        for (auto& meeting : meetings) {
            long long start = meeting[0], end = meeting[1];

            // Free up rooms that are available before meeting start
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty()) {
                int room = available.top(); available.pop();
                busy.push({end, room});
                count[room]++;
            } else {
                auto [freeTime, room] = busy.top(); busy.pop();
                busy.push({freeTime + (end - start), room});
                count[room]++;
            }
        }

        // Find the room with the max meetings
        int maxMeetings = 0, resultRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > maxMeetings) {
                maxMeetings = count[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};
