add_executable(ProcessExplorer_macOS main.cpp)

target_link_libraries(ProcessExplorer_macOS PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

set_target_properties(ProcessExplorer_macOS PROPERTIES
    MACOSX_BUNDLE TRUE
)
