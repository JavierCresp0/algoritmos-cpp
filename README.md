# ⚙️ Algoritmos en C++ · Metodología y Programación Avanzada

Conjunto de implementaciones en **C++** de algoritmos clásicos vistos en la asignatura **Metodología y Programación Avanzada** (1º curso, 2022) cursada en el **Politécnico de Leiria (Portugal)**. Incluye desde técnicas básicas (ordenación, recursividad) hasta algoritmos avanzados (Dijkstra, backtracking).

## 📚 Contenido

| Carpeta | Algoritmo / Técnica | Descripción |
|---------|---------------------|-------------|
| `01-MPAirlines-Dijkstra/` | **Dijkstra** sobre grafo ponderado | Cálculo de la ruta de vuelo más barata entre ciudades |
| `02-Mochila-Backtracking/` | **Mochila 0/1** con backtracking | Problema clásico de optimización combinatoria con poda |
| `Ejercicios/ordenacion_insercion.cpp` | Ordenación por **inserción** | Implementación y medición de tiempos (mejor, peor y caso medio) |
| `Ejercicios/potencia_recursiva_vs_iterativa.cpp` | **Potencia**: recursiva vs iterativa | Comparativa de enfoques con traza |
| `Ejercicios/potencia_divide_venceras.cpp` | **Potencia rápida** (divide y vencerás) | Optimización del cálculo de aⁿ |
| `Ejercicios/merge_sort.cpp` | **Merge sort** | Ordenación por mezcla (divide y vencerás) |
| `Ejercicios/voraz_scheduling.cpp` | Algoritmo **voraz** (scheduling) | Minimización del tiempo medio de espera |
| `Ejercicios/voraz_scheduling_fichero.cpp` | Variante del voraz anterior | Lectura de los tiempos desde fichero |
| `Ejercicios/mochila_programacion_dinamica.cpp` | **Mochila 0/1** con programación dinámica | Tabla de subproblemas y reconstrucción de la solución |

## ⭐ Proyectos destacados

### 🛫 MPAirlines — Algoritmo de Dijkstra
Aplicación interactiva por menús que carga una matriz de adyacencia con precios de vuelos desde `vuelos.txt` y calcula:
- **Ruta más barata** entre dos ciudades (Dijkstra)
- **Reconstrucción del camino** completo
- **Coste total** del trayecto

Maneja **gestión dinámica de memoria** (matrices `float**`, arrays auxiliares `C`, `P`, `S`) y entrada/salida de ficheros.

### 🎒 Mochila 0/1 — Backtracking
Resuelve el problema clásico de la mochila por backtracking, explorando el árbol de combinaciones posibles con **poda** para descartar ramas no prometedoras. Reconstruye también la **mochila óptima** y muestra opcionalmente la **traza** del algoritmo.

## 🛠️ Tecnologías

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat&logo=c%2B%2B&logoColor=white)
![GCC](https://img.shields.io/badge/GCC-A42E2B?style=flat&logo=gnu&logoColor=white)

## 🎯 Técnicas algorítmicas aplicadas

- **Voraces (greedy)**: scheduling, minimización de tiempo medio
- **Divide y vencerás**: merge sort, potencia rápida
- **Backtracking**: mochila 0/1 con poda
- **Grafos**: representación con matriz de adyacencia, Dijkstra
- **Recursividad**: comparada con su variante iterativa
- **Gestión dinámica de memoria** en C++

## 🚀 Compilación y ejecución

```bash
# Compilar un ejercicio
g++ -O2 -o mpairlines 01-MPAirlines-Dijkstra/MPAirlines.cpp
./mpairlines

# La mochila
g++ -O2 -o mochila 02-Mochila-Backtracking/p8_mochila.cpp
./mochila
```

### Formato de `vuelos.txt` (MPAirlines)
Matriz cuadrada N×N con los precios de los vuelos directos. Una celda con `0` indica que no existe vuelo directo. El programa interpreta el grafo como dirigido.

## 👥 Coautoría

Algunos de estos ejercicios fueron desarrollados en pareja con **Luis David Díaz Mesa** durante la asignatura.

---

📌 *Asignatura del 1º curso del Grado en Ingeniería Informática — Politécnico de Leiria (Portugal) / Universidad Miguel Hernández.*
