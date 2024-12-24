cmake_minimum_required(VERSION 3.29)

project(Printf_NoBonus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

# Directories to include
set(PROJECT_DIRS "./")

# Directories to exclude
set(EXCLUDE_DIRS "cmake-build-debug")

set(sources "")
set(headers "")
set(include_dirs "")

# Iterate over project directories
foreach(project_dir ${PROJECT_DIRS})
	message(STATUS "Processing directory: ${project_dir}")

	file(GLOB_RECURSE source_files RELATIVE "${CMAKE_SOURCE_DIR}" "${project_dir}/*.c")
	foreach(source ${source_files})
		set(excluded OFF)
		foreach(exclude_dir ${EXCLUDE_DIRS})
			if(source MATCHES "^${exclude_dir}/")
				set(excluded ON)
				break()
			endif()
		endforeach()
		if(excluded)
			message(STATUS "Skipping excluded source file: ${source}")
			continue()
		endif()
		message(STATUS "Adding source file: ${source}")
		list(APPEND sources ${source})
	endforeach()

	file(GLOB_RECURSE header_files RELATIVE "${CMAKE_SOURCE_DIR}" "${project_dir}/*.h")
	foreach(header ${header_files})
		set(excluded OFF)
		foreach(exclude_dir ${EXCLUDE_DIRS})
			if(header MATCHES "^${exclude_dir}/")
				set(excluded ON)
				break()
			endif()
		endforeach()
		if(excluded)
			message(STATUS "Skipping excluded header file: ${header}")
			continue()
		endif()
		message(STATUS "Adding header file: ${header}")
		get_filename_component(header_dir ${header} DIRECTORY)
		if(include_dirs)
			list(FIND include_dirs ${header_dir} dir_index)
			if(dir_index EQUAL -1)
				list(APPEND include_dirs ${header_dir})
			endif()
		else()
			list(APPEND include_dirs ${header_dir})
		endif()
		list(APPEND headers ${header})
	endforeach()

	# Add the root directory as an include directory if it directly contains header files
	if(project_dir STREQUAL "./")
		file(GLOB root_headers "./*.h")
		if(root_headers)
			list(APPEND include_dirs "./")
		endif()
	endif()
endforeach()

add_executable(${PROJECT_NAME} ${sources} ${headers})

foreach(dir ${include_dirs})
	message(STATUS "Adding include directory: ${dir}")
	include_directories(${dir})
endforeach()