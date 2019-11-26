
add_library (udp_server STATIC server.h server.cpp )

target_include_directories(udp_server PRIVATE ${Boost_INCLUDE_DIRS})
target_include_directories(udp_server PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})