cmake_minimum_required(VERSION 3.25.1)

project(qtcreator-layout VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(
  src/version.h.in
  src/version.h
)

add_executable(qtcreator-layout
  src/layouts.cc
  src/main.cc
  src/settings.cc
)

target_include_directories(qtcreator-layout
  PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}/src
)

find_package(Qt6 REQUIRED COMPONENTS Core)

target_link_libraries(qtcreator-layout
  PRIVATE
  Qt6::Core
)

include(GNUInstallDirs)

install(TARGETS qtcreator-layout RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

set(CPACK_DEBIAN_PACKAGE_DEPENDS libqt6core6)

include(CPack)
