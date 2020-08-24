#include "GestionPro.cpp"

// ====================================================================== Programa principal  ===============================================

int main () 
{
    // system("clear");
    // CREACION DE OBJETOS 
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
            // system("clear");
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