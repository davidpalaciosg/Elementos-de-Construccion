# Elementos de Construcción
Proyecto realizado en C++ para simular un software de gestión de inventarios.

##Uso de estructuras básicas del lenguaje: 
- Condicionales
- Ciclos 
- Arrays 
- Matrices 
- Funciones
- Estructuras básicas.

### Explicación de estructuras
El proyecto funciona por roles: Comprador y Administrador.
Dependiendo del rol, se ejecutan ciertas funciones (similares a métodos en POO).
Además, cuenta con funciones de interés general: 

	//Funciones generales
	void Inicializacion(); //Inicializa todos los datos 
	void Bienvenida(); //Da la bienvenida al proyecto
	void MenuPrincipal(); //Despliega el menú principal del proyecto
####Producto
Simula los datos básicos de los productos del sistema:  id, nombre,  descripción, valor unitario,  y cantidad en el inventario.

     struct Producto
	{
		int id;
    	string nombre;
  	  string descripcion;
  	  int valorunitario;
   	 int cantidadeninventario;
	}
####Administrador
Tiene los datos básicos de cualquier persona:  nombre de usuario, contraseña, nombre apellido, cedula, teléfono. 

	struct Administrador
	{
   	 string nombredeusuario;
    	string contrasena;
    	string nombre;
    	string apellido;
   	 string cedula;
   	 string telefono;
	};

En el rol de Administrador se ejecutan las siguientes funciones:  

	//Funciones administrador
	bool LoginAdmin(); //Admite el ingreso al sistema como Administrador
	void MenuAdmin(); //Despliega el menú de Administrador
	void ConsultarProductos(); //Muestra los productos insertados en el sistema
	void AgregarComprador();
	void AgregarProducto();
	void ModificarProducto();
	void EliminarProducto();
	void GenerarHistorialParaUsuario(); //Genera el historial de ventas para un Usuario
	void GenerarHistorialParaEmpresa(); //Genera el historial de ventas para todo el sistema

####Comprador
Tiene los datos básicos de cualquier persona:  nombre de usuario, contraseña, nombre apellido, cedula, teléfono. Se diferencia porque tiene un carrito de compras (array de tipo Producto), además de un historial de compras (matriz de enteros), un número de compras realizadas, cantidad de productos adquiridos y un total gastado.

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

En el rol de Administrador se ejecutan las siguientes funciones:  

	//Funciones comprador
	bool LoginComprador(); //Admite el ingreso al sistema como Comprador
	void MenuComprador(); //Despliega el menú de Comprador
	void VisualizarPorID(); //Busca productos por ID
	void VisualizarPorNombre(); //Busca productos por Nombre
	void VisualizarPorValor(); //Busca productos por valor
	void AgregarAlCarrito(); //Agrega productos al carrito
	void ImprimirCarrito(); //Muestra en pantalla el carrito actual
	void ModificarCarrito();
	void EliminarDelCarrito();
	void ConfirmarCarrito();
	void GenerarHistorialComprador();

Este proyecto no es de interés comercial y únicamente representa un proyecto personal y de práctica educativa.