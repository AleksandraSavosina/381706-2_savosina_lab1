file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${stacklisttest} ${srcs} ${hdrs})
target_link_libraries(${stacklisttest} ${stacklistlib} gtest)
