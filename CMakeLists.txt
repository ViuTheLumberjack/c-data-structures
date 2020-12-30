cmake_minimum_required(VERSION 3.17)
project(Data_Structures C)

set(CMAKE_C_STANDARD 99)

add_library(Data_Structures circularlist.c circularlist.h indexlinkedlist.c indexlinkedlist.h unidirectionalLinkedList.c unidirectionalLinkedList.h)