cmake_minimum_required(VERSION 3.8.0)

project(SCConsole)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
include_directories(
    ${Boost_INCLUDE_DIR}
    ${SCLib_SOURCE_DIR}/include
    ${SCLib_SOURCE_DIR}/include/expressions
    ${SCLib_SOURCE_DIR}/include/header_libs
    ${SCLib_SOURCE_DIR}/include/expressions/ode_expressions/
    ${SCLib_SOURCE_DIR}/include/solvers/ode_solvers
    )

set(
    HEADER ${SCLib_SOURCE_DIR}/include
    ${SCLib_SOURCE_DIR}/include/expressions
    ${SCLib_SOURCE_DIR}/include/expressions/ode_expressions/
    ${SCLib_SOURCE_DIR}/include/solvers/ode_solvers
    ${SCLib_SOURCE_DIR}/include/header_libs
    )
set(SOURCE source/main.cpp)

add_executable(${PROJECT_NAME} ${HEADER} ${SOURCE})
target_link_libraries(${PROJECT_NAME} SCLib)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11 cxx_std_14)
