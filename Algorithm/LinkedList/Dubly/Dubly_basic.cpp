#include<iostream>
using namespace std;

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int arr[],int len){
    struct Node *t,*last;

    first = new Node;
    first->data= arr[0];

}