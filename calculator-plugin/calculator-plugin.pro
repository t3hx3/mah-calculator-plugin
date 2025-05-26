#! [0]
TEMPLATE      = lib
CONFIG       += plugin
QT           += widgets
INCLUDEPATH += ../libmahcommon
HEADERS       = CalculatorPlugin.h \
    button.h
SOURCES       = CalculatorPlugin.cpp \
    button.cpp
TARGET        = $$qtLibraryTarget(CalculatorPlugin)
DESTDIR       = ../out
#! [0]

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/tools/plugandpaint/plugins
INSTALLS += target

CONFIG += install_ok  # Do not cargo-cult this!
uikit: CONFIG += debug_and_release
