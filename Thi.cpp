//Mang 2 chieu - Mang vuong (bai tap mo ta chi tiet theo file Excel Mang Vuong)
//In ra duong cheo chinh va duong cheo phu cua mang vuong
//In cac phan tu tren va duoi duong cheo chinh
//In cac phan tu tren va duoi duong cheo phu
//In cac phan tu theo cau 7

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <Windows.h>

#define size 100

//Cau 1a
void NhapSoDongSoCot(int *n)
{
	do
	{
		printf("\n\nVui long nhap so dong so cot cho mang vuong: ");
		scanf("%d", &(*n));
	} while (*n <= 0 || *n > size);
}

void NhapMang(int a[][size], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 10;
		}
	}
}

void XuatMang(int a[][size], int n)
{
	printf("\nMang da nhap la: \n\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("  %d  ", a[i][j]);
		}
		printf("\n");
	}
}

//Cau 1b
int KiemTraSoNguyenTo(int n)
{
	if (n == 0)
	{
		return 0;
	}
	for (int i = 2; i < n; i++)
	{
		if (n%i == 0)
		{
			return 0; break;
		}
	}
	return 1;
}

void InSoNguyenToDuongCheoPhu(int a[][size], int n)
{
	printf("\nIn cac so nguyen to tren duong cheo phu: \n\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + j == (n - 1) && KiemTraSoNguyenTo(a[i][j]) == 1)
			{
				printf("  %d  ", a[i][j]);
			}
			else
			{
				printf("     ");
			}
		}
		printf("\n");
	}
}

//Cau 1c
void ChuyenMang2ChieuVe1Chieu(int a[][size], int n, int b[], int *k)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[*k] = a[i][j];
			*k = *k + 1;
		}
	}
}

void SapXepGiamDan(int b[], int k)
{
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (b[i] < b[j])
			{
				int tam = b[i];
				b[i] = b[j];
				b[j] = tam;
			}
		}
	}
}

void InPhanTuLonThuHai(int b[], int k)
{
	for (int i = 0; i < k; i++)
	{
		if (b[i] != b[i + 1])
		{
			printf("\nPhan tu lon thu 2 trong mang vuong la: %d", b[i + 1]); break;
		}
	}
}

//Cau 1d
void XuatCacPhanTuBienVaTinhTong(int a[][size], int n)
{
	int s = 0;
	printf("\nMang da nhap la: \n\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
			{
				printf("  %d  ", a[i][j]);
				s += a[i][j];
			}
			else
			{
				printf("     ");
			}
		}
		printf("\n");
	}
	printf("\n\nTong cac phan tu nam tren bien: Tong = %d", s);
}

//Cau 2a
struct NhanVien
{
	int MaNhanVien;
	char TenNhanVien[50];
	int NamSinh;
	int GioiTinh;
	float Luong;
};

void NhapThongTin_NV(NhanVien &a)
{
	printf("\nNHAP THONG TIN\n");
	printf("\nVui long nhap Ma Nhan vien: "); scanf("%d", &a.MaNhanVien);
	printf("\nVui long nhap Ten Nhan vien: "); fflush(stdin); gets(a.TenNhanVien);
	do
	{
		printf("\nVui long nhap Nam sinh: "); scanf("%d", &a.NamSinh);
	} while (a.NamSinh < 1950);

	do
	{
		printf("\nVui long nhap Gioi tinh: "); scanf("%d", &a.GioiTinh);
	} while (a.GioiTinh != 0 && a.GioiTinh != 1);

	do
	{
		printf("\nVui long nhap Luong: "); scanf("%f", &a.Luong);
	} while (a.Luong < 0);
	system("cls");
}

void XuatThongTin_NV(NhanVien &a)
{
	printf("\n\nMa Nhan Vien: %d", a.MaNhanVien);
	printf("\nTen Nhan Vien: %s", a.TenNhanVien);
	printf("\nNam Sinh: %d", a.NamSinh);
	if (a.GioiTinh == 1) 
	{
		printf("\nGioi Tinh: %s", "Nam");
	}
	else
	{
		printf("\nGioi Tinh: %s", "Nu");
	}
	
	printf("\nLuong: %.0f", a.Luong);
}

void NhapSoLuong_NV(int &n)
{
	printf("\nVui long nhap so luong nhan vien: "); scanf("%d", &n);
	system("cls");
}

void NhapMang_NV(NhanVien a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		NhapThongTin_NV(a[i]);
	}
}

void XuatMang_NV(NhanVien a[], int n)
{
	printf("\nXUAT THONG TIN\n");
	for (int i = 0; i < n; i++)
	{
		XuatThongTin_NV(a[i]);
	}
}

//Cau 2b
void InDanhSach_TuoiTren25(NhanVien a[], int n)
{
	printf("\n========================================");
	printf("\nDANH SACH NHAN VIEN TREN 25 TUOI");
	for (int i = 0; i < n; i++)
	{
		if (2018 - a[i].NamSinh > 25)
		{
			XuatThongTin_NV(a[i]);
		}
	}
}

//Cau 2c
void InDanhSach_Nam_LuongTren10(NhanVien a[], int n)
{
	printf("\n========================================");
	printf("\nDANH SACH NHAN VIEN NAM VA CO LUONG TREN 10\n");
	for (int i = 0; i < n; i++)
	{
		if (a[i].GioiTinh == 1 && a[i].Luong > 10)
		{
			XuatThongTin_NV(a[i]);
		}
	}
}

//Cau 2d
void SapXep_DanhSachNV_GiamDan(NhanVien a[], int n)
{
	NhanVien tam;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].Luong < a[j].Luong)
			{
				tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
		}
	}
}

void Menu(int &x)
{
	printf("\n==========================DE KIEM TRA CUOI KY===========================\n");
	printf("\n\nCau 1a: Nhap xuat mang vuong                       - Vui long nhan 1!"); 
	printf("\n\nCau 1b: In so nguyen to tren Duong cheo phu        - Vui long nhan 2!"); 
	printf("\n\nCau 1c: In chu so lon thu 2 trong mang             - Vui long nhan 3!"); 
	printf("\n\nCau 1d: In phan tu bien va tinh tong               - Vui long nhan 4!"); 
	printf("\n\nCau 2a: Nhap xuat mang Nhan vien                   - Vui long nhan 5!"); 
	printf("\n\nCau 2b: In Danh sach nhan vien tren 25 tuoi        - Vui long nhan 6!"); 
	printf("\n\nCau 2c: In Nhan vien nam va luong tren 10          - Vui long nhan 7!"); 
	printf("\n\nCau 2d: In Danh sach nhan vien co luong giam dan   - Vui long nhan 8!"); 
	printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n\n => Vui long nhap so: ");
	scanf("%d", &x);
}

void main()
{
abc:
	int x = 0;
	Menu(x);

	int a[size][size], n;
	srand((int)time(NULL));

	system("cls");
	switch (x)
	{
	case 1:
	{
		// Cau 1a
		NhapSoDongSoCot(&n);
		NhapMang(a, n);
		XuatMang(a, n);
		_getch();
		break;
	}
	case 2 :
	{
		// Cau 1b
		NhapSoDongSoCot(&n);
		NhapMang(a, n);
		XuatMang(a, n);
		InSoNguyenToDuongCheoPhu(a, n);
		_getch();
		break;
	}
	case 3 :
	{
		//Cau 1c
		int b[size];
		int k = 0;
		NhapSoDongSoCot(&n);
		NhapMang(a, n);
		XuatMang(a, n);
		ChuyenMang2ChieuVe1Chieu(a, n, b, &k);
		SapXepGiamDan(b, k);
		InPhanTuLonThuHai(b, k);
		_getch();
		break;
	}
	case 4:
	{
		//Cau 1d
		NhapSoDongSoCot(&n);
		NhapMang(a, n);
		XuatMang(a, n);
		XuatCacPhanTuBienVaTinhTong(a, n);
		_getch();
		break;
	}
	case 5:
	{
		//Cau 2a
		NhanVien nv[size];
		int m;
		NhapSoLuong_NV(m);
		NhapMang_NV(nv, m);
		XuatMang_NV(nv, m);
		_getch();
		break;
	}
	case 6:
	{
		//Cau 2b
		printf("\nDANH SACH NHAN VIEN MAU\n");
		NhanVien c[3] =
		{
			{ 1, "Anh A", 1992, 1, 11 },
			{ 2, "Chi B", 1991, 0, 12 },
			{ 3, "Chi C", 1999, 0, 8 },
		};
		XuatMang_NV(c, 3);
		InDanhSach_TuoiTren25(c, 3);
		_getch();
		break;
	}
	case 7:
	{
		//Cau 2c
		printf("\nDANH SACH NHAN VIEN MAU\n");
		NhanVien c[3] =
		{
			{ 1, "Anh A", 1992, 1, 11 },
			{ 2, "Chi B", 1991, 0, 12 },
			{ 3, "Chi C", 1999, 0, 8 },
		};
		XuatMang_NV(c, 3);
		InDanhSach_Nam_LuongTren10(c, 3);
		_getch();
		break;
	}
	case 8:
	{
		//Cau 2d
		printf("\nDANH SACH NHAN VIEN MAU\n");
		NhanVien c[3] =
		{
			{ 1, "Anh A", 1992, 1, 11 },
			{ 2, "Chi B", 1991, 0, 12 },
			{ 3, "Chi C", 1999, 0, 8 },
		};
		XuatMang_NV(c, 3);
		SapXep_DanhSachNV_GiamDan(c, 3);
		printf("\n========================================");
		printf("\nDANH SACH NHAN VIEN CO LUONG GIAM DAN\n");
		XuatMang_NV(c, 3);
		_getch();
		break;
	}
	default:
		printf("\nDU LIEU NHAP KHONG HOP LE\n"); 
		break;
	}
	system("cls");
	goto abc;
}
