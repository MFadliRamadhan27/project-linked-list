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
void hapusCatatanPertama() {
    if (head == NULL) {
        cout << "Tidak ada catatan yang bisa dihapus.\n";
        return;
    }

    Catatan* hapus = head;
    head = head->next;
    cout << "Catatan \"" << hapus->isi << "\" telah dihapus.\n";
    delete hapus;
}
void hapusSemuaCatatan() {
    while (head != NULL) {
        Catatan* hapus = head;
        head = head->next;
        delete hapus;
    }
    cout << "Semua catatan telah dihapus.\n";
}