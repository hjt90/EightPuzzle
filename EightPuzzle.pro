QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Common_tools.cpp \
    astar_search.cpp \
    basenode.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Common_tools.h \
    astar_search.h \
    basenode.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_ICONS = myico.ico
//版本信息
VERSION = 0.0.0.3
//公司名称
QMAKE_TARGET_COMPANY = "hjt90"
//产品名称
QMAKE_TARGET_PRODUCT = "EightPuzzle"
//文件说明
QMAKE_TARGET_DESCRIPTION = "A GUI EightPuzzle Game"
//版权信息
QMAKE_TARGET_COPYRIGHT = ""
//中文（简体）
RC_LANG = 0x0004
