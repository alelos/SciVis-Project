project(Connector)

# Required cmake version
cmake_minimum_required(VERSION 2.6.0)

# global needed variables
set(APPLICATION_NAME ${PROJECT_NAME})

set(LIBSSH_SHARED_LIBRARY
  ssh
  CACHE INTERNAL "libssh shared library"
)

set(APPLICATION_VERSION_MAJOR "0")
set(APPLICATION_VERSION_MINOR "0")
set(APPLICATION_VERSION_PATCH "0")

set(APPLICATION_VERSION "${APPLICATION_VERSION_MAJOR}.${APPLICATION_VERSION_MINOR}.${APPLICATION_VERSION_PATCH}")

# check subdirectories
add_subdirectory(src)


add_executable(exec main.cpp connector.cpp)
target_link_libraries(exec ${LIBSSH_SHARED_LIBRARY})



message(STATUS "********************************************")
message(STATUS "********** ${PROJECT_NAME} building  **********")
message(STATUS "********************************************")