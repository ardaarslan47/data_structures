#include <iostream>
#include <queue>

template <typename T>
struct node
{
    T data;
    node *left;
    node *right;

    node(T _data) : data(_data), left(nullptr), right(nullptr) {}
};

template <typename T>
class binaryTree
{
private:
    node<T> *root;

    void insertHelper(node<T> *&current, T _data)
    {
        if (current == nullptr)
        {
            current = new node<T>(_data);
        }
        else if (_data < current->data)
        {
            insertHelper(current->left, _data);
        }
        else
        {
            insertHelper(current->right, _data);
        }
    }

    void deleteTree(node<T> *current)
    {
        if (current)
        {
            deleteTree(current->left);
            deleteTree(current->right);
            delete current;
        }
    }

    node<T> *findMin(node<T> *current)
    {
        while (current && current->left)
        {
            current = current->left;
        }
        return current;
    }

    node<T> *deleteNodeHelper(node<T> *current, T key)
    {
        if (current == nullptr)
            return current;

        if (key < current->data)
        {
            current->left = deleteNodeHelper(current->left, key);
        }
        else if (key > current->data)
        {
            current->right = deleteNodeHelper(current->right, key);
        }
        else
        {
            if (current->left == nullptr)
            {
                node<T> *temp = current->right;
                delete current;
                return temp;
            }
            else if (current->right == nullptr)
            {
                node<T> *temp = current->left;
                delete current;
                return temp;
            }

            node<T> *temp = findMin(current->right);
            current->data = temp->data;
            current->right = deleteNodeHelper(current->right, temp->data);
        }
        return current;
    }

public:
    binaryTree() : root(nullptr) {}

    ~binaryTree()
    {
        deleteTree(root);
    }

    void insert(T _data)
    {
        insertHelper(root, _data);
    }

    void inOrderTraversal(node<T> *current)
    {
        if (current)
        {
            inOrderTraversal(current->left);
            std::cout << current->data << " ";
            inOrderTraversal(current->right);
        }
    }

    void inOrderTraversal()
    {
        inOrderTraversal(root);
    }

    void levelOrderTraversal()
    {
        if (root == nullptr)
            return;

        std::queue<node<T> *> q;
        q.push(root);

        while (!q.empty())
        {
            node<T> *current = q.front();
            q.pop();
            std::cout << current->data << " ";

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }

    void deleteNode(T key)
    {
        root = deleteNodeHelper(root, key);
    }
};

int main()
{
    binaryTree<int> bt;
    bt.insert(5);
    bt.insert(3);
    bt.insert(7);
    bt.insert(1);
    bt.insert(4);
    bt.insert(6);
    bt.insert(8);

    std::cout << "In-order traversal: ";
    bt.inOrderTraversal();
    std::cout << std::endl;

    std::cout << "Level-order traversal: ";
    bt.levelOrderTraversal();
    std::cout << std::endl;

    bt.deleteNode(4);
    bt.insert(2);

    std::cout << "In-order traversal after deleting node with key 4: ";
    bt.inOrderTraversal();
    std::cout << std::endl;


    std::cout << "Level-order traversal after deleting node with key 4: ";
    bt.levelOrderTraversal();
    std::cout << std::endl;

    return 0;
}
