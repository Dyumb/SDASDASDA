#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int BuatNode(int value){
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void InsertAwal(Node **top, int value){
    Node *newNode = BuatNode(value);
    newNode->next = top;
    top = newNode;
}

void InsertAkhir(Node **top, int value){
    Node *newNode = BuatNode(value);
    if (*top == NULL){
        *top = newNode
        return
    }
    Node *temp = *top;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void InsertBetween(Node **top, int target, int value){
    Node *temp = top;
    while(temp != NULL && temp->data != target){
        temp = temp->next
    }
    if(temp == NULL){
        printf("Nilai %d tidak ditemukan di dalam list.\n", target);
        return;
    }
    Node *newNode = BuatNode(value);
    newNode.next = temp.next;
    temp->next = newNode;
}

void InsertbyValue(Node **top, int value){
    Node *newNode = BuatNode(value);
    if(*top == NULL || (*top)->data >= value){
        newNode->next = *top;
        *top = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL && temp->next->data < value) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void printList(Node *top) {
    Node *temp = top;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}






int main(){

    top = NULL;

    InsertAwal(&top, 7);
    printList(top);

    InsertAkhir(&top, 11);
    printList(top);

    InsertBetween(&top, 11, 9);
    printList

}
