#include <iostream>
#include <chrono>
#include "utils/SLL.hpp"
#include "utils/DLL.hpp"
#include "utils/CSLL.hpp"
#include "utils/node.hpp"
using namespace std;
using namespace chrono;

void sll_observe(Sll* obj, void (Sll::*method)(), string msg){
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
}

int main() {
    const int N = 10000; // test size, you can change (e.g. 1e4, 1e5)
    


    return 0;
}
