template <typename T>
struct node
{
    T data;
    node *next;

    node(T _data, node *_next = nullptr) : data(_data), next(_next){};
};

template <typename T>
class stack
{
private:
    node<T> *top;

public:
    stack() : top(nullptr){};
    ~stack(){};

    void push(T _data)
    {
        top = new node<T>(_data, top);
    };
    T pop()
    {
        if (isEmpty())
            throw;

        node<T> *nodeToDelete = top;
        T value = nodeToDelete->data;

        top = top->next;

        delete nodeToDelete;
        return value;
    };
    T peek()
    {
        if (isEmpty())
            throw;

        return top->data;
    };
    bool isEmpty()
    {
        return top == nullptr;
    };
};