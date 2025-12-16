cmake_minimum_required(VERSION 3.16)
project(SFMLApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#custom libs
add_library(Licence_checker Libs/Licence_checker.cpp)
add_library(Autosave Libs/Autosave.cpp)

# Найти SFML (у тебя стоит 3.0.2 из apt)
find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)

add_executable(sfml-app main.cpp)

target_link_libraries(sfml-app PRIVATE Licence_checker)
target_link_libraries(sfml-app PRIVATE Autosave)
target_link_libraries(sfml-app PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

#custom includes
target_include_directories(Licence_checker PUBLIC ${CMAKE_SOURCE_DIR}/Libs)
target_include_directories(Autosave PUBLIC ${CMAKE_SOURCE_DIR}/Libs)
