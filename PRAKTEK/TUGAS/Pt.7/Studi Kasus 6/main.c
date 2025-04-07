#include "kota.h"

int main() {
    CityNode* cityList = NULL;

    InsertName(&cityList, "Bandung", "Amir");
    InsertName(&cityList, "Bandung", "Wahab");
    InsertName(&cityList, "Bandung", "Yahya");

    InsertName(&cityList, "Jakarta", "Badu");
    InsertName(&cityList, "Jakarta", "Hasan");

    InsertName(&cityList, "Surabaya", "Dedi");
    InsertName(&cityList, "Surabaya", "Eka");
    InsertName(&cityList, "Surabaya", "Fani");
    InsertName(&cityList, "Surabaya", "Gita");

    InsertName(&cityList, "Medan", "Hendra");
    InsertName(&cityList, "Medan", "Indra");

    InsertName(&cityList, "Makassar", "Kiki");

    printf("\n\nData awal:\n");
    PrintStructure(cityList);

    InsertName(&cityList, "Bandung", "Yahya");
    InsertName(&cityList, "Jakarta", "Hasan");
    InsertName(&cityList, "Surabaya", "Gita");
    InsertName(&cityList, "Medan", "Joko");
    InsertName(&cityList, "Makassar", "Lia");

    printf("\n\nData setelah penambahan:\n");
    PrintStructure(cityList);

    printf("\n\nData setelah penghapusan:\n");
    DeleteName(&cityList, "Bandung", "Amir");
    DeleteName(&cityList, "Jakarta", "Badu");
    DeleteName(&cityList, "Surabaya", "Dedi");
    PrintStructure(cityList);

    printf("\n\nData setelah penghapusan kota:\n");
    DeleteElement(&cityList, "Bandung");
    PrintStructure(cityList);

    CityNode* cityCurrent = cityList;
    while (cityCurrent != NULL) {
        Node* nameCurrent = cityCurrent->p;
        while (nameCurrent != NULL) {
            Node* temp = nameCurrent;
            nameCurrent = nameCurrent->q;
            free(temp);
        }
        CityNode* temp = cityCurrent;
        cityCurrent = cityCurrent->next;
        free(temp);
    }

    return 0;
}