#include<iostream>
#include<string>
using namespace std;
struct EMP{
    int num;
    std::string nom;
    float ven[12], sal;

};

int main(){
    EMP EMPLEADOS[100];
        int n;
        cin>>n;
        for (int i=0; i<n;i++){
        cin>>EMPLEADOS[i].num;
        cin.ignore();
        getline (cin, EMPLEADOS[i].nom);
        for (int j=0; j<12;j++){
        cin>>EMPLEADOS[i].ven[j];
        }
        cin>>EMPLEADOS[i].sal;
    }
    int maxIndex = 0;
    float maxVentas = 0;
    for (int i = 0; i < n; i++){
        float totalVentas = 0;
        for (int j = 0; j < 12; j++){
            totalVentas += EMPLEADOS[i].ven[j];
        }
        if (totalVentas > maxVentas){
            maxVentas = totalVentas;
            maxIndex = i;
        }
    }
    cout << " Empleado con mayores ventas anuales: " << endl;
    cout << "Numero: " << EMPLEADOS[maxIndex].num << endl;
    cout << "Nombre: " << EMPLEADOS[maxIndex].nom << endl;
    for (int i = 0; i < n; i++){
        float total = 0;
        for (int j = 0; j < 12; j++){
            total += EMPLEADOS[i].ven[j];
        }
        if (total > 100){
            EMPLEADOS[i].sal *= 1.10;
        }
    }
    cout << " Empleados con menos de 30 ventas en diciembre: ";
    for (int i = 0; i < n; i++){
        if (EMPLEADOS[i].ven[11] < 30){
            cout << "Numero: " <<EMPLEADOS[i].num << ", Nombre: " << EMPLEADOS[i].nom << endl;
        }
    }
    return 0;
}