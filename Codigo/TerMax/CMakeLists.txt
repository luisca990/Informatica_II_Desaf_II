cmake_minimum_required(VERSION 3.16)

project(TerMax LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core LinguistTools)

set(TS_FILES TerMax_es_CO.ts)

add_executable(TerMax
  main.cpp
  ${TS_FILES}
  combustible.h combustible.cpp
  venta.h venta.cpp
  surtidor.h surtidor.cpp
  isla.h isla.cpp
  tanque.h tanque.cpp
  region.h region.cpp
  estacionservicio.h estacionservicio.cpp
  termaxgestionestacion.h termaxgestionestacion.cpp
  constantes.h
  archivo.h archivo.cpp

)
target_link_libraries(TerMax Qt${QT_VERSION_MAJOR}::Core)

if(COMMAND qt_create_translation)
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

include(GNUInstallDirs)
install(TARGETS TerMax
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
