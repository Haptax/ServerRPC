/*
 * calculadora_server.c
 * Implementación de las funciones del servidor RPC
 */

#include "calculadora.h" // Incluye el archivo de encabezado generado por rpcgen
#include <stdio.h>       // Para printf
#include <stdlib.h>      // Para exit y atof
#include <math.h>        // Para manejar NaN/Infinity en división por cero (opcional)

// Implementación de la función de suma
float * sum_1_svc(inputs *argp, struct svc_req *rqstp)
{
    static float result; // Variable estática para almacenar el resultado

    printf("Servidor: Proceso de suma activo.\n");
    // Realiza la suma de los dos números obtenidos y los almacena en la variable 'result'
    result = argp->num1 + argp->num2;
    printf("Servidor: Solicitud recibida: Sumar %f + %f\n", argp->num1, argp->num2);
    printf("Servidor: Resultado: %f\n", result);

    return &result; // Retorna la dirección de la variable estática al cliente
}

// Implementación de la función de resta
float * res_1_svc(inputs *argp, struct svc_req *rqstp)
{
    static float result; // Variable estática para almacenar el resultado

    printf("Servidor: Proceso de resta activo.\n");
    // Realiza la resta de los dos números obtenidos y los almacena en la variable 'result'
    result = argp->num1 - argp->num2;
    printf("Servidor: Solicitud recibida: Restar %f - %f\n", argp->num1, argp->num2);
    printf("Servidor: Resultado: %f\n", result);

    return &result; // Retorna la dirección de la variable estática al cliente
}

// Implementación de la función de multiplicación
float * mul_1_svc(inputs *argp, struct svc_req *rqstp)
{
    static float result; // Variable estática para almacenar el resultado

    printf("Servidor: Proceso de multiplicación activo.\n");
    // Realiza la multiplicación de los dos números obtenidos y los almacena en la variable 'result'
    result = argp->num1 * argp->num2;
    printf("Servidor: Solicitud recibida: Multiplicar %f * %f\n", argp->num1, argp->num2);
    printf("Servidor: Resultado: %f\n", result);

    return &result; // Retorna la dirección de la variable estática al cliente
}

// Implementación de la función de división
float * div_1_svc(inputs *argp, struct svc_req *rqstp)
{
    static float result; // Variable estática para almacenar el resultado

    printf("Servidor: Proceso de división activo.\n");
    printf("Servidor: Solicitud recibida: División %f / %f\n", argp->num1, argp->num2);

    if (argp->num2 == 0.0) {
        // Manejo de la división por cero en el servidor.
        // Podrías devolver un valor específico o usar una señal de error.
        // Para RPC, si se devuelve NULL, el cliente podría detectarlo como un error de llamada.
        // Sin embargo, si el cliente ya verifica 0, esto es una capa de seguridad.
        printf("Servidor: ERROR: División por cero no permitida.\n");
        // Establecer un resultado que indique un error, por ejemplo, NaN o un valor centinela.
        // En RPC, el resultado se espera, por lo que devolver un valor no válido es común.
        result = NAN; // Not a Number, requiere <math.h>
    } else {
        // Realiza la división de los dos números obtenidos y los almacena en la variable 'result'
        result = argp->num1 / argp->num2;
        printf("Servidor: Resultado: %f\n", result);
    }

    return &result; // Retorna la dirección de la variable estática al cliente
}
