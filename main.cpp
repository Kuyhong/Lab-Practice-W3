#include <iostream>
#include <chrono>
#include "utils/SLL.hpp"
using namespace std;
using namespace chrono;

int main() {
    const int N = 10000; // test size, you can change (e.g. 1e4, 1e5)
    SLL_HeadOnly sll1;
    SLL_HeadTail sll2;
    DLL_HeadTail dll3;

    cout << "===== A5: Push/Pop Ends Timing =====\n";
    cout << "Number of operations: " << N << "\n\n";
    benchmark ( "SLL (head only):    " , sll1,N ) ;
    benchmark ( "SLL (head + tail):  " , sll2,N ) ;
    benchmark ( "DLL (head + tail):  " , dll3,N ) ;


    return 0;
}
