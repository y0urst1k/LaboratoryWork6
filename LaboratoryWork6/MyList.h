#pragma once
#include "Data.h"

struct Node
{
    Node(const Car&);
    Car car;
    Node* prev, * next;
};

struct MyList
{
    MyList();
    Node* head, * tail;

    Node* PushFront(Car car);
    Node* PushBack(Car car);

    void PopFront();
    void PopBack();

    Node* GetAt(int index) const;

    Node* Insert(int index, Car car);
    void Delete(int index);

    int Size() const;
    void Clear();

    bool IsEmpty() const;

    ~MyList();
};