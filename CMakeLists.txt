cmake_minimum_required(VERSION 3.3)
project(integral)

set(CMAKE_CXX_STANDARD 11)


#set(CMAKE_C_COMPILER "/usr/local/bin/clang-omp" CACHE FILEPATH "C compiler" FORCE)
#set(CMAKE_CXX_COMPILER "/usr/local/bin/clang-omp++" CACHE FILEPATH "C++ compiler" FORCE)


include_directories(/usr/local/include)

#FIND_PACKAGE(OpenMP REQUIRED)
#if(OPENMP_FOUND)
#    message("OPENMP FOUND")
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
#    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
#    include_directories(${OpenMP_INCLUDE_DIRS})
#endif()

set(SOURCE_FILES main.cpp IntegralCalculation.h)
add_executable(integral ${SOURCE_FILES})
#target_link_libraries(integral ${OpenMP_LIBRARIES})