#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
	head = nullptr;
}

LinkedList::~LinkedList() {
	while (head != nullptr) {
		deleteFront();
	}
}

void LinkedList::insertFront(int item) {
	Node* newNode = new Node(item, head);
	head = newNode;
}

void LinkedList::deleteFront() {
	if(head != nullptr) {
		Node* oldHead = head;
		head = head->link;
		delete oldHead;
	}
}

void LinkedList::printList() {
	Node* currNode = head;
	while(currNode != nullptr) {
		std::cout << currNode->data << " ";
		currNode = currNode->link;
	}
}

/////////// your code goes here... DO NOT change the function signatures ///////////

bool LinkedList::swap(int pos1, int pos2) {
    if (pos1 == pos2 || head == nullptr) return false;
    
    Node* prev1 = nullptr, *prev2 = nullptr;
    Node* curr1 = head, *curr2 = head;
    int count = 0;

    while (count < pos1 && curr1) {
        prev1 = curr1;
        curr1 = curr1->link;
        count++;
    }
    
    if (!curr1) return false; // pos1 is out of range

    count = 0;
    while (count < pos2 && curr2) {
        prev2 = curr2;
        curr2 = curr2->link;
        count++;
    }
    
    if (!curr2) return false; // pos2 is out of range

    // Swap nodes
    if (prev1) prev1->link = curr2;
    else head = curr2;

    if (prev2) prev2->link = curr1;
    else head = curr1;

    Node* temp = curr1->link;
    curr1->link = curr2->link;
    curr2->link = temp;

    return true;
}

bool LinkedList::find_and_delete(int target) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr) {
        if (curr->data == target) {
            if (prev) {
                prev->link = curr->link;
            } else {
                head = curr->link;
            }
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->link;
    }

    return false; // target not found
}
bool LinkedList::swap(int pos1, int pos2) {
 //遍历，查找两个位置上的节点
 Node* tmp = head;
 Node* pre = nullptr;
 Node* node1 = nullptr;
 Node* node2 = nullptr;
 Node* pre_node1 = nullptr;
 Node* pre_node2 = nullptr;
 Node* after_node1 = nullptr;
 Node* after_node2 = nullptr;
 int cnt = 0;

 while(tmp != nullptr) {
  if(cnt == pos1){
   node1 = tmp;
   pre_node1 = pre;
   after_node1 = node1 -> link;
  }
  if(cnt == pos2){
   node2 = tmp;
   pre_node2 = pre;
   after_node2 = node2 -> link;
  }
  pre = tmp;
  tmp = tmp->link;
  cnt++;
 }

 if(cnt < pos1 || cnt < pos2){
  return false;
 }
 if(pos1 == pos2){
  return true;
 }

 //交换位置
 pre_node1 -> link = node2;
 node2 -> link = after_node1;

 pre_node2 -> link = node1;
 node1 -> link = after_node2;

 return true;
}

bool LinkedList::find_and_delete(int target) {
 //遍历，查找
 Node* tmp = head;
 Node* pre = nullptr;
 while(tmp != nullptr) {
  if(tmp -> data == target){
   if(pre == nullptr){
    deleteFront();
    return true;
   }
   pre -> link = tmp->link;
   delete tmp;
   return true;
  }
  pre = tmp;
  tmp = tmp->link;
 }

 return false;
}

