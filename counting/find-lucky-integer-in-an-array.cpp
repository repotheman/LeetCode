class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freq(501, 0);
        for (int x : arr)
            if (x <= 500)
                freq[x]++;
        for (int i = 500; i >= 1; --i)
            if (freq[i] == i)
                return i;
        return -1;
    }
};