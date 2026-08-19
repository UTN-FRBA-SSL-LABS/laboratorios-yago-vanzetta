#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

 void test_compra_con_descuento(void) {
    printf("\n[compra con descuento]\n");
    Carrito c;
    carrito_init(&c);

    Producto m = {"Leche", 350, 2};
    Producto p = {"Pan", 200, 3};
    carrito_agregar(&c, m);
    carrito_agregar(&c, p);

    ASSERT_IGUAL(1300, carrito_total(&c));
    ASSERT_IGUAL(1170, carrito_descuento(carrito_total(&c), 10));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_agregar_hasta_llenar(void) {
    printf("\n[agregar hasta llenar]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};

    for (int i = 0; i < 4; i++) {
        carrito_agregar(&c, p);
    }
    ASSERT_IGUAL(4, carrito_contar(&c));

    ASSERT_IGUAL(0, carrito_agregar(&c, p));
    ASSERT_IGUAL(4, carrito_contar(&c));
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
   test_compra_con_descuento(); 
    test_agregar_hasta_llenar();  
    RESUMEN();
    return EXIT_CODE();
}
