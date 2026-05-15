// Time Complexity: O(log n)
// Space Complexity: O(log n)
class Solution {
public:
    double solve(double x, long long n){
        if(n==0)    return 1;
        double num=solve(x,n/2);
        if(n%2==0){
            return num*num;
        }
        else{
            return x*num*num;
        }
    }
    double myPow(double x, int n) {
        long long N=n;
        if(N<0){
            N*=-1;
            x=1/x;
        }
        return solve(x,N);
    }
};
