file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${plextest} ${srcs} ${hdrs})
target_link_libraries(${plextest} ${plexlib} gtest)
