project(format_test)

find_package(GTest REQUIRED)


add_executable(test test.cpp)
target_link_libraries(test format_lib GTest::GTest GTest::Main)

