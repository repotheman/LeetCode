class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int total = 0;
        for (int x : cardPoints) {
            total += x;
        }

        int windowSize = n - k;

        // If we take all cards
        if (windowSize == 0) {
            return total;
        }

        int windowSum = 0;

        // First window
        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }

        int minWindowSum = windowSum;

        // Sliding window
        for (int right = windowSize; right < n; right++) {
            windowSum += cardPoints[right];
            windowSum -= cardPoints[right - windowSize];

            minWindowSum = min(minWindowSum, windowSum);
        }

        return total - minWindowSum;
    }
};