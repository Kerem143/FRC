#include <iostream>
using namespace std;

char islem;
double x;
double y;

int main() {
    cout << "1. sayiyi girin: " << flush;
    cin >> x;

    cout << "yapmak istediginiz islemi (+,-,*,/) girin: " << flush;
    cin >> islem;

    cout << "2. sayiyi girin: " << flush;
    cin >> y;

    if (islem == '+') {
        cout << "Sonuc: " << x + y << endl;
    }
    else if (islem == '-') {
        cout << "Sonuc: " << x - y << endl;
    }
    else if (islem == '*') {
        cout << "Sonuc: " << x * y << endl;
    }
    else if (islem == '/') {
        if (y != 0)
            cout << "Sonuc: " << x / y << endl;
        else
            cout << "Hata: Sıfıra bölünemez!" << endl;
    }
    else {
        cout << "Gecersiz islem!" << endl;
    }

    return 0;
}
