cmake_minimum_required(VERSION 3.29)

project(Minishell)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Find all .c files inside the minishell/src and minishell/lib/src directories
file(GLOB_RECURSE SOURCES
		minishell/src/*.c
		minishell/lib/src/*.c
		minishell/include/*.h
		minishell/lib/include/*.h
)

# Add executable with all found sources
add_executable(minishell ${SOURCES})

# Include header directories (fixed syntax)
include_directories(
		minishell/include
		minishell/lib/include
)
