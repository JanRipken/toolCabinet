cmake_minimum_required(VERSION 3.0)
project(toolCabinet)

set(CMAKE_CXX_STANDARD 11)

# Add include directories
include_directories(
    jsoncpp/include
    header
)

link_directories(jsoncpp/lib)
# Source files
set(SOURCES
    src/app.cpp
    src/cabinet.cpp
    src/helper.cpp
    src/tool.cpp
)



# Main executable
add_executable(toolCabinet ${SOURCES})
target_link_libraries(toolCabinet jsoncpp)

# Test executables
set(TEST_DIR build/tests)

add_executable(cabinet_test 
    tests/cabinet_test.cpp
    src/cabinet.cpp
    src/tool.cpp)
target_link_libraries(cabinet_test jsoncpp )

add_executable(tool_test
    tests/tool_test.cpp
    src/tool.cpp)
target_link_libraries(tool_test jsoncpp )




# Clean target
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${TEST_DIR}
    COMMAND ${CMAKE_COMMAND} -E remove build/toolCabinet
    COMMENT "Cleaning..."
)

# Run target
add_custom_target(run
    COMMAND ./toolCabinet
    DEPENDS toolCabinet
    COMMENT "Running..."
)

# Test target
add_custom_target(test
    COMMAND ./cabinet_test
    COMMAND ./tool_test
    DEPENDS cabinet_test tool_test
    COMMENT "Running tests..."
)

