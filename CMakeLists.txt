cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME 381706-2_savosina_labs) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта 

set(matrix matrix) #Переменная с именем библиотеки
set(matrix_test matrix_test) #Переменная с именем библиотеки
set(set set) #Переменная с именем библиотеки
set(set_test set_test)
set(stack stack)
set(stack_test stack_test)
set(list list)
set(list_test list_test)
set(queue queue)
set(queue_test queue_test)
set(stacklist stack)
set(stacklist_test stacklist_test)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/matrix)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/set)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/stack)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/queue)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/list)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/stacklist)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/list_test)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/stack_test)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/queue_test)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/stacklist_test)



add_subdirectory(gtest)
#add_subdirectory(set) #Собираем проект в поддиректории vector
#add_subdirectory(matrix)
add_subdirectory(stack)
add_subdirectory(list)
add_subdirectory(queue)
add_subdirectory(list_test)
add_subdirectory(queue_test)
add_subdirectory(stack_test)
add_subdirectory(stacklist_test)

# REPORT
message( STATUS "")
message( STATUS "General configuration for ${PROJECT_NAME}")
message( STATUS "======================================")
message( STATUS "")
message( STATUS "   Configuration: ${CMAKE_BUILD_TYPE}")
message( STATUS "")
