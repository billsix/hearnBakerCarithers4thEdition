## Computer Graphics with OpenGL 4th Edition, by Hearn Baker

Source code from the book, ported to run on modern Operating Systems.

### Download this source code

Use git to clone https://github.com/billsix/hearnBakerCarithers4thEdition.git .
This can be done using a standalone git client, or later after you have an IDE
installed for your Operating System (listed below).

### Install Dependencies

#### Windows

Download and install [CMake](http://www.cmake.org/cmake/resources/software.html).

Download and install Microsoft Visual Studio (NOT Visual Studio Code).

Double click on buildDebug.bat.  This will compile the code and open Visual Studio.

On the right, right click on the project you want to run, in the drop
down click on "Set as current project" or whatever it is, and then
on the menubar click the green triangle to run.



#### Mac OS X

Install XCode.

Download and install [CMake](http://www.cmake.org/cmake/resources/software.html)
if you don't already have it.  Make sure to add the cmake executable to your PATH
environment variable. You may instead use [Homebrew](http://brew.sh) to simplify
the installation:

    brew install cmake

Open Terminal, cd to the directory that has this project, and run "./macBuildDebug.sh"

This will compile the code, and open XCode.  On the top of this window, you can select
the current project that will be executed when you click on the "play" triangle in the upper
left of the window

#### Linux (Ubuntu)

    sudo apt-get install cmake glfw build-dep

    ./buildDebug.sh

Run any of the demos like this

    ./buildInstall/bin/ch3OGLexample
