# Acceso a Memoria en C++

## Descripción

Este proyecto evalúa el impacto del patrón de acceso a memoria y del tipo de dato sobre el rendimiento de una operación matricial en C++.

Se implementan tres versiones de un mismo algoritmo para comparar los tiempos de ejecución utilizando diferentes órdenes de recorrido de la matriz y diferentes tipos de datos (`float` y `double`).

El programa ejecuta múltiples pruebas para distintos tamaños de matriz y calcula estadísticas como el tiempo promedio y la desviación estándar de cada implementación.

---

## Objetivo

Analizar cómo factores como:

- El orden de acceso a la memoria (localidad de referencia).
- El tipo de dato utilizado (`float` vs `double`).

afectan el tiempo de ejecución de un algoritmo.

---

## Tecnologías utilizadas

- C++
- STL (`vector`)
- `<chrono>` para medición de tiempos
- `<cmath>` para cálculos estadísticos

---

## Versiones implementadas

### Versión A
- Tipo de dato: `float`
- Acceso a la matriz: `A[k][i]`

### Versión B
- Tipo de dato: `float`
- Acceso a la matriz: `A[i][k]`

### Versión C
- Tipo de dato: `double`
- Acceso a la matriz: `A[k][i]`

---

## Funcionalidades

- Comparación de tres implementaciones del mismo algoritmo.
- Ejecución automática para diferentes tamaños de matriz.
- Realización de 30 muestras por cada caso.
- Cálculo del tiempo promedio.
- Cálculo de la desviación estándar.
- Presentación de resultados por consola.

---

## Tamaños evaluados

El programa realiza pruebas para matrices de tamaño:

- 64 × 64
- 128 × 128
- 256 × 256
- 512 × 512
- 1024 × 1024
- 2048 × 2048

---

## Conceptos aplicados

- Análisis de rendimiento
- Benchmarking
- Localidad espacial de memoria
- Complejidad computacional
- Estadística básica aplicada al rendimiento
- Optimización de código

---


---

## Ejemplo de salida

```
N = 512

VERSION A
Media: xxxx us
Desviación: xxxx us

VERSION B
Media: xxxx us
Desviación: xxxx us

VERSION C
Media: xxxx us
Desviación: xxxx us
```

---

## Autor

Veronica Flor Escobar

Estudiante de Ingeniería de Sistemas  
Universidad Icesi
