#include <iostream>
#include <string.h>
#include <stdlib.h>
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
// ===============================CLASE CELULARES
    class Celular : public Producto{     
    public:
        Celular(float pes,float prec,float vol);
    };

// ===============================CLASE Televisor
    class Televisor : public Producto{     
    public:
        Televisor(float pes,float prec,float vol);
    };
// ===============================CLASE Computador
    class Computador : public Producto{     
    public:
        Computador(float pes,float prec,float vol);
    };
// ==================================================CLASE Usuario
    class Usuario {     
    public:
        string nombre[numUsuarios];
        static int indice;
        static int ContadorElementosEnCarrito;
        Producto Carrito[numProductos];
        Usuario();
        bool logear();
        void addProductoCarrito(Producto product);
        void  printCarrito(Producto Carrito[]);
        void limpiarCarrito(Producto Carrito[]);
    };



