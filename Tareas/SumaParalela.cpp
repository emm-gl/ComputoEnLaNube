// Computo en la nube
//23.01.23
//Emmanuel González Calitl A01320739
//Este código realiza la suma de dos arreglos de manera paralela
//Código fuente para ser compilado y ejecutado desde: https://www.codingame.com/playgrounds/54443/openmp/playground debido a falta de entorno de desarrollo en Visual Studio.



//#include "pch.h"      
#include <iostream>
#include <omp.h>

#define N 1000
#define chunk 100
#define mostrar 10

void imprimeArreglo (float *d);

int main()
{
    std::cout << "Sumando Arreglos en Paralelo!\n"; 
    float a[N], b[N], c[N];
    int i;

    // Generación o petición de la información para llenar los arreglos:
    for (i = 0; i < N; i++)
    {
        a[i] = i * 10;
        b[i] = (i + 3) * 3.7;
    }
    int pedazos = chunk;

    #pragma omp parallel for\
            shared (a, b, c, pedazos) private(i)\
            schedule(static, pedazos)

            // Uso correcto del for paralelo:
            for (i = 0; i < N; i++)
                    c[i] = a[i] + b[i];

    // Impresión de los elementos de cada arreglo:
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl; 
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl; 
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl; 
    imprimeArreglo(c);
}

// Función para la impresión de los elementos de cada arreglo 
void imprimeArreglo (float *d)
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}