cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

project(foobar LANGUAGES C CXX)

find_package(OpenGL REQUIRED)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/src
  contrib/freeglut/include
  )


if(APPLE)
    find_package(OpenGL REQUIRED)
    find_package(GLUT REQUIRED)
endif(APPLE)
if(WIN32)
    option(FREEGLUT_BUILD_SHARED_LIBS "Build the GLUT example programs" ON)
    option(FREEGLUT_BUILD_STATIC_LIBS "Build the GLUT static example programs" ON)
    add_subdirectory(contrib/freeglut)
    target_link_libraries(${PROJECT_NAME} OpenGL::GL freeglut)
endif(WIN32)

add_executable(ch3OGLexample Chapter3/ch3OGLexample.c)
if(APPLE)
    target_link_libraries(ch3OGLexample OpenGL::GL GLUT::GLUT)
endif(APPLE)

if(APPLE OR WIN32)
     set(BUILD_SHARED_LIBS OFF)
     if(WIN32)
         # no console on start
         target_link_options(ch3OGLexample PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
     endif(WIN32)
endif()



add_executable(ch4CircleVariations Chapter4/ch4CircleVariations.cpp)
if(APPLE)
    target_link_libraries(ch4CircleVariations OpenGL::GL GLUT::GLUT)
endif(APPLE)

if(APPLE OR WIN32)
     set(BUILD_SHARED_LIBS OFF)
     if(WIN32)
         # no console on start
         target_link_options(ch4CircleVariations PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
     endif(WIN32)
endif()


add_executable(ch4LineGraph Chapter4/ch4LineGraph.c)
if(APPLE)
    target_link_libraries(ch4LineGraph OpenGL::GL GLUT::GLUT)
endif(APPLE)

if(APPLE OR WIN32)
     set(BUILD_SHARED_LIBS OFF)
     if(WIN32)
         # no console on start
         target_link_options(ch4LineGraph PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
     endif(WIN32)
endif()

add_executable(ch4PieChart Chapter4/ch4PieChart.cpp)
if(APPLE)
    target_link_libraries(ch4PieChart OpenGL::GL GLUT::GLUT)
endif(APPLE)

if(APPLE OR WIN32)
     set(BUILD_SHARED_LIBS OFF)
     if(WIN32)
         # no console on start
         target_link_options(ch4PieChart PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
     endif(WIN32)
endif()

add_executable(ch7CompositeTransformation2D Chapter7/ch7CompositeTransformation2D.cpp)
if(APPLE)
    target_link_libraries(ch7CompositeTransformation2D OpenGL::GL GLUT::GLUT)
endif(APPLE)

if(APPLE OR WIN32)
     set(BUILD_SHARED_LIBS OFF)
     if(WIN32)
         # no console on start
         target_link_options(ch7CompositeTransformation2D PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
     endif(WIN32)
endif()

add_executable(ch8ViewingProgram2D Chapter8/ch8ViewingProgram2D.cpp)
if(APPLE)
    target_link_libraries(ch8ViewingProgram2D OpenGL::GL GLUT::GLUT)
endif(APPLE)

if(APPLE OR WIN32)
     set(BUILD_SHARED_LIBS OFF)
     if(WIN32)
         # no console on start
         target_link_options(ch8ViewingProgram2D PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
     endif(WIN32)
endif()



# doesn't build
#add_executable(ch3errorcheck Chapter3/ch3errorcheck.c)
#target_link_libraries(${PROJECT_NAME} OpenGL::GL GLUT::GLUT)
