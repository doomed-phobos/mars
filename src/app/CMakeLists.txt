find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

add_executable(mars
   main.cpp
   app.cpp)
target_include_directories(mars
   PRIVATE
   ${CMAKE_SOURCE_DIR}/src
   ${GTKMM_INCLUDE_DIRS})
target_link_libraries(mars ${GTKMM_LIBRARIES})