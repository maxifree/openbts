set(SOURCE_FILES CLI.cpp CLIBase.cpp CLICommands.cpp CLIServer.cpp)
add_library(cli STATIC ${SOURCE_FILES})
target_link_libraries(cli control)
