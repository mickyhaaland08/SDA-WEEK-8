#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "identityorang.h"

void tambahOrang(Kota *p, string nama) {
    Orang *baru = (Orang *)malloc(sizeof(Orang));
    baru->nama = strdup(nama);
    baru->next = p->daftarOrang;
    p->daftarOrang = baru;
}

void hapusKota(Kota *p) {
    Orang *q = p->daftarOrang;
    while (q != NULL) {
        Orang *hapus = q;
        q = q->next;
        free(hapus->nama);
        free(hapus);
    }
    p->daftarOrang = NULL;
    free(p->namaKota);
    p->namaKota = NULL;
}

void tampilkanKota(Kota kota[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        Kota *p = &kota[i];
        if (p->namaKota != NULL) {
            printf("%s", p->namaKota);  // cetak nama kota dulu
            Orang *q = p->daftarOrang;
            while (q != NULL) {
                printf(" \"%s\"", q->nama);  // cetak setiap nama orang
                q = q->next;
            }
            printf("\n");  // pindah baris setelah satu kota selesai
        }
    }
}


void hapusKotaByNama(Kota kota[], int jumlah, string nama) {
    for (int i = 0; i < jumlah; i++) {
        Kota *p = &kota[i];
        if (p->namaKota != NULL && strcmp(p->namaKota, nama) == 0) {
            hapusKota(p);
            printf("Kota '%s' telah dihapus.\n", nama);
            return;
        }
    }
    printf("Kota '%s' tidak ditemukan.\n", nama);
}
