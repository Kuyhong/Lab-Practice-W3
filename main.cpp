#include "utils/SLL.hpp"
#include <iostream>
using namespace std ; 
int main() {
    SLL_HeadOnly list;
    list.push_front(10);
    list.push_back(20);
    list.pop_front();
    std:: cout <<"Head value :"<<(list.head->val = -1)<<"/n";
    return 0;
};
