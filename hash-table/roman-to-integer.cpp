class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            // Get the value of the current character
            int currentVal = getValue(s[i]);

            // Check if subtractive notation is needed
            if (i + 1 < s.length()) {
                int nextVal = getValue(s[i + 1]);
                if (currentVal < nextVal) {
                    ans += (nextVal - currentVal);
                    i++; // Skip the next character
                    continue;
                }
            }

            // Add the current value
            ans += currentVal;
        }
        return ans;
    }

private:
    // Helper function to get the value of a Roman numeral character
    int getValue(char ch) {
        switch (ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0; // Invalid character
        }
    }
};