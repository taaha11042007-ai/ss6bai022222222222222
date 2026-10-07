#include <stdio.h>
#include <string.h>

int main() {
    const int MAX = 100;

    char maPhieu[100][15];
    char tenSach[100][50];
    int soNgayMuon[100];
    int tienPhat[100];

    int soLuong = 0;
    int luaChon;

    do {
        printf("\n================ HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ================\n");
        printf("1. Them luot muon sach moi\n");
        printf("2. Hien thi danh sach muon sach\n");
        printf("3. Cap nhat so ngay muon theo Ma phieu\n");
        printf("4. Xoa luot muon sach theo Ma phieu\n");
        printf("5. Thong ke danh sach phieu muon bi phat\n");
        printf("6. Thoat chuong trinh\n");
        printf("==============================================================================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        while (getchar() != '\n');

        switch (luaChon) {
            case 1: {
                if (soLuong >= MAX) {
                    printf("He thong day, khong the them phieu muon moi!\n");
                    break;
                }

                char maNhap[15];
                int trungMa;
                int ngay;

                do {
                    trungMa = 0;

                    printf("\n=== THEM LUOT MUON SACH MOI ===\n");
                    printf("Nhap ma phieu muon: ");
                    scanf("%14s", maNhap);
                    while (getchar() != '\n');

                    for (int i = 0; i < soLuong; i++) {
                        if (strcmp(maPhieu[i], maNhap) == 0) {
                            trungMa = 1;
                            break;
                        }
                    }

                    if (trungMa) {
                        printf("Ma phieu da ton tai! Vui long nhap ma khac.\n");
                    }

                } while (trungMa);

                strcpy(maPhieu[soLuong], maNhap);

                printf("Nhap ten sach: ");
                fgets(tenSach[soLuong], 50, stdin);

                if (tenSach[soLuong][strlen(tenSach[soLuong]) - 1] == '\n') {
                    tenSach[soLuong][strlen(tenSach[soLuong]) - 1] = '\0';
                }

                do {
                    printf("Nhap so ngay muon thuc te: ");
                    scanf("%d", &ngay);
                    while (getchar() != '\n');

                    if (ngay <= 0) {
                        printf("So ngay muon phai lon hon 0. Vui long nhap lai!\n");
                    }

                } while (ngay <= 0);

                soNgayMuon[soLuong] = ngay;

                if (soNgayMuon[soLuong] > 14) {
                    tienPhat[soLuong] =
                        (soNgayMuon[soLuong] - 14) * 5000;
                } else {
                    tienPhat[soLuong] = 0;
                }

                printf("--> Tien phat tu dong tinh: %d VND\n",
                       tienPhat[soLuong]);

                soLuong++;

                printf("--> Them luot muon sach thanh cong!\n");

                break;
            }

            case 2: {
                if (soLuong == 0) {
                    printf("\nDanh sach muon sach hien dang rong!\n");
                    break;
                }

                int tongTienPhat = 0;

                printf("\n============================== DANH SACH MUON SACH ==============================\n");
                printf("%-5s | %-10s | %-35s | %-10s | %-15s\n",
                       "STT",
                       "Ma Phieu",
                       "Ten Sach",
                       "So Ngay",
                       "Tien Phat (VND)");
                printf("---------------------------------------------------------------------------------\n");

                for (int i = 0; i < soLuong; i++) {
                    printf("%-5d | %-10s | %-35s | %-10d | %-15d\n",
                           i + 1,
                           maPhieu[i],
                           tenSach[i],
                           soNgayMuon[i],
                           tienPhat[i]);

                    tongTienPhat += tienPhat[i];
                }

                printf("---------------------------------------------------------------------------------\n");
                printf("Tong tien phat toan he thong: %d VND\n", tongTienPhat);

                break;
            }

            case 3: {
                char maNhap[15];
                int viTri = -1;
                int ngayMoi;

                printf("\n=== CAP NHAT SO NGAY MUON ===\n");
                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%14s", maNhap);
                while (getchar() != '\n');

                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        viTri = i;
                        break;
                    }
                }

                if (viTri == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n", maNhap);
                } else {
                    printf("Tim thay phieu muon cua sach: %s (So ngay hien tai: %d)\n",
                           tenSach[viTri],
                           soNgayMuon[viTri]);

                    do {
                        printf("Nhap so ngay muon thuc te moi: ");
                        scanf("%d", &ngayMoi);
                        while (getchar() != '\n');

                        if (ngayMoi <= 0) {
                            printf("So ngay muon phai lon hon 0. Vui long nhap lai!\n");
                        }

                    } while (ngayMoi <= 0);

                    soNgayMuon[viTri] = ngayMoi;

                    if (soNgayMuon[viTri] > 14) {
                        tienPhat[viTri] =
                            (soNgayMuon[viTri] - 14) * 5000;
                    } else {
                        tienPhat[viTri] = 0;
                    }

                    printf("--> Tien phat moi: %d VND\n",
                           tienPhat[viTri]);

                    printf("--> Cap nhat so ngay muon thanh cong!\n");
                }

                break;
            }

            case 4: {
                char maNhap[15];
                int viTri = -1;

                printf("\n=== XOA LUOT MUON SACH ===\n");
                printf("Nhap ma phieu muon can xoa: ");
                scanf("%14s", maNhap);
                while (getchar() != '\n');

                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        viTri = i;
                        break;
                    }
                }

                if (viTri == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n", maNhap);
                } else {
                    for (int i = viTri; i < soLuong - 1; i++) {
                        strcpy(maPhieu[i], maPhieu[i + 1]);
                        strcpy(tenSach[i], tenSach[i + 1]);
                        soNgayMuon[i] = soNgayMuon[i + 1];
                        tienPhat[i] = tienPhat[i + 1];
                    }

                    soLuong--;

                    printf("Xoa phieu muon thanh cong!\n");
                }

                break;
            }

            case 5: {
                int coPhieuPhat = 0;

                printf("\n=== THONG KE PHIEU MUON QUA HAN ===\n");
                printf("%-5s | %-10s | %-35s | %-10s | %-15s\n",
                       "STT",
                       "Ma Phieu",
                       "Ten Sach",
                       "So Ngay",
                       "Tien Phat (VND)");
                printf("---------------------------------------------------------------------------------\n");

                for (int i = 0; i < soLuong; i++) {
                    if (soNgayMuon[i] > 14) {
                        printf("%-5d | %-10s | %-35s | %-10d | %-15d\n",
                               i + 1,
                               maPhieu[i],
                               tenSach[i],
                               soNgayMuon[i],
                               tienPhat[i]);

                        coPhieuPhat = 1;
                    }
                }

                if (!coPhieuPhat) {
                    printf("Khong co luot muon nao bi qua han phat!\n");
                }

                break;
            }

            case 6:
                printf("\nCam on ban da su dung he thong LIBRARY_WMS!\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }

    } while (luaChon != 6);

    return 0;
}