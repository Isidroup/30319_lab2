/*
 * pulsaciones.h
 *
 */

#ifndef PULSACIONES_H_
#define PULSACIONES_H_

#include <stdint.h>


/**
 * @brief   Definiciones de tiempo para pulsaciones
 * @details Estas constantes definen los tiempos umbral para
 *          detectar pulsaciones cortas (< TIEMPO1) y largas (>= TIEMPO1).
 *          Además, TIEMPO2 define el tiempo de espera tras una pulsación.
 *
 * @note    Los valores pueden ajustarse según las necesidades del sistema.
 *          se han ajustado para un tiempo de llamada de 1 ms.
 */

#define TIEMPO1 400
#define TIEMPO2 100

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
 */
uint8_t pulsaciones (const uint8_t pulsado, const uint8_t reset);


#endif /* PULSACIONES_H_ */
