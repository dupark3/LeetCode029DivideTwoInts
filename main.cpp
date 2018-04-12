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
        if (dividend <= INT_MIN || divisor == 0)
            return INT_MAX;

        bool opposite_signs = false;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
            opposite_signs = true;
            dividend = dividend - dividend - dividend; // flip sign
        }

        int answer = 0;
        while (abs(dividend) >= abs(divisor)){
            dividend -= divisor;
            ++answer;
        }

        if (opposite_signs)
            return answer - answer - answer;
        else
            return answer;
    }
};

int main()
{
    Solution s;
    int answer = s.divide(2147483647, 1);
    cout << answer << endl;

    return 0;
}
