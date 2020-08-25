#include "GestionProductos.h"

// ==================================================CLASE PRODUCTO
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
    Celular::Celular(float pes,float prec,float vol):Producto( pes, prec, vol){
        string marcas[5] = { "Xiaomi", "Samsung",  "iPhone", "LG","Sony" };
        for (int i = 0; i < 5; i++)
        {
         tipo[i] = marcas[i];
        }
    }
// ===============================CLASE Televisor
    Televisor::Televisor(float pes,float prec,float vol):Producto( pes, prec, vol){
        string marcas[5] = { "AOC", "Samsung",  "Haier", "LG","Sony" };
        for (int i = 0; i < 5; i++)
        {
         tipo[i] = marcas[i];
        }
    }
// ===============================CLASE Computador
    Computador::Computador(float pes,float prec,float vol):Producto( pes, prec, vol){
        string marcas[5] = { "Xiaomi", "Apple",  "Acer", "ASUS","GIGABYTE" };
        for (int i = 0; i < 5; i++)
        {
         tipo[i] = marcas[i];
        }
    }
// ==================================================CLASE Usuario
    Usuario::Usuario(){

    }
    Usuario::Usuario(char *new_nom){
        nombre[0] = *new_nom;

    }

    int Usuario::ContadorElementosEnCarrito= 0;
    int Usuario::indice= 0;

    bool Usuario::logear(){
            string login;
            Usuario user;
            bool resultado = false;
            cout <<"Ingrese Nombre de usuario : ";
            cin >> login;
            // for (int i = 0; i < numUsuarios; i++)
            // {
                if (login == user.nombre) {
                    cout <<"Usuario Extitoso : ";
                    resultado = true;
                    return resultado;
                }
                
            // }
            if (resultado == false)
            {
                    cout <<"Usuario Incorrecto : ";
            }
            
     
        return resultado;
    };

    void Usuario::regisLogin(Usuario user){
        
    }
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
    void    Usuario::limpiarC(Producto Carrito[]){
        for (int i = 0; i < ContadorElementosEnCarrito; i++){
            Producto vacio;
            Carrito[i]= vacio;
        }
        ContadorElementosEnCarrito= 0;
        indice = 0;
    };
    string Usuario::getNombre() {
        return this->nombre;
    }

    void Usuario::setNombre(string nombre) {
        this->nombre = nombre;
    }
    string Usuario::registrarUsuario( ){
        string Nom_user;
        cout << "Ingrese Usuario: "<<endl;
        cin >> Nom_user;

        return Nom_user;
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
        cout<< "Selecciono "<<productos[0].tipo[--opcion]<<endl;
		return opcion;
    }
    // Menu de compras 
    int  menuCompras(){
        // system("clear");
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

