//Divide two integers without using multiplication, division and mod operator.
//
//If it is overflow, return MAX_INT.

#include <climits> //INT_MAX
#include <cmath> // abs
#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int answer = 0;
        if (dividend == INT_MIN && divisor == -1 || divisor == 0){
            return INT_MAX;
        }
        if (dividend == INT_MIN){
            dividend += abs(divisor);
            answer = 1;
        } if (divisor == INT_MIN){
            return 0;
        }
//        float logdividend = log10(abs(dividend));
//        double logdivisor = log10(abs(divisor));
//        double logdifference = logdividend - logdivisor;
        answer += pow(10, (log10(abs(dividend)) - log10(abs(divisor)))) + 0.0001;

        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            return answer - answer - answer; // opposite signs, quotient is negative
        else
            return answer;
    }
};

int main()
{
    Solution s;
    int answer = s.divide(-100, -2147483648);
    cout << answer << endl;

    return 0;
}
