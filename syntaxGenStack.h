#ifndef SYNTAXGENSTACK_H
#define SYNTAXGENSTACK_H
#include <iostream>
#include <stdexcept>
#include <fstream>

//#include "stackNotes.cpp"
using namespace std;

template <class T>

class syntaxGenStack{
  public:
    syntaxGenStack(); // constructor
    syntaxGenStack(int maxSize); //overloaded constructor
    ~syntaxGenStack(); //destructor

    void push(const T& d); //pushes the &object of class T
    T pop();
    T peek();
    void resize();

    bool isFull();
    bool isEmpty();

    //int maxSize;
    int size;
    int top;
    T *myArray; //pointer because the over loaded constructor is not set to how many elements there will be
};

template <class T>
syntaxGenStack<T>::syntaxGenStack(){
  myArray = new T[128];
  size = 128;
  top = -1;
}

template <class T>
syntaxGenStack<T>::syntaxGenStack(int maxSize){
  myArray = new T[maxSize];
  size = maxSize;
  top = -1;
}

template <class T>
syntaxGenStack<T>::~syntaxGenStack(){
  delete myArray;
}

template <class T>
void syntaxGenStack<T>::push(const T& d){
  if(top >= size-1){
    this->resize();
    myArray[++top] = d;
}
  else{
    myArray[++top] = d;
}
}

template<class T>
T syntaxGenStack<T>::peek(){
  //check if empty
  if(top<0){
    std::cout << "Stack is empty" << endl;
    return '\0';
  }
  return myArray[top];
}

template <class T>
T syntaxGenStack<T>::pop(){
  if(top<0){
    throw std::runtime_error("Stack is empty.");
    return '\0';
  }
  else{
    return myArray[top--];
  }
}

template <class T>
bool syntaxGenStack<T>::isEmpty(){
  return (top == -1);
}

template <class T>
bool syntaxGenStack<T>::isFull(){
  return (top == size-1);
}

template <class T>
void syntaxGenStack<T>::resize(){
    syntaxGenStack stack2(size);
    while(!this->isEmpty()){
        stack2.push(this->pop());
      }
    delete myArray;
    size *= 2;
    myArray = new T[size];
    while(!stack2.isEmpty()){
      this->push(stack2.pop());
      }
    }
#endif
