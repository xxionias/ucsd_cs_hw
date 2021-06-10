#include <iostream>
#include "ContactNode.h"

using namespace std;

ContactNode::ContactNode(string name, string num) {
  contactName = name;
  contactPhoneNum = num;
}

void ContactNode::InsertAfter(ContactNode* nodePtr) {
  this->nextNodePtr = nodePtr;
}

string ContactNode::GetName() {
  return this->contactName;
}

string ContactNode::GetPhoneNumber() {
  return this->contactPhoneNum;
}

ContactNode* ContactNode::GetNext() {
  return this->nextNodePtr;
}

void ContactNode::PrintContactNode() {
  cout << "Name: " << contactName << endl;
  cout << "Phone number: " << contactPhoneNum << endl;
}
