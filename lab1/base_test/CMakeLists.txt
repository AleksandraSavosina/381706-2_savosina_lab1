file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${base_test} ${srcs} ${hdrs})
target_link_libraries(${base_test} ${base} gtest)
