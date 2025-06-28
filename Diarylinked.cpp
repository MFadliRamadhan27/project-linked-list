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
void tampilkanCatatan() {
    if (head == NULL) {
        cout << "Belum ada catatan.\n";
        return;
    }

    cout << "===== Daftar Catatan Harian =====\n";
    Catatan* temp = head;
    int nomor = 1;
    while (temp != NULL) {
        cout << nomor++ << ". " << temp->isi << endl;
        temp = temp->next;
    }
}