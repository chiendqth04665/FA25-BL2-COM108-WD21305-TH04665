#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void thongTinThuCung() {
    char ma[20], ten[50];
    int namSinh;

    printf("Nhap ma thu cung: ");
    fgets(ma, sizeof(ma), stdin);
    ma[strcspn(ma, "\n")] = 0;

    printf("Nhap ten thu cung: ");
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = 0;

    printf("Nhap nam sinh: ");
    scanf("%d", &namSinh);
    getchar();

    printf("\nThong tin thu cung\n");
    printf("Ma: %s\n", ma);
    printf("Ten: %s\n", ten);
    printf("Nam sinh: %d\n", namSinh);
    printf("Tuoi: %d\n", 2025 - namSinh);
}