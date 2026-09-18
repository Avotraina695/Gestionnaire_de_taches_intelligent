cmake_minimum_required(VERSION 4.1)
project(Gestionnaire_de_taches_intelligent C)

set(CMAKE_C_STANDARD 11)

add_executable(Gestionnaire_de_taches_intelligent main.c
        Include/Tache.h
        src/Tache.c
        Include/Menu.h
        src/Menu.c
        Include/Stockage.h
        src/Stockage.c
)
