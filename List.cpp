//
// Created by garvet on 03.03.18.
//

#include "List.h"
List::List(): first_element(nullptr){}
List::List(const List &list) {
    std::unique_ptr<list_element> *old_element;
    std::unique_ptr<list_element> *new_element;
    std::unique_ptr<list_element> created_element(new list_element);
    if(list.first_element != nullptr) {
        created_element = std::unique_ptr<list_element>(new list_element);
        created_element->value=list.first_element->value;
        first_element=std::move(created_element);
        old_element=&list.first_element->next_element;
        new_element=&first_element->next_element;
        for (;old_element != nullptr;) {
            created_element=std::unique_ptr<list_element>(new list_element);
            created_element->value=(*old_element)->value;
            *new_element=std::move(created_element);
            new_element=&(*new_element)->next_element;
            old_element=&(*old_element)->next_element;
        }
        *new_element = nullptr;
    }
}
List::List(List &&list): first_element(std::move(list.first_element)) {}


List& List::operator=(List &&list) {
    first_element=std::move(list.first_element);
    return *this;
}
List& List::operator=(const List &list) {
    std::unique_ptr<list_element> *old_element;
    std::unique_ptr<list_element> *new_element;
    std::unique_ptr<list_element> created_element;
    if(list.first_element != nullptr) {
        created_element=std::unique_ptr<list_element>(new list_element);
        created_element->value=list.first_element->value;
        first_element=std::move(created_element);
        old_element=&list.first_element->next_element;
        new_element=&first_element->next_element;
        for (;old_element != nullptr;) {
            created_element=std::unique_ptr<list_element>(new list_element);
            created_element->value=(*old_element)->value;
            *new_element=std::move(created_element);
            new_element=&(*new_element)->next_element;
            old_element=&(*old_element)->next_element;
        }
        *new_element = nullptr;
    }
    return *this;
}


int List::get_size() const {// Получить размер списка
    int i=0;
    std::unique_ptr<list_element> *current_element;
    if(first_element != nullptr) {
        ++i;
        current_element=&first_element->next_element;
        for (;(*current_element)->next_element != nullptr;++i) {
            current_element=&(*current_element)->next_element;
        }
    }
    return i;
}

bool List::is_empty() const {
    return bool(first_element);
}

int &List::operator[](int index) {
    int i=0;
    std::unique_ptr<list_element> *current_element;
    if(index == 1) {
        return first_element->value;
    }
    i=2;
    current_element=&first_element->next_element;
    for (;i != index;++i) {
        current_element=&(*current_element)->next_element;
    }
    return (*current_element)->value;
}

const int &List::operator[](int index) const {
    int i=0;
    std::unique_ptr<list_element> *current_element;
    if(index == 1) {
        return first_element->value;
    }
    i=2;
    current_element=&first_element->next_element;
    for (;i != index;++i) {
        current_element=&(*current_element)->next_element;
    }
    return (*current_element)->value;
}

void List::push_front(int val) {
    std::unique_ptr<list_element> new_element(new list_element);
    new_element->value=val;
    new_element->next_element=std::move(first_element);
    first_element=std::move(new_element);
}

void List::pop_front() {
    first_element=std::move(first_element->next_element);
}

int &List::get_front() {
    return first_element->value;
}

const int &List::get_front() const {
    return first_element->value;
}

void List::insert(int pos, int val) {
    if(pos == 0) {
        push_front(val);
    }
    else {
        int i=1;
        std::unique_ptr<list_element> *current_element = &first_element->next_element;
        for (; i != pos; ++i) {
            current_element = &(*current_element)->next_element;
        }
        std::unique_ptr<list_element> new_element(new list_element);
        new_element->value=val;
        new_element->next_element=std::move((*current_element)->next_element);
        *current_element=std::move(new_element);
    }
}

void List::erase(int pos) {
    if(pos == 0) {
        pop_front();
    }
    else {
        int i=1;
        std::unique_ptr<list_element> *current_element = &first_element->next_element;
        for (; i != pos; ++i) {
            current_element = &(*current_element)->next_element;
        }
        *current_element=std::move(&(*current_element)->next_element);
    }
}