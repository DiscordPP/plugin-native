cmake_minimum_required(VERSION 3.15)
project(discordpp-plugin-native)

if (CMAKE_CXX_STANDARD LESS 14)
    error(${PROJECT_NAME} requires at least C++14)
endif ()

###################

list(PREPEND ALL_DISCORDPP_PLUGINS discordpp::PluginNative)
list(APPEND ALL_DISCORDPP_LIBRARIES discordpp-plugin-native)
set(ALL_DISCORDPP_INCLUDES ${ALL_DISCORDPP_INCLUDES} "#include <discordpp/plugin-native.hh>\n" PARENT_SCOPE)
set(ALL_DISCORDPP_LIBRARIES ${ALL_DISCORDPP_LIBRARIES} PARENT_SCOPE)
set(ALL_DISCORDPP_PLUGINS ${ALL_DISCORDPP_PLUGINS} PARENT_SCOPE)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} INTERFACE discordpp)
