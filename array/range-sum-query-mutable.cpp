class NumArray {
    vector<int> tree;
    vector<int> nums;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void updateTree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            nums[idx] = val;
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                updateTree(2 * node, start, mid, idx, val);
            } else {
                updateTree(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int queryTree(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0; // no overlap
        if (l <= start && end <= r) return tree[node]; // total overlap
        int mid = (start + end) / 2;
        return queryTree(2 * node, start, mid, l, r) +
               queryTree(2 * node + 1, mid + 1, end, l, r);
    }

public:
    NumArray(vector<int>& arr) {
        nums = arr;
        n = arr.size();
        tree.assign(4 * n, 0);
        if (n > 0) build(1, 0, n - 1);
    }

    void update(int index, int val) {
        updateTree(1, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return queryTree(1, 0, n - 1, left, right);
    }
};
