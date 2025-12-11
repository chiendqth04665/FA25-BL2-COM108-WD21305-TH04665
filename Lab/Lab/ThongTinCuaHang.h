#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void thongTinCuaHang() {
    int n;
    float arr[100];
    float tong = 0;
    float min;
    int dem = 0;

    printf("Nhap so luong thu cung: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap can nang thu cung %d: ", i + 1);
        scanf("%f", &arr[i]);
    }
    getchar();

    min = arr[0];

    for (int i = 0; i < n; i++) {
        tong += arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    float tb = tong / n;

    for (int i = 0; i < n; i++)
        if (arr[i] < tb)
            dem++;

    printf("\nKet qua\n");
    printf("Can nang trung binh: %.1f\n", tb);
    printf("Can nang thap nhat: %.1f\n", min);
    printf("So thu cung co can nang duoi muc TB: %d\n", dem);
}