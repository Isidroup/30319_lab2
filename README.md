# 30319 Laboratorio 2

Este repositorio contiene los recursos para el laboratorio 2 de la asignatura de Sistemas Electrónicos con Microprocesadores (otoño 2025).

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

El proyecto está preparado para ser compilado con Keil uVision. Abre el archivo `lab2.uvprojx` en la carpeta `build_keil/` y selecciona el target deseado.

## Autores

- Docentes de la asignatura Sistemas Electrónicos con Microprocesadores
- Universidad de Zaragoza

## Contacto

Para dudas o sugerencias, contactar con el equipo docente a través de los canales oficiales de la asignatura.
