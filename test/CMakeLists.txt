### nklz4cpp Test Application ###
#################################
include(GoogleTest)

add_executable(${PROJECT_NAME}_Test)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
# set(SOURCES
#     src/nklz4cpp-test.cpp
# )
target_sources(${PROJECT_NAME}_Test PRIVATE ${SOURCES})
target_link_libraries(${PROJECT_NAME}_Test PRIVATE GTest::gtest_main)
gtest_discover_tests(${PROJECT_NAME}_Test)
#################################