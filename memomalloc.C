#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
    for(;;) {
        void* ptr = malloc(1024 * 50);
            cerr << "Memory allocation failed!" << endl;
            break; 
        }
    return 0;
}
