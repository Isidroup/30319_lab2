/**
 * @file lab2.1.c
 * @brief Práctica de gestión de pulsaciones y control de LEDs en FM4.
 * @details
 *   - Detecta pulsaciones cortas y largas en SW2.
 *   - Controla el LED RGB y el LED_ETH con efecto "breathing".
 *   - Utiliza periféricos GPIO y SysTick.
 * @author [Tu Nombre]
 * @date :2025/09/18 09:55:34
 */

 // Incluir  cabeceras necesarias
 ....

/**
 * @brief Programa principal.
 * @details
 *   - Inicializa periféricos (GPIO, SysTick, LEDs).
 *   - Ejecuta un bucle cíclico que:
 *       - Detecta pulsaciones en SW2.
 *       - Cambia el color del LED RGB según pulsaciones.
 *       - Aplica efecto "breathing" al LED_ETH.
 * @return No retorna (bucle infinito).
 */
int main(void)
{
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
    while (1)
    {
        if (......) // Si SysTick ha desbordado
        {   // Aquí va el código que se ejecuta cada 1 ms
            GPIO_ChannelToggle(P7D);                 // Actualiza P7D/D8
            ...
        }
        // Aquí va el código que se ejecuta en cada iteraciónº
        // Ejemplo: Parpadeo led ETH
        breath_led(LED_ETH);
    }
}
