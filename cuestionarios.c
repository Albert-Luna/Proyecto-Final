#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char pregunta[256];
    char opciones[4][100];
    char respuesta_correcta;
} Pregunta;

// Prototipos de funciones para las diferentes manipulaciones de datos
void cargar_preguntas(Pregunta *preguntas, int *total_preguntas);
void mostrar_pregunta(Pregunta p);
char obtener_respuesta();
void validar_respuesta(Pregunta p, char respuesta, int *puntaje);
void guardar_resultados(int puntaje, int total_preguntas);
void iniciar_cuestionario();

void cargar_preguntas(Pregunta *preguntas, int *total_preguntas) {
    FILE *file = fopen("preguntas.txt", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo de preguntas.\n");
        return;
    }
    while (fscanf(file, "%[^\n]\n", preguntas[*total_preguntas].pregunta) != EOF) {
        for (int i = 0; i < 4; i++) {
            fscanf(file, "%[^\n]\n", preguntas[*total_preguntas].opciones[i]);
        }
        fscanf(file, "%c\n", &preguntas[*total_preguntas].respuesta_correcta);
        (*total_preguntas)++;
    }
    fclose(file);
}

void mostrar_pregunta(Pregunta p) {
    printf("%s\n", p.pregunta);
    for (int i = 0; i < 4; i++) {
        printf("%c) %s\n", 'a' + i, p.opciones[i]);
    }
}

char obtener_respuesta() {
    char respuesta;
    printf("Seleccione una respuesta (a, b, c, d): ");
    scanf(" %c", &respuesta);
    return respuesta;
}

void validar_respuesta(Pregunta p, char respuesta, int *puntaje) {
    if (respuesta == p.respuesta_correcta) {
        printf("¡Correcto!\n");
        (*puntaje)++;
    } else {
        printf("Incorrecto. La respuesta correcta es: %c\n", p.respuesta_correcta);
    }
}

void guardar_resultados(int puntaje, int total_preguntas) {
    FILE *file = fopen("resultados.txt", "a");
    if (file != NULL) {
        fprintf(file, "Puntaje: %d/%d\n", puntaje, total_preguntas);
        fclose(file);
    } else {
        printf("Error al guardar los resultados.\n");
    }
}

void iniciar_cuestionario() {
    Pregunta preguntas[100];
    int total_preguntas = 0, puntaje = 0;

    cargar_preguntas(preguntas, &total_preguntas);
    if (total_preguntas == 0) {
        printf("No hay preguntas disponibles.\n");
        return;
    }

    printf("Iniciando cuestionario. Responda las siguientes preguntas:\n\n");
    for (int i = 0; i < 5 && i < total_preguntas; i++) {
        mostrar_pregunta(preguntas[i]);
        char respuesta = obtener_respuesta();
        validar_respuesta(preguntas[i], respuesta, &puntaje);
    }

    guardar_resultados(puntaje, 5);
    printf("Cuestionario terminado. Puntaje final: %d/5\n", puntaje);
}


void menuCuestionarios() {
    int opcion;
    printf("\n--- Simulador de Cuestionarios Técnicos ---\n");
    printf("1. Electrónica Básica\n");
    printf("2. Matemática\n");
    printf("3. Programación\n");
    printf("0. Regresar\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            iniciar_cuestionario("electronica.txt");
            break;
        case 2:
            iniciar_cuestionario("matematica.txt");
            break;
        case 3:
            iniciar_cuestionario("programacion.txt");
            break;
        case 0:
            printf("Regresando al menú principal.\n");
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }
}