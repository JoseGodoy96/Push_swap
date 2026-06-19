# Push_swap
 
> A C program that sorts a stack of integers using a limited set of operations,
> aiming to do it with the **fewest possible moves**.
 
Project completed at the **42** school (42 Málaga campus). Since it is an already
evaluated and closed submission, the repository contains **a single commit**: the
project is **finished** and receives no further changes.
 
---
 
## 📖 Description
 
**Push_swap** is one of 42's classic algorithmic projects. The goal is to sort a
series of numbers received as arguments using **two stacks** (`a` and `b`) and a
reduced set of operations. The project's grade depends directly on **efficiency**:
the fewer moves used to sort, the better.
 
The program:
 
1. **Parses and validates** the arguments (it accepts loose numbers or a single
   string containing several numbers). It detects non-numeric input, duplicates, and
   values outside the `int` range, exiting with `Error` when appropriate.
2. **Builds stack `a`** on top of a doubly linked list and normalizes the values to
   indices to make sorting easier.
3. **Sorts** using special cases for small sizes (2 and 3 elements) and, for the
   rest, a **cost algorithm** that computes, for each element of `b`, its target
   position in `a` and the cost of the rotations, always executing the cheapest move.
4. **Prints** to standard output the sequence of operations performed.
---
 
## ⚙️ Available operations
 
| Operation | Effect                                                             |
| --------- | ------------------------------------------------------------------ |
| `sa` / `sb` / `ss` | Swap the first two elements of `a` / `b` / both.          |
| `pa` / `pb`        | Move the first element of one stack to the other.         |
| `ra` / `rb` / `rr` | Rotate `a` / `b` / both upward.                           |
| `rra`/ `rrb`/ `rrr`| Rotate `a` / `b` / both downward.                         |
 
---
 
## 🧠 The algorithm
 
- **2 elements** → a single `sa` if needed.
- **3 elements** → direct sorting with predefined cases.
- **More elements** → **cost algorithm (Turk style):**
  1. The elements are pushed to stack `b`.
  2. For each node in `b`, its **target position** in `a` and the **cost** (number
     of rotations) in both stacks are computed.
  3. The **cheapest** move is selected (combining single and double rotations when
     possible) and executed.
  4. This repeats until `b` is empty, and finally `a` is rotated until the minimum is
     on top.
Each node's structure stores the value, its normalized index, the position, and the
precomputed costs:
 
```c
typedef struct s_list
{
    int             value;
    int             index;
    int             position;
    int             target;
    int             cost_a;
    int             cost_b;
    struct s_list   *prev;
    struct s_list   *next;
}   t_list;
```
 
---
 
## 🗂️ Project structure
 
```
Push_swap/
├── Makefile
├── push_swap.h
├── checker_linux            # official 42 checker to verify the output
├── Parsing/
│   ├── main.c
│   ├── stack_init*.c        # stack initialization and validation
│   └── lst_utils*.c         # linked list utilities
├── Operations/
│   └── operations*.c        # sa, sb, pa, pb, ra, rb, rra, rrb, etc.
├── Algorithm/
│   ├── algorithms.c         # small cases and orchestration
│   └── cost_algorithm*.c    # cost algorithm
└── Personal/                # notes and support material (subject, norm, phases)
```
 
---
 
## 🚀 Compilation and usage
 
```bash
# Build
make
 
# Sort a list of numbers
./push_swap 3 2 1 6 5 8
# Output: sequence of operations (sa, pb, ra, ...)
 
# It also accepts the numbers inside a single string
./push_swap "3 2 1 6 5 8"
```
 
### Makefile rules
 
| Command        | Description                                          |
| -------------- | ---------------------------------------------------- |
| `make`         | Builds the `push_swap` executable.                   |
| `make clean`   | Removes the object files (`.o`).                    |
| `make fclean`  | Removes the `.o` files and the executable.           |
| `make re`      | Recompiles everything from scratch.                  |
 
### Included test rules
 
The Makefile ships shortcuts to test performance with random lists:
 
```bash
make count_100     # number of operations for 100 random numbers
make count_500     # number of operations for 500 random numbers
make compare_100   # checks with checker_linux that the output sorts correctly
make compare_500
```
 
Manual verification with the official checker:
 
```bash
ARG="`seq 1 100 | shuf`"
./push_swap $ARG | ./checker_linux $ARG     # should print "OK"
```
 
---
 
## 👤 Author
 
**jgodoy-m** — Student at [42 Málaga](https://www.42malaga.com/)
 
---
 
## 📝 Note about this repository
 
This project is part of the **42** curriculum. As it is an already finished and
graded submission, the repository's history consists of **a single commit**. It is
not under active development: the code is complete and meets the requirements of the
assignment.
 

# Push_swap


Un programa en C que ordena una pila de enteros usando un conjunto limitado de
operaciones, buscando hacerlo con el menor número de movimientos posible.



Proyecto realizado en la escuela 42 (campus de 42 Málaga). Por tratarse de una
entrega ya evaluada y cerrada, el repositorio contiene un único commit: el
proyecto está terminado y no recibe nuevos cambios.


# 📖 Descripción

Push_swap es uno de los proyectos algorítmicos clásicos de 42. El objetivo es
ordenar una serie de números recibidos como argumentos utilizando dos pilas
(a y b) y un juego reducido de operaciones. La nota del proyecto depende
directamente de la eficiencia: cuantos menos movimientos se usen para ordenar,
mejor.

El programa:


Parsea y valida los argumentos (admite números sueltos o una única cadena
con varios números). Detecta entradas no numéricas, duplicados y valores fuera
del rango de int, terminando con Error cuando corresponde.
Construye la pila a sobre una lista doblemente enlazada y normaliza los
valores a índices para facilitar el ordenado.
Ordena aplicando casos especiales para tamaños pequeños (2 y 3 elementos) y,
para el resto, un algoritmo de costes que calcula para cada elemento de b
su posición de destino en a y el coste de las rotaciones, ejecutando siempre
el movimiento más barato.
Imprime por la salida estándar la secuencia de operaciones realizadas.



# ⚙️ Operaciones disponibles

OperaciónEfectosa / sb / ssIntercambia los dos primeros elementos de a / b / ambos.pa / pbMueve el primer elemento de una pila a la otra.ra / rb / rrRota hacia arriba a / b / ambas.rra/ rrb/ rrrRota hacia abajo a / b / ambas.


# 🧠 El algoritmo


2 elementos → un único sa si hace falta.
3 elementos → ordenación directa con casos predefinidos.
Más elementos → algoritmo de costes (estilo Turk):

Se empujan los elementos a la pila b.
Para cada nodo de b se calcula su posición objetivo en a y el
coste (número de rotaciones) en ambas pilas.
Se selecciona el movimiento más barato (combinando rotaciones simples y
dobles cuando es posible) y se ejecuta.
Se repite hasta vaciar b, y finalmente se hace girar a hasta dejar el
mínimo arriba.





La estructura de cada nodo guarda el valor, su índice normalizado, la posición y
los costes precalculados:

ctypedef struct s_list
{
    int             value;
    int             index;
    int             position;
    int             target;
    int             cost_a;
    int             cost_b;
    struct s_list   *prev;
    struct s_list   *next;
}   t_list;


# 🗂️ Estructura del proyecto

Push_swap/
├── Makefile
├── push_swap.h
├── checker_linux            # checker oficial de 42 para verificar la salida
├── Parsing/
│   ├── main.c
│   ├── stack_init*.c        # inicialización y validación de la pila
│   └── lst_utils*.c         # utilidades de lista enlazada
├── Operations/
│   └── operations*.c        # sa, sb, pa, pb, ra, rb, rra, rrb, etc.
├── Algorithm/
│   ├── algorithms.c         # casos pequeños y orquestación
│   └── cost_algorithm*.c    # algoritmo de costes
└── Personal/                # notas y material de apoyo (subject, norma, fases)


# 🚀 Compilación y uso

bash# Compilar
make

# Ordenar una lista de números
./push_swap 3 2 1 6 5 8
# Salida: secuencia de operaciones (sa, pb, ra, ...)

# También admite los números dentro de una sola cadena
./push_swap "3 2 1 6 5 8"

Reglas del Makefile

ComandoDescripciónmakeCompila el ejecutable push_swap.make cleanElimina los archivos objeto (.o).make fcleanElimina los .o y el ejecutable.make reRecompila todo desde cero.

Reglas de prueba incluidas

El Makefile trae atajos para probar el rendimiento con listas aleatorias:

bashmake count_100     # nº de operaciones para 100 números aleatorios
make count_500     # nº de operaciones para 500 números aleatorios
make compare_100   # comprueba con checker_linux que la salida ordena bien
make compare_500

Verificación manual con el checker oficial:

bashARG="`seq 1 100 | shuf`"
./push_swap $ARG | ./checker_linux $ARG     # debe imprimir "OK"


# 👤 Autor

jgodoy-m — Estudiante de 42 Málaga


# 📝 Nota sobre el repositorio

Este proyecto forma parte del currículo de 42. Al ser una entrega ya finalizada
y corregida, el historial del repositorio se compone de un solo commit. No está
en desarrollo activo: el código está completo y cumple los requisitos de la consigna.
