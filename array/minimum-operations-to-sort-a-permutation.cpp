class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // Step 1: find where 0 is located
        int p = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                p = i;
            }
        }

        // Step 2: check if the array is a valid rotation (forward)
        // or a valid reversed rotation (backward)
        bool forward = true;
        bool backward = true;

        for (int i = 0; i < n; i++) {
            int current = nums[i];
            int next = nums[(i + 1) % n];

            // in forward case, next should be current + 1
            if (next != (current + 1) % n) {
                forward = false;
            }

            // in backward case, next should be current - 1
            if (next != (current - 1 + n) % n) {
                backward = false;
            }
        }

        // Step 3: if neither works, we can never sort it
        if (!forward && !backward) {
            return -1;
        }

        // Step 4: if it's already a forward rotation,
        // the cost is p (rotate p times) or reverse trick
        if (forward) {
            return min(p, n - p + 2);
        }

        // Step 5: backward case, we must reverse at least once.
        // Try every number of left rotations 'a' before reversing,
        // and keep the cheapest total.
        int best = INT_MAX;
        for (int a = 0; a < n; a++) {
            int q = (n - 1 - p + a) % n;   // position of 0 after reversing
            int cost = a + 1 + min(q, n - q + 2);
            best = min(best, cost);
        }

        return best;
    }
};