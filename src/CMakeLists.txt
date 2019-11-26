CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

project(tmp_logger_fltk)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FLTK_DIR D:/repo/fltk/build)
set(FLTK_FLUID_EXECUTABLE D:/repo/fltk/build/bin/Debug/fluid.exe)

find_package(FLTK REQUIRED NO_MODULE)
find_package(OpenGL REQUIRED)

set(BOOST_ROOT D:/repo/boost)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_LIBS ON)
find_package( Boost )
link_directories(${Boost_LIBRARY_DIRS})

add_subdirectory( main )
add_subdirectory( server )