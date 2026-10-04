class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;   // powers of three are positive
        if (n == 1) return true;    // base case: 3^0 = 1
        if (n % 3 != 0) return false; // must be divisible by 3

        return isPowerOfThree(n / 3); // check the reduced number
    }
};
