#include <iostream>
#include <cmath>
#include <conio.h> // Para _getch()
#include <cstdlib> // Para system()
#include <string>
using namespace std;

void clearConsole() {
    system("cls || clear"); //esta monda no funciona en el terminal de clion
}

const double PI = 3.1415926535897932;

double readDouble(const string& text) {
    double val = -1;
    do {
        cout << text << " ";
        cin >> val;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida" << endl;
            val = -1;
        } else if (val <= 0||val > DBL_MAX) {
            cout << "Cantidad fuera de rango." << endl;
        }
    } while (val <= 0||val > DBL_MAX);

    return val;
}
//esto da asco pero me dio pereza (y no tengo tanto tiempo xd) para implementar una funcion que pueda manejar todo
int readInt(const string& text) {
    int val = -1;
    do {
        cout << text;
        cin >> val;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida" << endl;
            val = -1;
        } else if (val <= 0||val > INT_MAX) {
            cout << "Cantidad fuera de rango." << endl;
        }
    } while (val <= 0||val > INT_MAX);

    return val;
}

void ejercicio1() {

    double radius = -1;
    do {
        cout << "Ingrese el radio del círculo: ";
        cin >> radius;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida" << endl;
            radius = -1;
        } else if (radius <= 0||radius > DBL_MAX) {
            cout << "Radio fuera de rango. Ingrese valor mayor que 0 y no mayor a " << DBL_MAX << endl;
        }
    } while (radius <= 0||radius > DBL_MAX);

    double perimeter = 2 * PI * radius;
    cout << "El perimetro de el circulo con radio " << radius << "es: " << perimeter << endl;
}

void ejercicio2() {

    double radius = -1;
    do {
        cout << "Ingrese el radio del cono: ";
        cin >> radius;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida" << endl;
            radius = -1;
        } else if (radius <= 0||radius > DBL_MAX) {
            cout << "Radio fuera de rango. Ingrese valor mayor que 0 y no mayor a " << DBL_MAX << endl;
        }
    } while (radius <= 0||radius > DBL_MAX);

    double height = -1;
    do {
        cout << "Ingrese la altura del cono: ";
        cin >> height;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida" << endl;
            height = -1;
        } else if (height <= 0||height > DBL_MAX) {
            cout << "Altura fuera de rango. Ingrese valor mayor que 0 y no mayor a " << DBL_MAX << endl;
        }
    } while (height <= 0||height > DBL_MAX);

    double volume = 1.0/3.0 * PI * (radius * radius) * height;
    cout << "El volumen del cono de radio " << radius << " y altura " << height << " es de " << volume << endl;
}

void ejercicio3() {
    int herbs = readInt("Ingrese las libras de hierbas que desea llevar");
    int drops = readInt("Ingrese los frascos de gotas que desea llevar");
    int creams = readInt("Ingrese la cantidad de potes de crema que desea llevar");

    double herbsPrice = 2000.0;
    double dropsPirce = 5000.0;
    double creamsPrice = 10000.0;

    double herbsTotal = herbs * herbsPrice;
    double dropsTotal = drops * dropsPirce;
    double creamsTotal = creams * creamsPrice;

    double price = herbsTotal + dropsTotal + creamsTotal;

    cout << "\n========== FACTURA ==========\n";
    cout << "Hierbas (" << herbs << ")  : $" << herbsTotal << endl;
    cout << "Gotas (" << drops << ")    : $" << dropsTotal << endl;
    cout << "Cremas (" << creams << ")  : $" << creamsTotal << endl;
    cout << "-----------------------------\n";
    cout << "TOTAL: $" << price << endl;
    cout << "=============================\n";
}

void ejercicio4() {
    double farenheit = readDouble("Ingrese la temperatura en grados farenheit: ");

    double celsius = (farenheit - 32)  * 5 / 9;
    double kelvin = celsius + 273.15;

    cout << "La temperatura ingresada: " << farenheit << " equivale a : " << endl;
    cout << celsius << " grados celsius" << endl;
    cout << kelvin << " grados kelvin" << endl;
}

void ejercicio5() {
    double length = readDouble("Ingrese la longitud del alambre");
    double side = readDouble("Ingrese el tamaño del lado del cuadrado");

    if (4 * side > length) {
        cout << "El alambre no alcanza para construir el cuadrado." << endl;
        return;
    }

    double squareArea = side * side;
    double circlePerimeter = length - (4 * side);
    double circleRadius = (circlePerimeter / (2 * PI));

    double circleArea = PI * (circleRadius * circleRadius);

    cout << "Area del cuadrado: " << squareArea << "cm2" << endl;
    cout << "Perimetro usado para el circulo: " << circlePerimeter << "cm" << endl;
    cout << "Radio del circulo: " << circleRadius << "cm" << endl;
    cout << "Area del circulo: " << circleArea << "cm2" << endl;
}

void ejercicio6() {
    int hours = readInt("Ingrese las horas");
    int minutes = readInt("Ingrese los minutos");
    int seconds = readInt("Ingrese los segundos");

    int total = (hours * 60 * 60) + (minutes * 60) + (seconds);

    cout << "El valor total de segundos es de: " << total << endl;
}

void ejercicio7() {
    int secondsInput = readInt("Ingrese el valor en segundos");

    int hours = (secondsInput / 3600);
    int minutes = ((secondsInput % 3600) / 60);
    int seconds = secondsInput % 60;

    cout << "El valor en segundos " << seconds << " equivale a :" << endl;
    cout << "Horas: " << hours << endl;
    cout << "Minutos: " << minutes << endl;
    cout << "Segundos: " << seconds << endl;
}

void optionalShow(int value, const string& text) {
    if (value > 0) {
        cout << "Sacara " << value << " billetes de " << text << endl;
    }
}

void ejercicio8() {
    int withdrawn = readInt("Ingrese la cantidad de dinero a retirar:");

    if (withdrawn % 1000 != 0) {
        cout << "No se puede retirar esa cantidad, solo múltiplos de 1000." << endl;
        return;
    }


    int fiftyBills  = withdrawn / 50000;
    int current     = withdrawn % 50000;

    int twentyBills = current / 20000;
    current         = current % 20000;

    int tenBills    = current / 10000;
    current         = current % 10000;

    int fiveBills   = current / 5000;
    current         = current % 5000;

    int twoBills    = current / 2000;
    current         = current % 2000;

    int oneBills    = current / 1000;
    current         = current % 1000;

    optionalShow(fiftyBills, "50.000");
    optionalShow(twentyBills, "20.000");
    optionalShow(tenBills, "10.000");
    optionalShow(fiveBills, "5.000");
    optionalShow(twoBills, "2.000");
    optionalShow(oneBills, "1.000");
}

int main() {
    int next = 1;

    do {
        cout << "Taller 0 Estructuras de Datos" << endl;
        for (int ej = 1; ej < 9; ej++) {
            cout << "Ejercicio " << ej << endl;
        }

        cout << "Ingrese el ejercicio que desea ver: ";
        int ejercicio;
        cin >> ejercicio;

        switch (ejercicio) {
            case 1: ejercicio1(); break;
            case 2: ejercicio2(); break;
            case 3: ejercicio3(); break;
            case 4: ejercicio4(); break;
            case 5: ejercicio5(); break;
            case 6: ejercicio6(); break;
            case 7: ejercicio7(); break;
            case 8: ejercicio8(); break;

            default: {
                cout << "Ejercicio inválido" << endl;
                cout << "Presione enter para reintentar..." << endl;
                _getch();
                continue;
            }
        }

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida" << endl;
        } else if (ejercicio > 8 || ejercicio < 1) {
            cout << "Ejercicio invalido" << endl;
        }

        cout << "Desea ver otro ejercicio? (1 = Si, Otro = No): ";
        cin >> next;


    } while (next == 1);

    return 0;
}
