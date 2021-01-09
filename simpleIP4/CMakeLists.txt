cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.
									# Если версия установленой программы
									# старее указаной, произайдёт аварийный выход.

project(simpleIP4)				# Название проекта

set(IP4_LIB simpleIP4.cpp)		# Установка переменной со списком исходников

add_library(simpleIP4 STATIC ${IP4_LIB})# Создание статической библиотеки