cmake_minimum_required (VERSION 3.13)
project (coursework)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)


include (FindPkgConfig)
if (NOT PKG_CONFIG_FOUND)
    message (FATAL_ERROR "pkg-config not found")
endif ()

# check for libpng
pkg_check_modules (LIBPNG libpng16 REQUIRED)
if (NOT LIBPNG_FOUND)
    message(FATAL_ERROR "You don't seem to have libpng16 development libraries installed")
else ()
    include_directories (${LIBPNG_INCLUDE_DIRS})
    link_directories (${LIBPNG_LIBRARY_DIRS})
    link_libraries (${LIBPNG_LIBRARIES})
endif ()
add_executable(coursework coursework.cpp Game.cpp Utility.cpp Block.cpp Scene.cpp Button.cpp Level.cpp)

target_link_libraries(coursework ${OPENGL_gl_LIBRARY}  ${GLUT_LIBRARIES} )
set(CMAKE_CXX_FLAGS "-I ${CMAKE_OSX_SYSROOT} ${CMAKE_CXX_FLAGS} -std=c++11")


if (APPLE)
  set (CMAKE_CXX_FLAGS "-Wno-deprecated-declarations ${CMAKE_CXX_FLAGS}")
endif ()

set_target_properties(coursework PROPERTIES
	CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
