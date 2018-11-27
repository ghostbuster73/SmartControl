cmake_minimum_required(VERSION 3.8.0)

project(SCLib)

find_package(Boost 1.67 REQUIRED)

set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

include_directories(
    ${Boost_INCLUDE_DIR}
    include/
    include/expressions
    include/expressions/ode_expressions/
    include/solvers
    include/solvers/ode_solvers
    include/header_libs
    )

set(HEADER
    include/header_libs/exprtk.hpp
    include/expressions/expression.h
    include/expressions/ode_expressions/phase_expression.h
    include/solvers/ode_solvers/phase_solver.h
    include/solvers/ode_solvers/i_ode_solver.h
    include/solvers/ode_solvers/runge_kutta_solver.h
    )

set(SOURCE
    source/expressions/expression.cpp
    source/expressions/ode_expressions/phase_expression.cpp
    source/solvers/ode_solvers/phase_solver.cpp
    source/solvers/ode_solvers/runge_kutta_solver.cpp
    )

add_library(${PROJECT_NAME} SHARED ${HEADER} ${SOURCE})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11 cxx_std_14)
