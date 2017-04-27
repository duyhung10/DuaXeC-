#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include "thuvien.h"

using namespace std ;

#define ChDaiDuongDua	20
#define ChRongDuongDua	20


struct ToaDo{
	int x, y;
};


struct HinhDang{
	char mang[3][3];
};


struct Xe{
	ToaDo ViTri;
	HinhDang hd;
};


struct VatCan{
	ToaDo ViTri;
	HinhDang hd;
};


void KhoiTao (Xe &xe, VatCan &Vatcan){

	// Tạo Xe

	xe.ViTri.y = ChDaiDuongDua - 2;
	xe.ViTri.x = ChRongDuongDua / 2;

	xe.hd.mang[0][0] = xe.hd.mang[0][2] = xe.hd.mang[2][0] = xe.hd.mang[2][2] = 'o';	// bánh xe
	xe.hd.mang[0][1] = '^';                                                         	// đầu xe
	xe.hd.mang[1][0] = xe.hd.mang[1][2] = '|';	                                        // thân xe
	xe.hd.mang[2][1] = '-';                                                             // đuôi xe
	xe.hd.mang[1][1] = '*';                                                             // điểm giữa xe - điểm lấy tọa độ xe. **

	// Tạo vật cản

	Vatcan.ViTri.x = 2 + rand() % (ChRongDuongDua-2 -2 +1);
	Vatcan.ViTri.y = -2;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			Vatcan.hd.mang[i][j] = '*';
}


void HienThiXe (Xe xe){
	for (int k = -1; k <= 1; k++){
		for (int j = -1; j <= 1; j++){
			int x = j + xe.ViTri.x;
			int y = k + xe.ViTri.y;

			gotoXY (x, y);
			cout<< xe.hd.mang[k+1][j+1] ;
		}
	}
}


void DieuKhien (Xe &xe){
	if (kbhit()){
		int key = getch();

		if ((key == 'A' || key == 'a') && xe.ViTri.x > 2)
			xe.ViTri.x--;
		else if ((key == 'D' || key == 'd') && xe.ViTri.x < ChRongDuongDua - 2)
			xe.ViTri.x++;
        else if ((key == 'W' || key == 'w') && xe.ViTri.y >1 )
            xe.ViTri.y--;
        else if ((key == 'S' || key == 's') && xe.ViTri.y < ChDaiDuongDua - 2)
            xe.ViTri.y++;
	}
}


void HienThiVatCan(VatCan &Vatcan){

    for (int k = -1; k <= 1; k++)
		for (int j = -1; j <= 1; j++){
			int x = j + Vatcan.ViTri.x;
			int y = k + Vatcan.ViTri.y;

			if (y >= 0 && y < ChDaiDuongDua)
			{
				gotoXY (x, y);
				cout<< Vatcan.hd.mang[k+1][j+1];
			}
    }

	Vatcan.ViTri.y++;  // Vật cản đi xuống dưới

	if (Vatcan.ViTri.y > ChDaiDuongDua){
		Vatcan.ViTri.x = 2 + rand() % (ChRongDuongDua -2 -2 +1);
		Vatcan.ViTri.y = -2;
	}
}


int main()
{
	srand (time (NULL));

	Xe xe;
	VatCan Vatcan;

	KhoiTao (xe, Vatcan);

    int diem = 0;
	while (1)
	{
	    clrscr();
        // Vẽ đường đua
        for (int i = 0; i < ChDaiDuongDua; i++)
            cout<< '|' << endl ;

        for (int i = 0; i < ChDaiDuongDua; i++){
            gotoXY (ChRongDuongDua, i);
            cout<< '|' << endl ;
        }

        gotoXY (0, ChRongDuongDua);
        for (int i = 0; i < ChRongDuongDua+1; i++)
            cout<< '-' ;


		HienThiXe(xe);

		HienThiVatCan(Vatcan);

		DieuKhien (xe);
        // Tăng Điểm + Xử Lí Va Chạm
        gotoXY(30, 5);
        cout<< "Diem = " << diem;

		Sleep (200);

	}


	return 0;
}
