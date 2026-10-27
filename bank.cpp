#include <iostream>
#include <string>
using namespace std;

class Rekening {
private:
    string pemilik;
    long long saldo;

public:
    Rekening(const string& pemilik_, long long saldoAwal)
        : pemilik(pemilik_), saldo(0) {
        if (saldoAwal >= 0) {
            saldo = saldoAwal;
        } else {
            cout << "Saldo awal tidak valid. Saldo diset 0." << endl;
        }
    }

    void deposit(double jumlah) {
        if (jumlah > 0) {
            saldo += static_cast<long long>(jumlah);
            cout << "Deposit: Rp " << static_cast<long long>(jumlah) << " berhasil." << endl;
        } else {
            cout << "Jumlah deposit tidak valid." << endl;
        }
    }

    void withdraw(double jumlah) {
        if (jumlah <= 0) {
            cout << "Jumlah withdraw tidak valid." << endl;
        } else if (jumlah > saldo) {
            cout << "Saldo tidak mencukupi." << endl;
        } else {
            saldo -= static_cast<long long>(jumlah);
            cout << "Withdraw: Rp " << static_cast<long long>(jumlah) << " berhasil." << endl;
        }
    }

    long long getSaldo() const {
        return saldo;
    }

    void tampilInfo() const {
        cout << "Pemilik: " << pemilik << " | Saldo: Rp " << saldo << endl;
    }
};

int main() {
    Rekening rek("Andi", 1000000);
    rek.tampilInfo();

    rek.deposit(250000);   // valid
    rek.deposit(-5000);    // tidak valid

    rek.withdraw(300000);  // valid
    rek.withdraw(5000000); // saldo tidak mencukupi

    rek.tampilInfo();
    return 0;
}
