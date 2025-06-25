#include <iostream>
using namespace std;

struct Pesan {
    string isi;
    Pesan* next;
};

Pesan* head = NULL;
