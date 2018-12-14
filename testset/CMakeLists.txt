file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${settest settest} ${srcs} ${hdrs})
target_link_libraries(${settestsettest} ${setlib} gtest)
