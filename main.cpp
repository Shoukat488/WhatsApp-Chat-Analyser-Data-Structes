#include<iostream>
using namespace std;

template<class T>
class TreeNode;

template<class T>
class TreeNode{

    public:
    T data;
    int frequency;
    TreeNode<T> *leftNode;
    TreeNode<T> *rightNode;

    public:

    TreeNode(T data)
    {
        this->data = data;
        frequency = 1;
        leftNode = rightNode =   NULL;
    }
    
    void insert(T value)
    {
        if(data == value)
        {
            frequency++;
            return;
        }

        if(value < data)
        {
            if(leftNode == NULL)
            leftNode = new TreeNode<T>(value) ;
            else
            leftNode->insert(value);                
            
        } else if(value > data)
        {
            if(rightNode == NULL)
            rightNode = new TreeNode<T>(value) ;
            else
            rightNode->insert(value);                
            
        }
    }

    void traverseInOrder()
    {
        if(leftNode != NULL)
        leftNode->traverseInOrder();

        cout<<data<<" ";

        if(rightNode != NULL)
        rightNode->traverseInOrder();
    }
  
};

template<class T>
class Tree{

    private:
    TreeNode<T> *root;

    public:
    Tree()
    {
        root = NULL;
    }

    void insert(T data)
    {
        if(root == NULL)
        root = new TreeNode<T>(data);
        else
        root->insert(data);
    }
    void traverseInOrder()
    {
        root->traverseInOrder();
    }
};
int main()
{

    Tree<int> *tree = new Tree<int>();
//5,4,8,6,7,10,2,18,14,15
    tree->insert(5);
    tree->insert(4);
    tree->insert(8);
    tree->insert(6);
    tree->insert(7);
    tree->insert(10);
    tree->insert(2);
    tree->insert(18);
    tree->insert(14);
    tree->insert(15);

    tree->traverseInOrder();
}