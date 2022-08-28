//#pragma once
//class OldStack
//{
//};
//
//// stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
//#include <iostream>
//
//
//
//
//
//class stack
//{ //TODO topItem needs to be read as a generic variable
//private:
//    const static int _maxStack = 999;
//
//    int topItem;
//
//
//public:
//    //list initialization
//    stack() { topItem = -1; std::cout << "I am stack" << "\n"; }
//
//    template <typename T>
//    bool push(T item);
//    int pop();
//    void popTemp();
//    bool isEmpty();
//
//    int currentStack[_maxStack];
//
//};
//template <typename T>
//bool stack::push(T item)
//{
//    if (topItem >= (_maxStack - 1))
//    {
//        std::cout << "overflow";
//        return false;
//    }
//    else
//    {
//        currentStack[++topItem] = item;
//        return true;
//    }
//}
//
//void stack::popTemp()
//{
//    if (isEmpty())
//    {
//        std::cout << "Stack is empty";
//    }
//    else
//    {
//        std::cout << currentStack[topItem--] << '\n';
//    }
//}
//
//
//int stack::pop()
//{
//    if (topItem < 0)
//    {
//        return 0;
//    }
//    else
//    {
//        int item = currentStack[topItem--];
//        return item;
//    }
//}
//
//bool stack::isEmpty()
//{
//    return (topItem < 0);
//}
//
//int main()
//{
//    class stack stack;
//    stack.push(2);
//    stack.push(4.2);
//    stack.push(6);
//
//    while (!stack.isEmpty())
//    {
//
//        stack.popTemp();
//    }
//}
//
//
//
