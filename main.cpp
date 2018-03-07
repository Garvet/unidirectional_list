#include <iostream>

#include "List.h"

int main() {
    int N;
    List list;
    int elements = 10;
    int number_insert=2;
    int number_erase=6;

    if(list.is_empty()) {

        std::cout << "Create " << elements << " elements" << std::endl;
        for(int i=1;i<=elements;++i) {
            list.push_front(10*(i-1));
        }

        N = list.get_size();
        for (int i = 0; i < N; ++i) {
            std::cout << i << "\t" << list[i] << std::endl;
        }


        std::cout << std::endl;
        std::cout << "Pop element" << std::endl;
        list.pop_front();
        N = list.get_size();
        for (int i = 0; i < N; ++i) {
            std::cout << i << "\t" << list[i] << std::endl;
        }

        N = list.get_size();
        if((N > number_insert - 1) && (N >= 0)) {
            std::cout << std::endl;
            std::cout << "Insert in " << number_insert << std::endl;
            list.insert(number_insert, 15);

            N = list.get_size();
            for (int i = 0; i < N; ++i) {
                std::cout << i << "\t" << list[i];
                if (i == number_insert)
                    std::cout << " <-";
                std::cout << std::endl;
            }
        }

        N = list.get_size();
        if((N > number_erase) && (N >= 0)) {
            std::cout << std::endl;
            std::cout << "Erase " << number_erase << std::endl;
            list.erase(number_erase);

            N = list.get_size();
            for (int i = 0; i < N; ++i) {
                std::cout << i << "\t" << list[i];
                if (i == number_erase - 1)
                    std::cout << " /_";
                if (i == number_erase)
                    std::cout << " \\";
                std::cout << std::endl;
            }
        }

        std::cout << std::endl;
        std::cout << "list2(list)" << std::endl;
        List list2(list);
        N = list2.get_size();
        for (int i = 0; i < N; ++i) {
            std::cout << i << "\t" << list2[i] << std::endl;
        }

        std::cout << std::endl;
        std::cout << "list3=list" << std::endl;
        List list4;
        List list3(list4);
        list3=list;
        N = list3.get_size();
        for (int i = 0; i < N; ++i) {
            std::cout << i << "\t" << list3[i] << std::endl;
        }

        std::cout << std::endl;
        std::cout << "list4=std::move(list)" << std::endl;
        list4=std::move(list);
        N = list4.get_size();
        for (int i = 0; i < N; ++i) {
            std::cout << i << "\t" << list4[i] << std::endl;
        }

        std::cout << std::endl;
        if(list.is_empty()) {
            std::cout << "list is empty" << std::endl;
        }

        std::cout << std::endl;
        std::cout << "List list5=std::move(list2)" << std::endl;
        List list5=std::move(list2);
        N = list5.get_size();
        for (int i = 0; i < N; ++i) {
            std::cout << i << "\t" << list5[i] << std::endl;
        }

        std::cout << std::endl;
        if(list2.is_empty()) {
            std::cout << "list2 is empty" << std::endl;
        }
    }
    return 0;
}