#include <iostream>
#include "sum.h"

int main() {
    int num1 = 5;
    int num2 = 7;
    int result = sum(num1, num2);
    
    std::cout << "The sum of " << num1 << " and " << num2 << " is: " << result<< std::endl;

    return 0;
}
