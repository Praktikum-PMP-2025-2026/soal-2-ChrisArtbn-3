#include <stdio.h>
#include <stdlib.h>

struct angka {
    int data;
    struct angka* next;
}
;

struct angka* createList() {
    struct angka *head = NULL, *temp = NULL, *newangka = NULL;
    int N, data;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        newangka = (struct angka*)malloc(sizeof(struct angka));
        
        scanf("%d", &data);
        
        newangka->data = data;
        newangka->next = NULL;

        if (head == NULL) {
            head = newangka;
            temp = head;
        } else {
            temp->next = newangka;
            temp = temp->next;
        }
    }
    return head;
}

int getpanjang1 (struct angka* head1){
    int pipi = 0;
    struct angka* now = head1;
    while (now != NULL){
        pipi++;
        now = now->next;
    }
    return pipi;
}

int getpanjang2 (struct angka* head2){
    int hehe = 0;
    struct angka* curr = head2;
    while (curr != NULL){
        hehe++;
        curr = curr->next;
    }
    return hehe;
}

struct angka* sortedList1(struct angka* head1){
    struct angka* nowangka = head1;
    int pipi = getpanjang1(head1);

    int itr = 0;
    int tuker;

    while (itr < pipi){
        struct angka *tranverseangka1 = head1;
        struct angka *previousangka1 = head1;

        tuker = 0;

        while (tranverseangka1->next != NULL){
            struct angka* ptr = tranverseangka1->next;
            if (tranverseangka1->data > ptr->data){
                tuker = 1;
                if (tranverseangka1 == head1){
                    tranverseangka1->next = ptr->next;
                    ptr->next = tranverseangka1;
                    previousangka1 = ptr;
                    head1 = previousangka1;
                }
                else{
                    tranverseangka1->next = ptr->next;
                    ptr->next = tranverseangka1;
                    previousangka1->next = ptr;
                    previousangka1 = ptr;
                }
                continue;
            }
            previousangka1 = tranverseangka1;
            tranverseangka1 = tranverseangka1->next;
        }

        if (!tuker){
            break;
        }
        itr++;
    }
    return head1;

}

struct angka* sortedList2(struct angka* head2){
     struct angka* nowangka = head2;
     int hehe = getpanjang2(head2);
     int itr = 0;
     int tuker;

    while (itr < hehe){
        struct angka *tranverseangka2 = head2;
        struct angka *previousangka2 = head2;

        tuker = 0;
        while (tranverseangka2->next != NULL){
            struct angka* ptr = tranverseangka2->next;
            if (tranverseangka2->data > ptr->data){
                tuker = 1;
                if (tranverseangka2 == head2){
                    tranverseangka2->next = ptr->next;
                    ptr->next = tranverseangka2;
                    previousangka2 = ptr;
                    head2 = previousangka2;
                }
                else{
                    tranverseangka2->next = ptr->next;
                    ptr->next = tranverseangka2;
                    previousangka2->next = ptr;
                    previousangka2 = ptr;
                }
                continue;
            }
            previousangka2 = tranverseangka2;
            tranverseangka2 = tranverseangka2->next;
        }

        if (!tuker){
            break;
        }
        itr++;
    }
    return head2;

}


struct angka* sortedgabungan(struct angka* head1, struct angka* head2){

   if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    if (head1->data <= head2->data) {
        head1->next = sortedgabungan(head1->next, head2);
        return head1;
    }
    else {
        head2->next = sortedgabungan(head1, head2->next);
        return head2;
    }
}

void printList(struct angka* head){
    if (head == NULL){
        printf("MERGED EMPTY");
    }
    else{
        printf("MERGED");
        while (head != NULL){
            printf("%d", head->data);
            head = head->next;
        }
    }
}

int main(){
    struct angka* head1 = NULL;
    struct angka* head2 = NULL;
    struct angka* gabunganHead = NULL;

    head1 = createList();
    head2 = createList(); 
    head1 = sortedList1(head1);
    head2 = sortedList2(head2);

    gabunganHead = sortedgabungan(head1, head2);

    printList(gabunganHead);

    return 0;
}

/* Referensi 
    https://www.geeksforgeeks.org/dsa/concatenation-of-two-linked-lists/
    https://www.geeksforgeeks.org/dsa/bubble-sort-for-linked-list-by-swapping-nodes/
    https://www.geeksforgeeks.org/dsa/sorting-a-singly-linked-list/#sort-linked-list-using-bubble-sort
*/
