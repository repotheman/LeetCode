class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int n = haystack.length();
        int m = needle.length();

        if (m == 0) {
            return 0;
        }

        // 1. Build the LPS array for the needle
        std::vector<int> lps(m, 0);
        for (int i = 1, length = 0; i < m;) {
            if (needle[i] == needle[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // 2. Search haystack using the LPS array
        int i = 0; // pointer for haystack
        int j = 0; // pointer for needle
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == m) {
                // Match found, return start index
                return i - j;
            } else if (i < n && haystack[i] != needle[j]) {
                // Mismatch, use LPS to find next match position
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return -1; // No match found
    }
};