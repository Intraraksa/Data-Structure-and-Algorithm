#include <iostream>

using namespace std;

class Node{
  public:
    int value;
    Node* next;
  Node(int value){
    this->value = value;
    next = nullptr;
  }
};

class LinkedList{
  private:
    int length;
    Node* head;
    Node* tail;
  public:
  LinkedList(int value){
    length = 1;
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
  }

  // function for printlength
  void printLength(){
    cout << length << endl;
  }
  void printList(){
    Node* temp;
    temp = head;
    while (temp != nullptr){
      cout << temp->value << endl;
      temp = temp->next;
    }
  }
// function to append to last
  void append(int value){
    Node* newNode = new Node(value);
    tail->next = newNode;
    tail = newNode;
    this->length = this->length+1;
  }
// function to delete from last
  void deleteLast(){
    if (length == 0) return;
    Node* pre = head;
    Node* temp = head;
    while (temp->next){
      pre = temp;
      temp = temp->next;
    }
    tail = pre;
    tail->next = nullptr;
    this->length = this->length - 1;
    if (length==0){
      head = nullptr;
      tail = nullptr;  
    }
    delete temp;
  }

// function to prepend
  void prepend(int value){
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
  }
// function to delete first
  void deleteFirst(){
    if (length==0) return;
    Node* temp = head;
    if (length==1){
      head = nullptr;
      tail = nullptr;
    }
    else{
      head = temp->next;
      delete temp;
    }
    length--;
  }
// function to get index memory
  Node* get(int index){
    if (index < 0 || index >= length){
      return nullptr;
    }
    else{
    Node* temp = head;
    for (int i=0; i < index; i++){
        temp =  temp->next;
    }
    return temp;
      }
  }
// function to set value into particular index
bool set(int value,int index){
  Node* temp = get(index);
  if (temp != nullptr){
    temp->value = value;
    return true;
  }
  return false;
}
};

// Main function
int main(){
  LinkedList* linkedlist = new LinkedList(5);
  // linkedlist->printLength();
  linkedlist->append(6);
  linkedlist->append(12);
  linkedlist->append(13);
  linkedlist->printList();
  linkedlist->set(16,3);
  linkedlist->printList();
}
