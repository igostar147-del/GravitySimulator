# Gravity Simulator

Gravity Simulator — это программа, моделирующая движение большого количества тел под действием гравитации.

Проект реализует простую физическую модель N-body simulation:
- тела притягиваются друг к другу;
- движутся по орбитам;
- сталкиваются и сливаются;
- формируют структуры, похожие на галактики.

Для визуализации используется библиотека SFML.

- 2D визуализация системы тел
- гравитационное взаимодействие
- движение по законам механики
- генерация случайной галактики
- столкновения и слияние тел
- trails 
- цветные объекты разных размеров

- C++
- SFML 2.6
- STL (`std::vector`)
- CMake
#Сборка

mkdir build
cd build

cmake ..
cmake --build 

GravitySimulator.exe
```text
include/
    Body.h
    GalaxyGenerator.h
    Renderer.h
    Simulation.h
    Vector2.h

src/
    Body.cpp
    GalaxyGenerator.cpp
    Renderer.cpp
    Simulation.cpp
    Vector2.cpp
    main.cpp
