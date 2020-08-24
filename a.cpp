#include <iostream>
#include <string.h>
#include <stdlib.h>
#include<cstdio>

using namespace std; 
// ====================================================================== VAR GLOBALES ==========================================
    #define numUsuarios  5  //Indica la cantidad de usuarios que quieres tener 
    #define numProductos 50 //Tamano de tu carrito de compras 
    #define Cuentas_de_usuario { "Carlos20", "Jesus97",  "Pablo3", "Maria2","Luisi" } //Nombres de usuario que puede usar para logear
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
        cout << "\tPeso: "<<getPeso()<<"\tPrecio: "<<getPrecio()<<"\tVolumen: "<<getVolumen()<<endl;
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
        static int indice;
        static int ContadorElementosEnCarrito;
        Producto Carrito[numProductos];
        Usuario();
        bool logear();
        int  menuCompras();
        Producto getCarrito();
        void addProductoCarrito(Producto product);
        void  printCarrito(Producto Carrito[]);
        void limpiarCarrito(Producto Carrito[]);
    };

    Usuario::Usuario(){
        string marcas[5] = Cuentas_de_usuario;
        indice=0;
        for (int i = 0; i < numUsuarios; i++)
        {
            nombre[i]= marcas[i];
        }
    }
    int Usuario::ContadorElementosEnCarrito= 0;
    int Usuario::indice= 0;

    
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

    void Usuario::addProductoCarrito(Producto product){
        Carrito[indice]=product;
        ContadorElementosEnCarrito++;
        indice++;
    }
    void Usuario::printCarrito(Producto Carrito[]){
        cout << "\t\t  ======  Sistema de Compras    ======"<<endl;
		cout << "\t\t  ======  Usuario Logeado       ======"<<endl;
		cout << "\t\t  ======  Gestion de Carrito    ===="<<endl;
		cout << "\t\t  ======  Ver Carrito Actual  ====";
		cout << "\n\n";
        cout <<"=== Carrito de compras Actual"<<endl;
        cout << "Tiene " <<ContadorElementosEnCarrito<<" Elementos cargados"<<endl;
        if (ContadorElementosEnCarrito==0)
        {
        cout << "Carrito Vacio" << endl;
        }else{
            for (int i = 0; i < ContadorElementosEnCarrito; i++)
            {
                
                Producto p1;
                p1 = Carrito[i];
                if (p1.getPeso()==0)
                {

                }else       {                    
                    cout <<i+1<<"- ";
                    p1.printProducto();   
                }
                
                
            }

        }

    }

    void Usuario::limpiarCarrito(Producto Carrito[]){
        for (int i = 0; i < ContadorElementosEnCarrito; i++){
            Producto vacio;
            Carrito[i]= vacio;
        }
        ContadorElementosEnCarrito= 0;
        indice = 0;
        cout << "Gracias por comprar :)"<<endl;
        cout << "Carrito vacio"<<endl;
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
    
       // Menu de compras-> marcas 
    int  menuComprasMarcas(Producto productos[]){
		int opcion;
		cout <<"\n\n";
		cout << "\t\t  ======  Sistema de Compras    ======"<<endl;
		cout << "\t\t  \t======  Tienda  ====";
		cout << "\t\t  ======  Marcas disponibles  ====";
		cout <<"\n\n";
        for (int i = 0; i < 5; i++)
        {
		    cout << "\n \t "<<i+1<<". "<<productos[i].tipo[i]<<endl;   
        }        
		cout << "\n\n  6. Regresar  "<<endl;
		cout << "\t Seleccione su producto :=> ";
		cin>>opcion;
        cout<< "Selecciono "<<productos[opcion].tipo[opcion]<<endl;
		return opcion;
    }
    // Menu de compras 
    int  menuCompras(){
        system("clear");
		int opcion;

		cout <<"\n\n";
		cout << "\t\t  ======  Sistema de Compras    ======"<<endl;
		cout << "\t\t  ======  Usuario Logeado       ======"<<endl;
		cout << "\t\t  ======  Gestion de Carrito    ====="<<endl;
		cout << "\t\t  ======  Seleccionar Producto  ====";
		cout <<"\n\n";
		cout << "\n \t 1. Televisor ";
		cout << "\n \t 2. Celular    ";
		cout << "\n \t 3. Computador     ";
		cout << "\n \t 0. Regresar  ";
		cout << "\n \t\t Seleccione su producto :=> ";
		cin>>opcion;
		cout << "\n \t\t === Elemento agregado al carro === ";
		return opcion;
    }
    // Menu de compras 
    int  menuVerCarro(){
		int opcion=4;
		cout <<"\n\n";

		return opcion;
    }
    // Menu de compras 
    int  menuPagar(){
		int opcion=5;
		cout <<"\n\n";

		return opcion;
    }
    // Menu de opciones gestionar carro 
    int  menuGestionCarro(){
		int opcion;
        cout <<"\n\n";
		cout << "\t\t  ======  Sistema de Compras    ======"<<endl;
		cout << "\t\t  ======  Usuario Logeado       ======"<<endl;
		cout << "\t\t  ======  Gestion de Carrito    =====";
		cout <<"\n\n";
		cout << "\n \t 1. Seleccionar Producto ";
		cout << "\n \t 2. Ver Carrito    ";
		cout << "\n \t 3. Pagar Carrito    ";
		cout << "\n \t 0. Regresar      "<<endl;
		cout << "\n \t\t Seleccione su Opcion :=> ";
		cin>>opcion;
        switch (opcion)
        {
        case 1:
            return menuCompras();
            break;
        
        case 2:
            return menuVerCarro();
            break;
        
        case 3:
            return menuPagar();
            break;
        
        default:
            break;
        }
        return opcion;
    }
 

// ====================================================================== Programa principal  ===============================================

int main () 
{
    system("clear");
    // CREACION DE OBJETOS 
    Usuario users;
    Usuario *u1 = new Usuario();            //Usuarios Principal
    // Celulares
    Celular cel1   =    Celular(80,200,40);
    Celular cel2   =    Celular(70,300,30);
    Celular cel3   =    Celular(60,100,60);
    Celular cel4   =    Celular(50,400,20);
    Celular cel5   =    Celular(40,900,10);
    Celular celus[5] = {cel1,cel2,cel3,cel4,cel5};
    // Televisores
    Televisor tv1  =  Televisor(100,200,200);
    Televisor tv2  =  Televisor(100,250,300);
    Televisor tv3  =  Televisor(100,300,400);
    Televisor tv4  =  Televisor(100,400,600);
    Televisor tv5  =  Televisor(100,500,1000);
    Televisor teves[5] = {tv1,tv2,tv3,tv4,tv5};
    // Computadores
    Computador pc1 = Computador(220,300,500);
    Computador pc2 = Computador(200,400,400);
    Computador pc3 = Computador(150,600,300);
    Computador pc4 = Computador(110,800,200);
    Computador pc5 = Computador(100,1000,100);
    Computador compus[5] = {pc1,pc2,pc3,pc4,pc5};
    // Variables necesarias
    int resultado,numProducto;
    float precioTotal=0;
    string nom_login;
    char letra;
    Producto p1 = Producto(60.5,50,10);
    Producto p2 = Producto(70.5,50000,1540);
    // u1->addProductoCarrito(pc1,0);
    // u1->addProductoCarrito(p2,1);
    // u1->printCarrito(u1->Carrito);
        while ((resultado = menuLogin() ) != 0)
        {
            system("clear");
            switch (resultado){

            // Ingresar usuario
            case 1:
                if (u1->logear()==true)     { //Usuario correcto 
                    while ((resultado )!=0)
                    {
                        switch (resultado= menuGestionCarro())
                        {
                            // ======================================Comprar T E L E V I S O R 
                            case 1: //Resultado de 1-3 
                            numProducto = menuComprasMarcas(teves);
                                switch (numProducto)
                                {
                                case 1:
                                    u1->addProductoCarrito(tv1)   ;
                                    precioTotal+= tv1.getPrecio();                                
                                    break;
                                case 2:
                                    u1->addProductoCarrito(tv2)   ;
                                    precioTotal+= tv2.getPrecio();                                
                                    break;
                                case 3:
                                    u1->addProductoCarrito(tv3)   ;
                                    precioTotal+= tv3.getPrecio();                                
                                    break;
                                case 4:
                                    u1->addProductoCarrito(tv4)   ;
                                    precioTotal+= tv4.getPrecio();                                
                                    break;
                                case 5:
                                    u1->addProductoCarrito(tv5)   ;
                                    precioTotal+= tv5.getPrecio();                                
                                    break;
                                default:
                                    break;
                                }
                            break;
                        
                            // ======================================Comprar C E L U L A L E R E S 
                            case 2: //Resultado de 1-3 
                            numProducto = menuComprasMarcas(celus);
                                switch (numProducto)
                                {
                                case 1:
                                    u1->addProductoCarrito(cel1)   ;
                                    precioTotal+= cel1.getPrecio();                                
                                    break;
                                case 2:
                                    u1->addProductoCarrito(cel2)   ;
                                    precioTotal+= cel2.getPrecio();                                
                                    break;
                                case 3:
                                    u1->addProductoCarrito(cel3)   ;
                                    precioTotal+= cel3.getPrecio();                                
                                    break;
                                case 4:
                                    u1->addProductoCarrito(cel4)   ;
                                    precioTotal+= cel4.getPrecio();                                
                                    break;
                                case 5:
                                    u1->addProductoCarrito(cel5)   ;
                                    precioTotal+= cel5.getPrecio();                                
                                    break;
                                default:
                                    break;
                                }
                            break;

                            // ======================================Comprar C O M P U T A D O R A S
                            case 3: //Resultado de 1-3 
                            numProducto = menuComprasMarcas(compus);
                                switch (numProducto)
                                {
                                case 1:
                                    u1->addProductoCarrito(pc1)   ;
                                    precioTotal+= pc1.getPrecio();                                
                                    break;
                                case 2:
                                    u1->addProductoCarrito(pc2)   ;
                                    precioTotal+= pc2.getPrecio();                                
                                    break;
                                case 3:
                                    u1->addProductoCarrito(pc3)   ;
                                    precioTotal+= pc3.getPrecio();                                
                                    break;
                                case 4:
                                    u1->addProductoCarrito(pc4)   ;
                                    precioTotal+= pc4.getPrecio();                                
                                    break;
                                case 5:
                                    u1->addProductoCarrito(pc5)   ;
                                    precioTotal+= pc5.getPrecio();                                
                                    break;
                                default:
                                    break;
                                }
                            break;
                            // ======================================CASO VER CARRITO

                            case 4: //Resultado de 4 opc 2-> Seleccione ver carrio 
                                u1->printCarrito(u1->Carrito);
                            break;
                            // ======================================CASO PAGAR CARRITO 

                            case 5: //Resultado de 5 opc 3-> Seleccione Pagar carrio 
                                u1->printCarrito(u1->Carrito);
                                cout << "Precio total es de: "<<precioTotal<<endl;
                                cout << "Pulse cualquier tecla para pagar..."<<endl;
                                cin >> letra;
                                u1->limpiarCarrito(u1->Carrito);

                            break;
                            
                            default:
                                break;
                            }
                    }
                     
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