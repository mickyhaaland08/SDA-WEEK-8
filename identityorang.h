// identityorang.h
#ifndef IDENTITYORANG_H
#define IDENTITYORANG_H

typedef char* string;

typedef struct Orang {
    string nama;
    struct Orang *next;
} Orang;

typedef struct {
    string namaKota;
    Orang *daftarOrang;
} Kota;

void tambahOrang(Kota *p, string nama);
void hapusKota(Kota *p);
void tampilkanKota(Kota kota[], int jumlah);
void hapusKotaByNama(Kota kota[], int jumlah, string nama);

#endif
