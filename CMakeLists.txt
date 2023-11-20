cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

project(hearnbaker LANGUAGES C CXX)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/src
  contrib/freeglut/include
  )


if(APPLE)
    find_package(OpenGL REQUIRED)
    find_package(GLUT REQUIRED)
else()
    option(FREEGLUT_BUILD_SHARED_LIBS "Build the GLUT example programs" ON)
    option(FREEGLUT_BUILD_STATIC_LIBS "Build the GLUT static example programs" ON)
    add_subdirectory(contrib/freeglut)
endif(APPLE)


add_executable(ch3OGLexample Chapter3/ch3OGLexample.c)
if(APPLE)
    target_link_libraries(ch3OGLexample OpenGL::GL GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch3OGLexample PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch3OGLexample OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)


add_executable(ch4CircleVariations Chapter4/ch4CircleVariations.cpp)
if(APPLE)
    target_link_libraries(ch4CircleVariations OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch4CircleVariations PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch4CircleVariations OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)


add_executable(ch4LineGraph Chapter4/ch4LineGraph.c)
if(APPLE)
    target_link_libraries(ch4LineGraph OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch4LineGraph PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch4LineGraph OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)

add_executable(ch4PieChart Chapter4/ch4PieChart.cpp)
if(APPLE)
    target_link_libraries(ch4PieChart OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch4PieChart PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch4PieChart OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)

add_executable(ch7CompositeTransformation2D Chapter7/ch7CompositeTransformation2D.cpp)
if(APPLE)
    target_link_libraries(ch7CompositeTransformation2D OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch7CompositeTransformation2D PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch7CompositeTransformation2D OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)

add_executable(ch8ViewingProgram2D Chapter8/ch8ViewingProgram2D.cpp)
if(APPLE)
    target_link_libraries(ch8ViewingProgram2D OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch8ViewingProgram2D PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch8ViewingProgram2D OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)

add_executable(ch10PerspectiveViewing3D Chapter10/ch10PerspectiveViewing3D.cpp)
if(APPLE)
    target_link_libraries(ch10PerspectiveViewing3D OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch10PerspectiveViewing3D PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch10PerspectiveViewing3D OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)

add_executable(ch12Animation Chapter12/ch12Animation.cpp)
if(APPLE)
    target_link_libraries(ch12Animation OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch12Animation PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch12Animation OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)

add_executable(ch13Polyhedron Chapter13/ch13Polyhedron.cpp)
if(APPLE)
    target_link_libraries(ch13Polyhedron OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch13Polyhedron PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch13Polyhedron OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)

add_executable(ch13QuadricSurfaces Chapter13/ch13QuadricSurfaces.cpp)
if(APPLE)
    target_link_libraries(ch13QuadricSurfaces OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch13QuadricSurfaces PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch13QuadricSurfaces OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)

add_executable(ch14BezierCurve Chapter14/ch14BezierCurve.cpp)
if(APPLE)
    target_link_libraries(ch14BezierCurve OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch14BezierCurve PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch14BezierCurve OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)

add_executable(ch20GLUTMenu Chapter20/ch20GLUTMenu.cpp)
if(APPLE)
    target_link_libraries(ch20GLUTMenu OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch20GLUTMenu PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch20GLUTMenu OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)

add_executable(ch20GLUTSubmenu Chapter20/ch20GLUTSubmenu.cpp)
if(APPLE)
    target_link_libraries(ch20GLUTSubmenu OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch20GLUTSubmenu PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch20GLUTSubmenu OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)

add_executable(ch20KeyboardCurveDrawing Chapter20/ch20KeyboardCurveDrawing.cpp)
if(APPLE)
    target_link_libraries(ch20KeyboardCurveDrawing OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch20KeyboardCurveDrawing PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch20KeyboardCurveDrawing OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)

add_executable(ch20MouseKeyboardSquares Chapter20/ch20MouseKeyboardSquares.cpp)
if(APPLE)
    target_link_libraries(ch20MouseKeyboardSquares OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch20MouseKeyboardSquares PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch20MouseKeyboardSquares OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)

add_executable(ch20MousePlotPoint Chapter20/ch20MousePlotPoint.cpp)
if(APPLE)
    target_link_libraries(ch20MousePlotPoint OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch20MousePlotPoint PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch20MousePlotPoint OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)

add_executable(ch20MousePolyline Chapter20/ch20MousePolyline.cpp)
if(APPLE)
    target_link_libraries(ch20MousePolyline OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch20MousePolyline PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch20MousePolyline OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)

add_executable(ch20PickOperations Chapter20/ch20PickOperations.cpp)
if(APPLE)
    target_link_libraries(ch20PickOperations OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch20PickOperations PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch20PickOperations OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)

add_executable(ch23MandelbrotSet Chapter23/ch23MandelbrotSet.cpp)
if(APPLE)
    target_link_libraries(ch23MandelbrotSet OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch23MandelbrotSet PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch23MandelbrotSet OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)

add_executable(ch23SelfSquaringFractal Chapter23/ch23SelfSquaringFractal.cpp)
if(APPLE)
    target_link_libraries(ch23SelfSquaringFractal OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch23SelfSquaringFractal PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch23SelfSquaringFractal OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)

add_executable(ch4DispLstReshape Chapter4/ch4DispLstReshape.cpp)
if(APPLE)
    target_link_libraries(ch4DispLstReshape OpenGL::GL OpenGL::GLU GLUT::GLUT)
endif(APPLE)

set(BUILD_SHARED_LIBS OFF)
if(WIN32)
    # no console on start
    target_link_options(ch4DispLstReshape PUBLIC "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif(WIN32)
if(LINUX)
  target_link_libraries(ch4DispLstReshape OpenGL::GL OpenGL::GLU freeglut)
endif(LINUX)


































































install(TARGETS ch3OGLexample
                ch4CircleVariations
                ch4LineGraph
                ch4PieChart
                ch4DispLstReshape
                ch7CompositeTransformation2D
                ch8ViewingProgram2D
                ch10PerspectiveViewing3D
                ch12Animation
                ch13Polyhedron
                ch13QuadricSurfaces
                ch14BezierCurve
                ch20GLUTMenu
                ch20GLUTSubmenu
                ch20KeyboardCurveDrawing
                ch20MouseKeyboardSquares
                ch20MousePlotPoint
                ch20MousePolyline
                ch20PickOperations
                ch23MandelbrotSet
                ch23SelfSquaringFractal
                ch4DispLstReshape
                DESTINATION bin)


# doesn't build
#add_executable(ch3errorcheck Chapter3/ch3errorcheck.c)
#target_link_libraries(${PROJECT_NAME} OpenGL::GL GLUT::GLUT)
