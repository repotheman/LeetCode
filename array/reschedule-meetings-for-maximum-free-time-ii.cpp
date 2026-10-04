class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps(n + 1);

        // Step 1: Calculate all gaps
        gaps[0] = startTime[0];  // from 0 to first meeting
        for (int i = 1; i < n; ++i)
            gaps[i] = startTime[i] - endTime[i - 1];  // between meetings
        gaps[n] = eventTime - endTime[n - 1];  // after last meeting

        // Step 2: Compute prefix and suffix max gaps
        vector<int> maxLeft(n + 1), maxRight(n + 1);
        maxLeft[0] = gaps[0];
        for (int i = 1; i <= n; ++i)
            maxLeft[i] = max(maxLeft[i - 1], gaps[i]);

        maxRight[n] = gaps[n];
        for (int i = n - 1; i >= 0; --i)
            maxRight[i] = max(maxRight[i + 1], gaps[i]);

        // Step 3: Try each meeting
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int duration = endTime[i] - startTime[i];
            int mergedGap = gaps[i] + gaps[i + 1];

            // Find max available slot elsewhere (excluding i-th and i+1-th gap)
            int maxGapOutside = 0;
            if (i > 0)
                maxGapOutside = max(maxGapOutside, maxLeft[i - 1]);
            if (i + 2 <= n)
                maxGapOutside = max(maxGapOutside, maxRight[i + 2]);

            // If the meeting can be moved to another large enough gap
            if (duration <= maxGapOutside)
                result = max(result, mergedGap + duration);
            else
                result = max(result, mergedGap);
        }

        return result;
    }
};
