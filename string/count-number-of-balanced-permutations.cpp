class Solution {
public:
    static const int MOD = 1000000007;
    int countBalancedPermutations(string num) {
        int n = num.size();
        vector<int> cnt(10, 0);
        long long total = 0;

        for (char c : num) {
            int d = c - '0';
            cnt[d]++;
            total += d;
        }

        // If total sum is odd, no balanced permutation is possible
        if (total % 2 != 0) {
            return 0;
        }

        int target = total / 2;
        int evenCount = (n + 1) / 2;
        int oddCount = n / 2;

        // Precompute factorials and inverse factorials up to n
        vector<long long> fact(n + 1, 1), invFact(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        // Fermat’s Little Theorem for modular inverse
        auto modexp = [&](long long a, long long e) -> long long {
            long long res = 1;
            while (e) {
                if (e & 1)
                    res = (res * a) % MOD;
                a = (a * a) % MOD;
                e >>= 1;
            }
            return res;
        };

        invFact[n] = modexp(fact[n], MOD - 2);
        for (int i = n; i > 0; i--) {
            invFact[i - 1] = invFact[i] * i % MOD;
        }

        vector<vector<long long>> dp(evenCount + 1,
                                     vector<long long>(target + 1, 0));
        dp[0][0] = 1;

        for (int d = 0; d <= 9; d++) {
            if (cnt[d] == 0)
                continue;
            vector<vector<long long>> nxt(evenCount + 1,
                                          vector<long long>(target + 1, 0));
            for (int u = 0; u <= evenCount; u++) {
                for (int s = 0; s <= target; s++) {
                    long long ways = dp[u][s];
                    if (!ways)
                        continue;
                    for (int x = 0; x <= cnt[d]; x++) {
                        int r = x;
                        int l = cnt[d] - x;
                        int newU = u + r;
                        int newS = s + d * r;
                        if (newU > evenCount || newS > target)
                            break;
                        long long add = ways * invFact[r] % MOD;
                        add = add * invFact[l] % MOD;
                        nxt[newU][newS] = (nxt[newU][newS] + add) % MOD;
                    }
                }
            }
            dp.swap(nxt);
        }

        long long ans = dp[evenCount][target];
        ans = ans * fact[evenCount] % MOD;
        ans = ans * fact[oddCount] % MOD;
        return ans;
    }
};