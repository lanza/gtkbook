cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_STANDARD 11)

project(gtkbook C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-fcolor-diagnostics)

find_package(GTK2 REQUIRED)

add_executable(helloworld hellogtk.c)
target_link_libraries(
  helloworld
  PUBLIC
  ${GTK2_LIBRARIES}
)
target_include_directories(helloworld PUBLIC ${GTK2_INCLUDE_DIRS})
