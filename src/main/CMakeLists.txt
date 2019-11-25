fltk_wrap_ui(MainUi main.fl)

add_library(MainUi ${MainUi_FLTK_UI_SRCS})
target_link_libraries(MainUi fltk ${FLTK_LIBRARIES} ${OPENGL_LIBRARIES})
target_include_directories(MainUi PRIVATE ${FLTK_INCLUDE_DIRS})

add_executable(tmp_logger main.cpp)

add_dependencies(tmp_logger MainUi)

target_link_libraries(tmp_logger fltk MainUi ${FLTK_LIBRARIES} ${OPENGL_LIBRARIES})
target_include_directories(tmp_logger PRIVATE ${FLTK_INCLUDE_DIRS})
