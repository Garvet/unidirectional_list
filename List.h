//
// Created by garvet on 03.03.18.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H
#include <memory>

struct list_element{
    int value;
    std::unique_ptr<list_element> next_element;
};

class List {
    std::unique_ptr<list_element> first_element;
public:
    List();
    List(const List &list);
    List(List &&list);
    ~List() = default;

    List &operator=(const List &list);
    List &operator=(List &&list);

    int get_size() const;
    bool is_empty() const;
    int& operator[](int index);
    const int& operator[](int index) const;
    void push_front(int val);
    void pop_front();
    int& get_front();
    const int& get_front() const;
    void insert(int pos, int val);
    void erase(int pos);
};

#endif //LIST_LIST_H