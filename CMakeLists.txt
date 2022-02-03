cmake_minimum_required(VERSION 3.8)
project(algorithms VERSION 0.0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED  YES)
set(DEFAULT_BUILD_TYPE "Release")

set(ALGO_BUILD)
option(ALGO_SHARED "Shared build" ON)
option(ALGO_STATIC "Static build" OFF)
option(ALGO_USE_C99 "c99" OFF)
option(ALGO_USE_TEST "Enable testing" OFF)

add_library(${PROJECT_NAME}
        src/algorithms.c
        src/sorts.c
        src/ray.c
        src/mat.c
        src/bounds.c
        src/vec.c
        src/kdtree.c
        src/primitive.c
        src/io.c)


target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        )

add_library(${PROJECT_NAME}_headers INTERFACE)
target_include_directories(${PROJECT_NAME}_headers INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (ALGO_USE_TEST)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        )

message(DEBUG ${CMAKE_INSTALL_INCLUDEDIR})

#install(DIRECTORY include/${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
#PATTERN ".*" EXCLUDE)

export (TARGETS ${PROJECT_NAME}
        NAMESPACE ${PROJECT_NAME}::
        FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        )

install (EXPORT ${PROJECT_NAME}
        FILE "${PROJECT_NAME}Config.cmake"
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

set(PACKAgE_NAME ${PROJECT_NAME})
set(prefix ${CMAKE_INSTALL_PREFIX})
set(exec_prefix ${CMAKE_INSTALL_PREFIX})
set(includedir "\${prefix}/${CMAKE_INSTALL_INCLUDEDIR}")
set(libdir "\${prefix}/${CMAKE_INSTALL_LIBDIR}")
set(PACKAGE_VERSION "${PROJECT_VERSION}")
configure_file(${CMAKE_CURRENT_LIST_DIR}/calgo.pc.in ${CMAKE_BINARY_DIR}/calgo.pc @ONLY)

install(FILES ${CMAKE_BINARY_DIR}/calgo.pc
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)