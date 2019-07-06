cmake_minimum_required (VERSION 2.6)
project (SimpleProject)

foreach(flag_var
        CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
    if(${flag_var} MATCHES "/MD")
        string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
    endif(${flag_var} MATCHES "/MD")
endforeach(flag_var)

file(GLOB_RECURSE GENBINFILES C:/MyDocuments/Projects/Aurora3/Source/common/gen/*[!.h])

foreach(gen_bin_file ${GENBINFILES})
	get_filename_component(DIR ${gen_bin_file} DIRECTORY)
	get_filename_component(FNAME ${gen_bin_file} NAME)
	execute_process(
		COMMAND "C:/MyDocuments/Projects/Aurora3/BuildTools/bin2header/bin2header.exe" ${FNAME}
		WORKING_DIRECTORY ${DIR}
	)
endforeach(gen_bin_file)

file(GLOB_RECURSE SRCFILES 
C:/MyDocuments/Projects/Aurora3/Source/common/*.cpp;
C:/MyDocuments/Projects/Aurora3/Source/common/*.c;
C:/MyDocuments/Projects/Aurora3/Source/common/*.cxx;
C:/MyDocuments/Projects/Aurora3/Source/katana/*.cpp;
C:/MyDocuments/Projects/Aurora3/Source/katana/*.c;
C:/MyDocuments/Projects/Aurora3/Source/katana/*.cxx;
*.cpp;
*.c;
*.cxx)
file(GLOB_RECURSE EDITOR_SRCFILES 
C:/MyDocuments/Projects/Aurora3/Source/common/*.cpp;
C:/MyDocuments/Projects/Aurora3/Source/common/*.c;
C:/MyDocuments/Projects/Aurora3/Source/common/*.cxx;
C:/MyDocuments/Projects/Aurora3/Source/editor/*.cpp;
C:/MyDocuments/Projects/Aurora3/Source/editor/*.c;
C:/MyDocuments/Projects/Aurora3/Source/editor/*.cxx;
*.cpp;
*.c;
*.cxx)
add_executable(SimpleProject ${SRCFILES} C:/MyDocuments/Projects/Aurora3/Source/resource.rc)
add_executable(SimpleProject_editor ${EDITOR_SRCFILES} C:/MyDocuments/Projects/Aurora3/Source/resource.rc)

set_target_properties(
	SimpleProject PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_SOURCE_DIR}/../build/debug"
	RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../build/release"
	RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_SOURCE_DIR}/../build/release"
	RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../build/debug"
)

set_target_properties(
	SimpleProject_editor PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_SOURCE_DIR}/../build/debug"
	RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../build/release"
	RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_SOURCE_DIR}/../build/release"
	RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../build/debug"
)

target_include_directories(SimpleProject PRIVATE 
	C:/MyDocuments/Projects/Aurora3/Source/common/
	C:/MyDocuments/Projects/Aurora3/Source/katana/
	C:/MyDocuments/Projects/lib/glfw/include
	C:/MyDocuments/Projects/lib/rttr/src
	C:/MyDocuments/Projects/lib/assimp-master/include
	C:/MyDocuments/Projects/lib/assimp-master/build/include
	C:/MyDocuments/Projects/lib/bullet3-2.86.1/src
	C:/MyDocuments/Projects/Aurora3/Source/common
	C:/MyDocuments/Projects/Aurora3/Source/katana
)
target_link_directories(SimpleProject PRIVATE 
	C:/MyDocuments/Projects/lib/glfw/lib
	C:/MyDocuments/Projects/lib/rttr/lib
	C:/MyDocuments/Projects/lib/assimp-master/build/code/Release
	C:/MyDocuments/Projects/lib/assimp-master/build/contrib/zlib/Release
	C:/MyDocuments/Projects/lib/bullet3-2.86.1/bin
)
target_link_libraries(SimpleProject 
	shlwapi.lib
	glfw3.lib 
	OpenGL32.lib
	librttr_core.lib
	assimp.lib
	zlibstatic.lib
	BulletCollision_vs2010.lib
	BulletDynamics_vs2010.lib
	LinearMath_vs2010.lib
)

target_include_directories(SimpleProject_editor PRIVATE 
	C:/MyDocuments/Projects/Aurora3/Source/common/
	C:/MyDocuments/Projects/lib/glfw/include
	C:/MyDocuments/Projects/lib/rttr/src
	C:/MyDocuments/Projects/lib/assimp-master/include
	C:/MyDocuments/Projects/lib/assimp-master/build/include
	C:/MyDocuments/Projects/lib/bullet3-2.86.1/src
	C:/MyDocuments/Projects/Aurora3/Source/common
	C:/MyDocuments/Projects/Aurora3/Source/katana
)
target_link_directories(SimpleProject_editor PRIVATE 
	C:/MyDocuments/Projects/lib/glfw/lib
	C:/MyDocuments/Projects/lib/rttr/lib
	C:/MyDocuments/Projects/lib/assimp-master/build/code/Release
	C:/MyDocuments/Projects/lib/assimp-master/build/contrib/zlib/Release
	C:/MyDocuments/Projects/lib/bullet3-2.86.1/bin
)
target_link_libraries(SimpleProject_editor
	shlwapi.lib
	glfw3.lib 
	OpenGL32.lib
	librttr_core.lib
	assimp.lib
	zlibstatic.lib
	BulletCollision_vs2010.lib
	BulletDynamics_vs2010.lib
	LinearMath_vs2010.lib
)