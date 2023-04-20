#include <iostream>
#include <queue>
#include <stack>

template <class T>
struct Node {
    T data;
    Node *lCld = nullptr, *rCld = nullptr;
};

template <class T>
class BiTree {
   public:
    BiTree();
    ~BiTree();
    void preOrder();
    void inOrder();
    void postOrder();
    void leverOrder();
    void allOrder();
    void nonRecursivePreOrder();
    void nonRecursiveInOrder();
    void nonRecursivePostOrder();
    Node<T> *findNodeAndDeepthAndChildNode(char ch);

   private:
    Node<T> *rt = nullptr;

   protected:
    void createBiTree(Node<T> *&node);
    void destoryBiTree(Node<T> *node);
    void preOrder(Node<T> *node);
    void inOrder(Node<T> *node);
    void postOrder(Node<T> *node);
};

template <class T>
BiTree<T>::BiTree() {
    createBiTree(this->rt);
}

template <class T>
BiTree<T>::~BiTree() {
    destoryBiTree(this->rt);
}

template <class T>
void BiTree<T>::createBiTree(Node<T> *&node) {
    char curNodeData;
    std::cin >> curNodeData;
    if (curNodeData == '#') node = nullptr;
    else {
        node = new Node<T>;
        node->data = curNodeData;
        createBiTree(node->lCld);
        createBiTree(node->rCld);
    }
}

template <class T>
void BiTree<T>::destoryBiTree(Node<T> *node) {
    if (node) {
        destoryBiTree(node->lCld);
        destoryBiTree(node->rCld);
        delete node;
    }
}

template <class T>
void BiTree<T>::allOrder() {
    this->preOrder();
    this->inOrder();
    this->postOrder();
    this->nonRecursivePreOrder();
    this->nonRecursiveInOrder();
    this->nonRecursivePostOrder();
    this->leverOrder();
}

template <class T>
void BiTree<T>::preOrder() {
    this->preOrder(this->rt);
    std::cout << '\n';
}

template <class T>
void BiTree<T>::inOrder() {
    this->inOrder(this->rt);
    std::cout << '\n';
}

template <class T>
void BiTree<T>::postOrder() {
    this->postOrder(this->rt);
    std::cout << '\n';
}

template <class T>
void BiTree<T>::preOrder(Node<T> *node) {
    if (node) {
        std::cout << node->data << ' ';
        preOrder(node->lCld);
        preOrder(node->rCld);
    }
}

template <class T>
void BiTree<T>::inOrder(Node<T> *node) {
    if (node) {
        inOrder(node->lCld);
        std::cout << node->data << ' ';
        inOrder(node->rCld);
    }
}

template <class T>
void BiTree<T>::postOrder(Node<T> *node) {
    if (node) {
        postOrder(node->lCld);
        postOrder(node->rCld);
        std::cout << node->data << ' ';
    }
}

template <class T>
void BiTree<T>::leverOrder() {
    std::queue<Node<T> *> q;
    q.push(this->rt);
    while (!q.empty()) {
        Node<T> *cur = q.front();
        q.pop();
        std::cout << cur->data << ' ';
        if (cur->lCld) q.push(cur->lCld);
        if (cur->rCld) q.push(cur->rCld);
    }
    std::cout << '\n';
}

template <class T>
void BiTree<T>::nonRecursivePreOrder() {
    if (!(this->rt)) return;
    std::stack<Node<T> *> stk;
    stk.push(this->rt);
    while (!stk.empty()) {
        Node<T> *cur = stk.top();
        stk.pop();
        std::cout << cur->data << ' ';
        if (cur->rCld) stk.push(cur->rCld);
        if (cur->lCld) stk.push(cur->lCld);
    }
    std::cout << '\n';
}

template <class T>
void BiTree<T>::nonRecursiveInOrder() {
    std::stack<Node<T> *> stk;
    Node<T> *cur = this->rt;
    while (!stk.empty() || cur) {
        while (cur) stk.push(cur), cur = cur->lCld;
        if (!stk.empty()) {
            cur = stk.top();
            std::cout << cur->data << ' ';
            stk.pop();
            cur = cur->rCld;
        }
    }
    std::cout << '\n';
}

template <class T>
void BiTree<T>::nonRecursivePostOrder() {
    if (rt) {
        std::stack<Node<T> *> stk;
        Node<T> *cur = this->rt, *lst = nullptr;
        while (cur || !stk.empty()) {
            if (cur) stk.push(cur), cur = cur->lCld;
            else {
                cur = stk.top();
                if (cur->rCld && cur->rCld != lst) cur = cur->rCld;
                else {
                    stk.pop();
                    std::cout << cur->data << ' ';
                    lst = cur, cur = nullptr;
                }
            }
        }
    }
    std::cout << '\n';
}

template <class T>
Node<T> *BiTree<T>::findNodeAndDeepthAndChildNode(char ch) {
    std::queue<std::pair<Node<T> *, int> > q;
    int id = 0;
    q.push({this->rt, ++id});
    while (!q.empty()) {
        Node<T> *cur = q.front().first;
        if (cur->data == ch) {
            int nowid = q.front().second, deep = 0;
            std::cout << "ID in levelorder: " << nowid << '\n';
            while (nowid) nowid >>= 1, deep++;
            std::cout << "Deepth: " << deep << '\n';
            if (cur->lCld) std::cout << "LeftChild: " << cur->lCld->data << '\n';
            else std::cout << "LeftChild: #\n";
            if (cur->rCld) std::cout << "RightChild: " << cur->rCld->data << '\n';
            else std::cout << "ReftChild: #\n";
            return cur;
        }
        q.pop();
        if (cur->lCld) q.push({cur->lCld, ++id});
        if (cur->rCld) q.push({cur->rCld, ++id});
    }
    return nullptr;
}

// ABD##E##CF##G##

int main() {
    BiTree<char> bt;
    bt.allOrder();
    char tmpch = '#';
    tmpch = bt.findNodeAndDeepthAndChildNode('B')->data;
    std::cout << "Value: " << tmpch << '\n';
    tmpch = '#';
    tmpch = bt.findNodeAndDeepthAndChildNode('E')->data;
    std::cout << "Value: " << tmpch << '\n';
    system("pause");
}