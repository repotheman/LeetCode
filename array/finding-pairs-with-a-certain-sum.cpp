class FindSumPairs {
    vector<int> nums1, nums2;
    unordered_map<int,int> cnt2;
public:
    FindSumPairs(vector<int>& A, vector<int>& B) : nums1(A), nums2(B) {
        for (int b : nums2) cnt2[b]++;
    }
    void add(int i, int v) {
        cnt2[nums2[i]]--;
        nums2[i] += v;
        cnt2[nums2[i]]++;
    }
    int count(int tot) {
        int ans = 0;
        for (int a : nums1)
            ans += cnt2[tot - a];
        return ans;
    }
};
