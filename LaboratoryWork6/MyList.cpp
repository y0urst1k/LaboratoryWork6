#include "Data.h"
#include "MyList.h"

Node::Node(const Car& carP) : car(carP)
{
	this->prev = this->next = nullptr;
};

MyList::MyList()
{
    this->head = this->tail = nullptr;
}

Node* MyList::PushFront(Car car)
{
    Node* ptr = new Node(car);

    ptr->next = head;
    if (head != nullptr)
        head->prev = ptr;
    if (tail == nullptr)
        tail = ptr;
    head = ptr;

    return ptr;
}

Node* MyList::PushBack(Car car)
{
    Node* ptr = new Node(car);

    ptr->prev = tail;
    if (tail != nullptr)
        tail->next = ptr;
    if (head == nullptr)
        head = ptr;
    tail = ptr;

    return ptr;
}

void MyList::PopFront()
{
    if (head == nullptr)
        return;

    Node* ptr = head->next;
    if (ptr != nullptr)
        ptr->prev = nullptr;
    else
        tail = nullptr;

    delete head;
    head = ptr;
}

void MyList::PopBack()
{
    if (tail == nullptr)
        return;

    Node* ptr = tail->prev;
    if (ptr != nullptr)
        ptr->next = nullptr;
    else
        head = nullptr;

    delete tail;
    tail = ptr;
}

Node* MyList::GetAt(int index) const
{
    Node* ptr = head;
    int n = 0;

    while (n != index)
    {
        if (ptr == nullptr)
            return ptr;
        ptr = ptr->next;
        n++;
    }

    return ptr;
}

Node* MyList::Insert(int index, Car car)
{
    if(index < 0)
        PushFront(car);

    Node* right = GetAt(index);
    if (right == nullptr)
        return PushBack(car);

    Node* left = right->prev;
    if (left == nullptr)
        return PushFront(car);

    Node* ptr = new Node(car);

    ptr->prev = left;
    ptr->next = right;
    left->next = ptr;
    right->prev = ptr;

    return ptr;
}

void MyList::Delete(int index)
{
    Node* ptr = GetAt(index);
    if (ptr == nullptr)
        return;

    if (ptr->prev == nullptr)
    {
        PopFront();
        return;
    }

    if (ptr->next == nullptr)
    {
        PopBack();
        return;
    }

    Node* left = ptr->prev;
    Node* right = ptr->next;
    left->next = right;
    right->prev = left;

    delete ptr;
}

int MyList::Size() const
{
    int count = 0;
    Node* ptr = head;

    while (ptr != nullptr)
    {
        count++;
        ptr = ptr->next;
    }

    return count;
}

void MyList::Clear()
{
    while (head != nullptr)
        PopFront();
}

bool MyList::IsEmpty() const
{
    return head == nullptr;
}

MyList::~MyList()
{
    while (head != nullptr)
        PopFront();
}