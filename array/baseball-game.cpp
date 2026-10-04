class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> ans;
        
        for (const string& op : operations) {
            if (op == "D") {
                if (!ans.empty()) {
                    ans.push(ans.top() * 2);
                }
            } 
            else if (op == "C") {
                if (!ans.empty()) {
                    ans.pop();
                }
            } 
            else if (op == "+") {
                if (ans.size() >= 2) {
                    int top1 = ans.top(); ans.pop();
                    int top2 = ans.top();
                    ans.push(top1);  // Restore top1
                    ans.push(top1 + top2);
                }
            } 
            else {
                ans.push(stoi(op));  // Convert string to integer
            }
        }

        // Sum all stack elements
        int sum = 0;
        while (!ans.empty()) {
            sum += ans.top();
            ans.pop();
        }
        return sum;
    }
};