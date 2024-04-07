#include <iostream>
#include <windows.h>

int main() {
    POINT coordinates;
    
    while (true) {
        if (GetCursorPos(&coordinates)) {
            std::cout << "Coordinate X: " << coordinates.x << " Y: " << coordinates.y << std::endl;
        }
        Sleep(100); 
    }
    
    return 0;
}
