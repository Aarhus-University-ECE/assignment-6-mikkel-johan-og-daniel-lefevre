cmake_minimum_required(VERSION 3.16)
project(assignment-6 VERSION 0.1.0 LANGUAGES C CXX) # ${PROJECT_NAME}

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
		Catch2
		GIT_REPOSITORY https://github.com/catchorg/Catch2.git
		GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_library(max STATIC max.c)
add_library(list STATIC list.c)

set(libs max list)
foreach (lib ${libs})
	target_compile_definitions(${lib} PUBLIC -DTEST)
	target_compile_options(${lib}
				PUBLIC
				$<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall -Wpedantic>
)

endforeach ()

add_executable(unit-tests tests/tests.cpp)
target_include_directories(unit-tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(unit-tests PRIVATE max list)
target_link_libraries(unit-tests PRIVATE Catch2::Catch2WithMain)
target_compile_definitions(unit-tests PUBLIC -DTEST)
