add_subdirectory(ui)

add_executable(tmp_logger main.cpp HeatersTable.cpp SensorsTable.cpp)

#add_dependencies(tmp_logger MainUi)
#add_dependencies(tmp_logger udp_server)

target_link_libraries(tmp_logger fltk MainUi udp_server ${FLTK_LIBRARIES} ${OPENGL_LIBRARIES})
target_include_directories(tmp_logger PRIVATE ${FLTK_INCLUDE_DIRS})

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")