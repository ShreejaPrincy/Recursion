// Time Complexity: O(log n)
// Space Complexity: O(log n)
class Solution {
public:
    long long mod = 1000000007;
    long long solve(int num, long long n) {
        if (n == 0)
            return 1;
        long long half = solve(num, n / 2);
        if (n % 2 == 0)
            return half * half % mod;
        else
            return (num * half % mod * half) % mod;
    }
    int countGoodNumbers(long long n) {
        long long even_pos = (n + 1) / 2;
        long long odd_pos = n / 2;
        long long ans = (solve(5, even_pos) * solve(4, odd_pos)) % mod;
        return (int)ans;
    }
};
