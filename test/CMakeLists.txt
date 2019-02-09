add_executable(project_name_test_app
	project_name_test.cpp)

target_link_libraries(project_name_test_app
    project_name
	libgmock_main
	libgtest
	libgmock
    )

add_test(NAME project_name_test
	COMMAND project_name_test_app)

