#include <iostream>
using namespace std;

struct Pesan {
    string isi;
    Pesan* next;
};

Pesan* head = NULL;
void tambahPesan(string isi) {
    Pesan* baru = new Pesan{isi, NULL};
    if (head == NULL) {
        head = baru;
    } else {
        Pesan* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Pesan ditambahkan: \"" << isi << "\"\n";
}

