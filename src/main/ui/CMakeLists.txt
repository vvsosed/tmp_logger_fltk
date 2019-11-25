fltk_wrap_ui(MainUi main.fl)

add_library(MainUi ${MainUi_FLTK_UI_SRCS})

target_link_libraries(MainUi fltk ${FLTK_LIBRARIES} ${OPENGL_LIBRARIES})

target_include_directories(MainUi PRIVATE ${FLTK_INCLUDE_DIRS})
target_include_directories(MainUi PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

