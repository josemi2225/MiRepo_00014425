#include <iostream>

using namespace std;

int main (){
    int numeroSecreto = 0; //numero secreto 

    cout << "Adivina el numero secreto: " <<endl;
    do
    {
        cout << "ingresa un numero: ";
        cin >> numeroSecreto;

        if (numeroSecreto < 22)
        {
            cout << "El numero es muy bajo.Intentelo de nuevo." << endl;

        }else if (numeroSecreto > 22)
        {
            cout << "El numero es muy alto. Intentelo de nuevo." << endl;
        }
        
        
    } while (numeroSecreto != 22);
    

    return 0;
}