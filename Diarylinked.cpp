#include <iostream>
using namespace std;

struct Catatan {
    string isi;
    Catatan* next;
};

Catatan* head = NULL;
void tambahCatatan(string isi) {
    Catatan* baru = new Catatan{isi, NULL};
    if (head == NULL) {
        head = baru;
    } else {
        Catatan* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Catatan ditambahkan: \"" << isi << "\"\n";
}