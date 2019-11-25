CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(tmp_logger_fltk)

set(FLTK_DIR D:/repo/fltk/build)
set(FLTK_FLUID_EXECUTABLE D:/repo/fltk/build/bin/Debug/fluid.exe)

FIND_PACKAGE(FLTK REQUIRED NO_MODULE)
FIND_PACKAGE(OpenGL REQUIRED)

message( ${FLTK_FOUND} )
message( ${FLTK_INCLUDE_DIRS} )
message( ${OPENGL_LIBRARIES} )

add_subdirectory( main )