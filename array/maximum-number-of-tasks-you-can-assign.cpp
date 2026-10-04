class Solution {
public:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> available(workers.end() - k, workers.end());  // strongest k workers

        for (int i = k - 1; i >= 0; i--) {  // hardest k tasks
            int task = tasks[i];

            auto it = available.lower_bound(task);
            if (it != available.end()) {
                available.erase(it);  // assign without pill
            } else {
                if (pills == 0) return false;

                it = available.lower_bound(task - strength);
                if (it == available.end()) return false;

                available.erase(it);  // assign with pill
                pills--;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int low = 0, high = min((int)tasks.size(), (int)workers.size());
        int result = 0;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (canAssign(mid, tasks, workers, pills, strength)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};
