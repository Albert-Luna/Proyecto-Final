#include <stdio.h>
#include <math.h>


#define PI 3.14159265
#define VELOCIDAD_LUZ 300000000.0


void LeyOhm() {


       int opcion;
    float voltaje, corriente, resistencia;

    printf("\nLey de ohm\n");
    printf("Seleccione qué desea calcular:\n");
    printf("1. Voltaje (V)\n");
    printf("2. Corriente (I)\n");
    printf("3. Resistencia (R)\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
           
            printf("Ingrese el valor de la corriente  ");
            scanf("%f", &corriente);
            printf("Ingrese el valor de la resistencia");
            scanf("%f", &resistencia);
            voltaje = corriente * resistencia;
            printf("El voltaje es: %.2f V\n", voltaje);
            break;

        case 2:
          
            printf("Ingrese el valor del voltaje ");
            scanf("%f", &voltaje);
            printf("Ingrese el valor de la resistencia ");
            scanf("%f", &resistencia);
            if (resistencia != 0) {
                corriente = voltaje / resistencia;
                printf("La corriente es: %.2f A\n", corriente);
            } 
            break;

        case 3:
           
            printf("Ingrese el valor del voltaje ");
            scanf("%f", &voltaje);
            printf("Ingrese el valor de la corriente ");
            scanf("%f", &corriente);
            if (corriente != 0) {
                resistencia = voltaje / corriente;
                printf("La resistencia es: %.2f Ω\n", resistencia);
            } 
            break;

        default:
            printf("Opción no válida. Intente de nuevo.\n");
            break;
    }
}


void BancoCapacitores() {
    float voltaje, frecuencia, potenciaActiva, fp_inicial;
    float fp_objetivo = 0.95;
    float q_inicial, q_objetivo, q_correccion, capacitancia;

    // Entrada de datos
    printf("introduzca el voltaje");
    scanf("%f", &voltaje);
    printf("introduzca la frecuencia");
    scanf("%f", &frecuencia);
    printf("introduzca la potencia");
    scanf("%f", &potenciaActiva);
    printf("Factor de potencia actual");
    scanf("%f", &fp_inicial);

   
    q_inicial = potenciaActiva * tan(acos(fp_inicial));  // Potencia reactiva inicial
    q_objetivo = potenciaActiva * tan(acos(fp_objetivo)); // Potencia reactiva deseada
    q_correccion = q_inicial - q_objetivo; // Potencia reactiva que debe compensarse con capacitores

 
    capacitancia = (1000000 * q_correccion) / (2 * 3.14159265 * frecuencia * voltaje * voltaje);

    
    printf("La capacitancia necesaria del banco de capacitores es: %.2f µF y la potencia es %.2f \n", capacitancia, q_correccion);
}


void DBGanancia() {
    float dB, ganancia;

  
    printf("Ingrese el valor en dB: ");
    scanf("%f", &dB);

    ganancia = pow(10, dB / 20);

    
    printf("La ganancia de voltaje es: %.2f\n", ganancia);
}



// Función para calcular reactancia inductiva o capacitiva
void Reactancia() {
    int opcion;
    float frecuencia, valor, reactancia;

    // Pregunta al usuario qué tipo de reactancia quiere calcular
    printf("Seleccione el tipo de reactancia que desea calcular:\n");
    printf("1. Reactancia Inductiva\n");
    printf("2. Reactancia Capacitiva\n");
    scanf("%d", &opcion);

    printf("Ingrese el valor de la frecuencia (Hz): ");
    scanf("%f", &frecuencia);

    if (opcion == 1) {
       
        printf("Ingrese el valor de la inductancia (H): ");
        scanf("%f", &valor);
        reactancia = 2 * PI * frecuencia * valor;
        printf("La reactancia inductiva (X_L) es: %.2f Ω\n", reactancia);
    } else if (opcion == 2) {
        // Cálculo de la reactancia capacitiva
        printf("Ingrese el valor de la capacitancia (F): ");
        scanf("%f", &valor);
        reactancia = 1 / (2 * PI * frecuencia * valor);
        printf("La reactancia capacitiva (X_C) es: %.2f Ω\n", reactancia);
    } else {
        printf("Opción no válida. Intente de nuevo.\n");
    }
}

void LongitudOnda() {
    float frecuencia, longitudOnda;

   
    printf("Ingrese la frecuencia : ");
    scanf("%f", &frecuencia);

  
    if (frecuencia != 0) {
        longitudOnda = VELOCIDAD_LUZ / frecuencia;
        printf("La longitud de onda es: %.2f metros\n", longitudOnda);
    } else {
        printf("frecuencia no puede ser cero.\n");
    }
}


void convertir_complejo() {
    int opcion;
    float x, y, r, theta;

    printf("Conversión de números complejos:\n");
    printf("1. Convertir de rectangular a polar\n");
    printf("2. Convertir de polar a rectangular\n");
    printf("Elige una opción (1 o 2): ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        // Conversión de rectangular a polar
        printf("Introduce la parte real (x): ");
        scanf("%f", &x);
        printf("Introduce la parte imaginaria (y): ");
        scanf("%f", &y);

        r = sqrt(x * x + y * y);           // Magnitud
        theta = atan2(y, x) * (180.0f / PI); // Ángulo en grados

        printf("Forma polar:\n");
        printf("Magnitud (r) = %.2f\n", r);
        printf("Ángulo (θ) = %.2f grados\n", theta);
    } 
    else if (opcion == 2) {
        // Conversión de polar a rectangular
        printf("Introduce la magnitud (r): ");
        scanf("%f", &r);
        printf("Introduce el ángulo (θ en grados): ");
        scanf("%f", &theta);

        float theta_rad = theta * (PI / 180.0f);
        x = r * cos(theta_rad);   // Parte real
        y = r * sin(theta_rad);   // Parte imaginaria

        printf("Forma rectangular:\n");
        printf("Parte real (x) = %.2f\n", x);
        printf("Parte imaginaria (y) = %.2f\n", y);
    } 
    else {
        printf("Opción no válida.\n");
    }
}

void estado_estable_serie() {
    float V, R, C, L ;
    float f = 60;
    
    // Solicitar valores al usuario
    printf("Introduce el voltaje de la fuente : ");
    scanf("%f", &V);
    printf("Introduce la resistencia : ");
    scanf("%f", &R);
    printf("Introduce la capacitancia: ");
    scanf("%f", &C);
    printf("Introduce la inductancia: ");
    scanf("%f", &L);
   

    // Calcular valores necesarios
    float omega = 2 * PI * f;
    float X_L = omega * L;                  // Reactancia inductiva
    float X_C = 1 / (omega * C);            // Reactancia capacitiva
    float Z = sqrt(R * R + (X_L - X_C) * (X_L - X_C)); // Impedancia total
    float I = V / Z;                        // Corriente total

    
    float V_R = I * R;
    float V_L = I * X_L;
    float V_C = I * X_C;

    // Mostrar los resultados
    printf("\nAnálisis de estado estable en CA:\n");
    printf("Impedancia total = %.2f ohmios\n", Z);
    printf("Corriente total= %.2f A\n", I);
    printf("Voltaje en la resistencia = %.2f V\n", V_R);
    printf("Voltaje en el inductor = %.2f V\n", V_L);
    printf("Voltaje en el capacitor = %.2f V\n", V_C);
}

void estable_paralelo() {
    float V, R, C, L;

    float f = 60;
    
    // Solicitar valores al usuario
    printf("Introduce el voltaje de la fuente (V): ");
    scanf("%f", &V);
    printf("Introduce la resistencia (R) en ohmios: ");
    scanf("%f", &R);
    printf("Introduce la capacitancia (C) en faradios: ");
    scanf("%f", &C);
    printf("Introduce la inductancia (L) en henrios: ");
    scanf("%f", &L);
   

    // Calcular valores necesarios
    float omega = 2 * PI * f;
    float X_L = omega * L;                  // Reactancia inductiva
    float X_C = 1 / (omega * C);            // Reactancia capacitiva
    
    // Corrientes en cada componente
    float I_R = V / R;                      // Corriente en la resistencia
    float I_L = V / X_L;                    // Corriente en el inductor
    float I_C = V * omega * C;              // Corriente en el capacitor
    
    // Corriente total (suma vectorial)
    float I_total = sqrt(I_R * I_R + pow(I_L - I_C, 2));

    // Impedancia total
    float Z = V / I_total;

    // Mostrar los resultados
    printf("\nAnálisis de estado estable en CA (Circuito en paralelo):\n");
    printf("Impedancia total (Z) = %.2f ohmios\n", Z);
    printf("Corriente total (I) = %.2f A\n", I_total);
    printf("Corriente en la resistencia (I_R) = %.2f A\n", I_R);
    printf("Corriente en el inductor (I_L) = %.2f A\n", I_L);
    printf("Corriente en el capacitor (I_C) = %.2f A\n", I_C);
}

