# 30319 — Laboratorio 2: Pulsador, LED RGB y SysTick

Este proyecto contiene los recursos de la segunda práctica de «Sistemas
Electrónicos con Microprocesadores». Se utiliza con una placa de desarrollo
FM4-176L-S6E2CC-ETH y con Keil μVision 5.

El laboratorio aplica un proceso completo de desarrollo de firmware: diseñar
una Máquina de Estados Finitos (MEF), implementarla, depurarla en simulación,
validarla mediante trazas y conectarla a una aplicación temporal sobre la
placa.

## Contenido

El proyecto dispone de tres *targets* de Keil:

- `Test_Pulsaciones`: simulación de la función `pulsaciones()`. El archivo
  `test/test_pulsaciones.c` genera secuencias de entrada en `g_sw2`; el
  resultado se observa en `g_pls` mediante Logic Analyzer. No es un banco de
  pruebas automático: el estudiante debe interpretar las trazas según su
  diseño de la MEF.
- `lab2.0`: aplicación que configura SysTick en modo encuesta y conmuta el pin
  `P7D` (D8) al detectar cada desbordamiento de 1 ms. Permite validar la base
  de tiempos con el depurador y el osciloscopio.
- `lab2.1`: aplicación final que integra la MEF, un contador de tres bits, el
  LED RGB, la señal temporal `P7D` y el efecto *breathing* de `LED_ETH`.

Los archivos `pulsaciones.c`, `lab2.0.c` y `lab2.1.c` contienen partes que se
deben completar durante la práctica. Las secuencias de estímulo de los casos
1 a 5 de `test_pulsaciones.c` forman parte de la actividad docente y no deben
modificarse; el alumnado puede añadir su propio caso de prueba en la zona
reservada para ello.

## Estructura

```text
lab2/
├── build_keil/
│   ├── lab2.uvprojx       # Proyecto Keil con los tres targets
│   └── lab2.uvoptx        # Preferencias de usuario de Keil
├── hal/
│   ├── include/
│   │   ├── HAL_FM4_gpio.h # Interfaz de acceso a GPIO
│   │   └── HAL_SysTick.h  # Interfaz de SysTick en modo encuesta
│   └── src/
│       ├── HAL_FM4_gpio.c # Implementación de acceso a GPIO
│       └── HAL_SysTick.c  # Implementación de la base de tiempos
├── bsp/
│   ├── include/
│   │   └── FM4_leds_sw.h  # Interfaz de LEDs y pulsador SW2
│   └── src/
│       └── FM4_leds_sw.c  # Implementación específica de la placa
├── src/
│   ├── lab2.0.c           # Aplicación de SysTick y P7D/D8
│   ├── lab2.1.c           # Aplicación integrada
│   ├── pulsaciones.c      # Implementación de la MEF
│   └── pulsaciones.h      # Interfaz y umbrales de pulsación
└── test/
    └── test_pulsaciones.c # Estímulos y trazas para validar la MEF
```

La aplicación utiliza la capa HAL para acceder a GPIO y SysTick, y la BSP para
controlar los LEDs y leer el pulsador. Los componentes de ejecución
`CMSIS:CORE` y `Device:Startup` están declarados en el proyecto Keil.

## Requisitos

- Placa FM4-176L-S6E2CC-ETH conectada por USB para los targets `lab2.0` y
  `lab2.1`.
- Keil μVision 5 con ARM Compiler 6 y el paquete `Keil.FM4_DFP` para
  `S6E2CCAJ0A`.
- Osciloscopio para observar la señal `P7D` durante las actividades de medida.

## Uso de la plantilla

1. Descomprime el proyecto en tu espacio de trabajo.
2. Abre `build_keil/lab2.uvprojx` con Keil μVision 5.
3. Selecciona el *target* indicado en la actividad: `Test_Pulsaciones`,
   `lab2.0` o `lab2.1`.
4. Sigue el orden y el procedimiento del manual antes de modificar la
   configuración o el código.

`Test_Pulsaciones` utiliza el simulador ARM Cortex-M4. Los targets `lab2.0` y
`lab2.1` están configurados para el dispositivo `S6E2CCAJ0A`, C99, ARM Compiler
6 y depuración mediante CMSIS-DAP. La frecuencia de trabajo utilizada para la
base de tiempos es 200 MHz; `SysTick_Init(SystemCoreClock / 1000U)` establece
un período de desbordamiento de 1 ms en modo encuesta.

## Actividades de aprendizaje

En `Test_Pulsaciones`, cada llamada a `pulsaciones()` representa una muestra de
1 ms. El alumnado diseña individualmente una MEF, compara propuestas en pareja
y selecciona una solución razonada antes de implementarla. La validación se
realiza observando las señales `g_sw2` y `g_pls` en Logic Analyzer, incluida una
secuencia de prueba adicional diseñada por la pareja.

En `lab2.0`, se mide la base de tiempos generada por SysTick: la señal `P7D`
cambia de nivel cada 1 ms, por lo que su período completo es aproximadamente
2 ms y su frecuencia 500 Hz.

En `lab2.1`, se integran pulsador, contador y LEDs en un superloop. Las tareas
se ejecutan secuencialmente e intercaladas; para mantener una cadencia objetivo
de 1 ms, las funciones deben realizar trabajo breve y acotado. La aplicación se
valida mediante un plan de pruebas definido por la pareja y una explicación al
profesor.

La actividad final de mejora de la interacción trabaja la competencia UZ4,
«Innovación y Creatividad»: el estudiante propone alternativas, selecciona y
justifica una solución, la verifica y explica sus limitaciones. Si utiliza IA,
debe declarar la herramienta, el *prompt*, la respuesta y la verificación
realizada.
