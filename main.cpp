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
        unsigned long answer = pow(10, (log10(abs(dividend)) - log10(abs(divisor)))) + 0.0001;

        if (answer > INT_MAX)
            return INT_MAX;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            return answer - answer - answer; // opposite signs, quotient is negative
        else
            return answer;
    }
};

int main()
{
    Solution s;
    int answer = s.divide(-2147483648, -1);
    cout << answer << endl;

    return 0;
}
