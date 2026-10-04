class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events by start day
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap for end days
        int i = 0, n = events.size(), day = 0, count = 0;

        while (i < n || !minHeap.empty()) {
            if (minHeap.empty()) {
                day = events[i][0]; // move to the next event's start day if heap is empty
            }

            // Add all events starting today to the heap
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]);
                i++;
            }

            // Remove expired events
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            // Attend the event that ends earliest
            if (!minHeap.empty()) {
                minHeap.pop();
                count++;
                day++;
            }
        }

        return count;
    }
};