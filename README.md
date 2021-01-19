# sensor-ufro-bd

Repositorio dedicado al modulo de base de datos del nodo "sensor-ufro" https://github.com/tomasjm/sensor-ufro

## Dependencias para compilar

Como este paquete es independiente de ROS, se necesitan tres cosas para compilar:
- GCC, G++, build-essentials
- CMake
- Ninja o make

1. `sudo apt-get update`
2. `sudo apt-get install build-essentials cmake ninja-build`

## Instrucciones y descripción

CMake es un generador de "buildsystem" y Ninja es un "buildsystem" tal y como la herramienta Make (a.k.a "makefile").

1. `git clone https://github.com/tomasjm/sensor-ufro-bd && cd sensor-ufro-bd`
2. `mkdir build && cd build`
3. `cmake .. -G "Ninja"`
4. `ninja`

Para compilar con "make":

3. `cmake .. && make`
