#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

using namespace std ;

#define chieudaiConsole 80
#define chieucaoConsole 25
#define chieudaiDuongDua 25


struct ToaDo{
    int y, x;
};

struct HinhDang{
    char a[3][3];
};

struct Xe{
    ToaDo td;
    HinhDang hd;
    int diem;
};

struct VatCan{
    ToaDo td;
    HinhDang hd;
};

void KhoiTaoXe (Xe &xe){
	xe.td.y = chieucaoConsole - 2;
	xe.td.x = chieudaiDuongDua / 2;

	xe.hd.a[0][0] = xe.hd.a[0][2] = xe.hd.a[2][0] = xe.hd.a[2][2] = 'o';	// vẽ 4 bánh xe
	xe.hd.a[0][1] = '^';	                                                // đầu xe
	xe.hd.a[1][0] = xe.hd.a[1][2] = '|';                                	// thân xe
	xe.hd.a[2][1] = '_';                                                    // đuôi xe
	xe.hd.a[1][1] = 'x';                                                    // điểm lấy tọa độ của xe

    xe.diem = 0;
}

void KhoiTaoVatCan (VatCan &vc){

	vc.td.x = 2 + rand() % (chieudaiDuongDua -3-2+1);
	vc.td.y = -2;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			vc.hd.a[i][j] = '*' ;
}


void HienThi (Xe xe, VatCan vc)
{
	clrscr();

	// Vẽ đường biên
	for (int i = 0; i < chieucaoConsole; i++)
		cout << "|";

	for (int i = 0; i < chieudaiConsole; i++)
	{
		gotoXY (chieudaiDuongDua, i);
		cout << "|";
	}


	// Hiển thị xe
	for (int kDong = -1; kDong <= 1; kDong++)
		for (int kCot = -1; kCot <= 1; kCot++)
		{
			int x = kCot + xe.td.x;
			int y = kDong + xe.td.y;

			gotoXY (x, y);
			cout<< xe.hd.a[kDong+1][kCot+1];
		}


	// Hiển thị vật cản
	for (int kDong = -1; kDong <= 1; kDong++)
		for (int kCot = -1; kCot <= 1; kCot++)
		{
			int x = kCot + vc.td.x;
			int y = kDong + vc.td.y;

			if (y >= 0 && y < chieucaoConsole)
			{
				gotoXY (x, y);
				cout<< vc.hd.a[kDong+1][kCot+1];
			}
		}


	// Thông báo điểm
	gotoXY (chieudaiDuongDua + 5, 12);
	cout<< xe.diem ;
}


void DieuKhien(){

}

void XuLiTrongGame(){

}


int main(){

	srand (time (NULL));

	while (1)
	{
		// 1. Hiển thị xe và vật cản


		// 2. Điều khiển xe


		// 3. Xử lí trong game
	}

	return 0;
}

