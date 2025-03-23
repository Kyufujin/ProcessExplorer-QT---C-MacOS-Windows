set(CMAKE_AUTOMOC ON)
add_executable(ProcessExplorer_macOS 
main.cpp
ProcessExplorer.cpp
ProcessControler.cpp
ProcessUnit.cpp
../UI/MainWindow.cpp 
)
target_include_directories(ProcessExplorer_macOS PRIVATE ../UI)

target_link_libraries(ProcessExplorer_macOS PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

set_target_properties(ProcessExplorer_macOS PROPERTIES MACOSX_BUNDLE TRUE)