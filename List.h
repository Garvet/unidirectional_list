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
    List();                                 //+
    List(const List &list);                 ///?
    List(List &&list);                      ///?
    ~List() = default;                      //+

    List &operator=(const List &list);      ///?
    List &operator=(List &&list);           ///?

    int get_size() const;                   ///---// Получить размер списка
    bool is_empty() const;                  ///?// Возвращает true, если список пуст и должен делать это эффективно
    int& operator[](int index);             ///?// Неконстантный оператор получения ссылки на i-й элемент (если такой синтаксис в новинку, то гугли перегрузку операторов. Это синтаксический сахар, но по сути вызов обычных функций)
    const int& operator[](int index) const; ///?// Константный оператор получения ссылки. Должна знать, почему он нам нужен и почему не можем ограничиться только первым (см. const у методов)
    void push_front(int val);               //+ // Добавление элемента в начало списка
    void pop_front();                       ///?// Удаление элемента из начала списка
    int& get_front();                       ///?// Получение первого элемента
    const int& get_front() const;           ///?// Аналогично, как и в случае с операторами []
    void insert(int pos, int val);          ///?// Добавить новый элемент в заданную позицию
    void erase(int pos);                    ///?// Удалить определенный элемент
};


#endif //LIST_LIST_H
