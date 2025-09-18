#include <iostream>
#include <locale.h>
#include <windows.h>

using namespace std;

// імплікація
bool implication(bool a, bool b){
    return (!a || b);
}

// Перевірка введення
bool inputBool(string name){
    int value;
    do{
        cout << "Введіть значення " << name << " : ";
        cin >> value;
        
        if (value != 0 && value !=1){
            cout << "Помилка вводу! Введіть лише 0 або 1" << endl;
        }
    } while (value != 0 && value != 1);
    
    return value;
}

int main(){
    SetConsoleOutputCP(65001); // Увімкнути UTF-8 вивід
    setlocale(LC_ALL, "uk_UA.UTF-8");

    bool x = inputBool("x");
    bool y = inputBool("y");
    bool z = inputBool("z");
    
    cout << "\n(x → (y → z)) → ((x ∧ y) → z)" << endl;

    //1. y → z
    bool a1 = implication(y, z);
    cout << "1. y → z : " << a1 << endl;

    //2. x → (y → z)
    bool a2 = implication(x, a1);
    cout << "2. x → (y → z) : " << a2 << endl;

    //3. x ∧ y
    bool a3 = (x && y);
    cout << "3. x ∧ y : " << a3 << endl;

    //4. (x ∧ y) → z
    bool a4 = implication(a3, z);
    cout << "4. (x ∧ y) → z : " << a4 << endl;

    //5. (x → (y → z)) → ((x ∧ y) → z)
    bool result = implication(a2, a4);
    cout << "5. (x → (y → z)) → ((x ∧ y) → z) : " << result << endl;

    return 0;
}