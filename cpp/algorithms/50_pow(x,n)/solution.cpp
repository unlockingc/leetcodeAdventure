class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        if (n == 0)
            return 1.0;
        if (n == 1)
            return x;
        if (n == -1)
            return 1.0/x;

        res = myPow(x, n/2);
        res *= res;
        if (abs(n)%2 != 0) {
            if (n > 0)
                res *= x;
            else
                res /= x;
        }
        return res;
    }
};
