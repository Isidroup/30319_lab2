#include <stdint.h>
#include "pulsaciones.h"


/**
 * @brief   Detector de pulsación
 * @details Detecta los patrones pulsación larga y
 *             pulsación corta en el dato
 *             que se le pasa como argumento.
 * @param pulsado  estado de la pulsación:
 *                    está pulsado → 1
 *                    no está pulsado → 0
 * @param reset reseteo de la MEF si /= 0
 * @return  0      si no hay pulsacion.
 * @return  1      pulsación corta.
 * @return  2      pulsación larga.
 *
 * @note  Diagrama de estados implementado: https://tinyurl.com/4wa7e3hw
 *
 *        Los umbrales de duración de una pulsación se definen en pulsaciones.h
 */
uint8_t pulsaciones (const uint8_t pulsado, const uint8_t reset)
{

}
