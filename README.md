# Fract'ol

Un visualizador interactivo de fractales desarrollado en C que permite explorar la belleza matemática de los conjuntos de Mandelbrot, Julia y Burning Ship con múltiples esquemas de colores y controles en tiempo real.

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)](https://github.com/usuario/fractol)
[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![42 School](https://img.shields.io/badge/42-School-000000.svg)](https://42.fr/)

---

## Tabla de Contenidos

- [ Características Principales](#-características-principales)
- [ Tecnologías](#️-tecnologías)
- [ Requisitos del Sistema](#-requisitos-del-sistema)
- [ Instalación](#-instalación)
- [ Uso](#-uso)
- [ Controles](#-controles)
- [ Fractales Disponibles](#-fractales-disponibles)

---

## Características Principales

**Visualización en Tiempo Real**: Renderizado fluido de fractales con zoom y navegación interactiva

**Múltiples Esquemas de Color**: Paletas interpoladas, rayadas y especiales para visualización artística

**Controles Intuitivos**: Navegación con mouse y teclado, zoom con rueda del mouse

**Parámetros Personalizables**: Configuración de valores iniciales para fractales de Julia

**Alta Resolución**: Renderizado en 900x900 píxeles con hasta 500 iteraciones

**Cambio Dinámico**: Intercambio entre tipos de fractales sin reiniciar la aplicación

---

## Tecnologías

- **Lenguaje**: C (estándar C99)
- **Librería Gráfica**: [MinilibX](https://github.com/42Paris/minilibx-linux) para manejo de ventanas y eventos
- **Librería Personalizada**: [libft](libft/) - Implementación propia de funciones estándar de C
- **Matemáticas**: Números complejos y algoritmos de iteración fractal
- **Sistema de Compilación**: Make con Makefile optimizado

---

## Requisitos del Sistema

### Linux (Recomendado)
```bash
# Ubuntu/Debian
sudo apt-get install gcc make xorg libxext-dev libbsd-dev

# Fedora/CentOS
sudo yum install gcc make xorg-x11-server-devel libXext-devel libbsd-devel

```
### macOS
```
# Instalar Xquartz
brew install xquartz
# Reiniciar después de la instalación

```

## Instalación

### 1. Clonar el Repositorio
```
git clone https://github.com/CristianYepes/fractol.git
cd fractol
```

### 2. Compilar el Proyecto

```
make
```

### 3. Ejecutar

```
# Mandelbrot
./fractol M

# Julia con parámetros por defecto
./fractol J

# Julia con parámetros personalizados
./fractol J -0.7 0.27015

# Burning Ship
./fractol B

# Con esquema de color personalizado (hexadecimal)
./fractol M FF0000
```


## Uso

### Ejemplos Básicos

```bash
# Visualizar el conjunto de Mandelbrot
./fractol M

# Visualizar Julia con valores específicos
./fractol J 0.285 0.01

# Burning Ship con color personalizado
./fractol B 00FF00
```

### Parámetros de Color

Los códigos de color deben estar en formato hexadecimal (RRGGBB):

- `FF0000` - Rojo
- `00FF00` - Verde
- `0000FF` - Azul
- `FFFFFF` - Blanco
- `000000` - Negro

### Controles

| Tecla/Acción | Función |
|--------------|---------|
| ↑ ↓ ← → | Navegar por el fractal |
| Rueda del Mouse | Zoom in/out |
| +/- | Ajustar nivel de detalle |
| Espacio | Cambiar esquema de colores |
| Click Izquierdo | Cambiar parámetros (solo Julia) |
| 1, 2, 3 | Cambiar tipo de fractal |
| ESC | Salir de la aplicación |

---

## Fractales Disponibles

### Mandelbrot
El clásico conjunto de Mandelbrot, donde cada punto c en el plano complejo se evalúa mediante la iteración z² + c.

### Julia
Conjuntos de Julia con parámetros personalizables. Los valores recomendados están entre -2.0 y 2.0.

**Ejemplos populares:**
```bash
./fractol J -0.7 0.27015
./fractol J -0.75 0.11
./fractol J 0.285 0.01
```

### Burning Ship
Una variación del conjunto de Mandelbrot que utiliza el valor absoluto, creando formas que recuerdan a barcos ardiendo.
