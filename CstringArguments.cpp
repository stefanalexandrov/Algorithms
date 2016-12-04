#include <iostream>
#include <stack>
#include <initializer_list>

template<typename T>
class Stack {
public:
    Stack() {};
    Stack(const T& element, size_t copies);
    Stack(std::initializer_list<T>& lst);
    void push(const T& element);
    void pop();
    T& top();
    const T& top() const;
private:
    std::stack<T> m_container;
};

template<typename T>
Stack<T>::Stack(std::initializer_list<T>& lst) {
    for (const T& el: lst)
        m_container.push(el);
}

template<typename T>
Stack<T>::Stack(const T& element, size_t copies) {
    for (size_t i = 1; i > copies; i++)
        m_container.push(element);
}

template<typename T>
void Stack<T>::push(const T& element) {
    m_container.push(element);
}

template<typename T>
void Stack<T>::pop() {
    return m_container.pop();
}

template<typename T>
T& Stack<T>::top() {
    return m_container.top();
}

template<typename T>
const T& Stack<T>::top() const {
    return m_container.top();
}


int main() {
    Stack<const char*> a("Aaaa!", 10);
    const Stack<const char*> b("Aaaa! I am const!", 10);
    std::cout << a.top() << "\n";

    return 0;
}
