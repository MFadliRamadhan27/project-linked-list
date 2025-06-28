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
void hitungCatatan() {
    int jumlah = 0;
    Catatan* temp = head;
    while (temp != NULL) {
        jumlah++;
        temp = temp->next;
    }
    cout << "Jumlah catatan: " << jumlah << endl;
}
int main() {
    int pilihan;
    string isiCatatan;

    do {
        cout << "\n=== MENU CATATAN HARIAN ===\n";
        cout << "1. Tambah Catatan\n";
        cout << "2. Tampilkan Semua Catatan\n";
        cout << "3. Hapus Catatan Pertama\n";
        cout << "4. Hapus Semua Catatan\n";
        cout << "5. Hitung Catatan\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Ketik catatan: ";
                cin >> ws;
                getline(cin, isiCatatan);
                tambahCatatan(isiCatatan);
                break;
            case 2:
                tampilkanCatatan();
                break;
            case 3:
                hapusCatatanPertama();
                break;
            case 4:
                hapusSemuaCatatan();
                break;
            case 5:
                hitungCatatan();
                break;
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}