#include <bits/stdc++.h>

const int maxSize = 1e3 + 7;

template <class Element>
class SegList {
   public:
    SegList();
    SegList(Element a[], int len);
    Element getItem(int pos);
    int locate(Element x);
    void insert(int pos, Element x);
    Element remove(int pos);
    bool empty();
    int getLength();
    void printList();

   private:
    Element data[maxSize];
    int length;
};

template <class Element>
SegList<Element>::SegList() {
    this->length = 0;
}

template <class Element>
Element SegList<Element>::getItem(int pos) {
    if (pos < 1 || pos > this->length) throw "wrong pos";
    return this->data[pos - 1];
}

template <class Element>
SegList<Element>::SegList(Element a[], int len) {
    if (len > maxSize) throw "wrong length";
    this->length = len;
    for (int i = 0; i < len; i++) data[i] = a[i];
}

template <class Element>
int SegList<Element>::locate(Element x) {
    for (int i = 0; i < this->length; i++)
        if (data[i] == x) return i + 1;
    return -1;
}

template <class Element>
void SegList<Element>::insert(int pos, Element x) {
    if (this->length >= maxSize) throw "full";
    else if (pos < 1 || pos > length) throw "wrong pos";
    for (int i = this->length; i >= pos; i--) data[i] = data[i - 1];
    data[pos - 1] = x;
}

template <class Element>
Element SegList<Element>::remove(int pos) {
    if (!this->length) throw "empty";
    else if (pos < 1 || pos > length) throw "wrong pos";
    Element tmp = data[pos - 1];
    for (int i = pos; i < this->length; i++) data[i - 1] = data[i];
    this->length--;
    return tmp;
}

template <class Element>
bool SegList<Element>::empty() {
    return !(this->length);
}

template <class Element>
int SegList<Element>::getLength() {
    return this->length;
}

template <class Element>
void SegList<Element>::printList() {
    for (int i = 0; i < this->length; i++) std::cout << data[i] << " \n"[i == this->length - 1];
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    SegList<int> sl(a, 5);
    sl.printList();
    std::cout << sl.locate(3) << '\n';
    std::cout << sl.getItem(4) << '\n';
    sl.insert(1, 6);
    sl.printList();
    sl.remove(3);
    sl.printList();
    // system("pause");
}