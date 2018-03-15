//
// Created by garvet on 03.03.18.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H
#include <memory>

template<class T>
struct list_element{
    T value;
    std::unique_ptr<list_element<T>> next_element;
};

template<class T>
class List {
    std::unique_ptr<list_element<T>> first_element;
public:
    List();
    List(const List<T> &list);
    List(List<T> &&list);
    ~List() = default;

    List<T> &operator=(const List<T> &list);
    List<T> &operator=(List<T> &&list);

    int get_size() const;
    bool is_empty() const;
    T& operator[](int index);
    const T& operator[](int index) const;
    void push_front(T val);
    void pop_front();
    T& get_front();
    const T& get_front() const;
    void insert(int pos, T val);
    void erase(int pos);
};



template<class T>
List<T>::List(): first_element(nullptr){}

template<class T>
List<T>::List(const List<T> &list) {
    list_element<T> *old_element;
    list_element<T> *new_element;
    if (list.first_element != nullptr) {
        first_element = std::unique_ptr<list_element<T>>(new list_element<T>);
        first_element->value = list.first_element->value;
        old_element = list.first_element->next_element.get();
        new_element = first_element.get();
        while (old_element != nullptr) {
            new_element->next_element = std::unique_ptr<list_element<T>>(new list_element<T>);
            new_element->next_element->value = old_element->value;
            new_element = new_element->next_element.get();
            old_element = old_element->next_element.get();
        }
        new_element->next_element = nullptr;
    }
}

template<class T>
List<T>::List(List<T> &&list): first_element(std::move(list.first_element)) {}

template<class T>
List<T>& List<T>::operator=(List<T> &&list) {
    first_element = std::move(list.first_element);
    return *this;
}

template<class T>
List<T>& List<T>::operator=(const List<T> &list) {
    this->first_element=std::move(List(list).first_element);
    return *this;
}

template<class T>
int List<T>::get_size() const {
    int i = 0;
    list_element<T> *current_element;
    if(first_element != nullptr) {
        ++i;
        current_element = first_element.get();
        for (;current_element->next_element != nullptr;++i) {
            current_element = current_element->next_element.get();
        }
    }
    return i;
}

template<class T>
bool List<T>::is_empty() const {
    return (first_element == nullptr);
}

template<class T>
T &List<T>::operator[](int index) {
    list_element<T> *current_element;
    if(index == 0) {
        return first_element->value;
    }
    current_element = first_element->next_element.get();
    for (int i=1; i != index; ++i) {
        current_element = current_element->next_element.get();
    }
    return current_element->value;
}

template<class T>
const T &List<T>::operator[](int index) const {
    list_element<T> *current_element;
    if(index == 0) {
        return first_element->value;
    }
    current_element = first_element->next_element.get();
    for (int i=1; i != index; ++i) {
        current_element = current_element->next_element.get();
    }
    return current_element->value;
}

template<class T>
void List<T>::push_front(T val) {
    std::unique_ptr<list_element<T>> new_element(new list_element<T>);
    new_element->value = val;
    new_element->next_element = std::move(first_element);
    first_element=std::move(new_element);
}

template<class T>
void List<T>::pop_front() {
    if (first_element != nullptr)
        first_element = std::move(first_element->next_element);
}

template<class T>
T &List<T>::get_front() {
    if (first_element)
        return first_element->value;
}

template<class T>
const T &List<T>::get_front() const {
    if (first_element != nullptr)
        return first_element->value;
}

template<class T>
void List<T>::insert(int pos, T val) {
    if (pos == 0) {
        push_front(val);
    }
    else {
        list_element<T> *current_element = first_element.get();
        for (int i = 1 ; i != pos; ++i) {
            current_element = current_element->next_element.get();
        }
        std::unique_ptr<list_element<T>> new_element(new list_element<T>);
        new_element->value = val;
        new_element->next_element = std::move(current_element->next_element);
        current_element->next_element = std::move(new_element);
    }
}

template<class T>
void List<T>::erase(int pos) {
    if(pos == 0) {
        pop_front();
    }
    else {
        list_element<T> *current_element = first_element.get();
        for (int i = 1; i != pos; ++i) {
            current_element = current_element->next_element.get();
        }
        current_element->next_element = std::move(current_element->next_element->next_element);
    }
}

#endif //LIST_LIST_H