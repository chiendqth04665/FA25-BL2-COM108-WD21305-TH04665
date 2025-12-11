#define _CRT_SECURE_NO_WARNINGS
#define N_BAN 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ThongTinThuCung.h"
#include "TinhTong.h"
#include "ThongTinCuaHang.h"

void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main()
{
    int chon;

    do
    {
        printf("\n----------------MENU----------------\n");
        printf("        1. Thong tin Thu cung\n");
        printf("        2. Tinh Tong\n");
        printf("        3. Thong tin cua hang\n");
        printf("        0. Thoat\n");
        printf("--------------------------------------\n");

        printf("Chon chuc nang: ");
        if (scanf("%d", &chon) != 1) { clearBuffer(); printf("Nhap khong hop le.\n"); continue; }
        clearBuffer();

        if (chon >= 1 && chon <= 10)
        {
            int lap = 1;
            int chucNangHienTai = chon;

            while (lap == 1)
            {
                switch (chucNangHienTai)
                {
                case 1:
                    thongTinThuCung(); break;
                case 2:
                    tinhTong(); break;
                case 3:
                    thongTinCuaHang(); break;
                }

                printf("\nNhan 1 de lap lai chuc nang.\n");
                printf("Nhan phim bat ky de quay lai MENU.\n");
                printf("Nhan 0 de thoat.\n");
                if (scanf("%d", &lap) != 1) { clearBuffer(); lap = 0; }
                clearBuffer();

                if (lap == 0)
                {
                    chon = 0;
                    break;
                }
            }
        }
        else if (chon != 0)
        {
            printf("Chuc nang khong hop le! Quay lai MENU...\n");
        }

    } while (chon != 0);
    return 0;
}