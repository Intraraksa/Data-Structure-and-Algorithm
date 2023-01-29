#include <iostream>
using namespace std;

class Node{
  public:
    int value;
    Node* next;
    Node* prev;

    Node(int value){
      this->value = value;
      next = nullptr;
      prev = nullptr;
    }
};

class DoublyLinkedList{
  private:
    Node* head;
    Node* tail;
    int length;

  public:
    DoublyLinkedList(int value){
      Node* newNode = new Node(value);
      head = newNode;
      tail = newNode;
      length = 1;
    }

  void gethead(){
    cout << head->value << endl;
  }

  void gettail(){
    cout << tail-> value << endl;
  }
  void printLength(){
    cout << length << endl;
  }
// function for see values in list
  void printList(){
    // if (length != 0){
      Node* temp = head;
      while(temp){
        cout << temp->value << endl;
        temp = temp->next;
      }
    // }
  }
// function to append
  void append(int value){
    Node* newNode = new Node(value);
    // head = newNode;
    // tail = newNode;
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    length++;
  }
// function for delete last'
  void deleteLast(){
    if (length == 0) return;
    Node* temp = tail;
    if (length == 1){
      head = nullptr;
      tail = nullptr;
    }else{
      tail = tail->prev;
      tail->next = nullptr;
      // temp->prev = nullptr;
    }
    delete temp;
    length--;
  }
// function for prepend
  void prepend(int value){
    Node* newNode = new Node(value);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    length++;
  }
// function to delete first
  void deleteFirst(){
    Node* temp = head;
    if (length==1){
      head = nullptr;
      tail = nullptr;
    }else{
      head = head->next;
      head->prev = nullptr;
    }
    delete temp;
    length--;
  }
// function for get index
  Node* get(int index){
    if (index < 0 || index >= length){
      return nullptr;
      }else{
      Node* temp = head;
      for (int i=0; i < index; i++){
        temp = temp->next;
      }
      return temp;
    }
  }
};

int main(){
  DoublyLinkedList* Dll = new DoublyLinkedList(4);
  // Dll->printLength();
  Dll->append(7);
  Dll->printList();
  cout << Dll->get(1) << endl;
}