#include <iostream>

template <typename T>
class Stack
{
    private:
        int topElement;
        T *mass;
    public:
        Stack(int size);
        ~Stack();
        void push(T a);
        void pop();
        T top();
        bool isEmpty();
        int size() {
            return topElement + 1;
        }
};

template <typename T>
bool Stack<T>::isEmpty() {
    return topElement != -1 ? false : true;
}

template <typename T>
Stack<T>::~Stack() {
    delete []mass;
}

template <typename T>
Stack<T>::Stack(int size) {
    topElement = -1;
    mass = new T[size];
}

template <typename T>
T Stack<T>::top() {
    return mass[topElement];
}

template <typename T>
void Stack<T>::push(T a) {
    mass[++topElement] = a;
}

template <typename T>
void Stack<T>::pop() {
    if (topElement == -1)
        return;
    topElement--;
}
int main() {
    Stack<std::string> stack(10);
    stack.push("one");
    stack.push("two");
    std::cout << stack.top() << std::endl;
    stack.push("three");
    std::cout << stack.isEmpty() << " " << stack.size() << " " << stack.top() << std::endl;
    stack.pop();
    std::cout << stack.top() << std::endl;
    stack.push("five");
    std::cout << stack.top();
    return 0;
}