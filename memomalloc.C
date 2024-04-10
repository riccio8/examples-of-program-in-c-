// script for memory leak, it works only on linux based machine


#include <stdlib.h>
using namespace std;

int main()
{
  for(;;){
    malloc(1024 * 50);
  }

  return 0;
}
