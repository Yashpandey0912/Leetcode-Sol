class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long x, long long n) {
        if(n == 0)
            return 1;

        long long half = power(x, n / 2);

        if(n % 2 == 0)
            return (half * half) % MOD;

        return (half * half % MOD * x) % MOD;
    }

    int countGoodNumbers(long long n) {
        long long ans = power(20, n / 2);

        if(n % 2 == 1)
            ans = (ans * 5) % MOD;

        return ans;
    }
};