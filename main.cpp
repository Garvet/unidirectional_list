#include <iostream>

#include "List.h"

int main() {
    List list;

    list.push_front(10);
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.push_front(50);
    list.push_front(80);

    for(int i=0;i<list.get_size();++i){
        std::cout << list[i] << std::endl;
    }





    std::cout << "Hello, World!" << std::endl;
    return 0;
}