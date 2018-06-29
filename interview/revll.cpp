#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
};

void print_ll(Node *head) {
  for(Node *t=head;t != NULL;t = t->next) {
      cout << t->data << " ";
  }
  if (head) cout << endl;
}

Node *rev_ll(Node *head) {

    Node *rev_list = 0;
    while(head) {
        Node *t = head;
        head = head->next;
        t->next = rev_list;
        rev_list = t;
    }
    return rev_list;


    /* // below is working, but can it be written more clearly?
    if(!head) return 0;

    for(Node *t=head, *t1=t->next;t1;) {
        t->next = t1->next;
        t1->next = head;
        head = t1;
        t1 = t->next;
    }
    return head;
    */

}

int main() {
  int d;
  Node *head = NULL, *t=NULL;
  do {
      cin >> d;
      if(d != -1) {
          Node *n = new Node();
          n->data = d;
          n->next = 0;
          if(t) {
              t->next = n;
              t = t->next;
          } else {
              head = t = n;
          }
      }
  }while(d != -1);
  print_ll(head);
  head = rev_ll(head);
  print_ll(head);
  return 0;
}

