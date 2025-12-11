#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tinhTong() {
    int n, tong = 0;

    do {
        printf("Nhap so nguyen duong n (n > 3): ");
        scanf("%d", &n);
    } while (n <= 3);

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) tong += i;
    }

    printf("Tong cac so le tu 1 den %d: %d\n", n, tong);

    if (n % 5 == 0)
        printf("So %d chia het cho 5\n", n);
    else
        printf("So %d Khong chia het cho 5\n", n);

    getchar();
}
