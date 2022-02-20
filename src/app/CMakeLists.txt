find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

add_library(app-lib
   STATIC
   app.cpp
   ui/main_window.cpp)
target_include_directories(app-lib
   PUBLIC
   ${GTKMM_INCLUDE_DIRS}
   ..)
target_link_libraries(app-lib ${GTKMM_LIBRARIES})