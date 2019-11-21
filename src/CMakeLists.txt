CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(hello)

set(FLTK_DIR /home/volodymyr/Documents/repo/fltk/build)

FIND_PACKAGE(FLTK REQUIRED NO_MODULE)
FIND_PACKAGE(OpenGL REQUIRED)


#FLTK_WRAP_UI(Ui ui.fl)
#ADD_LIBRARY(Ui callbacks.cxx ${Ui_FLTK_UI_SRCS})

ADD_EXECUTABLE(hello hello.cpp)

#ADD_DEPENDENCIES(hello Ui)
#TARGET_LINK_LIBRARIES(hello Ui)
target_link_libraries(hello fltk ${FLTK_LIBRARIES} ${OPENGL_LIBRARIES})
target_include_directories(hello PRIVATE ${FLTK_INCLUDE_DIRS})

message( ${FLTK_FOUND} )
message( ${FLTK_INCLUDE_DIRS} )
#message( ${FLTK_BASE_LIBRARY} )
#message( ${FLTK_FLUID_EXECUTABLE} )
#message( ${FLTK_WRAP_UI} )

message( ${OPENGL_LIBRARIES} )