message("-- Linking sqlite3")
add_library(sqlite sqlite3.h sqlite3.c)
set_target_properties(sqlite PROPERTIES LINKER_LANGUAGE C)

# add_library(sqlite SHARED IMPORTED) # Neither SHARED nor MODULE is OK
# set_target_properties(sqlite PROPERTIES
#   IMPORTED_LOCATION sqlite3.dll
#   LINKER_LANGUAGE C
# )

target_include_directories(sqlite PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")
