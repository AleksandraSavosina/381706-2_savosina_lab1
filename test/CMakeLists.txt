file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${mtest} ${srcs} ${hdrs})
target_link_libraries(${mtest} ${include} gtest)
