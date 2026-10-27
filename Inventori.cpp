#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Item {
private:
    const string kode;
    string nama;
    double harga;
    int stok;

public:
    Item(const string& kode_, const string& nama_, double hargaAwal, int stokAwal)
        : kode(kode_), nama(nama_), harga(0), stok(0) {
        setHarga(hargaAwal);
        if (stokAwal >= 0) {
            stok = stokAwal;
        } else {
            cout << "Stok awal tidak valid. Stok diset 0." << endl;
        }
    }

    void setHarga(double h) {
        if (h > 0) {
            harga = h;
        } else {
            cout << "Harga harus > 0. Harga tidak diubah." << endl;
        }
    }

    void restock(int jumlah) {
        if (jumlah > 0) {
            stok += jumlah;
            cout << "Restock +" << jumlah << endl;
        } else {
            cout << "Jumlah restock tidak valid." << endl;
        }
    }

    void jual(int jumlah) {
        if (jumlah <= 0) {
            cout << "Jumlah penjualan tidak valid." << endl;
        } else if (jumlah > stok) {
            cout << "Stok tidak mencukupi." << endl;
        } else {
            stok -= jumlah;
            cout << "Terjual " << jumlah << " unit." << endl;
        }
    }

    void diskon(double persen) {
        if (persen >= 0 && persen <= 100) {
            harga -= harga * persen / 100.0;
            cout << "Diskon " << persen << "% diterapkan." << endl;
        } else {
            cout << "Persentase diskon harus 0-100." << endl;
        }
    }

    double totalValue() const {
        return harga * stok;
    }

    void tampilInfo() const {
        cout << fixed << setprecision(0);
        cout << "Kode: " << kode << " | Nama: " << nama
             << " | Harga: Rp " << harga << " | Stok: " << stok << endl;
    }
};

int main() {
    Item pulpen("IT01", "Pulpen", 3000, 10);
    pulpen.tampilInfo();

    pulpen.jual(3);
    pulpen.restock(5);
    pulpen.diskon(10);

    pulpen.tampilInfo();
    cout << fixed << setprecision(0);
    cout << "Total value inventory: Rp " << pulpen.totalValue() << endl;
    return 0;
}
