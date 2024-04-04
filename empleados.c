#include <stdio.h>
#define LONG_NOMBRE 40
#define CANT_MAX 2
#define MONEY 36
#define NUM 167
#define AT 160
#define IT 161
#define OT 162
#define UT 163

typedef struct{
    char nombre[LONG_NOMBRE];
    unsigned int edad;
    float salario;
}datos;

void menu (datos[]);
void ingresarDatos(datos[], int);
void procesarDatos(datos[], int);
void mostrarDatos(datos[], int);

int main (void){
    datos empleado[CANT_MAX];
    menu(empleado);
    return 0;
}
//ver como meter funciones adentro de funciones :v vamos reini vos podes 0-0 omg lol (estoy entrando en demencia) lmao
void menu (datos empleado[]){
    int Opcion_Elegida, Cant_Empleados;
    printf("\n-----Men%c-----\nBienvenido al programa.\nAqu%c podr%c ingresar y mostrar la informaci%cn de sus empleados.\nPor favor, ingrese 1, 2 o 3 dependiendo de su necesidad.\n\n", UT, IT, AT, OT);
    do{
        printf("1. Ingresar datos de un empleado.\n");
        //ingresar datos
        printf("2. Mostrar informaci%cn relevante.\n", OT);
        //Procesar y Mostrar datos
        printf("3. Salir.\n");
        //chau
        do{
            printf("ingrese su opci%cn: ", OT);
            scanf("%i", &Opcion_Elegida);
            if (Opcion_Elegida != 1 && Opcion_Elegida != 2 && Opcion_Elegida != 3){
                printf("La opci%cn que usted eligi%c no est%c permitida. Por favor, ingrese 1, 2 o 3 cual sea su preferencia.\n", OT, OT, AT);
            }
        } while (Opcion_Elegida != 1 && Opcion_Elegida != 2 && Opcion_Elegida != 3);
        if (Opcion_Elegida >= 1 && Opcion_Elegida <= 2) {
            switch (Opcion_Elegida){
                case 1:
                printf("\nCu%cntos empleados quiere ingresar%c. El m%cximo es de cinco.\n", AT, 63, AT);
                do{
                printf("Cantidad de empleados a ingresar: ");
                scanf("%i", &Cant_Empleados);
                if (Cant_Empleados > CANT_MAX && Cant_Empleados < 0){
                    printf("Cantidad no permitida. Por favor, ingrese un valor entre 1 y 5.\n");
                }
                } while (Cant_Empleados > CANT_MAX && Cant_Empleados < 0);
                ingresarDatos(empleado, Cant_Empleados);
                break;
                case 2:
                procesarDatos(empleado, Cant_Empleados);
                mostrarDatos(empleado, Cant_Empleados);
                break;
            }
        }
    } while (Opcion_Elegida != 3);
    printf("Hasta luego!\n");

}

void ingresarDatos(datos empleado [], int Cant_Empleados){
    for (int i = 0; i < Cant_Empleados; i++){
        //Pedimos el nombre de los empleados basados en la cantidad que ingresamos anteriormente
        printf("Empleado N%c %i.\n", NUM, i+1);
        printf("Nombre del empleado: ");
        scanf("\n%[^\n]s", &empleado[i].nombre);
        do{
            //Luego la edad (que debe ser mayor a 1)
            printf("Edad del empleado: ");
            scanf("%i", &empleado[i].edad);
            if (empleado[i].edad < 1){
                printf("Se debe ingresar una edad con un valor mayor a cero. Por favor, vuelva a ingresarlo.\n");
            }      
        } while (empleado[i].edad < 1);
        do{
            //Y por último el salario (que debe ser mayor a 0)
            printf("Salario del empleado (en d%clares): ", OT);
            scanf("%f", &empleado[i].salario);
            if (empleado[i].salario < 0){
                printf("Se debe ingresar un salario con un valor mayor a uno. Por favor, vuelva a ingresarlo.\n");
            } 
        } while ((empleado[i].salario < 0));
        printf("\n");
    }
    printf("\nDatos ingresados de forma correcta.\n");
    printf("-----------------------------------------------------------------------------------\n");
}

void procesarDatos(datos empleado[], int Cant_Empleados){
    /*inicializo mis variables, float para los promedios siendo q pueden dar con coma
    el mayor debe ser un int debido a que usaré ese valor para indicar en el vector quien tiene */
    float prom = 0, Mayor_Sal = 0;
    int i_Mayor_Sal= 0, i_Igual_Sal = 0;
    for (int i = 0; i < Cant_Empleados; i++){
        //sumo todos los salarios
        prom += empleado[i].salario;
    }
    //y los divido por la cantidad de empleados, obteniendo así el promedio de salarios
    prom /= Cant_Empleados;
    printf("\nEl promedio de salarios es de: %c%f\n", MONEY, prom);
    for (int i = 0; i < Cant_Empleados; i++){
        if(empleado[i].salario > Mayor_Sal){
            Mayor_Sal = empleado[i].salario;
            i_Mayor_Sal = i;
        } 
    }
    printf("El empleado con el mayor salario es: %s, con un valor de %c%f\n", empleado[i_Mayor_Sal].nombre, MONEY, empleado[i_Mayor_Sal].salario);
    printf("-----------------------------------------------------------------------------------\n");
}


void mostrarDatos(datos empleado[], int Cant_Empleados){
    printf("Informaci%cn empleados:\n", OT);
    for (int i = 0; i < Cant_Empleados; i++){
        printf("Empleado %d: Nombre: %s, edad: %i, salario: %c%f\n", i + 1, empleado[i].nombre, empleado[i].edad, MONEY, empleado[i].salario);
    }
    printf("-----------------------------------------------------------------------------------\n");
}