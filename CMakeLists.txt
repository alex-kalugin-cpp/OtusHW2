cmake_minimum_required(VERSION 3.2)
if(NOT DEFINED ENV{TRAVIS_BUILD_NUMBER})
  message("TRAVIS_BUILD_NUMBER not defined. Setting its value to 1.")
  set(ENV{TRAVIS_BUILD_NUMBER} 1)
endif(NOT DEFINED ENV{TRAVIS_BUILD_NUMBER})

project(ip_filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(ip_filter main.cpp)

add_executable(test_version test/test_version.cpp)

include_directories(simpleIP4)
add_subdirectory(simpleIP4)
set_target_properties(ip_filter test_version PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

set_target_properties(test_version PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)
target_link_libraries(ip_filter simpleIP4)
target_include_directories(ip_filter
    PRIVATE "${CMAKE_BINARY_DIR}"
)
target_link_libraries(test_version
    ${Boost_LIBRARIES}
    simpleIP4
 )
if (MSVC)
    target_compile_options(ip_filter PRIVATE
       /W4
       )
    target_compile_options(simpleIP4 PRIVATE
        /W4
    )
    target_compile_options(test_version PRIVATE
        /W4
    )
else ()
    target_compile_options(ip_filter PRIVATE
       -Wall -Wextra -pedantic -Werror
   )
    target_compile_options(simpleIP4 PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()


install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(test_version test_version)
