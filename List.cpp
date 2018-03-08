//
// Created by garvet on 03.03.18.
//

#include "List.h"

List::List(): first_element(nullptr){}

List::List(const List &list) {
    list_element *old_element;
    list_element *new_element;
    std::unique_ptr<list_element> created_element;
    if (list.first_element != nullptr) {
        created_element = std::unique_ptr<list_element>(new list_element);
        created_element->value = list.first_element->value;
        first_element = std::move(created_element);
        old_element = list.first_element->next_element.get();
        new_element = first_element.get();
        for (; old_element != nullptr;) {
            created_element = std::unique_ptr<list_element>(new list_element);
            created_element->value = old_element->value;
            new_element->next_element = std::move(created_element);
            new_element = new_element->next_element.get();
            old_element = old_element->next_element.get();
        }
        new_element->next_element = nullptr;
    }
}

List::List(List &&list): first_element(std::move(list.first_element)) {}


List& List::operator=(List &&list) {
    first_element = std::move(list.first_element);
    return *this;
}

List& List::operator=(const List &list) {
    list_element *old_element;
    list_element *new_element;
    std::unique_ptr<list_element> created_element;
    if (list.first_element != nullptr) {
        created_element = std::unique_ptr<list_element>(new list_element);
        created_element->value = list.first_element->value;
        first_element = std::move(created_element);
        old_element = list.first_element->next_element.get();
        new_element = first_element.get();
        for (; old_element != nullptr;) {
            created_element = std::unique_ptr<list_element>(new list_element);
            created_element->value = old_element->value;
            new_element->next_element = std::move(created_element);
            new_element = new_element->next_element.get();
            old_element = old_element->next_element.get();
        }
        new_element->next_element = nullptr;
    }
    return *this;
}


int List::get_size() const {
    int i = 0;
    list_element *current_element;
    if(first_element != nullptr) {
        ++i;
        current_element = first_element.get();
        for (;current_element->next_element != nullptr;++i) {
            current_element = current_element->next_element.get();
        }
    }
    return i;
}

bool List::is_empty() const {
    return !bool(first_element);
}

int &List::operator[](int index) {
    list_element *current_element;
    if(index == 0) {
        return first_element->value;
    }
    current_element = first_element->next_element.get();
    for (int i=1; i != index; ++i) {
        current_element = current_element->next_element.get();
    }
    return current_element->value;
}

const int &List::operator[](int index) const {
    list_element *current_element;
    if(index == 0) {
        return first_element->value;
    }
    current_element = first_element->next_element.get();
    for (int i=1; i != index; ++i) {
        current_element = current_element->next_element.get();
    }
    return current_element->value;
}

void List::push_front(int val) {
    std::unique_ptr<list_element> new_element(new list_element);
    new_element->value = val;
    new_element->next_element = std::move(first_element);
    first_element=std::move(new_element);
}

void List::pop_front() {
    if (first_element)
        first_element = std::move(first_element->next_element);
}

int &List::get_front() {
    if (first_element)
        return first_element->value;
}

const int &List::get_front() const {
    if (first_element)
        return first_element->value;
}

void List::insert(int pos, int val) {
    if (pos == 0) {
        push_front(val);
    }
    else {
        int i = 1;
        list_element *current_element = first_element.get();
        for (; i != pos; ++i) {
            current_element = current_element->next_element.get();
        }
        std::unique_ptr<list_element> new_element(new list_element);
        new_element->value = val;
        new_element->next_element = std::move(current_element->next_element);
        current_element->next_element = std::move(new_element);
    }
}

void List::erase(int pos) {
    if(pos == 0) {
        pop_front();
    }
    else {
        int i = 1;
        list_element *current_element = first_element.get();
        for (; i != pos; ++i) {
            current_element = current_element->next_element.get();
        }
        current_element->next_element = std::move(current_element->next_element->next_element);
    }
}