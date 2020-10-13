
if (USE_GTEST)
    add_executable(project_name_gtest_app
        project_name_gtest.cpp)

    target_link_libraries(project_name_gtest_app
        project_name
        libgmock_main
        libgtest
        libgmock
        )

    add_test(NAME project_name_gtest
        COMMAND project_name_gtest_app)
endif()

if (USE_CATCH)
    add_executable(project_name_test_app
        project_name_test.cpp)

    target_link_libraries(project_name_test_app
        project_name
        Catch2::Catch2
        )

    add_test(NAME project_name_test
        COMMAND project_name_test_app)
endif()

if (USE_BENCHMARK)
    add_executable(project_name_benchmark_app
        project_name_benchmark.cpp)

    target_link_libraries(project_name_benchmark_app
        project_name
        benchmark
        benchmark_main
        )

    add_test(NAME project_name_benchmark
        COMMAND project_name_benchmark_app)
endif()
