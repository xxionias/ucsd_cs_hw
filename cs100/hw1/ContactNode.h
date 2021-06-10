#ifndef CONTACT_NODE_H
#define CONTACT_NODE_H

#include <iostream>
#include <string>

using namespace std;

class ContactNode {

public:
  ContactNode(string name, string num);

  void InsertAfter(ContactNode* nodePtr);

  string GetName();

  string GetPhoneNumber();

  ContactNode* GetNext();

  void PrintContactNode();

private:
  string contactName;

  string contactPhoneNum;

  ContactNode* nextNodePtr;
};

#endif
