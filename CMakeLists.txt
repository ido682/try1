cmake_minimum_required(VERSION 3.0.0)
project(zooz_users VERSION 0.1.0)

# include(CTest)
# enable_testing()

set(PROJECT_SOURCE_DIR src)

include_directories(include)

file(GLOB_RECURSE SRC_FILES "${PROJECT_SOURCE_DIR}/*.cpp")

add_compile_options("-std=c++11")

add_executable(zooz_users ${SRC_FILES})

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
