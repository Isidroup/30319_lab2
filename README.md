# 30319 Laboratorio 2: Interfaz de usuario.

## Introducción

Este laboratorio se centra en la implementación de una interfaz de usuario básica utilizando pulsadores y LEDs en la placa de desarrollo Cypress FM4. Los estudiantes aprenderán a gestionar entradas digitales mediante pulsadores, implementar técnicas de detección de pulsaciones (cortas y largas) y controlar salidas visuales a través de LEDs.

## Objetivos

- Configurar y gestionar pines GPIO para entradas (pulsadores) y salidas (LEDs).
- Implementar una función de detección de pulsaciones que distinga entre pulsaciones cortas y largas.
- Modelar en software una máquina de estados para gestionar la lógica de la interfaz de usuario.

## Ejercicios del Laboratorio

### Ejercicio 2.1: Detección de Pulsaciones

- Implementar la función `pulsaciones()` que detecta pulsaciones cortas y largas en un pulsador conectado a un pin GPIO.
  Esta función, utiliza una MEF (Máquina de Estados Finitos) para gestionar los estados del pulsador y el tiempo de pulsación.
- El test de la función `pulsaciones()` se realiza mediante simulación.

### Ejercicio 2.2: Establecer una base de tiemmpos

- Configurar un temporizador para generar interrupciones periódicas cada 1 ms.

### Ejercicio 2.3: Control de LEDs gobernado por el pulsador

- Utilizar la función `pulsaciones()` para cambiar el estado de un LED cada vez que se detecta una pulsación corta.
- Se utiliza SysTick para la base de tiempos de 1 ms.

## Estructura del proyecto

- `_doc/` — Documentación adicional del laboratorio.
- `bsp/`  — Board Support Package (BSP) para la plataforma FM4.
      - `include/` — Cabeceras de los módulos BSP.
      - `src/`     — Código fuente de los módulos BSP.
- `hal/` — Hardware Abstraction Layer (HAL) para la plataforma FM4.
      - `include/` — Cabeceras de los módulos HAL.
      - `src/` — Código fuente de los módulos HAL.
- `src/`  — Código fuente principal de los ejercicios del laboratorio.
- `test/` — Test de la función `pulsaciones()`.
- `build_keil/` — Archivos de proyecto y configuración para Keil uVision.

## Descripción de los módulos

- **BSP**: Abstracción de bajo nivel para el hardware específico de la placa FM4.
- **HAL**: Capa de abstracción para facilitar el acceso a periféricos y recursos hardware.
- **src**: Implementación de los ejercicios y ejemplos del laboratorio.
- **test**: Código de test
-
## Cómo compilar

El proyecto está preparado para ser compilado con Keil uVision. Abre el archivo `lab2.uvprojx` en la carpeta `build_keil/` y selecciona el *target* deseado.
