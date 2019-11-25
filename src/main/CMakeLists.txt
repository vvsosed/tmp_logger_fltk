add_subdirectory(ui)

add_executable(tmp_logger main.cpp)

add_dependencies(tmp_logger MainUi)

target_link_libraries(tmp_logger fltk MainUi ${FLTK_LIBRARIES} ${OPENGL_LIBRARIES})
target_include_directories(tmp_logger PRIVATE ${FLTK_INCLUDE_DIRS})