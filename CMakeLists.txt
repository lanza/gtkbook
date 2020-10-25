cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_STANDARD 11)

project(gtkbook C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-fcolor-diagnostics)

find_package(GTK2 REQUIRED)

function(add_program name)
  add_executable(${name} ${name}.c)
  target_link_libraries(
    ${name}
    PUBLIC
    ${GTK2_LIBRARIES}
  )
  target_include_directories(${name} PUBLIC ${GTK2_INCLUDE_DIRS})
endfunction()

add_program(hellogtk)
add_program(helloC)
