Push_swap


Un programa en C que ordena una pila de enteros usando un conjunto limitado de
operaciones, buscando hacerlo con el menor número de movimientos posible.



Proyecto realizado en la escuela 42 (campus de 42 Málaga). Por tratarse de una
entrega ya evaluada y cerrada, el repositorio contiene un único commit: el
proyecto está terminado y no recibe nuevos cambios.


📖 Descripción

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



⚙️ Operaciones disponibles

OperaciónEfectosa / sb / ssIntercambia los dos primeros elementos de a / b / ambos.pa / pbMueve el primer elemento de una pila a la otra.ra / rb / rrRota hacia arriba a / b / ambas.rra/ rrb/ rrrRota hacia abajo a / b / ambas.


🧠 El algoritmo


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


🗂️ Estructura del proyecto

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


🚀 Compilación y uso

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


👤 Autor

jgodoy-m — Estudiante de 42 Málaga


📝 Nota sobre el repositorio

Este proyecto forma parte del currículo de 42. Al ser una entrega ya finalizada
y corregida, el historial del repositorio se compone de un solo commit. No está
en desarrollo activo: el código está completo y cumple los requisitos de la consigna.
