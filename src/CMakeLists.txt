
add_library(project_name STATIC
    project_name.hpp
    project_name.cpp
)

# for header only library: add_library(project_name INTERFACE project_name.hpp)

target_include_directories(project_name
	INTERFACE .)

add_executable(project_name_app
    main.cpp
)

target_link_libraries(project_name_app
    project_name)
