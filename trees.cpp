#include <algorithm>
#include <iostream>
#include <vector>

struct Node
{
    int data;
    std::vector<Node *> children;

    int depthOfTree()
    {
        int maxDepth = 0;

        for (const auto &child : children)
        {
            maxDepth = std::max(maxDepth, child->depthOfTree());
        }

        return maxDepth + 1;
    }

    int findDepth(int _data)
    {
        int dist = -1;

        if (data == _data)
            return dist + 1;

        for (const auto &child : children)
        {
            if ((dist = child->findDepth(_data)) >= 0)
            {
                return dist + 1;
            }
        }

        return dist;
    }

    int findHeightUtil(Node *root, int _data, int &height)
    {
        if (!root)
            return -1;

        int ans = -1;

        for (const auto &child : root->children)
        {
            ans = std::max(ans, findHeightUtil(child, _data, height));
        }

        ans++;

        if (root->data == _data)
            height = ans;

        return ans;
    }

    int findHeight(int _data)
    {
        int h = -1;

        int maxHeight = findHeightUtil(this, _data, h);

        return h;
    }

    bool ifNodeExist(int _data)
    {
        if (data == _data)
            return true;

        for (const auto &child : children)
        {
            bool res = child->ifNodeExist(_data);
            if (res)
                return true;
        }

        return false;
    }

    int findParent(int _data, int parent = -1)
    {
        if (data == _data)
            return parent;

        for (const auto &child : children)
        {
            int result = child->findParent(_data, data);
            if (result != -1)
                return result;
        }

        return -1;
    }

    Node(int _data)
    {
        data = _data;
    }
};

int main()
{
    Node *root = new Node(2);
    (root->children).push_back(new Node(3));
    (root->children).push_back(new Node(5));
    (root->children).push_back(new Node(8));
    (root->children[1]->children).push_back(new Node(6));
    (root->children[1]->children).push_back(new Node(10));
    (root->children[1]->children).push_back(new Node(19));
    (root->children[2]->children).push_back(new Node(16));
    (root->children[2]->children[0]->children).push_back(new Node(9));

    std::cout << root->depthOfTree() << "\n"
              << root->findDepth(9) << "\n"
              << root->findHeight(2) << "\n"
              << root->ifNodeExist(23) << "\n"
              << root->findParent(9);
}