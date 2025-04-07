#include "linklist.h"

Node* CreateNode(char* nm) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(newNode->nama, nm);
    newNode->q = NULL;
    return newNode;
}

void InsertNode(Node** list, char* nm) {
    Node* newNode = CreateNode(nm);
    if (newNode == NULL) return;

    if (*list == NULL) {
        *list = newNode;
    } else {
        Node* temp = *list;
        while (temp->q != NULL) {
            temp = temp->q;
        }
        temp->q = newNode;
    }
}

void DeleteNode(Node** list, char* nm) {
    if (*list == NULL) return;

    Node* temp = *list;
    Node* prev = NULL;

    while (temp != NULL && strcmp(temp->nama, nm) != 0) {
        prev = temp;
        temp = temp->q;
    }

    if (temp == NULL) return; // Node not found

    if (prev == NULL) {
        *list = temp->q; // Deleting the first node
    } else {
        prev->q = temp->q; // Bypass the node to be deleted
    }

    free(temp);
}

int CountNodes(Node* list) {
    int count = 0;
    Node* temp = list;
    while (temp != NULL) {
        count++;
        temp = temp->q;
    }
    return count;
}

void PrintList(Node* list) {
    Node* temp = list;
    while (temp != NULL) {
        printf("%s ", temp->nama);
        temp = temp->q;
    }
    printf("\n");
}

Element CreateElement(char* kt) {
    Element element;
    strcpy(element.kota, kt);
    element.p = NULL;
    return element;
}

void LinkToList(Element* element, Node* list) {
    element->p = list;
}