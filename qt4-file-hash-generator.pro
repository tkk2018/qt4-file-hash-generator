######################################################################
# Automatically generated by qmake (2.01a) Rab Dis 11 12:25:57 2024
# Edit this file to change/add configurations
######################################################################

TEMPLATE = app
TARGET = qt4-file-hash-generator
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += mainwindow.h
FORMS += mainwindow.ui
SOURCES += main.cpp mainwindow.cpp
RESOURCES += mainwindow.qrc

# Output
CONFIG(debug, debug|release) {
  DESTDIR = ./debug
} else {
  DESTDIR = ./release
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui
