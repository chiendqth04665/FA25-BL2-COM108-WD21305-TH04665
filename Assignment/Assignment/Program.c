#include <stdio.h>
#include <math.h>
#define SQR(x) ((x) * (x))
static inline float squaref(float x) { return x * x; }
int uocSoChung(int a, int b)
{
	if (b == 0) return a;
	return uocSoChung(b, a % b);
}
int boiSoChung(int a, int b)
{
	return (a * b) / boiSoChung(a, b);
}
struct SinhVien {
	char hoTen[50];
	float diem;
	char hocLuc[20];
};
int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
void rutGon(int* tu, int* mau)
{
	int g = gcd(abs(*tu), abs(*mau));
	*tu /= g;
	*mau /= g;
}
void xepLoai(float diem, char* hocluc)
{
	if (diem >= 9.0) strcpy(hocluc, "Xuat sac");
	else if (diem >= 8.0) strcpy(hocluc, "Gioi");
	else if (diem >= 6.5) strcpy(hocluc, "Kha");
	else if (diem >= 5.0) strcpy(hocluc, "Trung binh");
	else strcpy(hocluc, "Yeu");
}


void kiemTraSoNguyenTo()
{
	int x;
	printf("Nhap so nguyen x: ");
	scanf("%d", &x);

	printf("So %d la so nguyen.\n", x);

	int soNguyenTo = 1;
	if (x < 2) soNguyenTo = 0;
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
		{
			soNguyenTo = 0;
			break;
		}
	}
	if (soNguyenTo) printf("=> %d la so nguyen to.\n", x);
	else printf("=> %d khong phai la so nguyen to.\n", x);

	int soChinhPhuong = sqrt(x);
	if (soChinhPhuong * soChinhPhuong == x)
		printf("=> %d la so chinh phuong.\n", x);
	else
		printf("=> %d khong phai la so chinh phuong.\n", x);
}
void timUocVaBoiSoChung()
{
	int x, y;
	printf("Nhap x: ");
	scanf("%d", &x);
	printf("Nhap y: ");
	scanf("%d", &y);

	printf("Uoc chung lon nhat cua %d va %d = %d\n", x, y, uocSoChung(x, y));
	printf("Boi chung nho nhat cua %d va %d = %d\n", x, y, boiSoChung(x, y));
}
void tinhTienKaraoke()
{
	int gioBatDau, gioKetThuc;
	printf("Nhap gio bat dau (12-22): ");
	scanf("%d", &gioBatDau);
	printf("Nhap gio iet thuc (13-23): ");
	scanf("%d", &gioKetThuc);

	if (gioBatDau < 12 || gioKetThuc > 23 || gioKetThuc <= gioBatDau)
	{
		printf("Gio khong hop le!\n");
		return;
	}

	int soGio = gioKetThuc - gioBatDau;
	int giaKhoiDau = 150000;
	float tongtienDien = 0;

	if (soGio <= 3)
		tongtienDien = soGio * giaKhoiDau;
	else
		tongtienDien = 3 * giaKhoiDau + (soGio - 3) * giaKhoiDau * 0.7;

	if (gioBatDau >= 14 && gioBatDau <= 17)
		tongtienDien *= 0.9;

	printf("Tong tien Karaoke = %.0f VND\n", tongtienDien);
}
void tinhTienDien()
{
	int iwh, tienDien = 0;
	printf("Nhap so iWh su dung: ");
	scanf("%d", &iwh);

	if (iwh <= 50) tienDien = iwh * 1678;
	else if (iwh <= 100) tienDien = 50 * 1678 + (iwh - 50) * 1734;
	else if (iwh <= 200) tienDien = 50 * 1678 + 50 * 1734 + (iwh - 100) * 2014;
	else if (iwh <= 300) tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (iwh - 200) * 2536;
	else if (iwh <= 400) tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (iwh - 300) * 2834;
	else tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (iwh - 400) * 2927;

	printf("Tien dien = %d VND\n", tienDien);
}
void doiTien()
{
	int menhGia[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
	int soTien;

	printf("Nhap so tien can doi: ");
	scanf("%d", &soTien);

	for (int i = 0; i < 9; i++)
	{
		int soToTien = soTien / menhGia[i];
		if (soToTien > 0)
			printf("%d doi sang %d\n", soToTien, menhGia[i]);
		soTien %= menhGia[i];
	}
}
void tinhLaiVayTraGop()
{
	double tienVay;
	double laiSuat = 0.05;
	double gocPhaiTra, laiPhaiTra, soTienPhaiTra, soTienConLai;

	printf("Nhap so tien muon vay: ");
	scanf("%lf", &tienVay);

	gocPhaiTra = tienVay / 12;
	soTienConLai = tienVay;

	printf("\nHan tra tien\tLai phai tra\tGoc phai tra\tSo tien phai tra\tSo tien con lai\n");

	for (int i = 1; i <= 12; i++)
	{
		laiPhaiTra = soTienConLai * laiSuat;
		soTienPhaiTra = laiPhaiTra + gocPhaiTra;

		soTienConLai -= gocPhaiTra;
		if (soTienConLai < 0) soTienConLai = 0;

		printf("%d\t%.0f\t\t%.0f\t\t%.0f\t\t\t%.0f\n",
			i, laiPhaiTra, gocPhaiTra, soTienPhaiTra, soTienConLai);
	}
}
void vayTienMuaXe()
{
	double phanTramVay;
	double giaXe = 500000000;
	double soTienVay, traTruoc;
	double r, monthlyPay;
	int months = 24 * 12;

	printf("Nhap %% so tien muon vay: ");
	scanf("%lf", &phanTramVay);

	soTienVay = giaXe * (phanTramVay / 100.0);
	traTruoc = giaXe - soTienVay;

	r = 0.072 / 12.0;

	monthlyPay = soTienVay * r * pow(1 + r, months) / (pow(1 + r, months) - 1);

	printf("\nKET QUA VAY\n");
	printf("Tien tra truoc: %.0lf VND\n", traTruoc);
	printf("So tien vay: %.0lf VND\n", soTienVay);
	printf("Tien phai tra hang thang: %.0lf VND\n", monthlyPay);
}
void sapXepSinhVien()
{
	int n;
	printf("Nhap so sinh vien: ");
	scanf("%d", &n);

	struct SinhVien sv[100];

	for (int i = 0; i < n; i++)
	{
		fflush(stdin);
		printf("Nhap ho ten: ");
		gets(sv[i].hoTen);

		printf("Nhap diem: ");
		scanf("%f", &sv[i].diem);

		xepLoai(sv[i].diem, sv[i].hocLuc);
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (sv[i].diem < sv[j].diem)
			{
				struct SinhVien temp = sv[i];
				sv[i] = sv[j];
				sv[j] = temp;
			}
		}
	}

	printf("\nDANH SACH SINH VIEN\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d. %s - %.2f - %s\n", i + 1, sv[i].hoTen, sv[i].diem, sv[i].hocLuc);
	}
}
void fpolyLott()
{
	int a, b;
	int r1, r2;
	int trung = 0;

	printf("Nhap 2 so (1 - 15): ");
	scanf("%d %d", &a, &b);

	srand(time(NULL));
	r1 = rand() % 15 + 1;
	r2 = rand() % 15 + 1;

	printf("So cua ban: %d %d\n", a, b);
	printf("So he thong: %d %d\n", r1, r2);

	if (a == r1 || a == r2) trung++;
	if (b == r1 || b == r2) trung++;

	if (trung == 0) printf("Chuc ban may man lan sau!\n");
	else if (trung == 1) printf("Ban trung giai Nhi!\n");
	else printf("Ban trung giai Nhat!\n");
}
void tinhPhanSo()
{
	int tu1, mau1, tu2, mau2;

	printf("Nhap phan so 1 (tu mau): ");
	scanf("%d %d", &tu1, &mau1);

	printf("Nhap phan so 2 (tu mau): ");
	scanf("%d %d", &tu2, &mau2);

	int t, m;

	t = tu1 * mau2 + tu2 * mau1;
	m = mau1 * mau2;
	rutGon(&t, &m);
	printf("Tong = %d/%d\n", t, m);

	t = tu1 * mau2 - tu2 * mau1;
	m = mau1 * mau2;
	rutGon(&t, &m);
	printf("Hieu = %d/%d\n", t, m);

	t = tu1 * tu2;
	m = mau1 * mau2;
	rutGon(&t, &m);
	printf("Tich = %d/%d\n", t, m);

	t = tu1 * mau2;
	m = mau1 * tu2;
	rutGon(&t, &m);
	printf("Thuong = %d/%d\n", t, m);
}

int main()
{
	int chon;

	do
	{
		printf("MENU\n");
		printf("1. Kiem tra so nguyen to\n");
		printf("2. Tim UCLN - BCNN\n");
		printf("3. Tinh tien Karaoke\n");
		printf("4. Tinh tien dien\n");
		printf("5. Doi tien\n");
		printf("6. Tinh lai vay tra gop\n");
		printf("7. Vay tien mua xe\n");
		printf("8. Sap xep sinh vien\n");
		printf("9. Mini game FPOLY LOTT\n");
		printf("10. Tinh phan so\n");
		printf("0. Thoat\n");

		printf("Chon chuc nang: ");
		scanf("%d", &chon);

		if (chon >= 1 || chon <= 10)
		{
			int lap = 1;
			int chucNangHienTai = chon;

			while (lap == 1)
			{
				switch (chucNangHienTai)
				{
				case 1: kiemTraSoNguyenTo(); break;
				case 2: timUocVaBoiSoChung(); break;
				case 3: tinhTienKaraoke(); break;
				case 4: tinhTienDien(); break;
				case 5: doiTien(); break;
				case 6: tinhLaiVayTraGop(); break;
				case 7: vayTienMuaXe(); break;
				case 8: sapXepSinhVien(); break;
				case 9: fpolyLott(); break;
				case 10: tinhPhanSo(); break;
				}

				printf("\nNhan 1 de lap lai chuc nang.\n");
				printf("Nhan phim bat ky de quay lai MENU.\n");
				printf("Nhan 0 de thoat.\n");
				scanf("%d", &lap);

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
