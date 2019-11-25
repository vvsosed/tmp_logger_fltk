#FLTK_WRAP_UI(Ui ui.fl)
#ADD_LIBRARY(Ui callbacks.cxx ${Ui_FLTK_UI_SRCS})

add_executable(tmp_logger main.cpp)

#add_dependencies(tmp_logger Ui)
#target_link_libraries(tmp_logger Ui)
target_link_libraries(tmp_logger fltk ${FLTK_LIBRARIES} ${OPENGL_LIBRARIES})
target_include_directories(tmp_logger PRIVATE ${FLTK_INCLUDE_DIRS})
