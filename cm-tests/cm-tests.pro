QT += testlib
QT -= gui

#output paths
include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
INCLUDEPATH += source
TEMPLATE = app

SOURCES +=  source/models/tst_testcase1.cpp

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR =  $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR =  $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR =  $$PWD/build/$$DESTINATION_PATH/.ui
