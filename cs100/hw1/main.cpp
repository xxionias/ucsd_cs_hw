#include "ContactNode.h"

#include <iostream>
#include <string>

using namespace std;


int main() {
  string name, num;

  cout << "Person 1" << endl;
  cout << "Enter name:" << endl;
  getline(cin, name);
  cout << "Enter phone number:" << endl;
  cin >> num;
  ContactNode *person1;
  person1 = new ContactNode(name, num);
  cout << "You entered: " << person1->GetName() << ", "
                      << person1->GetPhoneNumber() << endl;
  cout << endl;

  cout << "Person 2" << endl;
  cout << "Enter name:" << endl;
  cin.ignore();
  getline(cin, name);
  cout << "Enter phone number:" << endl;
  cin >> num;
  ContactNode *person2;
  person2 = new ContactNode(name, num);
  cout << "You entered: " << person2->GetName() << ", "
                        << person2->GetPhoneNumber() << endl;
  person1->InsertAfter(person2);
  cout << endl;

  cout << "Person 3" << endl;
  cout << "Enter name:" << endl;
  cin.ignore();
  getline(cin, name);
  cout << "Enter phone number:" << endl;
  cin >> num;
  ContactNode *person3;
  person3 = new ContactNode(name, num);
  cout << "You entered: " << person3->GetName() << ", "
                        << person3->GetPhoneNumber() << endl;
  person2->InsertAfter(person3);
  cout << endl;

  cout << "CONTACT LIST" << endl;
  ContactNode *currNode = person1;
  while (currNode) {
    currNode->PrintContactNode();
    currNode = currNode->GetNext();
    cout << endl;
  }

  return 0;
}
