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
void tampilkanPesan() {
    if (head == NULL) {
        cout << "Belum ada pesan.\n";
        return;
    }

    cout << "===== Riwayat Chat =====\n";
    Pesan* temp = head;
    int nomor = 1;
    while (temp != NULL) {
        cout << nomor++ << ". " << temp->isi << endl;
        temp = temp->next;
    }
}
void hapusPesanPertama() {
    if (head == NULL) {
        cout << "Tidak ada pesan yang bisa dihapus.\n";
        return;
    }

    Pesan* hapus = head;
    head = head->next;
    cout << "Pesan \"" << hapus->isi << "\" telah dihapus.\n";
    delete hapus;
}
void hapusSemuaPesan() {
    while (head != NULL) {
        Pesan* hapus = head;
        head = head->next;
        delete hapus;
    }
    cout << "Semua pesan telah dihapus.\n";
}
void hitungPesan() {
    int jumlah = 0;
    Pesan* temp = head;
    while (temp != NULL) {
        jumlah++;
        temp = temp->next;
    }
    cout << "Jumlah pesan: " << jumlah << endl;
}
