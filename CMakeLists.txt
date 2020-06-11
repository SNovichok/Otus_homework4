cmake_minimum_required(VERSION 3.2)

if("$ENV{TRAVIS_BUILD_NUMBER}" STREQUAL "")
set(VERSION_NUMBER "0.0.1")
else()
set(VERSION_NUMBER "0.0.$ENV{TRAVIS_BUILD_NUMBER}")
endif()

project(homework2 VERSION ${VERSION_NUMBER})

add_executable(print_ip main.cpp)

set_target_properties(
    printIP PROPERTIES
    CXX_STANDART 17
    CXX_STANDART_REQUIRED ON
    )

if (MSVC)
    target_compile_options(print_ip PRIVATE /W4)
else()
    target_compile_options(print_ip PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
