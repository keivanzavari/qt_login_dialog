##############################################################################
# CMake
##############################################################################

cmake_minimum_required(VERSION 2.8)
project(qt_login_dialog)

##############################################################################
# Qt Environment
##############################################################################

# set compiler flag to supress:
# configure_file called with unknown argument(s):  COPY_ONLY
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-dev")


# find_package(Qt5Core)
find_package(Qt5Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.qrc)

qt5_add_resources(QT_RESOURCES_CPP ${QT_RESOURCES})
# QT5_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})

add_library(mainwindow mainwindow.cpp login_dialog.cpp)
target_link_libraries (mainwindow Qt5::Widgets)

set(EXEC_NAME qt_login_dialog)
add_executable(${EXEC_NAME} main.cpp ${QT_RESOURCES_CPP})
target_link_libraries (${EXEC_NAME} mainwindow)