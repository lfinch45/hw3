#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    // throws std::underflow_error if empty
    void pop();
    // throws std::underflow_error if empty
    const T& top() const;
};

template<typename T>
Stack<T>::Stack(){


}

template<typename T>
Stack<T>::~Stack(){

}

template<typename T>
bool Stack<T>::empty() const{
    return std::vector<T>::empty();
}

template<typename T>
size_t Stack<T>::size() const{
    return std::vector<T>::size();
}

template<typename T>
void Stack<T>::push(const T& item){
    std::vector<T>::push_back(item);
}

// throws std::underflow_error if empty
template<typename T>
void Stack<T>::pop(){
    if(std::vector<T>::empty()){
        throw std::underflow_error("Stack underflow error: pop");
    }
    std::vector<T>::pop_back();
}

// throws std::underflow_error if empty
template<typename T>
const T& Stack<T>::top() const{
    if(std::vector<T>::empty()){
        throw std::underflow_error("Stack underflow error: top");
    }
    return std::vector<T>::back();
}

#endif