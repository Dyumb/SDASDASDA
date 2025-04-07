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

    if (temp == NULL) return;

    if (prev == NULL) {
        *list = temp->q;
    } else {
        prev->q = temp->q;
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

CityNode* CreateCityNode(char* kt) {
    CityNode* newNode = (CityNode*)malloc(sizeof(CityNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(newNode->kota, kt);
    newNode->p = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertCity(CityNode** list, char* kt) {
    CityNode* newNode = CreateCityNode(kt);
    if (newNode == NULL) return;

    if (*list == NULL) {
        *list = newNode;
    } else {
        CityNode* temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void DeleteCity(CityNode** list, char* kt) {
    if (*list == NULL) return;

    CityNode* current = *list;
    CityNode* prev = NULL;

    while (current != NULL && strcmp(current->kota, kt) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Kota %s tidak ditemukan.\n", kt);
        return;
    }

    Node* nameCurrent = current->p;
    while (nameCurrent != NULL) {
        Node* temp = nameCurrent;
        nameCurrent = nameCurrent->q;
        free(temp);
    }

    if (prev == NULL) {
        *list = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

int CountCities(CityNode* list) {
    int count = 0;
    CityNode* temp = list;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
