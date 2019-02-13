file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${queuetest} ${srcs} ${hdrs})
target_link_libraries(${queuetest} ${queuelib} gtest)
