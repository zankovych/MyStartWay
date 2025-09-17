#include <iostream>
#include <locale.h>

#include <windows.h>
using namespace std;

int main(){


    SetConsoleOutputCP(65001); // Увімкнути UTF-8 вивід
    setlocale(LC_ALL, "uk_UA.UTF-8");

    short x, y, z; //основні змінні
    cout << "Введіть знчення x, y та z" << endl;
    cin >> x >> y >> z;

    cout << "(x → (y → z)) → ((x ∧ y) → z)" << endl; //виведення початкової формули

    short a1, a2, a3, a4; //почергове виконання кожної дії

    //y → z
    if (y==0 && z==0) {a1=1; cout << "1. y → z : 1" << endl;}
    else if (y==0 && z==1) {a1=1; cout << "1. y → z : 1" << endl;}
        else if (y==1 && z==1) {a1=1; cout << "1. y → z : 1" << endl;}
            else {a1=0; cout << "1. y → z : 0" << endl;}

    //x → (y → z)
    if (x==0 && a1==0) {a2=1; cout << "2. x → (y → z) : 1" << endl;}
    else if (x==0 && a1==1) {a2=1; cout << "2. x → (y → z) : 1" << endl;}
        else if (x==1 && a1==1) {a2=1; cout << "2. x → (y → z) : 1" << endl;}
            else {a2=0; cout << "2. x → (y → z) : 0" << endl;}

    //x ∧ y
    if (x==1 && y==1) {a3=1; cout << "3. x ∧ y : 1" << endl;}
    else {a3=0; cout << "3. x ∧ y : 0" << endl;}

    //(x ∧ y) → z
    if (a3==0 && z==0) {a4=1; cout << "4. (x ∧ y) → z : 1" << endl;}
    else if (a3==0 && z==1) {a4=1; cout << "4. (x ∧ y) → z : 1" << endl;}
        else if (a3==1 && z==1) {a4=1; cout << "4. (x ∧ y) → z : 1" << endl;}
            else {a4=0; cout << "4. (x ∧ y) → z : 0" << endl;}

    //(x → (y → z)) → ((x ∧ y) → z)
    if (a2==0 && a4==0) cout << "5. (x → (y → z)) → ((x ∧ y) → z) : 1" << endl;
    else if (a2==0 && a4==1) cout << "5. (x → (y → z)) → ((x ∧ y) → z) : 1" << endl;
        else if (a2==1 && a4==1) cout << "5. (x → (y → z)) → ((x ∧ y) → z) : 1" << endl;
            else cout << "5. (x → (y → z)) → ((x ∧ y) → z) : 0" << endl;
}