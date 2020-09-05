#include <iostream>

using namespace std;
struct Producto
{
    int id;
    string nombre;
    string descripcion;
    int valorunitario;
    int cantidadeninventario;

};
struct Comprador
{
    string nombredeusuario;
    string contrasena;
    string nombre;
    string apellido;
    string cedula;
    string telefono;
    Producto carritodecompras[10];
    int historial[10][10];
    int nventas=0;
    int cantproductos=0;
    int total=0;
};
struct Administrador
{
    string nombredeusuario;
    string contrasena;
    string nombre;
    string apellido;
    string cedula;
    string telefono;
};


void Inicializacion();
void Bienvenida();
void MenuPrincipal();

bool LoginAdmin();
void MenuAdmin();
void ConsultarProductos();
void AgregarComprador();
void AgregarProducto();
void ModificarProducto();
void EliminarProducto();
void GenerarHistorialParaUsuario();
void GenerarHistorialParaEmpresa();

bool LoginComprador();
void MenuComprador();
void VisualizarPorID();
void VisualizarPorNombre();
void VisualizarPorValor();
void AgregarAlCarrito();
void ImprimirCarrito();
void ModificarCarrito();
void EliminarDelCarrito();
void ConfirmarCarrito();
void GenerarHistorialComprador();


Administrador administradores[2];
Comprador compradores[10];
Producto productos[10];

int i,j,k,ncompradores=2,nproductos=5;
string usuarioiniciado;

int main()
{
    Inicializacion();
    Bienvenida();
    MenuPrincipal();
}

void MenuPrincipal()
{
    int opcion;
    while(opcion!=0)
    {
        cout <<"INICIO DE SESION "<<endl;
        cout <<"1. Ingresar como Administrador"<<endl;
        cout <<"2. Ingresar como Comprador"<<endl;
        cout <<"0. Salir"<<endl;
        cout <<"Digite una opcion: ";
        cin >> opcion;
        cout <<endl;
        switch(opcion)
        {
        case 1:
            if(LoginAdmin()==true)
                MenuAdmin();
            else
                cout <<"Usuario o contrasena no valido, digite otro por favor..."<<endl;
            break;
        case 2:
            if(LoginComprador()==true)
                MenuComprador();
            else
                cout <<"Usuario o contrasena no valido, digite otro por favor..."<<endl;
            break;
        case 0:
            cout <<"Hasta Luego....";
            break;
        default:
            cout <<"Opcion no disponible, seleccione otra por favor..."<<endl;
        }
        cout <<endl;
    }

}
bool LoginAdmin()
{
    string nombredeusuario, contrasena;
    cout <<"INICIO DE SESION COMO ADMINISTRADOR " <<endl;
    cout <<"Digite su Nombre de Usuario: ";
    cin>>nombredeusuario;
    cout <<"Digite su Contrasena: ";
    cin>>contrasena;
    for(i=0; i<1; i++)
        if(administradores[i].nombredeusuario==nombredeusuario)
            if(administradores[i].contrasena==contrasena)
            {
                usuarioiniciado = administradores[i].nombredeusuario;
                return true;
            }

    return false;
}

void MenuAdmin()
{
    int opcion;
    while(opcion!=0)
    {
        cout <<endl<<"SESION INICIADA COMO: "<<usuarioiniciado<<endl;
        cout <<"MENU ADMINISTRADOR"<<endl;
        cout << endl;
        cout <<"Que desea hacer?"<<endl;
        cout <<"1. Ingresar informacion de nuevo comprador"<<endl;
        cout <<"2. Consultar Productos de la base de datos"<<endl;
        cout <<"3. Agregar Producto a la base de datos"<<endl;
        cout <<"4. Modificar Producto de la base de datos"<<endl;
        cout <<"5. Eliminar Producto de la base de datos"<<endl;
        cout <<"6. Generar Historial de Ventas de un Usuario"<<endl;
        cout <<"7. Generar Historial de Ventas de la Empresa"<<endl;
        cout <<"0. Cerrar Sesion"<<endl;
        cout <<"Digite una opcion: ";
        cin >> opcion;
        cout <<endl;
        switch(opcion)
        {
        case 1:
            AgregarComprador();
            break;
        case 2:
            ConsultarProductos();
            break;
        case 3:
            AgregarProducto();
            break;
        case 4:
            ModificarProducto();
            break;
        case 5:
            EliminarProducto();
            break;
        case 6:
            GenerarHistorialParaUsuario();
            break;
        case 7:
            GenerarHistorialParaEmpresa();
            break;
        case 0:
            cout <<"Cerrando Sesion..."<<endl;
            break;
        default:
            cout<<"Opcion no disponible, intente nuevamente por favor..."<<endl;
        }
        cout <<endl;
    }

}
void AgregarComprador()
{
    Comprador nuevo;
    cout <<endl<<"NUEVO COMPRADOR "<<endl;
    cout <<"Digite Nombre: ";
    cin >>nuevo.nombre;
    cout <<"Digite Apellido: ";
    cin >>nuevo.apellido;
    cout <<"Digite Cedula: ";
    cin >>nuevo.cedula;
    cout <<"Digite Telefono: ";
    cin >>nuevo.telefono;
    cout <<"Digite Nombre de Usuario: ";
    cin >>nuevo.nombredeusuario;
    cout <<"Digite Contrasena: ";
    cin >>nuevo.contrasena;

    compradores[ncompradores] = nuevo;
    ncompradores++;
    cout <<"COMPRADOR ANADIDO CORRECTAMENTE..."<<endl;
}
void ConsultarProductos()
{
    int t;
    cout <<endl<<"PRODUCTOS EXISTENTES"<<endl;
    cout <<"************************************************************************************************************************"<<endl;
    for(t=0; t<nproductos; t++)
    {
        cout <<endl;
        cout <<"Producto numero: "<<t+1<<endl;
        cout <<"Nombre: "<<productos[t].nombre<<endl;
        cout <<"Descripcion: "<<productos[t].descripcion<<endl;
        cout <<"ID: "<<productos[t].id<<endl;
        cout <<"Valor unitario (Si es Material de construccion se lee el precio por libra): "<<productos[t].valorunitario<<"$"<<endl;
        cout <<"Cantidad en Inventario(Si es Material de construccion se lee en libras): "<<productos[t].cantidadeninventario<<endl;
    }
    cout <<"************************************************************************************************************************"<<endl;
}
void AgregarProducto()
{
    Producto nuevo;
    cout <<endl<<"NUEVO PRODUCTO "<<endl;
    cout <<"Digite Nombre: ";
    cin >>nuevo.nombre;
    cout <<"Digite Descripcion (Escriba_palabras_de_esta_manera): ";
    cin >>nuevo.descripcion;
    cout <<"Digite ID: ";
    cin >>nuevo.id;
    cout <<"Digite Valor Unitario (Si es Material de construccion se lee el precio por libra): ";
    cin >>nuevo.valorunitario;
    cout <<"Digite Cantidad en Inventario: ";
    cin >>nuevo.cantidadeninventario;

    productos[nproductos] = nuevo;
    nproductos++;

    cout <<"PRODUCTO ANADIDO CORRECTAMENTE..."<<endl<<endl;
}
void ModificarProducto()
{
    bool existe=false;
    string informacion;
    ConsultarProductos();
    cout <<"MODIFICAR PRODUCTO"<<endl<<endl;
    cout <<"Digite el Nombre del Producto que desea modificar: ";
    cin >> informacion;
    for(i=0; i<nproductos; i++)
    {
        if(productos[i].nombre==informacion)
        {
            existe = true;
            cout <<"Digite el nuevo Nombre del Producto: ";
            cin >> productos[i].nombre;
            cout <<"Digite Descripcion (Escriba_palabras_de_esta_manera): ";
            cin >> productos[i].descripcion;
            cout <<"Digite ID: ";
            cin >> productos[i].id;
            cout <<"Digite Valor Unitario: ";
            cin >> productos[i].valorunitario;
            cout <<"Digite Cantidad en Inventario: ";
            cin >> productos[i].cantidadeninventario;
        }
    }
    if(existe==false)
        cout <<"Producto inexistente, intente nuevamente por favor...."<<endl;
    else
        cout <<"PRODUCTO ACTUALIZADO CORRECTAMENTE...."<<endl;

}
void EliminarProducto()
{
    bool existe=false;
    string informacion;
    ConsultarProductos();
    cout <<"ELIMINAR PRODUCTO"<<endl<<endl;
    cout <<"Digite el Nombre del Producto que desea eliminar: ";
    cin >> informacion;
    for(i=0; i<nproductos; i++)
    {
        if(productos[i].nombre==informacion)
        {
            existe = true;
            for(j=i; j<nproductos-1; j++)
                productos[j] = productos[j+1];
        }
    }
    if(existe==false)
        cout <<"Producto inexistente, intente nuevamente por favor...."<<endl;
    else
    {
        cout <<"PRODUCTO ELIMINADO CORRECTAMENTE...."<<endl;
        nproductos--;
    }
}
void GenerarHistorialParaUsuario()
{
    bool existe=false;
    cout<<"GENERAR HISTORIAL DE VENTAS PARA USUARIO"<<endl;
    string nombredeusuario;
    cout <<"Digite el Nombre de Usuario del Comprador del que desea generar su Historial de Ventas: ";
    cin >> nombredeusuario;

    for(i=0; i<ncompradores; i++)
    {
        if(nombredeusuario==compradores[i].nombredeusuario)
        {
            existe = true;
            cout <<"USUARIO: " <<nombredeusuario <<endl;
            for(j=0; j<nproductos; j++)
            {
                for(k=0; k<compradores[i].nventas+1; k++)
                    cout<<compradores[i].historial[j][k]<<"    ";

                cout<<endl;
            }
            cout <<endl<<"Filas: Cantidad de producto vendido"<<endl;
            cout <<"Columnas: Numero de venta"<<endl;
        }
    }
    if(existe==false)
        cout <<"Usuario inexistente, intente nuevamente por favor..."<<endl;

}
void GenerarHistorialParaEmpresa()
{
    cout <<"GENERAR HISTORIAL DE VENTA DE LA EMPRESA"<<endl<<endl;

    int f,c,suma=0;
    int matriz[100][10];

    for(i=0; i<nproductos; i++)
        matriz[i][0] = productos[i].id;      //se ubican los ids de los productos en la primera columna

    for(f=0; f<nproductos; f++)
        for(c=1; c<10; c++)          //se inicializa toda la matriz desde la columna 1 en 0
            matriz[f][c]=0;

    for(i=0; i<ncompradores; i++)
        for(f=0; f<nproductos; f++)
            for(c=1; c<10; c++)      //a la matriz se le suman todos los hhistoriales de venta de los compradores
                matriz[f][c]+=compradores[i].historial[f][c];

    for(f=0; f<nproductos; f++)
    {
        for(c=0; c<10; c++)
        {
            cout <<matriz[f][c]<<" ";
        }
        cout << endl;
    }
    cout <<endl<<"Filas: Cantidad de producto vendido"<<endl;
    cout <<"Columnas: Numero de venta"<<endl;






}

bool LoginComprador()
{
    string nombredeusuario, contrasena;
    cout <<"INICIO DE SESION COMO COMPRADOR " <<endl;
    cout <<"Digite su Nombre de Usuario: "<<endl;
    cin>>nombredeusuario;
    cout <<"Digite su Contrasena: "<<endl;
    cin>>contrasena;
    for(i=0; i<ncompradores; i++)
        if(compradores[i].nombredeusuario==nombredeusuario)
            if(compradores[i].contrasena==contrasena)
            {
                usuarioiniciado = compradores[i].nombredeusuario;
                return true;
            }

    return false;
}
void MenuComprador()
{
    int opcion;
    while(opcion!=0)
    {
        cout <<endl<<"SESION INICIADA COMO: "<<usuarioiniciado<<endl;
        cout <<"MENU COMPRADOR"<<endl;
        cout <<"Que desea hacer?"<<endl;
        cout <<"1. Visualizar Productos organizados por ID"<<endl;
        cout <<"2. Visualizar Productos organizados por Nombre"<<endl;
        cout <<"3. Visualizar Productos organizados por Valor"<<endl;
        cout <<"4. Visualizar Carrito de Compras"<<endl;
        cout <<"5. Agregar Producto al Carrito de Compras"<<endl;
        cout <<"6. Modificar Carrito de Compras"<<endl;
        cout <<"7. Eliminar Producto del Carrito de Compras"<<endl;
        cout <<"8. Confirmar Carrito"<<endl;
        cout <<"9. Generar Historial de venta"<<endl;
        cout <<"0. Cerrar Sesion"<<endl;
        cout <<"Digite una opcion: ";
        cin >> opcion;
        cout <<endl;
        switch(opcion)
        {
        case 1:
            VisualizarPorID();
            break;
        case 2:
            VisualizarPorNombre();
            break;
        case 3:
            VisualizarPorValor();
            break;
        case 4:
            ImprimirCarrito();
            break;
        case 5:
            AgregarAlCarrito();
            break;
        case 6:
            ModificarCarrito();
            break;
        case 7:
            EliminarDelCarrito();
            break;
        case 8:
            ConfirmarCarrito();
            break;
        case 9:
            GenerarHistorialComprador();
            break;
        case 0:
            cout <<"Cerrando Sesion.."<<endl;
            break;
        default: cout<<"Opcion no disponible, intente nuevamente por favor..."<<endl;
        }
        cout <<endl;
    }
}
void VisualizarPorID()
{
    int id[10], aux;
    cout <<"VISUALIZAR PRODUCTOS POR ID"<<endl;
    for(i=0; i<nproductos; i++)
        id[i] = productos[i].id;

    for(i=0; i<nproductos; i++)
        for(j=0; j>nproductos-1; j++)
            if(id[j]<id[j+1])                 //se ordena de menor a mayor el vector
            {
                aux = id[j];
                id[j] = id[j+1];
                id[j+1] = aux;
            }
    cout <<"************************************************************************************************************************"<<endl;
    for(i=0; i<nproductos; i++)
    {
        for(j=0; j<nproductos; j++)
        {
            if(id[i]==productos[j].id)
            {
                cout <<endl;
                cout <<"Nombre: "<<productos[j].nombre<<endl;
                cout <<"Descripcion: "<<productos[j].descripcion<<endl;
                cout <<"ID: "<<productos[j].id<<endl;
                cout <<"Valor unitario (Si es Material de construccion se lee el precio por libra): "<<productos[j].valorunitario<<"$"<<endl;
                cout <<"Cantidad en Inventario(Si es Material de construccion se lee en libras): "<<productos[j].cantidadeninventario<<endl;
            }
        }
    }
    cout <<"************************************************************************************************************************"<<endl;
}
void VisualizarPorNombre()
{
    string nombres[10], aux;
    cout <<"VISUALIZAR PRODUCTOS POR NOMBRE"<<endl;
    for(i=0; i<nproductos; i++)
        nombres[i] = productos[i].nombre;

    for(i=0; i<nproductos; i++)
        for(j=0; j<nproductos-1; j++)
            if(nombres[j]>nombres[j+1])                 //se ordena de menor a mayor el vector
            {
                aux = nombres[j];
                nombres[j] = nombres[j+1];
                nombres[j+1] = aux;
            }
    cout <<"************************************************************************************************************************"<<endl;
    for(i=0; i<nproductos; i++)
    {
        for(j=0; j<nproductos; j++)
        {
            if(nombres[i]==productos[j].nombre)
            {
                cout <<endl;
                cout <<"Nombre: "<<productos[j].nombre<<endl;
                cout <<"Descripcion: "<<productos[j].descripcion<<endl;
                cout <<"ID: "<<productos[j].id<<endl;
                cout <<"Valor unitario (Si es Material de construccion se lee el precio por libra): "<<productos[j].valorunitario<<"$"<<endl;
                cout <<"Cantidad en Inventario(Si es Material de construccion se lee en libras): "<<productos[j].cantidadeninventario<<endl;
            }
        }
    }
    cout <<"************************************************************************************************************************"<<endl;
}

void VisualizarPorValor()
{
    int valores[10], aux;
    cout <<"VISUALIZAR PRODUCTOS POR VALOR UNITARIO"<<endl;
    for(i=0; i<nproductos; i++)
        valores[i] = productos[i].valorunitario;

    for(i=0; i<nproductos; i++)
        for(j=0; j<nproductos-1; j++)
            if(valores[j]>valores[j+1])                 //se ordena de menor a mayor el vector
            {
                aux = valores[j];
                valores[j] = valores[j+1];
                valores[j+1] = aux;
            }
    cout <<"************************************************************************************************************************"<<endl;
    for(i=0; i<nproductos; i++)
    {
        for(j=0; j<nproductos; j++)
        {
            if(valores[i]==productos[j].valorunitario)
            {
                cout <<endl;
                cout <<"Nombre: "<<productos[j].nombre<<endl;
                cout <<"Descripcion: "<<productos[j].descripcion<<endl;
                cout <<"ID: "<<productos[j].id<<endl;
                cout <<"Valor unitario (Si es Material de construccion se lee el precio por libra): "<<productos[j].valorunitario<<"$"<<endl;
                cout <<"Cantidad en Inventario(Si es Material de construccion se lee en libras): "<<productos[j].cantidadeninventario<<endl;
            }
        }
    }
    cout <<"************************************************************************************************************************"<<endl;
}
void AgregarAlCarrito()
{
    int id,cantidad,n;
    float total;
    bool existe=false;
    cout <<"AGREGAR PRODUCTO AL CARRITO"<<endl;
    for(i=0; i<ncompradores; i++)
    {
        if(usuarioiniciado==compradores[i].nombredeusuario)
        {
            ConsultarProductos();
            cout<<"Digite el ID del producto que desea anadir al carrito: ";
            cin >> id;
            for(j=0; j<nproductos; j++)
            {
                if(id == productos[j].id)
                {
                    n = compradores[i].cantproductos;
                    existe = true;
                    cout <<"Digite la cantidad del producto que desea anadir al carrito: ";
                    cin >> cantidad;
                    if(cantidad<productos[j].cantidadeninventario)
                    {
                        total = cantidad * productos[j].valorunitario;
                        compradores[i].carritodecompras[n] = productos[j];
                        compradores[i].carritodecompras[n].cantidadeninventario = cantidad;
                        compradores[i].carritodecompras[n].valorunitario = total;
                        compradores[i].total+=total;
                        compradores[i].cantproductos++;
                        cout <<"PRODUCTO ANADIDO AL CARRITO CORRECTAMENTE..."<<endl;
                    }
                    else
                        cout<<"Cantidad no valida, intente nuevamente por favor...."<<endl;
                }
            }
            if(existe == false)
                cout<<"Producto inexistente, intente nuevamente por favor..."<<endl;
        }
    }
}
void ModificarCarrito()
{
    int id,cantidad;
    float total;
    bool existe=false;
    cout <<"MODIFICAR CARRITO"<<endl;
    for(i=0; i<ncompradores; i++)
    {
        if(compradores[i].nombredeusuario==usuarioiniciado)
        {
            if(compradores[i].cantproductos!=0)
            {
                ImprimirCarrito();
                cout<<"Digite el ID del producto que desea editar del carrito: ";
                cin >> id;
                for(j=0; j<compradores[i].cantproductos; j++)
                {
                    if(id==compradores[i].carritodecompras[j].id)
                    {
                        existe = true;
                        for(k=0; k<nproductos; k++)
                        {
                            if(id==productos[k].id)
                            {
                                compradores[i].total-=compradores[i].carritodecompras[j].valorunitario;  //devuelve el dinero facturado
                                compradores[i].carritodecompras[j].cantidadeninventario=0;
                                compradores[i].carritodecompras[j].valorunitario=0;
                                cout <<"Digite la cantidad del producto que desea anadir al carrito: ";
                                cin >> cantidad;
                                if(cantidad<productos[k].cantidadeninventario)
                                {
                                    total = cantidad * productos[k].valorunitario;
                                    compradores[i].carritodecompras[j].cantidadeninventario=cantidad;      //se actualizan los datos
                                    compradores[i].carritodecompras[j].valorunitario = total;
                                    compradores[i].total+=total;
                                    cout<<"CARRITO ACTUALIZADO CORRECTAMENTE..."<<endl;
                                }
                                else
                                    cout<<"Cantidad no valida, intente nuevamente por favor..."<<endl;
                            }
                        }
                    }
                }
                if(existe==false)
                    cout<<"Producto inexistente en el carrito, intente nuevamente..."<<endl;
            }
            else
                cout<<"Opcion no valida, intente mas tarde por favor..."<<endl;
        }
    }
}
void EliminarDelCarrito()
{
    int id;
    bool existe=false;
    cout <<"ELIMINAR PRODUCTO DEL CARRITO"<<endl;
    for(i=0; i<ncompradores; i++)
    {
        if(usuarioiniciado==compradores[i].nombredeusuario)
        {
            if(compradores[i].cantproductos!=0)
            {
                ImprimirCarrito();
                cout<<"Digite el ID del producto que desea editar del carrito: ";
                cin >> id;
                for(j=0; j<compradores[i].cantproductos; j++)
                {
                    if(id==compradores[i].carritodecompras[j].id)
                    {
                        existe = true;
                        compradores[i].total-=compradores[i].carritodecompras[j].valorunitario;
                        for(k=j; k<compradores[i].cantproductos-1; k++)
                            compradores[i].carritodecompras[k]=compradores[i].carritodecompras[k+1];
                        compradores[i].cantproductos--;
                        cout<<"PRODUCTO ELIMINADO CORRECTAMENTE..."<<endl;
                    }
                }
                if(existe==false)
                    cout<<"Producto inexistente en el carrito, intente nuevamente..."<<endl;
            }
            else
                cout<<"Opcion no valida, intente mas tarde por favor..."<<endl;
        }

    }
}
void ConfirmarCarrito()
{
    int opcion,nventa;
    cout <<"CONFIRMAR CARRITO"<<endl;
    ImprimirCarrito();
    cout<<"Esta seguro de que desea adquirir su Carrito de Compras? (SI->1 NO->2): ";
    cin>>opcion;
    if(opcion==1)
    {
        for(i=0; i<ncompradores; i++)
            if(usuarioiniciado==compradores[i].nombredeusuario)
            {
                compradores[i].nventas++;
                for(j=0; j<compradores[i].cantproductos; j++)
                    for(k=0; k<nproductos; k++)
                        if(compradores[i].carritodecompras[j].id==productos[k].id)
                            productos[k].cantidadeninventario-=compradores[i].carritodecompras[j].cantidadeninventario;   //ACTUALIZA EL INVENTARIO
            }
        for(i=0; i<ncompradores; i++)
            if(usuarioiniciado==compradores[i].nombredeusuario)
                for(j=0; j<nproductos; j++)
                {
                    compradores[i].historial[j][0]=productos[j].id;       //INICIALIZACION DE LA MATRIZ CON LOS IDS EN LA PRIMERA COLUMNA
                    nventa=compradores[i].nventas;
                    compradores[i].historial[j][nventa]=0;         //INICIALIZACION DE LA MATRIZ EN CERO
                }

        for(i=0; i<ncompradores; i++)
        {
            if(usuarioiniciado==compradores[i].nombredeusuario)
                for(j=0; j<nproductos; j++)
                    for(k=0; k<compradores[i].cantproductos; k++)
                    {
                        nventa=compradores[i].nventas;
                        if(productos[j].id==compradores[i].carritodecompras[k].id)             //LLENA LA MATRIZ SI ENCUENTRA PRODUCTOS CON EL MISMO ID
                            compradores[i].historial[j][nventa] += compradores[i].carritodecompras[k].cantidadeninventario;
                    }
        }
        for(i=0; i<ncompradores; i++)
        {
            if(usuarioiniciado==compradores[i].nombredeusuario)
            {
                compradores[i].cantproductos=0;
                compradores[i].total=0;
            }
        }
        cout<<"GRACIAS POR SU COMPRA..."<<endl;
    }
    else if(opcion==2)
        cout <<"Vuelva mas tarde..."<<endl;
    else
        cout <<"Opcion no valida, intente nuevamente por favor..."<<endl;


}
void GenerarHistorialComprador()
{
    bool existe=false;
    cout<<"GENERAR HISTORIAL DE VENTAS "<<endl;
    for(i=0; i<ncompradores; i++)
    {
        if(usuarioiniciado==compradores[i].nombredeusuario)
        {
            existe = true;
            cout <<"USUARIO: "<<usuarioiniciado<<endl;
            for(j=0; j<nproductos; j++)
            {
                for(k=0; k<compradores[i].nventas+1; k++)
                    cout<<compradores[i].historial[j][k]<<"    ";

                cout<<endl;
            }

            cout <<endl<<"Filas: Cantidad de producto vendido"<<endl;
            cout <<"Columnas: Numero de venta"<<endl;
        }
    }
    if(existe==false)
        cout <<"Usuario inexistente, intente nuevamente por favor..."<<endl;
}




void ImprimirCarrito()
{
    int s,t;
    for(s=0; s<ncompradores; s++)
    {
        if(usuarioiniciado==compradores[s].nombredeusuario)
        {
            cout <<"CARRITO DE COMPRAS ACTUAL"<<endl;
            for(t=0; t<compradores[s].cantproductos; t++)
            {
                cout <<endl;
                cout <<"Nombre: "<<compradores[s].carritodecompras[t].nombre<<endl;
                cout <<"Descripcion: "<<compradores[s].carritodecompras[t].descripcion<<endl;
                cout <<"ID: "<<compradores[s].carritodecompras[t].id<<endl;
                cout <<"Valor Actual: "<<compradores[s].carritodecompras[t].valorunitario<<"$"<<endl;
                cout <<"Cantidad Actual(Si es Material de construccion se lee en libras): "<<compradores[s].carritodecompras[t].cantidadeninventario<<endl;
            }

            cout <<endl;
            cout <<"Total actual: "<<compradores[s].total<<"$";
        }
    }
    cout <<endl;
}


void Bienvenida()
{
    cout <<"*************************************************************************************" <<endl;
    cout <<"                     Presentado por: David Palacios" <<endl;
    cout <<"***************************************************************************************" <<endl<<endl;
    cout <<"                                   BIENVENIDO A PALAHERRAMIENTAS                            "<<endl;
}
void Inicializacion()
{
    administradores[0].nombre = "David";
    administradores[0].apellido = "Palacios";
    administradores[0].nombredeusuario = "david.palacios";
    administradores[0].contrasena = "david123";
    administradores[0].telefono = "3004988754";
    administradores[0].cedula = "0000000000";

    compradores[0].nombre = "Julian";
    compradores[0].apellido = "Alvarez";
    compradores[0].nombredeusuario = "julian.alvarez";
    compradores[0].contrasena = "julian123";
    compradores[0].telefono = "3142578414";
    compradores[0].cedula = "0000000000";

    compradores[1].nombre = "Pepito";
    compradores[1].apellido = "Perez";
    compradores[1].nombredeusuario = "pepito.perez";
    compradores[1].contrasena = "pepito123";
    compradores[1].telefono = "3004875621";
    compradores[1].cedula = "1010145921";

    productos[0].nombre = "Arena";
    productos[0].id = 1001;
    productos[0].descripcion= "Material de construccion";
    productos[0].valorunitario = 3000;
    productos[0].cantidadeninventario = 1000;

    productos[1].nombre = "Cemento";
    productos[1].id = 1002;
    productos[1].descripcion= "Material de construccion";
    productos[1].valorunitario = 5000;
    productos[1].cantidadeninventario = 1000;

    productos[2].nombre = "Ladrillo";
    productos[2].id = 1003;
    productos[2].descripcion= "Bloque de construccion";
    productos[2].valorunitario = 2000;
    productos[2].cantidadeninventario = 5000;

    productos[3].nombre = "Gravilla";
    productos[3].id = 1004;
    productos[3].descripcion= "Material de construccion";
    productos[3].valorunitario = 7000;
    productos[3].cantidadeninventario = 1000;

    productos[4].nombre = "Teja";
    productos[4].id = 1005;
    productos[4].descripcion= "Bloque de construccion";
    productos[4].valorunitario = 8000;
    productos[4].cantidadeninventario = 3000;

}

