cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME all_labs) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта 

set(matrix matrix)
set(matrix_lib matrix_lib)
set(matrix_test matrix_test) 

set(stacklist stacklist)
set(stacklist_lib stacklist_lib)
set(stacklist_test stacklist_test)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/matrix_lib)
add_subdirectory(matrix)
add_subdirectory(matrix_lib)
add_subdirectory(matrix_test)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/stacklist_lib)
add_subdirectory(stacklist)
add_subdirectory(stacklist_lib)
add_subdirectory(stacklist_test)


# REPORT
message( STATUS "")
message( STATUS "General configuration for ${PROJECT_NAME}")
message( STATUS "======================================")
message( STATUS "")
message( STATUS "   Configuration: ${CMAKE_BUILD_TYPE}")
message( STATUS "")
