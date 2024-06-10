template <typename T>
struct node
{
    T data;
    node *next;

    node(T _data) : data(_data), next(nullptr){};
};

template <typename T>
class queue
{
private:
    node<T> *first;

public:
    queue() : first(nullptr){};
    ~queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    };

    void enqueue(T _data)
    {
        if (isEmpty())
        {
            first = new node<T>(_data);
            return;
        }

        rear()->next = new node<T>(_data);
    };
    node<T> *rear()
    {
        if (isEmpty())
            throw;

        node<T> *rear = first;
        while (rear->next != nullptr)
        {
            rear = rear->next;
        }

        return rear;
    };
    T dequeue()
    {
        if (isEmpty())
            throw;

        node<T> *nodeToDelete = first;
        T value = nodeToDelete->data;
        first = nodeToDelete->next;

        delete nodeToDelete;
        return value;
    };
    T peek()
    {
        if (isEmpty())
            throw;
            
        return first->data;
    };
    bool isEmpty()
    {
        return first == nullptr;
    };
    int size()
    {
        if (isEmpty())
            return 0;

        int i = 0;
        node<T> *ref = first;

        while (ref != nullptr)
        {
            i++;
            ref = ref->next;
        }

        return i;
    }
};