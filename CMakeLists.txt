cmake_minimum_required(VERSION 2.6)

project("ColorLogger")

include_directories("inc")
aux_source_directory(src SRCS)

add_library(${PROJECT_NAME} STATIC SHARED ${SRCS})
