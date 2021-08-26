#include <iostream>
#include <vector>
#include <cmath>

/** @brief : After checking some examples, I have validated the following hypothesis :
 * Let a be the smaller of the 2 consecutive integers and X be the integer in range [A, B]
 * a*(a+1) = x
 * a^2 +a - x = 0
 * a = (-1 +- sqrt(1 + 4*x)) / 2
 * I have verified that Discriminant = sqrt(1 + 4x) returns an integer only when the desired consition is satisfied
 * */

bool isInteger(float N)
{
    // Convert float value
    // of N to integer
    int X = N;
 
    float temp2 = N - X;
 
    // If N is not equivalent
    // to any integer
    if (temp2 > 0) {
        return false;
    }
    return true;
}

int NumsThatAreProdOfTwoConsecutiveIntegers(int A, int B) {

    int result = 0;
    float discriminant{};
    for(int i=A; i <= B; i++) {
        discriminant = std::sqrt(1 + (4 * i));
        // std::cout << "Disc : " << discriminant << std::endl;
        if(isInteger(discriminant))
            ++result;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    // int A{6}, B{20};
    int A{21}, B{29};
    int res = NumsThatAreProdOfTwoConsecutiveIntegers(A, B);
    std::cout << "Result : " << res << std::endl;
    return 0;
}
