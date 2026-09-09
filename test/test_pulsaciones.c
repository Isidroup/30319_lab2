/** @file test_pulsaciones.c
 *  @brief Banco de pruebas para la función pulsaciones()
 *
 *  Este banco genera secuencias de entrada para analizar el comportamiento de
 *  pulsaciones() mediante el Logic Analyzer de Keil.
 *
 *  No realiza una comprobación automática de aprobado/error. El estudiante debe
 *  comparar las trazas de g_sw2 y g_pls con el comportamiento previsto por el
 *  diseño de su MEF.
 *
 *  Se incluyen escenarios de reposo, pulsación corta, pulsación larga y ruido
 *  en la entrada. Con un muestreo de 1 ms, el rebote físico del pulsador no se
 *  modela en estas pruebas.
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
  // Caso 1: Genera muestras en reposo.
  // En Analyzer, comprobar que g_pls se mantiene a 0.
  for (uint8_t i = 0; i < 5; i++) {
    g_pls = pulsaciones(g_sw2, 0);
  }

  // --------------------------------------------------------------------------
  // Caso 2: Genera una pulsación corta seguida de un intervalo sin pulsar.
  // En Analyzer, localizar un único evento de pulsación corta (g_pls = 1).
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
  // Caso 3: Genera una pulsación larga seguida de un intervalo sin pulsar.
  // En Analyzer, localizar un único evento de pulsación larga (g_pls = 2).
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
  // Caso 4: Genera una pulsación corta seguida de una secuencia de ruido.
  // En Analyzer, comprobar que el ruido no produce eventos adicionales.
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
  // Caso 5: Genera una pulsación extra larga seguida de un intervalo sin pulsar.
  // En Analyzer, comprobar que sólo se genera un evento de pulsación larga.
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
  // --------------------------------------------------------------------------
  // Caso adicional diseñado por la pareja
  //
  // Describe aquí la secuencia de entrada, el resultado esperado y la
  // evidencia que se observará en Analyzer. No modifiques los casos 1 a 5.
  //
  // ...

  // Fin de las secuencias de estímulo.
  // Detenerse aquí para revisar las trazas g_sw2 y g_pls en Analyzer.
  while (1) {
    __asm volatile ("BKPT #0"); // Punto de parada para depuración
  }
}
