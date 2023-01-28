#include <iostream>
#include <vector>
#include "Persona.h"
#include "Empleado.h"
#include "Secretario.h"
#include "Vendedor.h"
#include "Cliente.h"
#include "Coche.h"
using namespace std;



//Variables (las instanciamos todas arriba para no tener que repetirlas)
string nombre, apellidos, dni, direccion, telefono, num_fax, telefonoMovil;
double salario, nSalario, bonoAnual, porcentajeComisiones;
int aniosLaboral, puesto, areaVenta, numeroClientes;
char tipo;
bool despacho;


Cliente** clientes;
Coche* carro;
Vendedor** vendedores;
Secretario* secretario;
vector<Empleado*> empleados;
vector<Coche*> carros;

void menu() {
    cout << "\n::::::::::::MENU:::::::::::::" << endl;
    cout << "1.- Agregar Empleado" << endl;                    //Funciona
    cout << "2.- Listar Todos Los Empleados" << endl;           //Funciona
    cout << "3.- Modificar Empleado" << endl;                  //Necesito Arreglar esto...
    cout << "4.- Acciones Especificas Del Empleado" << endl;  //Cambiar auto, dar de alta,baja listas de clientes, etc Todavio no esta
    cout << "5.- Eliminar Empleado" << endl;                   //Funciona
    cout << "6.- Salir" << endl;                               //Funciona
}

Cliente* leerCliente() {

    cout << "Ingrese Nombre(s) del Cliente: ";
    getline(cin >> ws, nombre);
    cout << "Ingrese Apellido(s) del Cliente: ";
    getline(cin >> ws, apellidos);
    cout << "Ingrese el DNI del Cliente: ";
    cin >> dni;
    cout << "Ingrese la Direccion del Cliente: ";
    getline(cin >> ws, direccion);
    cout << "Ingrese el Numero de Telefono del Cliente: ";
    cin >> telefono;
    return new Cliente(nombre, apellidos, dni, direccion, telefono);
}

Empleado* leerEmpleado() {

    cout << "Ingrese Nombre(s) del Empleado: ";
    getline(cin >> ws, nombre);
    cout << "Ingrese Apellido(s) del Empleado: ";
    getline(cin >> ws, apellidos);
    cout << "Ingrese el DNI del Empleado: ";
    cin >> dni;
    cout << "Ingrese la Direccion del Empleado: ";
    getline(cin >> ws, direccion);
    cout << "Ingrese el Numero de Telefono del Empleado: ";
    cin >> telefono;
    cout << "Ingrese el Tipo de Empleado(a,b o c):\n";
    cout << "a. Secretario\t b. Vendedor\t c. Jefe De Zona\n";
    cin >> tipo;
    tipo = tolower(tipo);
    if (tipo == 'a') {
        cout << "Ingrese Salario del Secretario:\n";
        cin >> salario;
        cout << "Ingrese numero de Anios Laborales del Secretario:\n";
        cin >> aniosLaboral;
        cout << "Ingrese Puesto del Secretario:\n";
        cout << "1. DIRECCION\t 2. ALTA_DIRECCION\t 3. GERENCIA\n";
        cin >> puesto;
        cout << "Ingrese numero de FAX del Secretario:\n";
        cin >> num_fax;

        return new Secretario(nombre, apellidos, dni, direccion, telefono, salario, aniosLaboral, puesto, num_fax);
    }
    if (tipo == 'b') {
        cout << "Ingrese Salario del Vendedor:\n";
        cin >> salario;
        cout << "Ingrese numero de Anios Laborales del Vendedor:\n";
        cin >> aniosLaboral;
        //Asignar CARRO
        cout << "Ingrese Telefono Movil del Vendedor:";
        cin >> telefonoMovil;
        cout << "Ingrese el Area de Venta del Vendedor:";
        cin >> areaVenta;

        return new Vendedor( nombre,  apellidos,  dni,  direccion,telefono,  salario,  aniosLaboral,carro, telefonoMovil,
             areaVenta,  porcentajeComisiones);
    }
    if (tipo == 'c') {

        //return new JefeDeZona( nombre,  apellidos, dni,  direccion,telefono, salario, aniosLaboral, despacho, secretario,  carro, vendedores);
    }

}
int main()
{
    //Lista Carros
    Coche* carro1 = new Coche("AXB358", "Honda", "Civic");
    Coche* carro2 = new Coche("QWE314", "Toyota", "Corolla");
    Coche* carro3 = new Coche("AFE324", "Nissan", "Versa");
    Coche* carro4 = new Coche("FDW324", "Audi", "A3 Sedan");
    Coche* carro5 = new Coche("GDW134", "BMW", "X3");
    Coche* carro6 = new Coche("CDA245", "Chevrolet", "Joy Sedan");
    Coche* carro7 = new Coche("AXB359", "Honda", "Civic");
    Coche* carro8 = new Coche("QWE315", "Toyota", "Corolla");
    Coche* carro9 = new Coche("AFE326", "Nissan", "Versa");
    Coche* carro10 = new Coche("FDW325", "Audi", "A3 Sedan");
    Coche* carro11 = new Coche("GDW135", "BMW", "X3");
    Coche* carro12 = new Coche("CDA246", "Chevrolet", "Joy Sedan");
    //Vector se pude instanciar asi, para que no hayan lineas de pushback
    vector<Coche*> carros{ carro1 , carro2, carro3, carro4, carro5,
    carro6,carro7, carro8, carro9, carro10, carro11, carro12 };

    //Vendedores
    Vendedor* vendedor1 = new Vendedor("Javier", "Irigoyen Matos", "48002717", "Av. Benavides 560", "4432345", 2200, 3, carro1, "993994620", 1, 5);
    Vendedor* vendedor2 = new Vendedor("Daniel", "qw we", "4356437", "Av. rq 525", "3456425", 2500, 1, carro3, "993994621", 3, 6);
    Vendedor* vendedor3 = new Vendedor("Francisco", "as as", "5468435", "Av. gs 567", "4567424", 2700, 4, carro2, "993994622", 2, 7);
    Vendedor* vendedor4 = new Vendedor("Shirley", "ew ew", "3789543", "Av. hd 356", "1111111", 2900, 2, carro5, "993994623", 1, 8);
    Vendedor* vendedor5 = new Vendedor("Lorena", "tr tr", "7890563", "Av. sh 853", "2222222", 3000, 4, carro6, "993994624", 5, 1);
    Vendedor* vendedor6 = new Vendedor("Andre", "er er", "2457896", "Av. wr 145", "3333333", 3200, 1, carro4, "993994625", 4, 2);
    Vendedor* vendedor7 = new Vendedor("Pier", "uy uy", "2468975", "Av. ut 986", "4444444", 3500, 3, carro7, "993994626", 5, 3);
    Vendedor* vendedor8 = new Vendedor("Victor", "qr qr", "4789033", "Av. jg 345", "5555555", 4000, 4, carro9, "993994627", 3, 4);
    empleados.push_back(vendedor1);
    empleados.push_back(vendedor2);
    empleados.push_back(vendedor3);
    empleados.push_back(vendedor4);
    empleados.push_back(vendedor5);
    empleados.push_back(vendedor6);

    //secretarios
    Secretario* secretario1 = new Secretario("SJavier","Irigoyen Matos", "33434332","av.dsa 324", "3234532", 1100,2,3,"313443524");
    Secretario* secretario2 = new Secretario("SDaniel", "qw we", "8887654", "av.dsa 324", "3234532", 1100, 2, 3, "313443524");
    Secretario* secretario3 = new Secretario("SFrancisco", "qw we", "33123322", "av.dsa 324", "3234532", 1100, 2, 3, "313443524");
    Secretario* secretario4 = new Secretario("SShirley", "qw we", "1233231", "av.dsa 324", "3234532", 1100, 2, 3, "313443524");
    Secretario* secretario5 = new Secretario("SLorena", "qw we", "31123232", "av.dsa 324", "3234532", 1100, 2, 3, "313443524");
    Secretario* secretario6 = new Secretario("SAndre", "qw we", "12334566", "av.dsa 324", "3234532", 1100, 2, 3, "313443524");
    Secretario* secretario7 = new Secretario("SPier", "qw we", "943453342", "av.dsa 324", "3234532", 1100, 2, 3, "313443524");
    Secretario* secretario8 = new Secretario("SVictor", "qw we", "42345643", "av.dsa 324", "3234532", 1100, 2, 3, "313443524");
    empleados.push_back(secretario1);
    empleados.push_back(secretario2);
    empleados.push_back(secretario3);
    empleados.push_back(secretario4);
    empleados.push_back(secretario5);
    empleados.push_back(secretario6);
    //jefe de zona

    int opcion;
    do {
        menu();
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        switch (opcion){
            {
        case 1:
        {
            Empleado* empleado = leerEmpleado();
            empleados.push_back(empleado);
        }break;

        case 2:
        {
            cout << "Listado de Empleados:" << endl;
            for (int i = 0; i < empleados.size(); i++)
            {
                empleados[i]->imprimir();
            }
        }break;

        case 3:
        {
            
            //Necesito Arreglar esto...
            string d;
            cout << "Ingrese el DNI del Empleado que desea modificar: " << endl;
            cin >> d;
            for (int i = 0; i < empleados.size(); i++)
            {
                if (empleados[i]->getDni() == d)
                {
                    Empleado* empleado = leerEmpleado();
                    empleados[i] = empleado;
                }
            }
        };

            }break;
        case 4:
        {

        }break;
        case 5:
        {
            string d;
            cout << "Ingrese el DNI del empleado que desea eliminar: " << endl;
            cin >> d;

            for (int i = 0; i < empleados.size(); i++)
            {
                if (empleados[i]->getDni() == d)
                {
                    empleados.erase(empleados.begin() + i);
                }
            }
        }break;

        default:
            break;
        }
    } while (opcion != 6);
    return 0;
}
