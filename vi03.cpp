#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ==========================
// 1. Khai báo cấu trúc Sinh viên
// ==========================
struct SinhVien {
    string hoTen;
    string lop;
    string quocTich;
    float diemTongKet;
    string xepLoai;
};

// ==========================
// 2. Khai báo cấu trúc Danh sách
// ==========================
const int MAX = 100;

struct DanhSach {
    SinhVien a[MAX];
    int n;
};

// ==========================
// 3. Xác định xếp loại
// ==========================
string xepLoaiSV(float diem) {
    if (diem >= 8.0)
        return "Gioi";
    else if (diem >= 6.5)
        return "Kha";
    else if (diem >= 5.0)
        return "Trung binh";
    else
        return "Yeu";
}

// ==========================
// 4. Nhập thông tin 1 sinh viên
// ==========================
void nhapSinhVien(SinhVien &sv) {
    cin.ignore();

    cout << "Ho ten: ";
    getline(cin, sv.hoTen);

    cout << "Lop: ";
    getline(cin, sv.lop);

    cout << "Quoc tich: ";
    getline(cin, sv.quocTich);

    cout << "Diem tong ket: ";
    cin >> sv.diemTongKet;

    sv.xepLoai = xepLoaiSV(sv.diemTongKet);
}

// ==========================
// 5. Tạo danh sách gồm N phần tử
// ==========================
void taoDS(DanhSach &L) {
    cout << "Nhap so luong sinh vien N = ";
    cin >> L.n;

    for (int i = 0; i < L.n; i++) {
        cout << "\n--- Sinh vien thu " << i + 1 << " ---\n";
        nhapSinhVien(L.a[i]);
    }
}

// ==========================
// 6. In danh sách
// ==========================
void inDS(DanhSach L) {
    cout << "\n========== DANH SACH SINH VIEN ==========\n";

    cout << left
         << setw(5) << "STT"
         << setw(25) << "Ho ten"
         << setw(12) << "Lop"
         << setw(15) << "Quoc tich"
         << setw(12) << "Diem"
         << setw(15) << "Xep loai"
         << endl;

    for (int i = 0; i < L.n; i++) {
        cout << left
             << setw(5) << i + 1
             << setw(25) << L.a[i].hoTen
             << setw(12) << L.a[i].lop
             << setw(15) << L.a[i].quocTich
             << setw(12) << L.a[i].diemTongKet
             << setw(15) << L.a[i].xepLoai
             << endl;
    }
}

// ==========================
// 7. Thêm một sinh viên mới
// ==========================
void themPhanTu(DanhSach &L, int p) {
    if (L.n >= MAX) {
        cout << "Danh sach da day!\n";
        return;
    }

    if (p < 1 || p > L.n + 1) {
        cout << "Vi tri khong hop le!\n";
        return;
    }

    // Dịch các phần tử sang phải
    for (int i = L.n; i >= p; i--) {
        L.a[i] = L.a[i - 1];
    }

    cout << "\nNhap sinh vien moi:\n";
    nhapSinhVien(L.a[p - 1]);

    L.n++;

    cout << "Them sinh vien thanh cong!\n";
}

// ==========================
// 8. Xóa một sinh viên
// ==========================
void xoaPhanTu(DanhSach &L, int q) {
    if (q < 1 || q > L.n) {
        cout << "Vi tri khong hop le!\n";
        return;
    }

    // Dịch các phần tử sang trái
    for (int i = q - 1; i < L.n - 1; i++) {
        L.a[i] = L.a[i + 1];
    }

    L.n--;

    cout << "Xoa sinh vien thanh cong!\n";
}

// ==========================
// 9. Chương trình chính
// ==========================
int main() {
    DanhSach L;
    int p, q;

    // Tạo danh sách
    cout << "===== TAO DANH SACH =====\n";
    taoDS(L);

    // In danh sách
    cout << "\n===== IN DANH SACH =====\n";
    inDS(L);

    // Thêm sinh viên
    cout << "\n===== CHEN THEM PHAN TU =====\n";
    cout << "Chen sinh vien moi sau phan tu thu p = ";
    cin >> p;

    themPhanTu(L, p);

    cout << "\n===== DANH SACH SAU KHI CHEN =====\n";
    inDS(L);

    // Xóa sinh viên
    cout << "\n===== XOA PHAN TU =====\n";
    cout << "Xoa sinh vien tai vi tri thu q = ";
    cin >> q;

    xoaPhanTu(L, q);

    cout << "\n===== DANH SACH SAU KHI XOA =====\n";
    inDS(L);

    return 0;
}