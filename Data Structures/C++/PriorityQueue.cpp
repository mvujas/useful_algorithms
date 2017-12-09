#include <iostream>

using namespace std;

template<typename T> class Node;
template<typename T> class PriorityQueue;

template<typename T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T data)
        : data(data), left(NULL), right(NULL) {}
};

template<typename T>
class PriorityQueue {
private:
    Node<T>* root;
public:
    PriorityQueue()
        : root(NULL) {}

    bool empty() {
        return root == NULL;
    }

    void push(T el) {
        _push(&root, el);
    }

    void show() {
        _show(root);
        cout << endl;
    }

    T pop() {
        if(empty())
            throw "Priority queue is empty.";
        return _pop(&root);
    }
private:
    void _show(Node<T>* curr) {
        if(curr == NULL) {
            cout << ".";
            return;
        }
        cout << "(" << curr->data << " ";
        _show(curr->left);
        cout << " ";
        _show(curr->right);
        cout << ")";
    }

    // For custom classes you have to define operator< !!!
    void _push(Node<T>** curr, T& el) {
        if(*curr == NULL)
            *curr = new Node<T>(el);
        else if(el < (*curr)->data)
            _push(&(*curr)->left, el);
        else
            _push(&(*curr)->right, el);
    }

    T _pop(Node<T>** curr) {
        if((*curr)->left == NULL) {
            Node<T>* abandonedNode = *curr;
            T tmpVal = (*curr)->data;
            *curr = (*curr)->right;
            delete abandonedNode;
            return tmpVal;
        }
        return _pop(&(*curr)->left);
    }
};


int main()
{
    PriorityQueue<int>* pq = new PriorityQueue<int>();
    pq->push(5);
    pq->push(10);
    pq->push(15);
    pq->push(11);
    pq->push(0);
    pq->push(-1);
    pq->push(2);
    pq->push(52);
    pq->push(16);
    pq->push(-1);

    pq->show();
    while(!pq->empty()) {
        cout << pq->pop() << endl;
        pq->show();
    }
    return 0;
}
