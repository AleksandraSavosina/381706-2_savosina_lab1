file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${queue_test} ${srcs} ${hdrs})
target_link_libraries(${queue_test} ${queue_lib} gtest)