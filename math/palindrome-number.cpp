#include <climits>
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int original = x;
        int reversed = 0;
        while (x != 0) {
            int rem = x % 10;
            if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && rem > 7)) {
                return false;
            }
            reversed = reversed * 10 + rem;
            x /= 10;
        }
        return reversed == original;
    }
};