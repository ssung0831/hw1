#include "split.h"
#include <cstddef>
#include <iostream>
using namespace std;

void print(Node* to_print){
  // while(to_print != NULL){
  //   cout << to_print -> value << " ";
  //   to_print = to_print -> next;
  // }

  if(to_print == NULL){
    return;
  }
  else{
    cout << to_print -> value << " ";
    print(to_print -> next);
  }
}


int main(/*int argc, char* argv[]*/)
{
  Node* evens = nullptr;
  Node* odds = nullptr;

//random
//  Node* example = new Node(2, new Node(4, new Node(7, new Node(11, new Node(18, nullptr)))));
//  Node* example = new Node(9, new Node(15, new Node(42, new Node(65, new Node(79, new Node(112, new Node(150, nullptr)))))));
//all evens
//   Node* example = new Node(12, new Node(22, new Node(38, new Node(94, new Node(104, nullptr)))));
// //all odds
//   Node* example = new Node(1, new Node(7, new Node(11, new Node(21, new Node(99, nullptr)))));
//  //0's, equal nums
//   Node* example = new Node(0, new Node(4, new Node(5, new Node(6, new Node(6, nullptr)))));
  
  Node* example = new Node(2, nullptr);
  Node* n2 = new Node(4, nullptr);
  example -> next = n2;
  Node* n3 = new Node(7,nullptr);
  n2 -> next = n3;
  Node* n4 = new Node(11,nullptr);
  n3 -> next = n4;
  Node* n5 = new Node(18,nullptr);
  n4 -> next = n5;
  
  print(example);

  cout << endl;

  split(example, evens, odds);
  
  print(evens);

  cout << endl;

  print(odds);

  delete n5;
  delete n4;
  delete n3;
  delete n2;
  delete example;
  
}
