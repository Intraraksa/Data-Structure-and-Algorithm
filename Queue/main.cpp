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
class Queue{
  private:
    Node* first;
    Node* last;
    int length;

  public:
  Queue(int value){
    Node* newNode = new Node(value);
    first = newNode;
    last = newNode;
    length = 1;
  }
// function for print stack
  void printQueue(){
    Node* temp = first;
    while(temp){
      cout << temp->value << endl;
      temp = temp->next;
    }
  }
// function to get top
  void getFirst(){
    cout << "First of queue is " << first->value << endl;
  }
// function to get height
  void getLast(){
    cout << "Last of queue is " << last->value << endl;
  }
// function to get length
  void getLength(){
    cout << "Length is " << length << endl;
  }
// function to add value
  void enqueue(int value){
    Node* newNode = new Node(value);
    last->next = newNode;
    last = newNode;
    length++;
  }
// function to remove node
  void dequeue(){
    if (length == 0) return -666;
    if (length == 1){
      first = nullptr;
      last = nullptr;
    }else{
      Node* temp = first;
      first = temp->next;
      delete temp; 
    }
    length--;
  }
};

int main() {
  Queue* queue = new Queue(7);
  queue->enqueue(11);
  queue->enqueue(4);
  queue->printQueue();
  cout << "Delete" << endl;
  queue->dequeue();
  queue->dequeue();
  queue->printQueue();
  queue->getLength();
  
  
}