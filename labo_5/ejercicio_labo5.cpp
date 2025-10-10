#include <iostream>

using namespace std;

int main(){
    int numero;

    cout << "Porfavor introduzca un numero del 1 al 20"; 
    cin >> numero;
           
    cout << "\nTabla de multiplicar del " << numero << endl;

    for (int i = 1; i <= 20 ; i++)
    {
        cout << numero << "x" << i << " = " << numero * i<< endl;
    }
   return 0; 
}