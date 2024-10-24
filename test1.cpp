#include <iostream>
#include <vector>
#include <cmath>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex cout_mutex; 
std::mutex queue_mutex; 
std::condition_variable cv; 
std::queue<int> tasks;
bool finished = false; 

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

void check_moltiplicatore() {
    while (true) {
        int n;
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            cv.wait(lock, [] { return !tasks.empty() || finished; });
            if (finished && tasks.empty()) break; // Esci se finito
            n = tasks.front();
            tasks.pop();
        }

        std::vector<int> divisori = trova_divisore(n);
        int somma = 0;

        for (int d : divisori) {
            somma += d; 
        }

        if (somma == n) {
            std::lock_guard<std::mutex> guard(cout_mutex);
            std::cout << "FOUNDED NUMBER!! for number n: " << n 
                      << " divisori: ";
            for (int d : divisori) {
                std::cout << d << " ";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    int max_range;
    int min_range;

    std::cout << "Enter the max range (eg: 1 to N): ";
    std::cin >> max_range;
    std::cout << "Enter minimum range (eg: N to 1): "; 
    std::cin >> min_range; 

    const int num_threads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;

    for (int i = min_range; i <= max_range; ++i) {
        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            tasks.push(i);
        }
        cv.notify_one(); 
    }
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(check_moltiplicatore);
    }


    {
        std::lock_guard<std::mutex> lock(queue_mutex);
        finished = true;
    }
    cv.notify_all(); 

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
