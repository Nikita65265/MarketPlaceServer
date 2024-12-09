cmake_minimum_required(VERSION 3.16)

project(MarketDataBaseEditor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appMarketDataBaseEditor
    main.cpp
)

qt_add_qml_module(appMarketDataBaseEditor
    URI MarketDataBaseEditor
    VERSION 1.0
        QML_FILES RegistrationWindow/LoginForm.qml
        QML_FILES RegistrationWindow/TextInput_normal/TextInput_normal.qml
        QML_FILES Widgets/CurButton.qml
        SOURCES RegistrationWindow/loginform.h RegistrationWindow/loginform.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appMarketDataBaseEditor PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appMarketDataBaseEditor
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appMarketDataBaseEditor
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appMarketDataBaseEditor
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
