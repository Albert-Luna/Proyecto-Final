/*----------------------------------------------------------------
|  Autor: Albert Luna                  Matricula: 1-22-1500      |
|  Fecha: 1-11-2024                     Versión: No.2           |
|-----------------------------------------------------------------|
|  Descripción del Programa: Calculadora técnica y simulador de  |
|  cuestionarios técnicos sobre diversos temas.                  |
| ----------------------------------------------------------------*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.c"
#include "cuestionarios.c"

// Credenciales
#define USERNAME "Albert"
#define DEFAULT_PASSWORD "1221500"
#define PASSWORD_FILE "contrasena.txt"

// Prototipos de funciones
void mostrarMenu();
void cambiarContrasena();
void cargarContrasena(char *password);
void guardarContrasena(const char *password);

int main() {
    char username[20], password[20], storedPassword[20];
    int intentos = 3;
    int opcion;

    // Cargar la contraseña almacenada o usar la por defecto
    cargarContrasena(storedPassword);

    while (intentos > 0) {
        printf("Ingrese el nombre de usuario: ");
        scanf("%s", username);
        printf("Ingrese la contraseña: ");
        scanf("%s", password);

        if (strcmp(username, USERNAME) == 0 && strcmp(password, storedPassword) == 0) {
            printf("\nBienvenido, %s!\n", username);
            break;
        } else {
            intentos--;
            printf("Usuario o contraseña incorrectos. Intentos restantes: %d\n", intentos);
        }
    }

    if (intentos == 0) {
        printf("Demasiados intentos fallidos.\n");
        return 1;
    }

 
    do {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                 LeyOhm();
                break;
            case 2:
                BancoCapacitores();
                break;
            case 3:
                Reactancia();
                break;
            case 4:
                DBGanancia();
                break;
            case 5:
                LongitudOnda();
                break;
            case 6:
                convertir_complejo();
                break;
            case 7:
                estado_estable_serie();
                break;
            case 8:
                estable_paralelo();
                break;
            case 9:
                iniciar_cuestionario();
                break;
            case 10:
                cambiarContrasena();

                cargarContrasena(storedPassword); // Actualizar la contraseña guardada en el archivo
                break;
            case 0:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}

// Función para mostrar el menú
void mostrarMenu() {
    printf("\n--- Menú ---\n");
    printf("1. Calcular Ley de Ohm\n");
    printf("2. Calculo de Banco de Capacitores\n");
    printf("3. Calcular Reactancia\n");
    printf("4. Conversión de dB a Ganancia\n");
    printf("5. Calcular Longitud de Onda\n");
    printf("6. Conversión rectangular a polar\n");
    printf("7. Estado estable serie\n");
    printf("8. Estado estable paralelo\n");
    printf("9. Simulador de Cuestionarios Técnicos\n");
    printf("10. Cambiar contraseña\n");
    printf("0. Salir\n");
    printf("Seleccione una opción: ");
}



void cambiarContrasena() {
    char nuevaContrasena[20], confirmacion[20];

    printf("Introduzca la nueva contraseña: ");
    scanf("%s", nuevaContrasena);
    printf("Confirme la nueva contraseña: ");
    scanf("%s", confirmacion);

    if (strcmp(nuevaContrasena, confirmacion) == 0) {
        guardarContrasena(nuevaContrasena);
        printf("Contraseña cambiada exitosamente.\n");
    } else {
        printf("Las contraseñas no coinciden. Inténtelo nuevamente.\n");
    }
}


void cargarContrasena(char *password) {
    FILE *file = fopen(PASSWORD_FILE, "rt");
    if (file == NULL) {
        
        strcpy(password, DEFAULT_PASSWORD);
    } else {
        fscanf(file, "%s", password);
        fclose(file);
    }
}


void guardarContrasena(const char *password) {
    FILE *file = fopen(PASSWORD_FILE, "wt");
    if (file == NULL) {
        printf("Error al guardar la contraseña.\n");
        return;
    }
    fprintf(file, "%s", password);
    fclose(file);
}
