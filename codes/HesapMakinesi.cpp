#include <iostream>
using namespace std;
char islem;
double x;
double y;
int main (){
   cout << "1.sayiyi girin: "<< endl;
   cin >> x;
   cout << "yapmak istediginiz islemi (+,-,*,/) girin: "<< endl;
   cin >> islem;
   cout << "2.sayiyi girin: "<< endl;
   cin >> y;
   if (islem == '+') {
    cout << x + y;
   }
   if (islem == '-') {
    cout << x - y;
   }
   if (islem == '*') {
    cout << x * y;
   }
   if (islem == '/') {
    cout << x / y;
   }
}
