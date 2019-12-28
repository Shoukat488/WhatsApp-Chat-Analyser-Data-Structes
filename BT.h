#include<bits/stdc++.h>
#include <queue>
#include<stack>
using namespace std;

template<class T>
class TreeNode;
template<class T>
class Tree;

template<class T>
class TreeNode{

    public:
    T data;
    T user ;
    int frequency;
    TreeNode<T> *leftNode;
    TreeNode<T> *rightNode;
    public:
    TreeNode(T data , T user);
    TreeNode(T data);
    void traverseInOrder();
};

template<class T>
class Tree{

    public:
    TreeNode<T> *root;
    long long int count;
    public:
    Tree();
    void insert(T data , T user = "");
    void traverseInOrder();
    TreeNode<T>* getRoot();
    TreeNode<T>* search(T value);
    long long int getCount();
    void BFS();
    template<class U>
    friend ifstream & operator >> (ifstream& file  , Tree<T> &tree);
    template<class U>
    friend ofstream & operator << (ofstream &file , Tree<T> &tree );
};

template<class T>
TreeNode<T>::TreeNode(T data)
    {
        this->data = data;
        frequency = 1;
        leftNode = rightNode =  NULL;
    }
template<class T>
TreeNode<T>::TreeNode(T data, T user)
    {
        this->data = data;
        this->user = user;
        frequency = 1;
        leftNode = rightNode =  NULL;
    }

template<class T>
TreeNode<T>* Tree<T>::getRoot()
{
    return root;
}
template<class T>
void Tree<T>::BFS()
{
    TreeNode<T> *temp = root;
    queue<TreeNode<T> *> q;

    q.push(temp);

    while (!q.empty() && temp != NULL)
    {
        temp = q.front();
        q.pop();

        cout<<temp->data<<" ";
        if(temp->leftNode != NULL)
            q.push(temp->leftNode);

        if(temp->rightNode != NULL)
        q.push(temp->rightNode);    
        
    }
    cout<<endl;
}
template<class T>
void TreeNode<T>::traverseInOrder()
    {
        if(leftNode != NULL)
        leftNode->traverseInOrder();

        cout<<data<<" ";

        if(rightNode != NULL)
        rightNode->traverseInOrder();
    }

template<class T>
Tree<T>::Tree()
    {
        root = NULL;
        count = 0;
    }
template<class T>
long long int Tree<T>::getCount()
{
    return count;
}
template<class T>
TreeNode<T>* Tree<T>::search(T value)
{
	stack<TreeNode<T> *> tempStack;
	TreeNode<T> *temp = root;

	while (temp != NULL || !tempStack.empty())
	{
		while (temp != NULL)
		{
			if(temp->data == value)
			{
                return temp;
				break;
			}
			tempStack.push(temp);
			temp = temp->leftNode;
		}
		if(!tempStack.empty())
		{
			temp = tempStack.top();
			tempStack.pop();
		}
		temp = temp->rightNode;
	}
    return NULL;
}

template<class T>
void Tree<T>::insert(T value , T user)
    {
       if(root == NULL)
        root = new TreeNode<T>(value , user);
        else
        {
        	if(root->data == value)
            {
                ++ (root->frequency);
                return;
            }
            queue<TreeNode<T> * > q;
            q.push(root);
            while (!q.empty())
            {
                TreeNode<T> *temp = q.front();
				q.pop();
                if(temp->leftNode != NULL)
                q.push(temp->leftNode);
                else
                {
	                temp->leftNode = new TreeNode<T>(value , user);
                    ++count;
	                break;
                }
                if(temp->rightNode != NULL )
                q.push(temp->rightNode);
                else
                {
                    temp->rightNode = new TreeNode<T>(value , user);
                    ++count;
                    break;
                }
            }
        }
    }
template<class T>
void Tree<T>::traverseInOrder()
    {
        root->traverseInOrder();
    }
// read data from file
template<class T>
ifstream& operator >> (ifstream& file , Tree<T> &tree )
    {
        T element;
        while (file)
        {
            file>>element;
            tree.insert(element , " ");
        }
        return file;
    }
// write data into file
template<class T>
ofstream& operator << (ofstream &file , Tree<T> &root)
    {

        return file;
    }