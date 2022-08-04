message("-- Linking sqlite3")
add_library(SQLITE sqlite3.dll)
#set_target_properties(SQLITE PROPERTIES LINKER_LANGUAGE CXX)