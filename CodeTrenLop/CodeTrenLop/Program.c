#include <stdio.h>

void kiemTraSoNguyen()
{
	printf("Kiem Tra So Nguyen");
	printf("\n");
}

void sapXepPhanTuMang()
{
	int integerArray[100] = {0};
	int tmp; //temperary
	int length;
	printf("Nhap so kich thuoc mang: ");
	scanf("%d", &length);
	printf("Nhap du lieu cho mang %d phan tu\n", length);
	//int length = sizeof(mangSoNguyen) / sizeof(int);
	for (int i = 0; i < length; i++)
	{
		printf("mang[%d] = ", i);
		scanf("%d", &integerArray[i]);
	}
	printf("Sap xep tang dan du lieu trong mang %d phan tu\n", length);
	for (int i = 0; i < length - 1; i++)
	{
		if (integerArray[i] > integerArray[i + 1])
		{
			tmp = integerArray[i];
			integerArray[i] = integerArray[i + 1];
			integerArray[i + 1] = tmp;
			i = -1;
		}
	}
	printf("Xuat du lieu trong mang %d phan tu\n", length);
	for (int i = 0; i < length; i++)
	{
		printf("mang[%d] = %d\n", i, integerArray[i]);
	}
}

void demoMang2Chieu()
{
	int array[2][3];
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 2;i++)
		{
			printf("mang [%d][%d] ", i, j);
			scanf("%d", &array[i][j]);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}

void lapChucNang(int chonChucNang)
{
	int tiepTuc = 1;
	while (tiepTuc == 1)
	{
		switch (chonChucNang)
		{
		case 1:
			kiemTraSoNguyen();
			break;
		case 2:
			sapXepPhanTuMang();
			break;
		case 3:
			demoMang2Chieu();
			break;
		default:
			printf("Chon sai. Chuc nang hop le [0-3]");
			break;
		}

		printf("Tiep tuc thuc hien chuc nang nay? [1=Co | 0=Khong]: ");
		scanf("%d", &tiepTuc);
		system("cls");
	}

}

int main()
{
	int chonChucNang;
	do
	{
		printf("Menu");
		printf("\n");
		printf("1. Kiem Tra So Nguyen");
		printf("\n");
		printf("2. Sap xep phan tu mang 1 chieu");
		printf("\n");
		printf("3. Demo mang 2 chieu");
		printf("\n");
		printf("0. Thoat");
		printf("\n");
		printf("Hay chon chuc nang [0-3]: ");
		scanf("%d", &chonChucNang);
		lapChucNang(chonChucNang);
	} while (chonChucNang != 0);
}


// GV: AnhTT184