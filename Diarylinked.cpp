#include <iostream>
using namespace std;

struct Catatan {
    string isi;
    Catatan* next;
};

Catatan* head = NULL;
