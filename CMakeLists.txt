cmake_minimum_required(VERSION 3.15)

add_library(modbus_rtu STATIC src/modbus_rtu.c)
target_include_directories(modbus_rtu PUBLIC include)
target_link_libraries(modbus_rtu PRIVATE freemodbus)
