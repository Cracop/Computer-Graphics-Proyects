#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//Rodrigo Barrera - 181935

 /*
Datos del empleados 
	Nombres del empleado(string).
	Apellidos del empleado (string).
	Identificación del empleado con número de ingreso (entero)
	Dirección. Este a su vez debe ser una estructura con:
    o	Calle o avenida
    o	Numero externo
    o	Código postal
    o	Ciudad 
    o	País
	Salario (real)
	Género (caracter)
	Estado civil (carácter)
	Número de hijos (entero)

Funciones a hacer
crear_empleado:  Solicita el espacio necesario y almacena la información del empleado capturado por teclado. La función retorna un apuntador al empleado recién creado o un código de error si falla la habilitación de memoria. Esta función debería ser llamada por insertar_empleado.

insertar_empleado:  Agrega un nuevo empleado (ordenado por su identificación). El procedimiento recibe, al menos, el apuntador a la lista de empleados. Retorna error si no hay memoria disponible.

borrar_empleado:  Elimina un empleado por su identificación. Recibe como parámetro el identificador del empleado y la lista. Debe retorna código de error si el empleado no está en la lista.

num_empleados:   Retorna el número de empleados que contiene la lista. También         
como las demás funciones y procedimiento anteriores debe recibir parámetros

mostrar_empleado:  Muestra por pantalla la información de un empleado particular. 
Retorna un código de error si el empleado no está en la lista.

los_empleados:  Muestra por pantalla la información de todos los empleados. Retorna un código de error si la lista está vacía.
 */

//Estructuras
struct direccion {
    char calle[50];
    int num_ext;
    int codigo_postal;
    char ciudad[60];
    char pais[40];
};

struct empleado{
    char nombres[40];
    char apellidos[45];
    int id;
    float salario;
    char genero;
    char estado_civil;
    int num_hijos;
    struct direccion* dir;
};

struct Nodo {
    struct empleado dato;
    struct Nodo* sig;
};

//Funciones

 struct empleado* crear_empleado(){
    struct empleado* emp = (struct empleado*)malloc(sizeof(struct empleado));
    struct direccion* dir = (struct direccion*)malloc(sizeof(struct direccion));
    if(emp == NULL || dir == NULL){
        printf("No hay memoria disponible\n");
        perror("No memoria: ");
        exit(0);
    }

    emp->dir = dir;

    printf("Nombre(s): ");  
    scanf("%s", &emp->nombres);
    while ((getchar()) != '\n');  

    printf("Apellidos: ");  
    scanf("%s", &emp->apellidos); 
    while ((getchar()) != '\n'); 

    printf("Identificación: ");  
    scanf("%d", &emp->id);
    while ((getchar()) != '\n');  

    printf("Salario (en pesos): ");  
    scanf("%f", &emp->salario);
    while ((getchar()) != '\n');  

    printf("Género: ");
    scanf("%c", &emp->genero);
    while ((getchar()) != '\n');  

    printf("Estado Civil: ");  
    scanf("%c", &emp->estado_civil);

    printf("Número de Hijos: "); 
    scanf("%d", &emp->num_hijos);
    while ((getchar()) != '\n');  

    printf("Da la dirección\n");
    printf("\tCalle: ");
    scanf("%s", &emp->dir->calle);
    while ((getchar()) != '\n'); 

    printf("\tNum Exterior: ");
    scanf("%d", &emp->dir->num_ext);
    while ((getchar()) != '\n'); 

    printf("\tCodigo Postal: ");
    scanf("%d", &emp->dir->codigo_postal);
    while ((getchar()) != '\n'); 

    printf("\tCiudad: ");
    scanf("%s", &emp->dir->ciudad);
    while ((getchar()) != '\n'); 

    printf("\tPaís: ");
    scanf("%s", &emp->dir->pais);
    while ((getchar()) != '\n'); 
    //Despues de aquí tienes que presionar dos veces enter, no sé por qué


    
    

    

    // printf("Nombres: %s\n", emp->nombres);
    // printf("Apellidos: %s\n", emp->apellidos);
    // printf("ID: %d\n", emp->id);
    // printf("Genero: %c", emp->genero);

    return emp;
}

void insertar_empleado(struct Nodo *head){
    //Creo el nodo
    struct Nodo* nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    if (nuevoNodo == NULL){
        printf("No hay memoria disponible");
        perror("No memoria: ");
        exit(0);
    }
 
    struct Nodo *last = head;
    struct empleado* emp = crear_empleado();

    int idAInsertar = emp-> id;
    //printf("Insertar id %d",idAInsertar);
    int idActual;
    // 2. Coloco el dato
    nuevoNodo->dato  = *emp;
    
 
    // 3. Si la lista esta vacía, el nuevo nodo será la cabeza (Luego se volvió superfluo porque usé un nodo centinela)
    if (head == NULL)
    {
       head = nuevoNodo;
       return;
    } 
    
    // 4. Viajo por toda la lista, hasta llegar al final o encuentre un id más grande
    while (last->sig != NULL && last -> sig -> dato.id < idAInsertar){
        last = last->sig;
    }

    // 5. Cambio los apuntadores
    nuevoNodo -> sig = last->sig;
    last->sig = nuevoNodo;
    return;  
}

void los_empleados(struct Nodo *node){  
    struct empleado emp;
    if (node-> sig== NULL){
        printf("No hay empleados\n");
        //perror("Sin empleados");
        return;
    }
    printf("Los Empleados:\n");
    node = node->sig;//Debido al nodo centinela, debo empezar desde uno adelante
    while (node != NULL){
        emp = node->dato;
        printf("\tNombre: %s %s - ID: %d\n", emp.nombres,emp.apellidos, emp.id);
        node = node->sig;
  }
}

int num_empleados(struct Nodo *node){  
    int cont=0;

    node = node->sig;//Debido al nodo centinela, debo empezar desde uno adelante

    while (node != NULL){//avanzó hasta el final
      cont++;
      node = node->sig;
  }
  return cont;
}

int mostrar_empleado(struct Nodo *nodo){
    struct empleado emp;
    int idABuscar;
    printf("¿De que empleado quieres saber más?\n\n");
    scanf("%d", &idABuscar); 

    nodo = nodo->sig;//Debido al nodo centinela, debo empezar desde uno adelante
    while (nodo != NULL){
        emp = nodo->dato;
        if (emp.id==idABuscar){
            printf("\nNombre: %s %s\nID: %d\n\tSalario: %f\n\tGénero: %c\n\tEstado Civil: %c\n\tNúmero de Hijos: %d", emp.nombres,emp.apellidos, emp.id, emp.salario, emp.genero, emp.estado_civil, emp.num_hijos);
            printf("\n\tDirección: %s %d, %s, %s, %d \n", emp.dir->calle, emp.dir->num_ext, emp.dir->ciudad, emp.dir->pais, emp.dir->codigo_postal);
            return 1;
        }
        nodo = nodo->sig;   
  }
  return 0;

}

int borrar_empleado(struct Nodo *nodo, int idABorrar){
    struct Nodo *temp = nodo, *prev;
    //struct empleado emp = temp->dato;

    //Recorro la lista hasta el final o encontrar el id
    while (temp != NULL && temp->dato.id != idABorrar){
        prev = temp;
        temp = temp->sig;
    }
 
    // Si el dato no está en la lista
    if (temp == NULL)
        return 0;
 
    // Cambio apuntadores
    prev-> sig = temp->sig;
 
    // Libero memoria
    free(temp);
    return 1;

}

//MAIN
int main(){
    int int_acc;//La accion que va a tomar el usuario
    int id; // El id cuando quiero borrar
    int cont; //el contador de empleados
    //Creo el apuntador a la cabeza
    
    //Creo la lista
    struct Nodo* head = NULL;
    head = (struct Nodo*)malloc(sizeof(struct Nodo));
    printf("\nNómina por Rodrigo Barrera 181935");

    while (1){//El ciclo correrá hasta que me salga del programa

        printf("\nQue deseas hacer?\n\n");
        printf("\t1 - Insertar Empleado\n");
        printf("\t2 - Borrar Empleado\n");
        printf("\t3 - Num Empleados\n");
        printf("\t4 - Mostrar Empleado\n");
        printf("\t5 - Los Empleados\n");
        printf("\t0 - Salir\n");

        scanf("%d", &int_acc);

        switch(int_acc){
            case 0: 
                exit(0);
                break;

            case 1: 
                insertar_empleado(head);
                while ((getchar()) != '\n'); // limpio el buffer para que scanf guarde el nuevo valor
                break;

            case 2: 
                printf("¿Que empleado quieres eliminar?\n");
                scanf("%d", &id); 
                if (borrar_empleado(head, id)){
                    printf("Usuario eliminado\n");
                }else{
                    printf("No puedes eliminar un usuario que no existe\n");  
                }
                while ((getchar()) != '\n'); // limpio el buffer para que scanf guarde el nuevo valor
                break;

            case 3: 
                cont = num_empleados(head);
                if (cont){
                    printf("Cantidad de empleados: %d\n", cont);
                }else{
                    printf("No hay empleados contratados\n");
                }
                while ((getchar()) != '\n'); // limpio el buffer para que scanf guarde el nuevo valor
                break;

            case 4: 
                if (!mostrar_empleado(head)){
                    printf("No hay tal empleado");
                }
                while ((getchar()) != '\n'); // limpio el buffer para que scanf guarde el nuevo valor
                break;

            case 5: 
                los_empleados(head);
                while ((getchar()) != '\n'); // limpio el buffer para que scanf guarde el nuevo valor
                break;

            default:
                printf("Debe ser una acción válida\n");
                while ((getchar()) != '\n'); // limpio el buffer para que scanf guarde el nuevo valor
                break;
        };
    }
}