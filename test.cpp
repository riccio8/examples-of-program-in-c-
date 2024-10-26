#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> find_divisors(int n) {
    std::vector<int> divisors;
    int sqrt_n = std::sqrt(n);  
    for (int i = 1; i <= sqrt_n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != 1 && i != n / i) {
                divisors.push_back(n / i); 
            }
        }
    }
    return divisors;
}

void check_multiplier(int n) {
    std::vector<int> divisors = find_divisors(n);
    int sum = 0;
    
    for (int d : divisors) {
        sum += d; 
    }

    if (sum == n) {
        std::cout << "FOUND PERFECT NUMBER! for number n: " << n 
                  << " divisors: ";
        for (int d : divisors) {
            std::cout << d << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int max_range;
    std::cout << "Enter the max range (1 to N): ";
    std::cin >> max_range;

    for (int i = 2; i <= max_range; ++i) {
        check_multiplier(i);
    }

    return 0;
}

// g++ -o perfect .\test.cpp
