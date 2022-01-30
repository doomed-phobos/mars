add_executable(mars
   app.cpp   
   main.cpp)
target_link_libraries(mars elements)
target_include_directories(mars PRIVATE ${CMAKE_SOURCE_DIR}/src)