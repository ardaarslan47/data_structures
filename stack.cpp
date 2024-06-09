#include <stdexcept> // for std::underflow_error

template <typename T>
struct node
{
    T data;
    node* next;
    node* prev;
};

template <typename T>
class stack
{
private:
    node<T>* last;

public:
    stack() : last(nullptr) {}

    void push(T _data)
    {
        node<T>* newNode = new node<T>;
        newNode->data = _data;
        newNode->prev = last;
        newNode->next = nullptr;

        if (last != nullptr)
        {
            last->next = newNode;
        }

        last = newNode;
    }

    T pop()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack is empty");
        }

        node<T>* nodeToDelete = last;
        T valueOfNodeToDelete = nodeToDelete->data;

        last = last->prev;
        if (last != nullptr)
        {
            last->next = nullptr;
        }

        delete nodeToDelete;
        return valueOfNodeToDelete;
    }

    T peek()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack is empty");
        }

        return last->data;
    }

    bool isEmpty()
    {
        return last == nullptr;
    }
};