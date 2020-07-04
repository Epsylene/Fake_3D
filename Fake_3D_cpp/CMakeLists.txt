cmake_minimum_required(VERSION 3.16)
project(Fake3D)

set(CMAKE_CXX_STANDARD 17)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "C:/Libraries/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS system window graphics)

add_executable(${PROJECT_NAME} main.cpp Drawer.cpp Drawer.h)

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics -static)
