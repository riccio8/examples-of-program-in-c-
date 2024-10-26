#include <iostream>
using namespace std;

int main(){
    __asm__(
        "loop: \n\t"
        "jmp l \n\t"
        "l: \n\t"
        "jmp loop \n\t"
    );
    
    return 0;
}
