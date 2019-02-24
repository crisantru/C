#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define nivelPila 5
#define numLote 4

typedef struct datosUsuario
{
    char nombre[25];
    char apellidoPat[15];
    char apellidoMat[15];
    char domicilio[60];
    //char codigoPostal[5];
    char telefono[10];
    int edad;
    int id;

    struct datosUsuario *siguiente;

} DATOSUSUARIO;

typedef struct datosAutomovil
{
    char marca[15];
    char modelo[20];
    char version[5];
    char placa[8];
    char color[15];

    struct datosAutomovil *siguiente;
    struct datosUsuario *usuario;
    struct elementoLote *lote;

} AUTOMOVIL;

typedef struct elementoPila
{
    int nivel;
    char nombreNivel[10];

    struct elementoPila *siguiente;

} ELEMENTOPILA;

typedef struct elementoLote
{
    int capacidad;
    char nombreLote[8];

    struct elementoPila *lote;
    struct elementoLote *siguiente;

} ELEMENTOLOTE;

typedef struct cola
{
    struct datosAutomovil *frente;
    struct datosAutomovil *final;

} COLA;

typedef struct elemeRepartVehiculo
{

    int prioridad;

    struct elemeRepartVehiculo *siguiente;
}

//{               //funciones de ususario
DATOSUSUARIO* insertarElementoUser(DATOSUSUARIO **inicioUsuarios, char nombreUsuario[25], char apellidoPat[15], char apellidoMat[15], char domicilio[60]/*, char codigoPostal[5]*/, char telefono[10], int edad, int *id);
DATOSUSUARIO* buscarElementoUser(DATOSUSUARIO **inicioUsuarios, int idBusca);
DATOSUSUARIO* editarNombreUser(DATOSUSUARIO **inicioUsuarios, char nombreUsuario[25], int idBusca);
DATOSUSUARIO* editarApellidoPUser(DATOSUSUARIO **inicioUsuarios, char apellidoPat[15], int idBusca);
DATOSUSUARIO* editarApellidoMUser(DATOSUSUARIO **inicioUsuarios, char apellidoMat[15], int idBusca);
DATOSUSUARIO* editarDomicilioUser(DATOSUSUARIO **inicioUsuarios, char domicilio[60], int idBusca);
DATOSUSUARIO* editarTelefonoUser(DATOSUSUARIO **inicioUsuarios, char telefono[10], int idBusca);
int eliminarElementoUser(DATOSUSUARIO **inicioUsuarios, int idElimina);
int editarElementoUser(DATOSUSUARIO **inicioUsuarios, int idBusca);
void imprimirUsuarios(DATOSUSUARIO *inicioUsuarios);
//}

//{                //funciones de vehiculo
AUTOMOVIL* altaVehiculo(AUTOMOVIL **inicioVehiculos, char marca[15], char modelo[20], char version[5], char placa[8], char color[15]);
AUTOMOVIL* buscarVehiculo(AUTOMOVIL **inicioVehiculos, char placa[8]);
AUTOMOVIL* editaMarcaV(AUTOMOVIL **inicioVehiculos, char marca[20], char placa[8]);
AUTOMOVIL* editaModeloV(AUTOMOVIL **inicioVehiculos, char modelo[15], char placa[8]);
AUTOMOVIL* editaPlacaV(AUTOMOVIL **inicioVehiculos, char placaS[8], char placa[8]);
int bajaVehiculo(AUTOMOVIL **inicioVehiculos, char placa[8]);
int editarVehiculo(AUTOMOVIL **inicioVehiculos, char placa[8]);
void imprimirVehiculos(AUTOMOVIL *inicioVehiculos);
//}

//Asiganacion vehiculo
AUTOMOVIL* asignaVehiculoUser(DATOSUSUARIO **inicioUsuarios, AUTOMOVIL **inicioVehiculos, char placa[8], int idBusca);

ELEMENTOPILA* estacionarVehiculo(AUTOMOVIL **inicioVehiculos, char placa[8], ELEMENTOPILA **topePila, ELEMENTOLOTE **lote, int *tamanoPila);
ELEMENTOPILA* meteVehiculo(AUTOMOVIL *vehiculo, int tiempo, ELEMENTOPILA **topePila, ELEMENTOLOTE **lote, int *tamanoPila);

int pilaVacia(ELEMENTOPILA *tope);
int pilaLlena(ELEMENTOPILA *tope);






int main()
{
    int opcion, edad, id = 0, idElimina, validaElimina, idBusca, validaEdita, inicialP, tamanoPila = -1;
    char nombreUsuario[25], apellidoPat[15], apellidoMat[15], domicilio[60], /*codigoPostal[5],*/ telefono[10];
    char marca[15], modelo[20], version[5], placa[8], color[15];

    ELEMENTOPILA *topePila = NULL;
    ELEMENTOLOTE *lote = NULL;


    DATOSUSUARIO *validaInserta = NULL;
    DATOSUSUARIO *inicioUsuarios = NULL;

    AUTOMOVIL *validaAlta = NULL;
    AUTOMOVIL *inicioVehiculos = NULL;

    do                      //Menu Principal
    {
        printf("\n\n  ********** Parking System **********");
        printf("\n\n -------------- Principal ------------");
        printf("\n|  1. Usuarios                        |");
        printf("\n|  2. Automoviles                     |");
        printf("\n|  3. Parking                         |");
        printf("\n|  4. Salir                           |");
        printf("\n -------------------------------------");

        printf("\n\nOpcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                                //Menu Usuarios
                do
                {
                    printf("\n\n Ruta: Principal/Usuarios");
                    printf("\n\n -------------- Usuarios --------------");
                    printf("\n|  1. Agregar Usuario                  |");
                    printf("\n|  2. Editar Usuario                   |");
                    printf("\n|  3. Eliminar Usuario                 |");
                    printf("\n|  4. Buscar Usuario                   |");
                    printf("\n|  5. Imprimir Usuarios                |");
                    printf("\n|  6. Salir                            |");
                    printf("\n --------------------------------------");

                    printf("\n\nOpcion: ");
                    scanf("%d", &opcion);

                    switch(opcion)
                    {
                        case 1:         //Agregar Usuario

                            printf("\n Ruta: Principal/Usuarios/AgregarUsuario");
                            printf("\n\n-------------------- Nuevo Usuario --------------------");
                            printf("\nDame el nombre del Nuevo Usuario: ");
                            fflush(stdout);
                            scanf (" %[^\n]%*c", nombreUsuario);
                            printf("\nApellido Paterno: ");
                            fflush(stdout);
                            scanf (" %[^\n]%*c", apellidoPat);
                            printf("\nApellido Materno: ");
                            fflush(stdout);
                            scanf (" %[^\n]%*c", apellidoMat);
                            printf("\nDomicilio: ");
                            fflush(stdout);
                            scanf (" %[^\n]%*c", domicilio);

                           // printf("\nCodigo Postal: ");
                            //fflush(stdout);
                            //scanf (" %[^\n]%*c", codigoPostal);

                            printf("\nTelefono: ");
                            fflush(stdout);
                            scanf (" %[^\n]%*c", telefono);
                            printf("\nEdad: ");
                            scanf ("%d", &edad);

                            validaInserta = insertarElementoUser(&inicioUsuarios, nombreUsuario, apellidoPat, apellidoMat, domicilio,/* codigoPostal,*/ telefono, edad, &id);

                                if(strcmp(validaInserta->nombre, nombreUsuario) == 0)
                                {
                                    printf("\nSe agrego un Nuevo Usuario");
                                    printf("\nUsuario: %s %s %s Id: %d", validaInserta->nombre, validaInserta->apellidoPat, validaInserta->apellidoMat, validaInserta->id);

                                }

                                else
                                    printf("\nHubo un problema al insertar datos del nuevo usuario");

                                if(validaInserta == NULL)
                                    printf("\nNo se pudo crear tu nuevo usuario...");

                            break;

                        case 2:                 //Editar Usuario

                            printf("\n Ruta: Principal/Usuarios/EditarUsuario");
                            printf("\n\n----------------- Editar Usuario ----------------");
                            printf("\nEscribe el id del usuario que deseas editar: ");
                            scanf("%d", &idBusca);
                            validaEdita = editarElementoUser(&inicioUsuarios, idBusca);

                            if(validaEdita == 1)
                                printf("\nEdicion Finalizada");

                            if(validaEdita == 0)
                            printf("\nNo se pudo editar hubo un problema");

                            break;

                        case 3:                 //Eliminar Usuario

                            printf("\n Ruta Principal/Usuarios/EliminarUsuario");
                            printf("\n\n------------------ Eliminar Usuario -----------------");
                            printf("\nEscribe el id del usuario que deseas eliminar: ");
                            scanf("%d", &idElimina);
                            validaElimina = eliminarElementoUser(&inicioUsuarios, idElimina);

                            if(validaElimina == 0)
                                printf("\nNo se puede eliminar el usuario solicitado. Verifique el ID y asegurese que el registro contenga usuarios...");

                            if(validaElimina == 1)
                                printf("\nSe elimino correctamente tu cliente del registro");

                            break;

                        case 4:                 //Buscar Usuario

                            printf("\n Ruta: Principal/Usuarios/BuscarUsuario");
                            printf("\n\n----------------- Buscar Usuario ----------------");
                            printf("\nDame el ID del usuario: ");
                            scanf("%d", &idBusca);
                            buscarElementoUser(&inicioUsuarios, idBusca);

                            break;

                        case 5:                 //Imprimir Usuarios

                            printf("\n Ruta: Principal/Usuarios/ImprimirUsuarios");
                            printf("\n------------------ Usuarios -------------------");
                            imprimirUsuarios(inicioUsuarios);
                            printf("\n-----------------------------------------------");

                            break;

                        case 6:
                            break;

                        default:
                            printf("\nOpcion Incorrecta...Vuelve a intentarlo");
                            break;
                    }

                } while(opcion != 6);

                break;

            case 2:
                                //Menu Automoviles
                do
                {
                    printf("\n\n Ruta: Principal/Automoviles");
                    printf("\n\n -------------- Automoviles ---------------");
                    printf("\n|  1. Alta Automovil                       |");
                    printf("\n|  2. Editar Automovil                     |");
                    printf("\n|  3. Asignar Automovil                    |");
                    printf("\n|  4. Baja Automovil                       |");
                    printf("\n|  5. Buscar Automovil                     |");
                    printf("\n|  6. Imprimir Automoviles                 |");
                    printf("\n|  7. Salir                                |");
                    printf("\n ------------------------------------------");

                    printf("\n\nOpcion: ");
                    scanf("%d", &opcion);

                    switch(opcion)
                    {
                        case 1:             //Agregar Automoviles

                            printf("\n\n Ruta: Principal/Automoviles/AltaAutomovil");
                            printf("\n\n----------------- Alta Automovil -----------------");
                            printf("\nMarca del vehiculo: ");
                            fflush(stdout);
                            scanf (" %[^\n]%*c", marca);
                            printf("\nModelo del vehiculo: ");
                            fflush(stdout);
                            scanf (" %[^\n]%*c", modelo);
                            printf("\nAño del vehiculo: ");
                            fflush(stdout);
                            scanf (" %[^\n]%*c", version);
                            printf("\nPlacas del vehiculo: ");
                            fflush(stdout);
                            scanf (" %[^\n]%*c", placa);
                            printf("\nColor del vehiculo: ");
                            fflush(stdout);
                            scanf (" %[^\n]%*c", color);

                            validaAlta = altaVehiculo(&inicioVehiculos, marca, modelo, version, placa, color);

                            if(strcmp(validaAlta->placa, placa) == 0)
                                printf("\n\nSe añadio correctamente el vehiculo");
                            else
                                printf("\nHubo un problema al crear el vehiculo");

                            if(validaAlta == NULL)
                                printf("\nNO se pudo dar de alta tu nuevo vehiculo...");

                            break;

                        case 2:             //Editar Vehiculo

                            printf("\n\n Ruta: Principal/Automoviles/EditarAutomovil");
                            printf("\n\n----------------- Editar Automovil -----------------");
                            printf("\nDame el número de placa del vehiculo: ");
                            fflush(stdout);
                            scanf (" %[^\n]%*c", placa);
                            validaEdita = editarVehiculo(&inicioVehiculos, placa);

                            if(validaEdita == 1)
                                printf("\nEdicion finalizada estado: OK");
                            else
                                printf("\nHubo un error en la edicion...");

                            break;

                        case 3:             //Asignar Vehiculo

                            printf("\n\n Ruta: Principal/Automoviles/AsignarAutomovil");
                            printf("\n\n----------- Asignación de Automovil -----------");
                            printf("\n\n**** NOTA: PARA PODER REALIZAR LA ASIGNACION DEL VEHICULO CON EXITO");
                            printf("\n\n**** DEBES TENER CORRECTAMENTE EL NUMERO DE PLACAS DEL VEHICULO...");
                            printf("\n\nEscribe el número de placa del vehiculo asignar: ");
                            fflush(stdout);
                            scanf (" %[^\n]%*c", placa);
                            printf("\nDame el Id del Usuario: ");
                            scanf("%d", &idBusca);
                            validaAlta = asignaVehiculoUser(&inicioUsuarios, &inicioVehiculos, placa, idBusca);

                            if(validaAlta == NULL)
                            {
                                printf("\nError....Comprueba el ID y Placas del Registro");
                                break;
                            }


                            if(validaAlta->usuario->id == idBusca && strcmp(validaAlta->placa, placa) == 0)
                            {
                                printf("\nLa asignación del Vehiculo-Usuario fue un exito...");
                                printf("\nUsuario: %s Vehiculo: %s Placa: %s", validaAlta->usuario->nombre, validaAlta->modelo, validaAlta->placa);

                            }

                            else
                                printf("\nHubo un error en la Asignacion de Vehiculo-Usuario, checar id y placas...");

                            break;

                        case 4:         //Baja Vehiculo

                            printf("\n\n Ruta: Principal/Automoviles/BajaAutomovil");
                            printf("\n\n----------------- Baja Automovil -----------------");
                            printf("\nDame el número de placa del vehiculo para dar de baja: ");
                            fflush(stdout);
                            scanf (" %[^\n]%*c", placa);
                            validaElimina = bajaVehiculo(&inicioVehiculos, placa);

                            if(validaElimina == 1)
                                printf("\nTu baja se realizo con exito");
                            else
                                printf("\nNose pudo dar de baja el vehiculo solicitado");

                            break;

                        case 5:         //Buscar Vehiculo

                            printf("\n\n Ruta: Principal/Automoviles/BuscarAutomovil");
                            printf("\n\n----------------- Buscar Automovil -----------------");
                            printf("\nDame el número de placa del vehiculo : ");
                            fflush(stdout);
                            scanf (" %[^\n]%*c", placa);
                            printf("\n\n----------------- Detalles Vehiculo -----------------");
                            validaAlta = buscarVehiculo(&inicioVehiculos, placa);

                            if(validaAlta == NULL)
                                printf("\nNo hay Vehiculos en el Registro");
                            printf("\n-----------------------------------------------------");

                            break;

                        case 6:         //Imprimir Automoviles

                            printf("\n\n Ruta: Principal/Automoviles/ImprimirAutomoviles");
                            printf("\n\n----------------- Lista de Automoviles -----------------");
                            imprimirVehiculos(inicioVehiculos);
                            printf("\n--------------------------------------------------------");

                            break;

                        case 7:

                            break;

                        default:
                            printf("\nOpcion Incorrecta...Vuelve a intentarlo");

                            break;
                    }

                } while(opcion != 7);

                break;

            case 3:                 //Menu parking

                do
                {
                    printf("\n\n Ruta: Principal/Parking");
                    printf("\n\n -------------- Parking ---------------");
                    printf("\n|  1. Parking de Vehiculo              |");
                    printf("\n|  2. Liberar Vehiculo                 |");
                    printf("\n|  3. Control Parking                  |");
                    printf("\n|  4. Salir                            |");
                    printf("\n --------------------------------------");

                    printf("\n\nOpcion: ");
                    scanf("%d", &opcion);

                    switch(opcion)
                    {

                        case 1:         //Parking Vehiculo

                            printf("\n\n Ruta: Principal/Parking/ParkingVehiculo");
                            printf("\n\n -------------- Parking Vehiculo ---------------");
                            printf("\nDame el numero de placa de tu vehiculo que deseas Estacionar: ");
                            fflush(stdout);
                            scanf (" %[^\n]%*c", placa);
                            estacionarVehiculo(&inicioVehiculos, placa, topePila, lote, tamanoPila);



                            break;

                        case 2:
                            break;

                        case 3:
                            break;

                        case 4:
                            break;

                        default:
                            printf("\nOpcion Incorrecta....");
                            break;


                    }

                } while (opcion != 4);



                break;

            case 4:
                break;

            default:
                printf("\nOpcion Incorrecta. Vuelve a intentarlo....");
        }

    } while(opcion != 4);

    return 0;
}


DATOSUSUARIO* insertarElementoUser(DATOSUSUARIO **inicioUsuarios, char nombreUsuario[25], char apellidoPat[15], char apellidoMat[15], char domicilio[60],/* char codigoPostal[5],*/ char telefono[10], int edad, int *id)
{

    DATOSUSUARIO *nuevoElementoUsuario;
    nuevoElementoUsuario = (DATOSUSUARIO *) malloc(sizeof(DATOSUSUARIO));

    if(nuevoElementoUsuario == NULL)
    {
        printf("\nError de asignamiento de memoria...");
        return NULL;

    }

    printf("\nsale if memo");
    strcpy(nuevoElementoUsuario->nombre, nombreUsuario);        //strcpy(destino, fuente);
    strcpy(nuevoElementoUsuario->apellidoPat, apellidoPat);
    strcpy(nuevoElementoUsuario->apellidoMat, apellidoMat);
    strcpy(nuevoElementoUsuario->domicilio, domicilio);
    strcpy(nuevoElementoUsuario->telefono, telefono);
    nuevoElementoUsuario->edad = edad;
    nuevoElementoUsuario->id = *id += 1;

    nuevoElementoUsuario->siguiente = *inicioUsuarios;
    *inicioUsuarios = nuevoElementoUsuario;

    return nuevoElementoUsuario;

}

int eliminarElementoUser(DATOSUSUARIO **inicioUsuarios, int idElimina)
{
    DATOSUSUARIO *eliminaAux = NULL;

    if((*inicioUsuarios) == NULL)
        return 0;

    if((*inicioUsuarios)->id == idElimina)
    {
        eliminaAux = *inicioUsuarios;
        *inicioUsuarios = (*inicioUsuarios)->siguiente;
        free(eliminaAux);
        return 2;
    }

    eliminarElementoUser(&((*inicioUsuarios)->siguiente), idElimina);

}

int editarElementoUser(DATOSUSUARIO **inicioUsuarios, int idBusca)
{

    int opcionEdita; //, validaBusqueda;
    char nombreUsuario[25], apellidoPat[15], apellidoMat[15], domicilio[60], telefono[10];

    DATOSUSUARIO *validaEdita = NULL;

    if(*inicioUsuarios == NULL)
    {
        printf("\nEl registro esta vacio no hay nada que editar");
        return 0;
    }

    validaEdita = buscarElementoUser(inicioUsuarios, idBusca);

    if(validaEdita == NULL)
    {
        printf("\nNo se encontro el ID solicitado");
        return 0;
    }

    printf("\n\n********************************* OPCIONES PARA EDITAR *******************************");
    printf("\n 1.- Nombre    2.- Apellido Pat    3.- Apellido Mat    4.- Domicilio    5.- Telefono");
    printf("\nOpcion a Editar: ");
    scanf("%d", &opcionEdita);
    printf("\nopcion: %d", opcionEdita);


    //Cambiar a switch........


    if(opcionEdita == 1)
    {
        printf("\nPrincipal/EditarUsuario/Nombre");
        printf("\nReintroduce el Nombre del usuario:  ");
        fflush(stdout);
        scanf (" %[^\n]%*c", nombreUsuario);

        validaEdita = editarNombreUser(inicioUsuarios, nombreUsuario, idBusca);

        if(validaEdita->nombre == nombreUsuario)
            printf("\nLaedicion fue un exito...");

        return 1;
    }

    if(opcionEdita == 2)
    {

        printf("\nentra a if opcion 2");
        printf("\nPrincipal/EditarUsuario/ApellidoPaterno");
        printf("\nReintroduce el Apellido Paterno del usuario:  ");
        fflush(stdout);
        scanf (" %[^\n]%*c", apellidoPat);
        printf("\nApellido Paterno con el que se va a remplazar: %s", apellidoPat);
        printf("\nManda a funcion editar nombre de usuario");

        validaEdita = editarApellidoPUser(inicioUsuarios, apellidoPat, idBusca);

        if(validaEdita->apellidoPat == apellidoPat)
            printf("\nLaedicion fue un exito...");

        return 1;
    }

    if(opcionEdita == 3 )
    {

        printf("\nentra a if opcion 3");
        printf("\nPrincipal/EditarUsuario/ApellidoMaterno");
        printf("\nReintroduce el Apellido Materno del usuario:  ");
        fflush(stdout);
        scanf (" %[^\n]%*c", apellidoMat);
        printf("\nApellido Materno con el que se va a remplazar: %s", apellidoMat);
        printf("\nManda a funcion editar nombre de usuario");

        validaEdita = editarApellidoMUser(inicioUsuarios, apellidoMat, idBusca);

        if(validaEdita->apellidoMat == apellidoMat)
            printf("\nLaedicion fue un exito...");

        return 1;
    }

    if(opcionEdita == 4 )
    {

        printf("\nentra a if opcion 4");
        printf("\nPrincipal/EditarUsuario/Domicilio");
        printf("\nReintroduce el nuevo Domicilio del usuario:  ");
        fflush(stdout);
        scanf (" %[^\n]%*c", domicilio);

        validaEdita = editarDomicilioUser(inicioUsuarios, domicilio, idBusca);

        if(validaEdita->domicilio == domicilio)
            printf("\nLaedicion fue un exito...");

        return 1;
    }

    if(opcionEdita == 5 )
    {

        printf("\nentra a if opcion 5");
        printf("\nPrincipal/EditarUsuario/Telefono");
        printf("\nReintroduce el nuevo Telefono del usuario:  ");
        fflush(stdout);
        scanf (" %[^\n]%*c", telefono);

        validaEdita = editarTelefonoUser(inicioUsuarios, telefono, idBusca);

        if(validaEdita->telefono == telefono)
            printf("\nLaedicion fue un exito...");

        return 1;
    }

    return 0;
}

DATOSUSUARIO* editarNombreUser(DATOSUSUARIO **inicioUsuarios, char nombreUsuario[25], int idBusca)
{
    //int compara;
    printf("\nEntra a editar nombre");
    char a[25] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    printf("\nNombre con el que se va a remplazar: %s", nombreUsuario);
    printf("\nvariable a string aux: %s", a);

    //compara = strcmp((*inicioUsuarios)->nombre, nombreUsuario);
    //printf("\nif compara: %d", compara);

    if((*inicioUsuarios)->id == idBusca)
    {
        printf("\nEntra a if compara");
        strcpy((*inicioUsuarios)->nombre, a);
        printf("\nnombre de usurio en blanco: %s", (*inicioUsuarios)->nombre);
        strcpy((*inicioUsuarios)->nombre, nombreUsuario);

        return *inicioUsuarios;
    }

    printf("\nsale if compara");
    editarNombreUser(&((*inicioUsuarios)->siguiente), nombreUsuario, idBusca);

}

DATOSUSUARIO* editarApellidoPUser(DATOSUSUARIO **inicioUsuarios, char apellidoPat[15], int idBusca)
{
    printf("\nEntra a editar apellido");
    char a[15] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    printf("\nApellido con el que se va a remplazar: %s", apellidoPat);
    printf("\nvariable a string aux: %s", a);

    //compara = strcmp((*inicioUsuarios)->nombre, nombreUsuario);
    //printf("\nif compara: %d", compara);

    if((*inicioUsuarios)->id == idBusca)
    {
        printf("\nEntra a if compara");
        strcpy((*inicioUsuarios)->apellidoPat, a);
        printf("\napellido de usuario en blanco: %s", (*inicioUsuarios)->apellidoPat);
        strcpy((*inicioUsuarios)->apellidoPat, apellidoPat);

        return *inicioUsuarios;
    }

    printf("\nsale if compara");
    editarApellidoPUser(&((*inicioUsuarios)->siguiente), apellidoPat, idBusca);

}

DATOSUSUARIO* editarApellidoMUser(DATOSUSUARIO **inicioUsuarios, char apellidoMat[15], int idBusca)
{
    printf("\nEntra a editar apellido Materno");
    char a[15] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    printf("\nApellido con el que se va a remplazar: %s", apellidoMat);
    printf("\nvariable a string aux: %s", a);

    //compara = strcmp((*inicioUsuarios)->nombre, nombreUsuario);
    //printf("\nif compara: %d", compara);

    if((*inicioUsuarios)->id == idBusca)
    {
        printf("\nEntra a if compara");
        strcpy((*inicioUsuarios)->apellidoMat, a);
        printf("\napellido de usuario en blanco: %s", (*inicioUsuarios)->apellidoMat);
        strcpy((*inicioUsuarios)->apellidoMat, apellidoMat);

        return *inicioUsuarios;
    }

    printf("\nsale if compara");
    editarApellidoMUser(&((*inicioUsuarios)->siguiente), apellidoMat, idBusca);

}

DATOSUSUARIO* editarDomicilioUser(DATOSUSUARIO **inicioUsuarios, char domicilio[60], int idBusca)
{
    printf("\nEntra a editar domicilio");
    char a[60] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    printf("\ndomicilio con el que se va a remplazar: %s", domicilio);
    printf("\nvariable a string aux: %s", a);

    //compara = strcmp((*inicioUsuarios)->nombre, nombreUsuario);
    //printf("\nif compara: %d", compara);

    if((*inicioUsuarios)->id == idBusca)
    {
        printf("\nEntra a if compara");
        strcpy((*inicioUsuarios)->domicilio, a);
        printf("\napellido de usuario en blanco: %s", (*inicioUsuarios)->domicilio);
        strcpy((*inicioUsuarios)->domicilio, domicilio);

        return *inicioUsuarios;
    }

    printf("\nsale if compara");
    editarApellidoMUser(&((*inicioUsuarios)->siguiente), domicilio, idBusca);

}

DATOSUSUARIO* editarTelefonoUser(DATOSUSUARIO **inicioUsuarios, char telefono[10], int idBusca)
{
    printf("\nEntra a editar telefono");
    char a[10] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    printf("\ndomicilio con el que se va a remplazar: %s", telefono);
    printf("\nvariable a string aux: %s", a);

    //compara = strcmp((*inicioUsuarios)->nombre, nombreUsuario);
    //printf("\nif compara: %d", compara);

    if((*inicioUsuarios)->id == idBusca)
    {
        printf("\nEntra a if compara");
        strcpy((*inicioUsuarios)->telefono, a);
        printf("\ntelefono de usuario en blanco: %s", (*inicioUsuarios)->telefono);
        strcpy((*inicioUsuarios)->telefono, telefono);

        return *inicioUsuarios;
    }

    printf("\nsale if compara");
    editarTelefonoUser(&((*inicioUsuarios)->siguiente), telefono, idBusca);





}

DATOSUSUARIO* buscarElementoUser(DATOSUSUARIO **inicioUsuarios, int idBusca)
{
    if((*inicioUsuarios) == NULL)
        return NULL;

    if((*inicioUsuarios)->id == idBusca)
    {
        printf("\nID: %d", (*inicioUsuarios)->id);
        printf("\nNombre del Cliente: %s %s %s", (*inicioUsuarios)->nombre, (*inicioUsuarios)->apellidoPat, (*inicioUsuarios)->apellidoMat);
        printf("\nDomicilio: %s ", (*inicioUsuarios)->domicilio);
        printf("\nTelefono: %s", (*inicioUsuarios)->telefono);
        printf("\nEdad: %d", (*inicioUsuarios)->edad);
        return *inicioUsuarios;
    }

  /*  if((*inicioUsuarios)->siguiente == NULL)
    {
        printf("\nSe termino la busqueda.No se encontro el usuario deseado");
        return ;
    }*/


    buscarElementoUser(&((*inicioUsuarios)->siguiente), idBusca);


}

void imprimirUsuarios(DATOSUSUARIO *inicioUsuarios)
{
    if(inicioUsuarios == NULL)
    {
        printf("\nTu lista de usuarios esta vacia...");
        return;
    }

    printf("\n\nID: %d", inicioUsuarios->id);
    printf("\nNombre del Cliente: %s %s %s", inicioUsuarios->nombre, inicioUsuarios->apellidoPat, inicioUsuarios->apellidoMat);
    printf("\nDomicilio: %s ", inicioUsuarios->domicilio);
    //printf("\nC.P. %s", inicioUsuarios->codigoPostal);
    printf("\nTelefono: %s", inicioUsuarios->telefono);
    printf("\nEdad: %d", inicioUsuarios->edad);

    if(inicioUsuarios->siguiente == NULL)
        return;

    imprimirUsuarios(inicioUsuarios->siguiente);

}

AUTOMOVIL* altaVehiculo(AUTOMOVIL **inicioVehiculos, char marca[15], char modelo[20], char version[5], char placa[8], char color[15])
{

    AUTOMOVIL* nuevoVehiculo;

    nuevoVehiculo = (AUTOMOVIL*) malloc(sizeof(AUTOMOVIL));

    if(nuevoVehiculo == NULL)
    {
        printf("\nError de alojamiento de memmoria...");
        return NULL;
    }

    strcpy(nuevoVehiculo->marca, marca);
    strcpy(nuevoVehiculo->modelo, modelo);
    strcpy(nuevoVehiculo->version, version);
    strcpy(nuevoVehiculo->placa, placa);
    strcpy(nuevoVehiculo->color, color);

    nuevoVehiculo->siguiente = *inicioVehiculos;
    nuevoVehiculo->usuario = NULL;
    *inicioVehiculos = nuevoVehiculo;


    return nuevoVehiculo;

}

void imprimirVehiculos(AUTOMOVIL *inicioVehiculos)
{
    if(inicioVehiculos == NULL)
    {
        printf("\nNo hay vehiculos en el registro");
        return;
    }

    printf("\n\n------------------ Detalles del Vehiculo ------------------");
    printf("\nMarca del Vehiculo: %s  Placas: %s", inicioVehiculos->marca, inicioVehiculos->placa);
    printf("\nModelo del Vehiculo: %s  Color: %s", inicioVehiculos->modelo, inicioVehiculos->color);
    printf("\nVersion del Vehiculo: %s", inicioVehiculos->version);

    if(inicioVehiculos->usuario == NULL)
        printf("\n\nPropietario: %p %p %p", inicioVehiculos->usuario->nombre, inicioVehiculos->usuario->apellidoPat, inicioVehiculos->usuario->apellidoMat);
    else
    {
        printf("\n\nPropietario: %s %s %s", inicioVehiculos->usuario->nombre, inicioVehiculos->usuario->apellidoPat, inicioVehiculos->usuario->apellidoMat);
        printf("\nDomicilio: %s", inicioVehiculos->usuario->domicilio);
        printf("\nTelefono: %s Edad: %d", inicioVehiculos->usuario->telefono, inicioVehiculos->usuario->edad);
    }


    if(inicioVehiculos->siguiente == NULL)
       return;


    imprimirVehiculos(inicioVehiculos->siguiente);

}

int bajaVehiculo(AUTOMOVIL **inicioVehiculos, char placa[8])
{
    AUTOMOVIL *bajaAutoAux = NULL;

    if(*inicioVehiculos == NULL)
    {
        printf("\nNo se puede dar de baja. No hay vehiculos registrados");
        return 0;
    }

    if(strcmp((*inicioVehiculos)->placa, placa) == 0)
    {
        bajaAutoAux = *inicioVehiculos;
        *inicioVehiculos = (*inicioVehiculos)->siguiente;
        free(bajaAutoAux);
        return 1;
    }

    bajaVehiculo(&((*inicioVehiculos)->siguiente), placa);

}

AUTOMOVIL* buscarVehiculo(AUTOMOVIL **inicioVehiculos, char placa[8])
{
    printf("\nEntre a buscar");

    if(*inicioVehiculos == NULL)
    {
        printf("\nentra if inicioVehiculos");
        return NULL;
    }

    printf("\nsale if");

    if(strcmp((*inicioVehiculos)->placa, placa) == 0)
    {
        printf("\nentra a if impresion");
        printf("\n\n---------------- Detalles Vehiculo --------------");
        printf("\nMarca del Vehiculo: %s Placa: %s", (*inicioVehiculos)->marca, (*inicioVehiculos)->placa);
        printf("\nModelo: %s Color: %s ", (*inicioVehiculos)->modelo, (*inicioVehiculos)->color);
        printf("\nAño del Vehiculo: %s Color: %s ", (*inicioVehiculos)->version, (*inicioVehiculos)->color);

        if((*inicioVehiculos)->usuario == NULL)
            printf("\n\nPropietario: %p %p %p", (*inicioVehiculos)->usuario->nombre, (*inicioVehiculos)->usuario->apellidoPat, (*inicioVehiculos)->usuario->apellidoMat);
        else
        {
            printf("\n\nPropietario: %s %s %s", (*inicioVehiculos)->usuario->nombre, (*inicioVehiculos)->usuario->apellidoPat, (*inicioVehiculos)->usuario->apellidoMat);
            printf("\nDomicilio: %s", (*inicioVehiculos)->usuario->domicilio);
            printf("\nTelefono: %s Edad: %d", (*inicioVehiculos)->usuario->telefono, (*inicioVehiculos)->usuario->edad);
        }

        return *inicioVehiculos;
    }

    printf("\nsale if strcmp");
    if((*inicioVehiculos)->siguiente == NULL)
        return NULL;

    buscarVehiculo(&((*inicioVehiculos)->siguiente), placa)    ;

}

int editarVehiculo(AUTOMOVIL **inicioVehiculos, char placa[8])
{
    int opcionEdita;
    char marca[15];
    char modelo[20];
    char placaS[8];

    AUTOMOVIL *validaEdita = NULL;

    if(*inicioVehiculos == NULL)
    {
        printf("\nNose puede editar no hay registros de vehiculos");
        return;

    }

    printf("\n------------- Detalles del Vehiculo -----------");
    buscarVehiculo(inicioVehiculos, placa);
    printf("\n\n*********** OPCIONES PARA EDITAR ************");
    printf("\n\n1.- Marca\t2.-Modelo\t3.-Placa");
    printf("\n\n*********************************************");

    printf("\nOpcion: ");
    scanf("%d", &opcionEdita);

    switch(opcionEdita)
    {
        case 1:         //edita Marca
            printf("\n Ruta Principal/Usuarios/EditarVehiculo/Marca");
            printf("\n\n-------- Editar Vehiculo -------");
            printf("\nRescribe el marca del vehiculo actual: ");
            fflush(stdout);
            scanf (" %[^\n]%*c", marca);
            validaEdita = editaMarcaV(inicioVehiculos, marca, placa);

            if(strcmp(validaEdita->marca, marca) == 0)
            {
                printf("\nSe edito correctamente el marca del vehiculo...");
                return 1;
            }

            break;

        case 2:         //edita Modelo

            printf("\n Ruta Principal/Usuarios/EditarVehiculo/Modelo");
            printf("\n\n-------- Editar Vehiculo -------");
            printf("\nRescribe el modelo del vehiculo actual: ");
            fflush(stdout);
            scanf (" %[^\n]%*c", modelo);
            validaEdita = editaModeloV(inicioVehiculos, modelo, placa);

            if(strcmp(validaEdita->modelo, modelo) == 0)
            {
                printf("\nSe edito correctamente el modelo del vehiculo...");
                return 1;
            }


            break;

        case 3:         //edita Placa

            printf("\n Ruta Principal/Usuarios/EditarVehiculo/Placa");
            printf("\n\n-------- Editar Vehiculo -------");
            printf("\nDame el nuevo numero de placas del vehiculo actual: ");
            fflush(stdout);
            scanf (" %[^\n]%*c", placaS);
            validaEdita = editaPlacaV(inicioVehiculos, placaS, placa);

            if(strcmp(validaEdita->placa, placaS) == 0)
            {
                printf("\nSe edito correctamente las placas del vehiculo...");
                return 1;
            }

            break;



            break;

        default:
            printf("\nOpcion Incorrecta....");
            break;
    }


    return 0;

}


AUTOMOVIL* editaMarcaV(AUTOMOVIL **inicioVehiculos, char marca[15], char placa[8])
{

    char limpia[15] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    if(strcmp((*inicioVehiculos)->placa, placa) == 0)
    {

        strcpy((*inicioVehiculos)->marca, limpia);
        strcpy((*inicioVehiculos)->marca, marca);
        return *inicioVehiculos;

    }

    editaMarcaV(&((*inicioVehiculos)->siguiente), marca, placa);

}

AUTOMOVIL* editaModeloV(AUTOMOVIL **inicioVehiculos, char modelo[20], char placa[8])
{

    char limpia[20] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    if(strcmp((*inicioVehiculos)->placa, placa) == 0)
    {

        strcpy((*inicioVehiculos)->modelo, limpia);
        strcpy((*inicioVehiculos)->modelo, modelo);
        return *inicioVehiculos;

    }

    editaModeloV(&((*inicioVehiculos)->siguiente), modelo, placa);

}

AUTOMOVIL* editaPlacaV(AUTOMOVIL **inicioVehiculos, char placaS[8], char placa[8])
{

    char limpia[20] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    if(strcmp((*inicioVehiculos)->placa, placa) == 0)
    {

        strcpy((*inicioVehiculos)->placa, limpia);
        strcpy((*inicioVehiculos)->placa, placaS);
        return *inicioVehiculos;

    }

    editaPlacaV(&((*inicioVehiculos)->siguiente), placaS, placa);

}

AUTOMOVIL* asignaVehiculoUser(DATOSUSUARIO **inicioUsuarios, AUTOMOVIL **inicioVehiculos, char placa[8], int idBusca)
{
    printf("\nEntra asigna vehiculo");
    AUTOMOVIL *asignaVehiculo = NULL;
    DATOSUSUARIO *asignaUsuario = NULL;


    asignaUsuario = buscarElementoUser(inicioUsuarios, idBusca);
    asignaVehiculo = buscarVehiculo(inicioVehiculos, placa);

    if(asignaVehiculo == NULL || asignaUsuario == NULL)
    {
        printf("\nEl ID del Usuario o las Placas que introduciste no corresponde a ninguno de los datos solicitados...");
        return NULL;
    }

    printf("\nvehiculo: %s placa: %s", asignaVehiculo->modelo, asignaVehiculo->placa);
    printf("\nusuario: %s id: %d", asignaUsuario->nombre, asignaUsuario->id);

    asignaVehiculo->usuario = asignaUsuario;

    return asignaVehiculo;

}

ELEMENTOPILA* estacionarVehiculo(AUTOMOVIL **inicioVehiculos, char placa[8], ELEMENTOPILA **topePila, ELEMENTOLOTE **lote, int *tamanoPila)
{
    int tiempo;

    AUTOMOVIL *vehiculo = NULL;

    vehiculo = buscarVehiculo(inicioVehiculos, placa);
    printf("\nvehiculo: %s", vehiculo->modelo);

    printf("\nDame el numero de horas que se va a quedar Aparcado: ");
    scanf("%d", &tiempo);

    meteVehiculo(&vehiculo, tiempo, &tope, &lote, &tamanoPila);





}

ELEMENTOPILA* meteVehiculo(AUTOMOVIL *vehiculo, int tiempo, ELEMENTOPILA **topePila, ELEMENTOLOTE **lote, int *tamanoPila)
{
    ELEMENTOPILA *nuevoElemePila = NULL;

    if(pilaVacia(tamanoPila) == 1 || pilaLlena(tamanoPila) == 0)
    {
        nuevoElemePila = (ELEMENTOPILA*) malloc(sizeof(ELEMENTOPILA));

        if(nuevoElemePila == NULL)
        {
            printf("\nError de alojamiento de memoria...");
            return NULL;

        }




    }




}

int pilaVacia(int tamanoPila)
{
    if(tamanoPila == -1)
        return 1;
    return 0;
}

int pilaLlena(int tamanoPila)
{
    if(tamanoPila == 2)
        return 1;
    return 0;
}











