//Divide two integers without using multiplication, division and mod operator.
//
//If it is overflow, return MAX_INT.
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <climits> //INT_MAX
#include <cmath> // abs
#include <iostream>

using namespace std;

int divide(int dividend, int divisor) {
    int answer = 0;
    if (dividend == INT_MIN && divisor == -1 || divisor == 0){
        return INT_MAX;
    }
    if (dividend == INT_MIN){
        dividend += abs(divisor);
        ++answer;
    } if (divisor == INT_MIN){
        return answer;
    }

    answer += pow(10, (log10(abs(dividend)) - log10(abs(divisor)))) + 0.0001;

    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        return -answer; // opposite signs, quotient is negative
    else
        return answer;
}


TEST_CASE ("Division is performed without /", "[division]"){

    REQUIRE ( divide(7,2)               == 3 );
    REQUIRE ( divide(7,-2)              == -3 );
    REQUIRE ( divide(INT_MAX, 1)        == INT_MAX );
    REQUIRE ( divide(INT_MIN, -1)       == INT_MAX );
    REQUIRE ( divide(INT_MIN, INT_MIN)  == 1 );
    REQUIRE ( divide(INT_MIN, -2)       == INT_MIN/-2 );

}
