/** @file test_pulsaciones.c
 *  @brief Banco de pruebas para la función pulsaciones()
 *
 *  Este banco de pruebas verifica el correcto funcionamiento de la función
 *  pulsaciones() que detecta pulsaciones cortas y largas de un pulsador.
 *  Se simulan diferentes escenarios de uso, incluyendo rebotes y ruido.
 *
 *  @author Isidro Urriza
 *  @date 2025-09-01
 */

#include "pulsaciones.h"
#include <stdint.h>

// Variables para simular la entrada del pulsador y almacenar el resultado
__attribute__((section(".bss.noinit"))) uint8_t
    g_sw2; // Simula el estado del pulsador (0 = no presionado, 1 = presionado)
uint8_t g_pls; // Almacena el resultado de la función pulsaciones

int main() {

  // Reset e inicialización de la función pulsaciones
  //   El segundo argumento '1' indica que se debe realizar el
  //   reset/inicialización
  g_sw2 = 0;
  pulsaciones(g_sw2, 1);

  //--------------------------------------------------------------------------
  // Test 1: Verifica que la salida se mantiene a 0 mientras no haya ninguna
  // pulsación Se ejecuta varias veces para asegurar que el sistema es estable
  // en reposo
  for (uint8_t i = 0; i < 5; i++) {
    g_pls = pulsaciones(g_sw2, 0);
  }

  // --------------------------------------------------------------------------
  // Test 2: Simula una pulsación corta seguida de un espacio
  // Primero se activa el pulsador (g_sw2 = 1) durante 5 llamadas
  for (uint8_t i = 0; i < 5; i++) {
    g_sw2 = 1;
    g_pls = pulsaciones(g_sw2, 0);
  }
  // Se desactiva el pulsador
  g_sw2 = 0;
  for (uint16_t i = 0; i <= TIEMPO2; i++) {
    g_pls = pulsaciones(g_sw2, 0);
  }

  // --------------------------------------------------------------------------
  // Test 3: Simula una pulsación larga seguida de un espacio
  // Se mantiene el pulsador activo por un tiempo de TIEMPO1 llamadas
  for (uint16_t i = 0; i < TIEMPO1; i++) {
    g_sw2 = 1;
    g_pls = pulsaciones(g_sw2, 0);
  }

  // Se suelta el pulsador
  for (uint16_t i = 0; i <= TIEMPO2; i++) {
    g_sw2 = 0;
    g_pls = pulsaciones(g_sw2, 0);
  }

  // --------------------------------------------------------------------------
  // Test 4: Simula una pulsación corta seguida de un espacio con ruido
  // Se activa el pulsador durante un tiempo corto
  for (uint8_t i = 0; i < 15; i++) {
    g_sw2 = 1;
    g_pls = pulsaciones(g_sw2, 0);
  }

  // Se simula ruido en el pulsador alternando su estado varias veces
  for (uint8_t j = 0; j < 3; j++) {
    // Ruido pulsador desactivado
    g_sw2 = 0;
    for (uint8_t i = 0; i < 5; i++) {
      g_pls = pulsaciones(g_sw2, 0);
    }

    // Ruido pulsador activado
    g_sw2 = 1;
    for (uint8_t i = 0; i < 5; i++) {
      g_pls = pulsaciones(g_sw2, 0);
    }
  }

  // Se estabiliza en pulsador desactivado
  g_sw2 = 0;
  for (uint16_t i = 0; i <= TIEMPO2; i++) {
    g_pls = pulsaciones(g_sw2, 0);
  }

  // --------------------------------------------------------------------------
  // Test 5: Simula una pulsación extra larga seguida de un espacio
  // Se mantiene el pulsador activo por un tiempo muy largo (600 llamadas)
  for (uint16_t i = 0; i < TIEMPO1 + 200; i++) {
    g_sw2 = 1;
    g_pls = pulsaciones(g_sw2, 0);
  }

  // Se libera el pulsador y se verifica que la salida vuelve a 0
  for (uint16_t i = 0; i <= TIEMPO2; i++) {
    g_sw2 = 0;
    g_pls = pulsaciones(g_sw2, 0);
  }

  // --------------------------------------------------------------------------
  // Fin del test - todas las pruebas pasaron correctamente
  while (1) {
    // Bucle infinito para indicar que el test ha finalizado correctamente
    __asm volatile ("BKPT #0"); // Punto de parada para depuración
  }
}
