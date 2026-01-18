cmake_minimum_required(VERSION 4.2)

project(
    nklz4cpp
    VERSION 1.0.0
    DESCRIPTION "C++ wrapper for lz4"
    LANGUAGES CXX
#    LANGUAGES CXX C
)

include(FetchContent)

enable_testing()

# LZ4 Dependency
find_package(lz4 QUIET)
if (NOT lz4_FOUND)
    if (EXISTS "other/lz4/build/cmake/CMakeLists.txt")
        message(STATUS "Building other/lz4...")
        add_subdirectory(other/lz4)
    else()
        message(STATUS "other/lz4 not found. Building from git...")
        # if(MSVC)
        #     set(BUILD_COMMAND ${CMAKE_VS_MSBUILD_COMMAND} /property:PlatformToolset=${CMAKE_VS_PLATFORM_TOOLSET} /p:Configuration=$<CONFIG> /p:Platform=${CMAKE_VS_PLATFORM_NAME} "visual/VS2022/lz4.sln")
        # else()
        #     set(BUILD_COMMAND make)
        # endif()
        FetchContent_Declare(
            lz4
            GIT_REPOSITORY      https://github.com/lz4/lz4.git
            GIT_TAG             v1.10.0
            SOURCE_SUBDIR       build/cmake # Start from build/cmake
            # Not required anymore since lz4 provides CMake scripts for building
            #BUILD_COMMAND       ${BUILD_COMMAND}
            #INSTALL_COMMAND     ""
            #CONFIGURE_COMMAND   ""
        )
        FetchContent_MakeAvailable(lz4)
    endif()
else()
    message(STATUS "Found system lz4 installation")
endif()

# TODO: If not present and build using FetchContent, lz4 is stored in <build_dir>/_deps/lz4-src (or lz4?)
# So if cmake -B build-msvc -S . is used, lz4 artifacts will be in build-msvc/_deps/lz4-src
# lz4_static will reference this path, so include and library linking should work automatically
# The local dependency will build in
# TODO: We should also do a search for lz4 in the OS or user paths before fetching or building locally

# GTest Dependency
find_package(googletest QUIET)
if (NOT googletest_FOUND)
    if (EXISTS "other/googletest/CMakeLists.txt")
        message(STATUS "Building other/googletest...")
        add_subdirectory(other/googletest)
    else()
        message(STATUS "other/googletest not found. Downloading via git...")
        FetchContent_Declare(
            googletest
            GIT_REPOSITORY      https://github.com/google/googletest.git
            GIT_TAG             v1.17.0
        )
        if (WIN32)
            set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        endif()
        FetchContent_MakeAvailable(googletest)
    endif()
else()
    message(STATUS "Found system googletest installation")
endif()

### nklz4cpp Library ###
########################
add_library(${PROJECT_NAME} STATIC)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
)
# target_compile_features(${PROJECT_NAME} PUBLIC c_std_11)
# set_target_properties(${PROJECT_NAME} PROPERTIES
#     C_EXTENSIONS OFF
#     C_STANDARD_REQUIRED ON
# )

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
# set(${PROJECT_NAME}_SOURCES
#     src/nklz4cpp.cpp
# )
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE lz4_static)
########################

add_subdirectory(test)