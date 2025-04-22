#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "identityorang.h"

int main() {
    Kota kota[10]; // array statis
    int jumlahKota = 0;
    char pilihan[10];

    while (1) {
        printf("\n=== MENU ===\n");
        printf("1. Tambah kota dan orang\n");
        printf("2. Hapus kota\n");
        printf("3. Tampilkan semua\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        fgets(pilihan, sizeof(pilihan), stdin);

        if (pilihan[0] == '1') {
            if (jumlahKota >= 10) {
                printf("Kapasitas kota penuh!\n");
                continue;
            }

            Kota *p = &kota[jumlahKota];
            char buffer[100];

            printf("Nama kota: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            p->namaKota = strdup(buffer);
            p->daftarOrang = NULL;

            int jumlahOrang;
            printf("Jumlah orang di %s: ", buffer);
            scanf("%d", &jumlahOrang);
            getchar();

            for (int i = 0; i < jumlahOrang; i++) {
                printf("  Nama orang ke-%d: ", i + 1);
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                tambahOrang(p, buffer);
            }

            jumlahKota++;

        } else if (pilihan[0] == '2') {
            char buffer[100];
            printf("Nama kota yang ingin dihapus: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            hapusKotaByNama(kota, jumlahKota, buffer);

        } else if (pilihan[0] == '3') {
            tampilkanKota(kota, jumlahKota);

        } else if (pilihan[0] == '4') {
            break;

        } else {
            printf("Pilihan tidak valid.\n");
        }
    }

    // Bersihkan memori
    for (int i = 0; i < jumlahKota; i++) {
        if (kota[i].namaKota != NULL) {
            hapusKota(&kota[i]);
        }
    }
}