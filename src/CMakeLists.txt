add_subdirectory(app)

find_program(GLIB_COMPILE_RESOURCES glib-compile-resources REQUIRED)
set(GRESOURCE_C gresource.c)
set(GRESOURCE_C_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C})
set(GRESOURCE_XML ${DATA_SOURCE_DIR}/resources.xml)
file(GLOB_RECURSE resource_data_files "${DATA_SOURCE_DIR}/*.*")
add_custom_command(
   OUTPUT ${GRESOURCE_C}
   WORKING_DIRECTORY ${DATA_SOURCE_DIR}
   COMMAND ${GLIB_COMPILE_RESOURCES}
   ARGS
      --target=${GRESOURCE_C_OUTPUT_DIR}
      --generate-source
      ${GRESOURCE_XML}
   VERBATIM
   MAIN_DEPENDENCY ${GRESOURCE_XML}
   DEPENDS
      ${resource_data_files})

add_custom_target(gresource-target
   DEPENDS ${GRESOURCE_C_OUTPUT_DIR})

add_executable(${PROJECT_NAME} main/main.cpp ${GRESOURCE_C_OUTPUT_DIR})
set_source_files_properties(
   ${GRESOURCE_C_OUTPUT_DIR}
   PROPERTIES GENERATED TRUE
)
target_link_libraries(${PROJECT_NAME} app-lib)
add_dependencies(${PROJECT_NAME} gresource-target)