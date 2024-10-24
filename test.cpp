#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> trova_divisore(int n) {
    std::vector<int> divisori;
    int sqrt_n = std::sqrt(n);  
    for (int i = 1; i <= sqrt_n; ++i) {
        if (n % i == 0) {
            divisori.push_back(i);
            if (i != 1 && i != n / i) {
                divisori.push_back(n / i); 
            }
        }
    }
    return divisori;
}

void check_moltiplicatore(int n) {
    std::vector<int> divisori = trova_divisore(n);
    int somma = 0;
    
    for (int d : divisori) {
        somma += d; 
    }

    if (somma == n) {
        std::cout << "FOUNDED NUMBER!! for number n: " << n 
                  << " divisor: ";
        for (int d : divisori) {
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
        check_moltiplicatore(i);
    }

    return 0;
}

// g++ -o perfetto .\test.cpp
