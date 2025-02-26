/**
 * Maps a value `x` from the range [in_min, in_max] to [out_min, out_max].
 * This function applies a linear transformation:
 * 1. Subtracts in_min to shift x to a zero-based range.
 * 2. Scales x to a [0,1] range by dividing by the input range length.
 * 3. Multiplies by the output range length to fit the new scale.
 * 4. Adds out_min to shift it into the target range.
 * 
 * Formula: 
 *   map(x) = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min
 */

#include <iostream>

#define Map(x, in_min, in_max, out_min, out_max) ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)


int main(){
    int value = 25;
    int res = Map(value, 2, 20, 0, 1500);
    std::cout << "res =: \n" << res << std::endl;
}
