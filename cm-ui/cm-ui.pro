QT += quick \
        #qml

TEMPLATE += app
CONFIG += c++14 \
            #qt debug
            #qtc_runnable

#output paths
include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += source \
                ../cm-lib/source \
                views \
               # assets


HEADERS += ../cm-lib/source/controllers/mastercontroller.h \ #! Very Important for run
            ../cm-lib/source/controllers/navigation-controller.h\ #! Very Important for run
            ../cm-lib/source/controllers/commandcontroller.h\
            ../cm-lib/source/framework/command.h\

            #this pulls all *.h files in the data folder(Very Important !)
            $$files(../cm-lib/source/data/*.h, true) \
             $$files(../cm-lib/source/models/*.h, true)

SOURCES += source/main.cpp \
            ../cm-lib/source/controllers/mastercontroller.cpp \ #! Very Important for run
            ../cm-lib/source/controllers/navigation-controller.cpp\ #! Very Important for run
            ../cm-lib/source/controllers/commandcontroller.cpp\
            ../cm-lib/source/framework/command.cpp \
            #this pulls all.cpp files in the data folder( ! Very Important)
            $$files(../cm-lib/source/data/*.cpp, true) \
            $$files(../cm-lib/source/models/*.cpp, true)



RESOURCES += views.qrc assets.qrc components.qrc \

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = $$PWD# /Users/Peter/Qt5.12.0/5.12.0/clang_64/qml

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =      

# Peter: pulling or referencing the controller(cm-lib) library into this cm-ui class
LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lcm-lib

DESTDIR = $$PWD/../../shadow-builds/cm-ui/ #$$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR =  $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR =  $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR =  $$PWD/build/$$DESTINATION_PATH/.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

