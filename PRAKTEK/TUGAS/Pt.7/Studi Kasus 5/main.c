#include "arraykota.h"

int main() {
    ArrayNRLL array;
    InitArray(&array);

    InsertName(&array, "Bandung", "Amir");
    InsertName(&array, "Bandung", "Wahab");
    InsertName(&array, "Bandung", "Yahya");

    InsertName(&array, "Jakarta", "Badu");
    InsertName(&array, "Jakarta", "Hasan");

    InsertName(&array, "Surabaya", "Dedi");
    InsertName(&array, "Surabaya", "Eka");
    InsertName(&array, "Surabaya", "Fani");
    InsertName(&array, "Surabaya", "Gita");

    InsertName(&array, "Medan", "Hendra");
    InsertName(&array, "Medan", "Indra");
    

    InsertName(&array, "Makassar", "Kiki");

    printf("\n\nData awal:\n");
    PrintStructure(&array);
    
    InsertName(&array, "Bandung", "Yahya");
    InsertName(&array, "Jakarta", "Hasan");
    InsertName(&array, "Surabaya", "Gita");
    InsertName(&array, "Medan", "Joko");
    InsertName(&array, "Makassar", "Lia");

    printf("\n\nData setelah penambahan:\n");
    PrintStructure(&array);
    
    printf("\n\nData setelah penghapusan:\n");
    DeleteName(&array, "Bandung", "Amir");
    DeleteName(&array, "Jakarta", "Badu");
    DeleteName(&array, "Surabaya", "Dedi");
    PrintStructure(&array);

    printf("\n\nData setelah penghapusan kota:\n");
    DeleteElement(&array, "Bandung");
    PrintStructure(&array);

    return 0;
}