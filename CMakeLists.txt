cmake_minimum_required(VERSION 3.6)
project(discordpp-plugin-template)

set(CMAKE_CXX_STANDARD 14)

###################

add_library(${PROJECT_NAME} INTERFACE)

INCLUDE_DIRECTORIES(${discordpp_SOURCE_DIR} ${json_SOURCE_DIR})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} INTERFACE )