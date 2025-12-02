// assignment_fixed.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define SQR(x) ((x) * (x))
static inline float squaref(float x) { return x * x; }
int gcd(int a, int b);
int uocSoChung(int a, int b);
int boiSoChung(int a, int b);
void rutGon(int* tu, int* mau);
void xepHocLuc(struct SinhVien* sv);
void clearBuffer(void);
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
int uocSoChung(int a, int b)
{
    if (b == 0) return abs(a);
    return uocSoChung(b, a % b);
}
int boiSoChung(int a, int b)
{
    int g = gcd(a, b);
    if (g == 0) return 0;
    return (a / g) * b; // avoid overflow a*b/g
}
void rutGon(int* tu, int* mau)
{
    if (*mau == 0) return;
    int g = gcd(abs(*tu), abs(*mau));
    if (g != 0) {
        *tu /= g;
        *mau /= g;
    }
}
struct SinhVien {
    char hoTen[100];
    float diem;
    char hocLuc[30];
};
void xepHocLuc(struct SinhVien* sv) {
    if (sv->diem >= 9.0f)
        strcpy(sv->hocLuc, "Xuat sac");
    else if (sv->diem >= 8.0f)
        strcpy(sv->hocLuc, "Gioi");
    else if (sv->diem >= 6.5f)
        strcpy(sv->hocLuc, "Kha");
    else if (sv->diem >= 5.0f)
        strcpy(sv->hocLuc, "Trung binh");
    else
        strcpy(sv->hocLuc, "Yeu");
}
void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}


void kiemTraSoNguyenTo()
{
    int x;
    printf("Nhap so nguyen x: ");
    if (scanf("%d", &x) != 1) { clearBuffer(); printf("Nhap khong hop le.\n"); return; }
    clearBuffer();

    printf("So %d la so nguyen.\n", x);

    int soNguyenTo = 1;
    if (x < 2) soNguyenTo = 0;
    for (int i = 2; i <= (int)sqrt((double)x); i++)
    {
        if (x % i == 0)
        {
            soNguyenTo = 0;
            break;
        }
    }
    if (soNguyenTo) printf("=> %d la so nguyen to.\n", x);
    else printf("=> %d khong phai la so nguyen to.\n", x);

    int soChinhPhuong = (int)(sqrt((double)x));
    if (soChinhPhuong * soChinhPhuong == x)
        printf("=> %d la so chinh phuong.\n", x);
    else
        printf("=> %d khong phai la so chinh phuong.\n", x);
}

void timUocVaBoiSoChung()
{
    int x, y;
    printf("Nhap x: ");
    if (scanf("%d", &x) != 1) { clearBuffer(); printf("Nhap khong hop le.\n"); return; }
    printf("Nhap y: ");
    if (scanf("%d", &y) != 1) { clearBuffer(); printf("Nhap khong hop le.\n"); return; }
    clearBuffer();

    printf("Uoc chung lon nhat cua %d va %d = %d\n", x, y, uocSoChung(x, y));
    printf("Boi chung nho nhat cua %d va %d = %d\n", x, y, boiSoChung(x, y));
}

void tinhTienKaraoke()
{
    int gioBatDau, gioKetThuc;
    printf("Nhap gio bat dau (12-22): ");
    if (scanf("%d", &gioBatDau) != 1) { clearBuffer(); printf("Nhap khong hop le.\n"); return; }
    printf("Nhap gio ket thuc (13-23): ");
    if (scanf("%d", &gioKetThuc) != 1) { clearBuffer(); printf("Nhap khong hop le.\n"); return; }
    clearBuffer();

    if (gioBatDau < 12 || gioKetThuc > 23 || gioKetThuc <= gioBatDau)
    {
        printf("Gio khong hop le!\n");
        return;
    }

    int soGio = gioKetThuc - gioBatDau;
    int giaKhoiDau = 150000;
    double tongtien = 0;

    if (soGio <= 3)
        tongtien = soGio * giaKhoiDau;
    else
        tongtien = 3 * giaKhoiDau + (soGio - 3) * giaKhoiDau * 0.7;

    if (gioBatDau >= 14 && gioBatDau <= 17)
        tongtien *= 0.9;

    printf("Tong tien Karaoke = %.0f VND\n", tongtien);
}

void tinhTienDien()
{
    int iwh;
    printf("Nhap so iWh su dung: ");
    if (scanf("%d", &iwh) != 1) { clearBuffer(); printf("Nhap khong hop le.\n"); return; }
    clearBuffer();

    long long tienDien = 0;
    if (iwh <= 50) tienDien = (long long)iwh * 1678;
    else if (iwh <= 100) tienDien = 50LL * 1678 + (long long)(iwh - 50) * 1734;
    else if (iwh <= 200) tienDien = 50LL * 1678 + 50LL * 1734 + (long long)(iwh - 100) * 2014;
    else if (iwh <= 300) tienDien = 50LL * 1678 + 50LL * 1734 + 100LL * 2014 + (long long)(iwh - 200) * 2536;
    else if (iwh <= 400) tienDien = 50LL * 1678 + 50LL * 1734 + 100LL * 2014 + 100LL * 2536 + (long long)(iwh - 300) * 2834;
    else tienDien = 50LL * 1678 + 50LL * 1734 + 100LL * 2014 + 100LL * 2536 + 100LL * 2834 + (long long)(iwh - 400) * 2927;

    printf("Tien dien = %lld VND\n", tienDien);
}

void doiTien()
{
    int menhGia[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
    int soTien;

    printf("Nhap so tien can doi: ");
    if (scanf("%d", &soTien) != 1) { clearBuffer(); printf("Nhap khong hop le.\n"); return; }
    clearBuffer();

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
    if (scanf("%lf", &tienVay) != 1) { clearBuffer(); printf("Nhap khong hop le.\n"); return; }
    clearBuffer();

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
    double giaXe = 500000000.0;
    double soTienVay, traTruoc;
    double r, monthlyPay;
    int months = 24 * 12;

    printf("Nhap %% so tien muon vay: ");
    if (scanf("%lf", &phanTramVay) != 1) { clearBuffer(); printf("Nhap khong hop le.\n"); return; }
    clearBuffer();

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
    printf("Nhap so luong sinh vien: ");
    if (scanf("%d", &n) != 1) { clearBuffer(); printf("Nhap khong hop le.\n"); return; }
    clearBuffer();

    if (n <= 0) {
        printf("So luong khong hop le!\n");
        return;
    }

    struct SinhVien* ds = malloc(n * sizeof(struct SinhVien));
    if (!ds) {
        printf("Khong the cap phat bo nho!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\nNhap ten sinh vien %d: ", i + 1);
        if (fgets(ds[i].hoTen, (int)sizeof(ds[i].hoTen), stdin) == NULL) {
            printf("Loi khi doc ten. Dung chuong trinh.\n");
            free(ds);
            return;
        }
        ds[i].hoTen[strcspn(ds[i].hoTen, "\n")] = 0;

        printf("Nhap diem: ");
        if (scanf("%f", &ds[i].diem) != 1) { clearBuffer(); printf("Nhap khong hop le.\n"); free(ds); return; }
        clearBuffer();

        xepHocLuc(&ds[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].diem < ds[j].diem) {
                struct SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    printf("\nDanh sach sinh vien\n");
    for (int i = 0; i < n; i++) {
        printf("\nTen: %s\n", ds[i].hoTen);
        printf("Diem: %.2f\n", ds[i].diem);
        printf("Hoc luc: %s\n", ds[i].hocLuc);
    }

    free(ds);
}

void fpolyLott()
{
    int a, b;
    int r1, r2;
    int trung = 0;

    printf("Nhap 2 so (1 - 15): ");
    if (scanf("%d %d", &a, &b) != 2) { clearBuffer(); printf("Nhap khong hop le.\n"); return; }
    clearBuffer();

    srand((unsigned)time(NULL));
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
    if (scanf("%d %d", &tu1, &mau1) != 2) { clearBuffer(); printf("Nhap khong hop le.\n"); return; }

    printf("Nhap phan so 2 (tu mau): ");
    if (scanf("%d %d", &tu2, &mau2) != 2) { clearBuffer(); printf("Nhap khong hop le.\n"); return; }
    clearBuffer();

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
        printf("\nMENU\n");
        printf("1. Kiem tra so nguyen to\n");
        printf("2. Tim Uoc va Boi chung nho nhat\n");
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
