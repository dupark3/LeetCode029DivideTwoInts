//Divide two integers without using multiplication, division and mod operator.
//
//If it is overflow, return MAX_INT.

#include <climits> //INT_MAX
#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor != 0){
            int answer = 0;
            while (dividend > divisor){
                dividend -= divisor;
                ++answer;
            }
            return answer;
        } else {
            return INT_MAX;
        }

    }
};

int main()
{
    Solution s;
    int answer = s.divide(5, 2);
    cout << answer << endl;

    return 0;
}
