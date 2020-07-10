
cmake_minimum_required(VERSION 3.17)

project(pig VERSION 0.1)
configure_file(pigConfig.h.in pigConfig.h)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

find_package(SDL2 REQUIRED)
include_directories(include/ ${SDL2_INCLUDE_DIRS})

set(PIG_SRCS
    src/Variaveis.cpp
    src/PIG_Variaveis.cpp
    src/AjustesEAtualizacoes.cpp
    src/CAnimacao.cpp
    src/CAssetLoader.cpp
    src/CGeradorParticulas.cpp
    src/CGerenciadorAnimacoes.cpp
    src/CGerenciadorObjetos.cpp
    src/CGerenciadorParticulas.cpp
    src/CGerenciadorTimers.cpp
    src/CJogo.cpp
    src/CMapaCaracteres.cpp
    src/CMouse.cpp
    src/CObjeto.cpp
    src/COffscreenRenderer.cpp
    src/Colisao.cpp
    src/CParticula.cpp
    src/CPilhaCoordenada.cpp
    src/CPoolNumeros.cpp
    src/CTimer.cpp
    src/Desenhar.cpp
    src/ForcaClass.cpp
    src/ImagemDeFundo.cpp
    src/ManipularEsferas.cpp
    src/ManipularEspaco.cpp
    src/MouseETeclado.cpp
    src/PIG_Animations.cpp
    src/PIG_Fontes.cpp
    src/PIG_Geometricos.cpp
    src/PIG_Jogo.cpp
    src/PIG_Objetos.cpp
    src/PIG_Timers.cpp
    src/SalvarECarregarSistemas.cpp
    src/Victor.cpp
)

set(PIG_INCLUDES
    include/AjustesEAtualizacoes.h
    include/Bibliotecas_Basicas.h
    include/CAnimacao.h
    include/CAssetLoader.h
    include/CGeradorParticulas.h
    include/CGerenciadorAnimacoes.h
    include/CGerenciadorObjetos.h
    include/CGerenciadorParticulas.h
    include/CGerenciadorTimers.h
    include/CJogo.h
    include/CMapaCaracteres.h
    include/CMouse.h
    include/CObjeto.h
    include/COffscreenRenderer.h
    include/Colisao.h
    include/CParticula.h
    include/CPilhaCoordenada.h
    include/CPoolNumeros.h
    include/CTimer.h
    include/Desenhar.h
    include/ForcaClass.h
    include/ImagemDeFundo.h
    include/ManipularEsferas.h
    include/ManipularEspaco.h
    include/MouseETeclado.h
    include/PIG_Animations.h
    include/PIG_Fontes.h
    include/PIG_Geometricos.h
    include/PIG_Jogo.h
    include/PIG_Objetos.h
    include/PIG_Pack.h
    include/PIG_Timers.h
    include/PIG_Variaveis.h
    include/PIG.h
    include/SalvarECarregarSistemas.h
    include/SDL_Pack.h
    include/Teclas.h
    include/TexturasEAvisos.h
    include/Tipos_PIG.h
    include/Tipos.h
    include/Variaveis.h
    include/Victor.h
)

add_library(pig SHARED ${PIG_SRCS})
target_link_libraries(pig PUBLIC ${SDL2_LIBRARIES})

set(INCLUDE_INSTALL_DIR "include/pig/" CACHE STRING ...)
set(LIBRARY_INSTALL_DIR "lib/" CACHE STRING ...)
set(SYSCONFIG_INSTALL_DIR "etc/pig/" CACHE STRING ...)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/pigConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/pigConfig.cmake"
    PATH_VARS INCLUDE_INSTALL_DIR
    INSTALL_DESTINATION ${LIBRARY_INSTALL_DIR}/pig/cmake
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/pigConfigVersion.cmake
    COMPATIBILITY AnyNewerVersion
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/pigConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/pigConfigVersion.cmake"
    DESTINATION ${LIBRARY_INSTALL_DIR}/pig/cmake
    COMPONENT pig
)

install(TARGETS pig DESTINATION ${LIBRARY_INSTALL_DIR})
install(FILES ${PIG_INCLUDES} DESTINATION ${INCLUDE_INSTALL_DIR})
