cmake_minimum_required(VERSION 3.21.1 FATAL_ERROR)
set(CMAKE_VERBOSE_MAKEFILE ON)

project("GameOfLife")

get_filename_component(CINDER_PATH "../../lib/cinder" ABSOLUTE)
get_filename_component(APP_PATH "../../" ABSOLUTE)
set(cinder_DIR "${CINDER_PATH}/lib/macosx/Release/")

include("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")
add_subdirectory("../../lib/Cinder" "../../build")

ci_make_app(
  APP_NAME    ${PROJECT_NAME}
  CINDER_PATH ${CINDER_PATH}
  SOURCES     ${APP_PATH}/src/main.cc
  INCLUDES    ${APP_PATH}/include
)