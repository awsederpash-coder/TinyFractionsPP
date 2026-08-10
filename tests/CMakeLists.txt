find_package(Catch2 3 QUIET)

if(NOT Catch2_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG v3.4.0
            GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(Catch2)
endif()

set(TEST_SOURCES
    main_test.cpp
)
add_executable(my_library_tests ${TEST_SOURCES})

target_link_libraries(my_library_tests PRIVATE
        my_library::my_library
        Catch2::Catch2
)

target_compile_features(my_library_tests PRIVATE cxx_std_17)

set_target_properties(my_library_tests PROPERTIES
        CXX_EXTENSIONS OFF
)

include(Catch)
catch_discover_tests(my_library_tests)

add_custom_target(run_tests
        COMMAND my_library_tests
        DEPENDS my_library_tests
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Running all tests..."
)