/**
 * @file lab2.0.c
 * @brief Ejemplo básico de uso de GPIO y SysTick en FM4.
 * @details
 *   - Inicializa los periféricos GPIO y SysTick.
 *   - Alterna el estado del pin P7D/D8 cada 1 ms.
 * @author [Tu Nombre]
 * @date :2025/09/18 09:55:23
 */

  // Incluir  cabeceras necesarias
 ....

/**
 * @brief Función principal.
 * @details
 *   - Configura los periféricos necesarios.
 *   - Ejecuta un bucle infinito que alterna el pin P7D/D8 cada 1 ms usando SysTick.
 * @return No retorna (bucle infinito).
 */
int main(void) {
  // Configuración de periféricos:
  //  - Config GPIO para utilizar leds y sw2
  ....

  //  -Config pin P7D/D8:
  //    Pin P7D/D8 como salida
  //    Pin P7D/D8 a 0
  ....
  //  -Config SysTick (1ms):
  SysTick_Init(SystemCoreClock / 1000U);

  // Ejecutivo cíclico
  while (1) {
    if (.........) // Si SysTick ha desbordado
    {
      GPIO_ChannelToggle(P7D); // Cambia P7D/D8
    }
  }
}
