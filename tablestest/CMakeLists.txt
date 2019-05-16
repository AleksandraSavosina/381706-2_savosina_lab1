file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${tablestest} ${srcs} ${hdrs})
target_link_libraries(${tablestest} ${tableslib} gtest)
