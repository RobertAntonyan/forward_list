#include <iostream>
#include <vector>
#include <string>

template <typename T>
class list
{
public:
    list();
    ~list();
    void pop_front();
    void push_back(T data);
    void clear();
    int getSize() { return Size; }
    T &operator[](const int index);
    void push_front(T data);
    void insert(T value, int index);
    void removeAt(int index);
    void pop_back();
    bool emty();

private:
    template <typename U>
    class Node
    {
    public:
        Node *pnext;
        T data;
        Node(T data = T(), Node *pnext = nullptr)
        {
            this->data = data;
            this->pnext = pnext;
        }
    };
    int Size;
    Node<int> *head;
};

template <typename T>
list<T>::list()
{
    Size = 0;
    head = nullptr;
}
template <typename T>
list<T>::~list()
{
    list<T>::clear();
}

template <typename T>
void list<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T> *current = this->head;
        while (current->pnext != nullptr)
        {
            current = current->pnext;
        }
        current->pnext = new Node<T>(data);
    }
    Size++;
}
template <typename T>
T &list<T>::operator[](const int index)
{
    int counter = 0;
    Node<T> *current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pnext;
        counter++;
    }
    return current->data;
}
template <typename T>
void list<T>::pop_front()
{
    Node<T> *temp = head;
    head = head->pnext;
    delete temp;
    Size--;
}
template <typename T>
void list<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}
template <typename T>
void list<T>::push_front(T data)
{
    head = new Node<T>(data, head);
    Size++;
}

template <typename T>
void list<T>::insert(T value, int index)
{
    if (index == 0)
    {
        push_front(value);
    }
    else
    {
        Node<T> *previous = this->head;
        for (int i = 0; i < index - 1; ++i)
        {
            previous = previous->pnext;
        }

        previous->pnext = new Node<T>(value, previous->pnext);
        Size++;
    }
}
template <typename T>
void list<T>::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T> *previous = this->head;
        for (int i = 0; i < index - 1; ++i)
        {
            previous = previous->pnext;
        }
        Node<T> *toDelete = previous->pnext;
        previous->pnext = toDelete->pnext;
        delete toDelete;
        Size--;
    }
}

template <typename T>
void list<T>::pop_back()
{
    removeAt(Size - 1);
}

template <typename T>
bool list<T>::emty()
{
    if (head == nullptr)
    {
        return true;
    }

    return false;
}

int main()
{
    list<int> lst;
    lst.push_front(5);
    std::cout << lst.emty() << std::endl;
}
