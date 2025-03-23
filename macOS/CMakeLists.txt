set(MACOS_SOURCES
    ProcessExplorer.cpp
    ProcessControler.cpp
    ProcessUnit.cpp
)

set(UI_SOURCES
    ../UI/MainWindow.cpp 
)

set(UI_HEADERS
    ../UI/MainWindow.hpp 
)

add_executable(ProcessExplorer_macOS 
main.cpp
${MACOS_SOURCES}
${UI_SOURCES}
)

target_link_libraries(ProcessExplorer_macOS PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

set_target_properties(ProcessExplorer_macOS PROPERTIES MACOSX_BUNDLE TRUE)