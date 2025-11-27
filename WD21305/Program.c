#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
	printf("Lab 6 Bai 1\n");
    printf("Nhap so luong phan tu cua mang: ");
    if (scanf_s("%d", &n) != 1) {
        printf("Nhap khong hop le.\n");
        return 1;
    }

    int* mang = (int*)malloc(n * sizeof(int));

    if (mang == NULL) {
        printf("Khong du bo nho.\n");
        return 1;
    }

    int i;

    for (i = 0; i < n; i++) {
        printf("Nhap mang[%d]: ", i);
        if (scanf_s("%d", &mang[i]) != 1) {
            printf("Nhap khong hop le.\n");
            free(mang);
            return 1;
        }
    }

    float tong = 0;
    int soLuong = 0;

    for (i = 0; i < n; i++) {
        if (mang[i] % 3 == 0) {
            tong += mang[i];
            soLuong++;
        }
    }

    if (soLuong == 0) {
        printf("Khong co phan tu nao chia het cho 3 trong mang.\n");
    }
    else {
        float trungBinh = tong / soLuong;
        printf("Trung binh cac so chia het cho 3 la: %.2f\n", trungBinh);
    }

    free(mang);

    return 0;
}