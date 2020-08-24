#include <iostream>
#include <string.h>
#include <stdlib.h>
#include<cstdio>

using namespace std; 
// ====================================================================== VAR GLOBALES ==========================================
    #define numUsuarios 5  //Indica la cantidad de usuarios que quieres tener 
// ====================================================================== CLASES ===============================================

// ==================================================CLASE PRODUCTO
    class Producto {     
    public:
        float peso;
        float precio;
        float volumen;
        string tipo[5] ;
        Producto();
        Producto(float pes,float prec,float vol);
        //GETTERS  
        float getPeso();
        float getPrecio();
        float getVolumen();
        void  setPeso(float peso);
        void  setPrecio(float precio);
        void  setVolumen(float volumen);
        void  printProducto();
       
    };
    Producto::Producto(){   };
    Producto::Producto(float pes,float prec,float vol){
        peso = pes;
        precio = prec;
        volumen = vol;
        for (int i = 0; i < 5; i++)
        {
         tipo[i] = "0";
        }
    }

    // Getters y setters 
    
        float Producto::getPeso() {
        	return this->peso;
        }
        void Producto::setPeso(float peso) {
        	this->peso = peso;
        }
        float Producto::getPrecio() {
        	return this->precio;
        }
        void Producto::setPrecio(float precio) {
        	this->precio = precio;
        }
        float Producto::getVolumen() {
        	return this->volumen;
        }
        void Producto::setVolumen(float volumen) {
        	this->volumen = volumen;
        }
    void Producto::printProducto(){
        cout << "Peso: "<<getPeso()<<"Precio: "<<getPrecio()<<"volumen: "<<getVolumen()<<endl;
    }
// ===============================CLASE CELULARES
    class Celular : public Producto{     
    public:
        Celular(float pes,float prec,float vol);
    };

    Celular::Celular(float pes,float prec,float vol):Producto( pes, prec, vol){
        string marcas[5] = { "Xiaomi", "Samsung",  "iPhone", "LG","Sony" };
        for (int i = 0; i < 5; i++)
        {
         tipo[i] = marcas[i];
        }
    }
// ===============================CLASE Televisor
    class Televisor : public Producto{     
    public:
        Televisor(float pes,float prec,float vol);
    };

    Televisor::Televisor(float pes,float prec,float vol):Producto( pes, prec, vol){
        string marcas[5] = { "AOC", "Samsung",  "Haier", "LG","Sony" };
        for (int i = 0; i < 5; i++)
        {
         tipo[i] = marcas[i];
        }
    }
// ===============================CLASE Computador
    class Computador : public Producto{     
    public:
        Computador(float pes,float prec,float vol);
    };

    Computador::Computador(float pes,float prec,float vol):Producto( pes, prec, vol){
        string marcas[5] = { "Xiaomi", "Apple",  "Acer", "ASUS","GIGABYTE" };
        for (int i = 0; i < 5; i++)
        {
         tipo[i] = marcas[i];
        }
    }
// ==================================================CLASE Usuario
    class Usuario {     
    public:
        string nombre[numUsuarios];
        int indice;
        Producto Carrito[10];
        Usuario();
        bool logear();
        int  menuCompras();
        Producto getCarrito();
        void addProductoCarrito(Producto product, int indice);
        void  printCarrito(Producto Carrito[]);
    };

    Usuario::Usuario(){
        string marcas[5] = { "Carlos20", "Jesus97",  "Pablo3", "Maria2","Luisi" };
        indice=0;
        for (int i = 0; i < numUsuarios; i++)
        {
            nombre[i]= marcas[i];
        }
        
    }
    
    bool Usuario::logear(){
            string login;
            Usuario user;
            bool resultado = false;
            cout <<"Ingrese Nombre de usuario : ";
            cin >> login;
            for (int i = 0; i < numUsuarios; i++)
            {
                if (login == user.nombre[i]) {
                    cout <<"Usuario Extitoso : ";
                    resultado = true;
                    return resultado;
                }
                
            }
            if (resultado == false)
            {
                    cout <<"Usuario Incorrecto : ";
            }
            
     
        return resultado;
    };

    void Usuario::addProductoCarrito(Producto product, int indice){
        Carrito[indice]=product;
    }
    void Usuario::printCarrito(Producto Carrito[]){
        int i=0;
        Producto p1;
        p1 = Carrito[0];
        p1.printProducto();
        p1 = Carrito[1];
        p1.printProducto();

    //     if (Carrito[i]==NULL)
    //     {
    //         cout << "No hay nada" << endl;
    //     }else if(Carrito[i]!=NULL)
    //     {
    //         Carrito[i].printProducto();
    //     }
        
        
    }

// ====================================================================== FUNCIONES ===============================================
    // Menu de opciones para logearse 
    int  menuLogin(){
		int opcion;
		cout <<"\n\n";
		cout << "\t\t  ======  Sistema de Compras    ======"<<endl;
		cout << "\t\t  ======  Login  ====";
		cout <<"\n\n";
		cout << "\n \t 1. Ingresar usuario ";
		cout << "\n \t 2. Salir    ";
		cout << "\n\n";
		cout << "\t Seleccione su Opcion :=> ";
		cin>>opcion;
		return opcion;
    }
    // Menu de opciones gestionar carro 
    int  menuGestionCarro(){
		int opcion;
        cout <<"\n\n";
		cout << "\t\t  ======  Sistema de Compras    ======"<<endl;
		cout << "\t\t  ======  Usuario:"<<endl<<"    ======"<<endl;
		cout << "\t\t  ======  Gestion de Carrito  ====";
		cout <<"\n\n";
		cout << "\n \t 1. Seleccionar Producto ";
		cout << "\n \t 2. Ver Carrito    ";
		cout << "\n \t 3. Pagar Carrito    ";
		cout << "\n\n  4. Regresar      " ;
		cout << "\t Seleccione su Opcion :=> ";
		cin>>opcion;
        switch (opcion)
        {
        case 1:
            // menuCompras();
            break;
        
        case 2:
            // menuVerCarro();
            break;
        
        case 3:
            // menuVerCarro();
            break;
        
        default:
            break;
        }
        return opcion;
    }
    // Menu de compras-> marcas 
    int  menuComprasMarcas(){
		int opcion;

		cout <<"\n\n";
		cout << "\t\t  ======  Sistema de Compras    ======"<<endl;
		cout << "\t\t  \t======  Tienda  ====";
		cout << "\t\t  ======  Marcas disponibles  ====";
		cout <<"\n\n";
		cout << "\n \t 1. Televisor ";
		cout << "\n \t 2. Celular    ";
		cout << "\n \t 3. Computador     ";
		cout << "\n\n  4. Regresar  ";
		cout << "\t Seleccione su producto :=> ";
		cin>>opcion;
		return opcion;
    }

    // Menu de compras 
    int  menuCompras(){
		int opcion;

		cout <<"\n\n";
		cout << "\t\t  ======  Sistema de Compras    ======"<<endl;
		cout << "\t\t  \t======  Tienda  ====";
		cout << "\t\t  ======  Productos disponibles  ====";
		cout <<"\n\n";
		cout << "\n \t 1. Televisor ";
		cout << "\n \t 2. Celular    ";
		cout << "\n \t 3. Computador     ";
		cout << "\n\n  4. Regresar  ";
		cout << "\t Seleccione su producto :=> ";
		cin>>opcion;
		return opcion;
    }
    // Menu de compras 
    int  menuVerCarro(){
		int opcion;

		cout <<"\n\n";
		cout << "\t\t  ======  Sistema de Compras    ======"<<endl;
		cout << "\t\t  \t======  Tienda  ====";
		cout << "\t\t  ======  Carrito Actual  ====";
		cout << "\n\n";
		cout << "\n \t 1. arrayde carrito ";
		cout << "\n\n  4. Regresar  ";
		cout << "\t Seleccione su producto :=> ";
		cin>>opcion;
		return opcion;
    }


// ====================================================================== Programa principal  ===============================================

int main () 
{
    // CREACION DE OBJETOS 
    Usuario *u1 = new Usuario();
    // Variables necesarias
    int resultado;
    string nom_login;
    
    Producto p1 = Producto(60.5,50,10);
    Producto p2 = Producto(70.5,50000,1540);
    u1->addProductoCarrito(p1,0);
    u1->addProductoCarrito(p2,1);
    u1->printCarrito(u1->Carrito);
        while ((resultado = menuLogin() ) != 0)
        {
            system("clear");
            switch (resultado){

            // Ingresar usuario
            case 1:
                if (u1->logear()==true)     { //Usuario correcto 
                    menuGestionCarro();
                }else
                {
                    cout<<"Logeo incorrecto"<<endl;
                    break;
                }
                

            break;
            // Salir 
            case 2:
                cout << "Fin de programa  "<<endl;
                return 0;
            break;
            
            default:
                cout << "Ingrese opcion valida  "<<endl;
                break;
            }
        }
            return 0;
}