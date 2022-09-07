// Lucas Otero, Trabajo Practico 1, 02/09/22

#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

int error(int k) {cout << "Error numero " << k << endl; return 1;}

void enter() { cout << "\n";}

int main(){

    int n = 120; // Cantidad de renglones del archivo DATOS

    int cantcli = 8; // Cantidad de clientes del archivo NOMBRES

    int canttipoprod = 5; // Cantidad de productos del archivo NOMBRES

    // Vectores para archivo NOMBRES:

    string nomcli[cantcli], tipoprod[canttipoprod];

    // Vectores para archivo DATOS:

    int vectorcodcli[n], vectorcodprod[n]; float vectorpeso[n], vectordistancia[n];

    // Abro los archivos

    ifstream datos; datos.open("datos.txt"); if (!datos) {error(1);}

    ifstream nombres; nombres.open("nombres.txt"); if (!nombres) {error(2);}

    // Almaceno el contenido en los vectores

    for (int i = 0; i <= (cantcli - 1); i++) {nombres >> nomcli[i];}

    for (int i = 0; i <= (canttipoprod - 1); i++) {nombres >> tipoprod[i];}

    nombres.close();

    for (int i = 0; i <= (n - 1); i++) {datos >> vectorcodcli[i]; datos >> vectorcodprod[i]; datos >> vectorpeso[i]; datos >> vectordistancia[i];}

    datos.close();

    /* Verificacion del correcto almacenado en los vectores: 

    for (int i = 0; i <= (cantcli - 1); i++) {cout << "Nombre de cliente " << i + 1<< ": "<< nomcli[i] << endl;}

    enter();

    for (int i = 0; i <= (canttipoprod - 1); i++) {cout << "Tipo de producto " << i + 1 << ": " << tipoprod[i] << endl;}

    enter();

    for (int i = 0; i <= (n - 1); i++) {
        cout << "Codigo de cliente " << i + 1 << ": " << vectorcodcli[i] << endl;
        cout << "Codigo de producto " << i + 1 << ": " << vectorcodprod[i] << endl;
        cout << "Peso " << i + 1 << ": " << vectorpeso[i] << endl;
        cout << "Distancia " << i + 1  << ": "  << vectordistancia[i] << endl;
        enter();
    }

    Verificacion EXITOSA */


    // Punto 1: Emitir listado (Cli - Prod) && Recicle el codigo para utilidades del punto 2

    enter();

    cout << "Listado por clientes, de los tipos de productos que superen los 13000 Kg acumulados: " << endl;

    enter();

    double pesoparcial = 0.0;

    int mayorcantventas = 0, mayorcantventasmax = 0, codmayorventascliente = 0; // Utiles para el punto 2

    for (int i = 0; i <= (cantcli - 1); i++) {

        mayorcantventas = 0;

        for (int j = 0; j <= (canttipoprod - 1); j++) {

            pesoparcial = 0.0;

            for (int k = 0; k <= (n - 1); k++) {

                if (vectorcodcli[k] == i) {

                    if (vectorcodprod[k] == j) {

                        pesoparcial = pesoparcial + vectorpeso[k];

                        if (pesoparcial > 13000.0) {

                            pesoparcial = 0.0; mayorcantventas++;

                            cout << "Cliente " << nomcli[i] << ": " << tipoprod[vectorcodprod[k]] << endl;

                        }

                    }

                }

            }

        }

        if (mayorcantventas > mayorcantventasmax) {

            mayorcantventasmax = mayorcantventas;

            codmayorventascliente = i;

        }

        enter();

    }

    /* Verificacion de que la mayor cantidad de ventas es de 4 para el cliente Bi

    cout << "La mayor venta es de " << mayorcantventasmax << " para el cliente " << nomcli[codmayorventascliente] << endl;

    */


    // Punto 2: Emitir listado del mayor cliente (Km) && Recicle el codigo para utilidades del punto 3

   /* Comprobación de que el Cliente en cuestión es Bi

   float km = 0.0;

    for (int i = 0; i <= (cantcli - 1); i++) {

        for (int j = 0; j <= (canttipoprod - 1); j++) {

            km = 0.0;

            for (int k = 0; k <= (n - 1); k++) {

                if (vectorcodcli[k] == i) {

                    if (vectorcodprod[k] == j) {

                       km = km + vectordistancia[k]; 
                    
                    }

                }

            }

            cout << "Cliente " << nomcli[i] << ", producto " << tipoprod[j] << ", km " << km << endl;

        }

        enter();

    }

    */

   
   enter();

   cout << "Listado de Km recorridos por tipo de producto (ascendente): " << endl;

   enter();
    
    float km = 0.0, kmvector[canttipoprod];

    string tipoprod2[canttipoprod];

    float kmmax = 0.0; // Utilies para el punto 3

    int codprodmayorkm = 0;


    for (int j = 0; j <= (canttipoprod - 1); j++) {

        km = 0.0; tipoprod2[j] = tipoprod[j];

        for (int k = 0; k <= (n - 1); k++) {

            if (vectorcodcli[k] == codmayorventascliente) {

                if (vectorcodprod[k] == j) {

                    km = km + vectordistancia[k]; 

                }

            }

        }

        if (km > kmmax) {

            kmmax = km;

            codprodmayorkm = j;

        }

        // cout << "Cliente " << nomcli[codmayorventascliente] << ", producto " << tipoprod[j] << ", km " << km << endl;

        kmvector[j] = km;

    }

    /* Verificacion del producto con mayor kilometros

    cout << "El producto con mayor kilomestros es el " << tipoprod[codprodmayorkm] << endl; */

    float aux = 0.0;

    string auxiliar;

    int zz = 0;

    for (int i = 0; i <= (canttipoprod - 1); i++) {

        zz = 0;

        for (zz = 0; zz < i; zz++) {

            if (kmvector[zz] > kmvector[i]) {

                aux = kmvector[zz];

                kmvector[zz] = kmvector[i];

                kmvector[i] = aux;

                auxiliar = tipoprod2[zz];

                tipoprod2[zz] = tipoprod2[i];

                tipoprod2[i] = auxiliar;

            }

        }

    }


    for (int i = 0; i <= (canttipoprod - 1); i++) {

        cout << tipoprod2[i] << ": " << kmvector[i] << endl;

    }


    // Punto 3:

    enter();

    int cantentregas = 0;

    for (int i = 0; i <= (n - 1); i++) {

        if (vectorcodprod[i] == codprodmayorkm) { cantentregas++;}

    }

    cout << "El producto con mayor cantidad de kilometros recorridos es el " << tipoprod[codprodmayorkm] << ", con " << cantentregas << " entregas" << endl;

    enter();


    getch(); return 0;
}


// Otra version:

/* 
    // Lucas Otero, Trabajo Practico 1, 02/09/22

    #include <iostream>
    #include <fstream>
    #include <conio.h>

    using namespace std;

    int error(int k) {cout << "Error numero " << k << endl; return 1;}

    void funcionj(string tipoprod2[], string tipoprod[], string nomcli[], float vectordistancia[], float vectorpeso[], int vectorcodcli[], int vectorcodprod[], float kmvector[], int n, int canttipoprod, float pesookm, int i, bool pesoo, int& mayorcantventas, float& kmmaxomayorcantventasmax, int& codmayorventasclientecodprodmayorkm) {

        for (int j = 0; j <= (canttipoprod - 1); j++) {

            pesookm = 0.0;

            for (int k = 0; k <= (n - 1); k++) {

                if (vectorcodcli[k] == i) {

                    if (vectorcodprod[k] == j) {

                        if (pesoo) {pesookm = pesookm + vectorpeso[k];}

                        else {pesookm = pesookm + vectordistancia[k];}

                        if (pesookm > 13000.0 && pesoo) {

                            pesookm = 0.0; mayorcantventas++;

                            cout << "Cliente " << nomcli[i] << ": " << tipoprod[vectorcodprod[k]] << endl;

                        }

                    }

                }
            }

            if (pesoo) {

                if (mayorcantventas > kmmaxomayorcantventasmax) {

                    kmmaxomayorcantventasmax = mayorcantventas;

                    codmayorventasclientecodprodmayorkm = i;

                }

            }

            else {

                if (pesookm > kmmaxomayorcantventasmax) {

                    kmmaxomayorcantventasmax = pesookm;

                    codmayorventasclientecodprodmayorkm = j;


                }

                tipoprod2[j] = tipoprod[j];

                kmvector[j] = pesookm;

            }

        }

    }

    void ordenarymostrar(bool& pesoo, float kmvector[], string tipoprod2[],int& canttipoprod, int& zz, float& auxkmvector, string& nombreauxiliarkm) {

        for (int i = 0; i <= (canttipoprod - 1); i++) {

            if (pesoo) {

                zz = 0;

                for (zz = 0; zz < i; zz++) {

                    if (kmvector[zz] > kmvector[i]) {

                        auxkmvector = kmvector[zz];

                        kmvector[zz] = kmvector[i];

                        kmvector[i] = auxkmvector;

                        nombreauxiliarkm = tipoprod2[zz];

                        tipoprod2[zz] = tipoprod2[i];

                        tipoprod2[i] = nombreauxiliarkm;

                    }

                }

                if (i == (canttipoprod - 1)) {pesoo = false; i = -1;}

            }

            else { cout << tipoprod2[i] << ": " << kmvector[i] << endl;}

        }

    }

    void enter() {enter();}

    int main(){

        int n = 120; // Cantidad de renglones del archivo DATOS

        int vectorcodcli[n]; int vectorcodprod[n]; float vectorpeso[n]; float vectordistancia[n];

        int cantcli = 8; // Cantidad de clientes del archivo NOMBRES

        int canttipoprod = 5; // Cantidad de productos del archivo NOMBRES

        float kmvector[canttipoprod];

        string nomcli[cantcli]; string tipoprod[canttipoprod];

        // No puedo alterar el orden del vector original, entonces lo duplico y altero el duplicado

        string tipoprod2[canttipoprod];

        // Abro los archivos

        ifstream datos; datos.open("datos.txt"); if (!datos) {error(1);}

        ifstream nombres; nombres.open("nombres.txt"); if (!nombres) {error(2);}

        // Almaceno el contenido en los vectores

        for (int i = 0; i <= (cantcli - 1); i++) {nombres >> nomcli[i];}

        for (int i = 0; i <= (canttipoprod - 1); i++) {nombres >> tipoprod[i];}

        nombres.close();

        for (int i = 0; i <= (n - 1); i++) {datos >> vectorcodcli[i]; datos >> vectorcodprod[i]; datos >> vectorpeso[i]; datos >> vectordistancia[i];}

        datos.close();

        /* Verificacion del correcto almacenado en los vectores: 

        for (int i = 0; i <= (cantcli - 1); i++) {cout << "Nombre de cliente " << i + 1<< ": "<< nomcli[i] << endl;}

        enter();

        for (int i = 0; i <= (canttipoprod - 1); i++) {cout << "Tipo de producto " << i + 1 << ": " << tipoprod[i] << endl;}

        enter();

        for (int i = 0; i <= (n - 1); i++) {
            cout << "Codigo de cliente " << i + 1 << ": " << vectorcodcli[i] << endl;
            cout << "Codigo de producto " << i + 1 << ": " << vectorcodprod[i] << endl;
            cout << "Peso " << i + 1 << ": " << vectorpeso[i] << endl;
            cout << "Distancia " << i + 1  << ": "  << vectordistancia[i] << endl;
            enter();
        }

        Verificacion EXITOSA */

        /*


        // Punto 1: Emitir listado (Cli - Prod) && Recicle el codigo para utilidades del punto 2

        enter();

        cout << "Listado por clientes, de los tipos de productos que superen los 13000 Kg acumulados: " << endl;

        enter();

        double pesoparcial = 0.0;

        int mayorcantventas = 0, codmayorventascliente = 0; float mayorcantventasmax = 0; // Utiles para el punto 2

        bool bpeso = true;

        for (int i = 0; i <= (cantcli - 1); i++) {

            mayorcantventas = 0;


            funcionj( tipoprod2, tipoprod, nomcli, vectordistancia, vectorpeso, vectorcodcli, vectorcodprod, kmvector, n, canttipoprod, pesoparcial, i, bpeso, mayorcantventas, mayorcantventasmax, codmayorventascliente);

            enter();
            
            /*
            for (int j = 0; j <= (canttipoprod - 1); j++) {

                pesoparcial = 0.0;

                for (int k = 0; k <= (n - 1); k++) {

                    if (vectorcodcli[k] == i) {

                        if (vectorcodprod[k] == j) {

                            pesoparcial = pesoparcial + vectorpeso[k];

                            if (pesoparcial > 13000.0) {

                                pesoparcial = 0.0; mayorcantventas++;

                                cout << "Cliente " << nomcli[i] << ": " << tipoprod[vectorcodprod[k]] << endl;

                            }

                        }

                    }

                }

            } 

            if (mayorcantventas > mayorcantventasmax) {

                mayorcantventasmax = mayorcantventas;

                codmayorventascliente = i;

            }

            cout << "\n" << endl; */

            /*

        } 


        /* Verificacion de que la mayor cantidad de ventas es de 4 para el cliente Bi

        cout << "La mayor venta es de " << mayorcantventasmax << " para el cliente " << nomcli[codmayorventascliente] << endl;

        */


        // Punto 2: Emitir listado del mayor cliente (Km) && Recicle el codigo para utilidades del punto 3

        /* Comprobación de que el Cliente en cuestión es Bi

        float km = 0.0;

        for (int i = 0; i <= (cantcli - 1); i++) {

            for (int j = 0; j <= (canttipoprod - 1); j++) {

                km = 0.0;

                for (int k = 0; k <= (n - 1); k++) {

                    if (vectorcodcli[k] == i) {

                        if (vectorcodprod[k] == j) {

                        km = km + vectordistancia[k]; 
                        
                        }

                    }

                }

                cout << "Cliente " << nomcli[i] << ", producto " << tipoprod[j] << ", km " << km << endl;

            }

            enter();

        }

        */

       /*

        enter();

        cout << "Listado de Km recorridos por tipo de producto (ascendente): " << endl;

        enter();
        
        float km = 0.0;

        float kmmax = 0.0; // Utilies para el punto 3

        int codprodmayorkm = 0;

        bpeso = false;

        funcionj( tipoprod2, tipoprod, nomcli, vectordistancia, vectorpeso, vectorcodcli, vectorcodprod, kmvector, n, canttipoprod, km, codmayorventascliente, bpeso, mayorcantventas, kmmax, codprodmayorkm);

        /*
        for (int j = 0; j <= (canttipoprod - 1); j++) {

            km = 0.0; tipoprod2[j] = tipoprod[j];

            for (int k = 0; k <= (n - 1); k++) {

                if (vectorcodcli[k] == codmayorventascliente) {

                    if (vectorcodprod[k] == j) {

                        km = km + vectordistancia[k]; 

                    }

                }

            }

            if (km > kmmax) {

                kmmax = km;

                codprodmayorkm = j;

            }

            // cout << "Cliente " << nomcli[codmayorventascliente] << ", producto " << tipoprod[j] << ", km " << km << endl;

            kmvector[j] = km;

        } /*

        /* Verificacion del producto con mayor kilometros

        cout << "El producto con mayor kilomestros es el " << tipoprod[codprodmayorkm] << endl;

        */

        /*

        float auxkmvector = 0.0;

        string nombreauxiliarkm;

        int zz = 0;

        bpeso = true;

        enter();

        ordenarymostrar(bpeso, kmvector, tipoprod2, canttipoprod, zz, auxkmvector, nombreauxiliarkm);

        /*

        for (int i = 0; i <= (canttipoprod - 1); i++) {

            zz = 0;

            for (zz = 0; zz < i; zz++) {

                if (kmvector[zz] > kmvector[i]) {

                    auxkmvector = kmvector[zz];

                    kmvector[zz] = kmvector[i];

                    kmvector[i] = auxkmvector;

                    nombreauxiliarkm = tipoprod2[zz];

                    tipoprod2[zz] = tipoprod2[i];

                    tipoprod2[i] = nombreauxiliarkm;

                }

            }

        }

        for (int i = 0; i <= (canttipoprod - 1); i++) {

            cout << tipoprod2[i] << ": " << kmvector[i] << endl;

        } */

        // Punto 3:

        /*

        enter();

        int cantentregas = 0;

        for (int i = 0; i <= (n - 1); i++) {

            if (vectorcodprod[i] == codprodmayorkm) { cantentregas++;}

        }

        cout << "El producto con mayor cantidad de kilometros recorridos es el " << tipoprod[codprodmayorkm] << ", con  " << cantentregas << " entregas" << endl;

        enter();


        getch(); return 0;
    }

*/