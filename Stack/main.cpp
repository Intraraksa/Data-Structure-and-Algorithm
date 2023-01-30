#include <iostream>
using namespace std;

class Node{
  public:
    int value;
    Node* next;
    
    Node (int value){
      this->value = value;
      next = nullptr;
    }
};

class Stack{
  private:
    Node* top;
    int height;
  public:
    Stack(int value){
      Node* newNode = new Node(value);
      top = newNode;
      height = 1;
    }
// function for print stack
  void printStack(){
    Node* temp = top;
    while(temp){
      cout << temp->value << endl;
      temp = temp->next;
    }
  }
// function to get top
  void getTop(){
    cout << "Top of stack is " << top->value << endl;
  }
// function to get height
  void getHeight(){
    cout << "Height is " << height << endl;
  }
// function for push
 void push(int value){
   Node* newNode = new Node(value);
   newNode->next = top;
   top = newNode;
   height++;
 }
// function to pop
  int pop(){
    if (height == 0) return -1;
    Node* temp = top;
    int toppedValue = top->value;
    top = top->next;
    delete temp;
    height--;
    return toppedValue;
  } 
};


int main() {
  Stack* stack = new Stack(5);
  stack->push(57);
  cout << stack->pop();
}