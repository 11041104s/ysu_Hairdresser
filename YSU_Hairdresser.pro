QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
QT += statemachine
FORMS += \
    editdialog.ui \
    mainwindow.ui
    //导入组件库的源文件
    SOURCES += \
        SDK/MaterialSDK/components/qtmaterialappbar.cpp \
        SDK/MaterialSDK/components/qtmaterialautocomplete.cpp \
        SDK/MaterialSDK/components/qtmaterialautocomplete_internal.cpp \
        SDK/MaterialSDK/components/qtmaterialavatar.cpp \
        SDK/MaterialSDK/components/qtmaterialbadge.cpp \
        SDK/MaterialSDK/components/qtmaterialcheckbox.cpp \
        SDK/MaterialSDK/components/qtmaterialcircularprogress.cpp \
        SDK/MaterialSDK/components/qtmaterialcircularprogress_internal.cpp \
        SDK/MaterialSDK/components/qtmaterialdialog.cpp \
        SDK/MaterialSDK/components/qtmaterialdialog_internal.cpp \
        SDK/MaterialSDK/components/qtmaterialdrawer.cpp \
        SDK/MaterialSDK/components/qtmaterialdrawer_internal.cpp \
        SDK/MaterialSDK/components/qtmaterialfab.cpp \
        SDK/MaterialSDK/components/qtmaterialflatbutton.cpp \
        SDK/MaterialSDK/components/qtmaterialflatbutton_internal.cpp \
        SDK/MaterialSDK/components/qtmaterialiconbutton.cpp \
        SDK/MaterialSDK/components/qtmateriallist.cpp \
        SDK/MaterialSDK/components/qtmateriallistitem.cpp \
        SDK/MaterialSDK/components/qtmaterialmenu.cpp \
        SDK/MaterialSDK/components/qtmaterialmenu_internal.cpp \
        SDK/MaterialSDK/components/qtmaterialpaper.cpp \
        SDK/MaterialSDK/components/qtmaterialprogress.cpp \
        SDK/MaterialSDK/components/qtmaterialprogress_internal.cpp \
        SDK/MaterialSDK/components/qtmaterialradiobutton.cpp \
        SDK/MaterialSDK/components/qtmaterialraisedbutton.cpp \
        SDK/MaterialSDK/components/qtmaterialscrollbar.cpp \
        SDK/MaterialSDK/components/qtmaterialscrollbar_internal.cpp \
        SDK/MaterialSDK/components/qtmaterialslider.cpp \
        SDK/MaterialSDK/components/qtmaterialslider_internal.cpp \
        SDK/MaterialSDK/components/qtmaterialsnackbar.cpp \
        SDK/MaterialSDK/components/qtmaterialsnackbar_internal.cpp \
        SDK/MaterialSDK/components/qtmaterialtable.cpp \
        SDK/MaterialSDK/components/qtmaterialtabs.cpp \
        SDK/MaterialSDK/components/qtmaterialtabs_internal.cpp \
        SDK/MaterialSDK/components/qtmaterialtextfield.cpp \
        SDK/MaterialSDK/components/qtmaterialtextfield_internal.cpp \
        SDK/MaterialSDK/components/qtmaterialtoggle.cpp \
        SDK/MaterialSDK/components/qtmaterialtoggle_internal.cpp \
    consume.cpp \
    customer.cpp \
    editdialog.cpp \
    employee.cpp \
    hairdressing.cpp \
        main.cpp \
    mainwindow.cpp \
    tablelist.cpp

    //导入组件库的头文件
    HEADERS += \
        SDK/MaterialSDK/components/qtmaterialappbar.h \
        SDK/MaterialSDK/components/qtmaterialappbar_p.h \
        SDK/MaterialSDK/components/qtmaterialautocomplete.h \
        SDK/MaterialSDK/components/qtmaterialautocomplete_internal.h \
        SDK/MaterialSDK/components/qtmaterialautocomplete_p.h \
        SDK/MaterialSDK/components/qtmaterialavatar.h \
        SDK/MaterialSDK/components/qtmaterialavatar_p.h \
        SDK/MaterialSDK/components/qtmaterialbadge.h \
        SDK/MaterialSDK/components/qtmaterialbadge_p.h \
        SDK/MaterialSDK/components/qtmaterialcheckbox.h \
        SDK/MaterialSDK/components/qtmaterialcheckbox_p.h \
        SDK/MaterialSDK/components/qtmaterialcircularprogress.h \
        SDK/MaterialSDK/components/qtmaterialcircularprogress_internal.h \
        SDK/MaterialSDK/components/qtmaterialcircularprogress_p.h \
        SDK/MaterialSDK/components/qtmaterialdialog.h \
        SDK/MaterialSDK/components/qtmaterialdialog_internal.h \
        SDK/MaterialSDK/components/qtmaterialdialog_p.h \
        SDK/MaterialSDK/components/qtmaterialdrawer.h \
        SDK/MaterialSDK/components/qtmaterialdrawer_internal.h \
        SDK/MaterialSDK/components/qtmaterialdrawer_p.h \
        SDK/MaterialSDK/components/qtmaterialfab.h \
        SDK/MaterialSDK/components/qtmaterialfab_p.h \
        SDK/MaterialSDK/components/qtmaterialflatbutton.h \
        SDK/MaterialSDK/components/qtmaterialflatbutton_internal.h \
        SDK/MaterialSDK/components/qtmaterialflatbutton_p.h \
        SDK/MaterialSDK/components/qtmaterialiconbutton.h \
        SDK/MaterialSDK/components/qtmaterialiconbutton_p.h \
        SDK/MaterialSDK/components/qtmateriallist.h \
        SDK/MaterialSDK/components/qtmateriallist_p.h \
        SDK/MaterialSDK/components/qtmateriallistitem.h \
        SDK/MaterialSDK/components/qtmateriallistitem_p.h \
        SDK/MaterialSDK/components/qtmaterialmenu.h \
        SDK/MaterialSDK/components/qtmaterialmenu_internal.h \
        SDK/MaterialSDK/components/qtmaterialmenu_p.h \
        SDK/MaterialSDK/components/qtmaterialpaper.h \
        SDK/MaterialSDK/components/qtmaterialpaper_p.h \
        SDK/MaterialSDK/components/qtmaterialprogress.h \
        SDK/MaterialSDK/components/qtmaterialprogress_internal.h \
        SDK/MaterialSDK/components/qtmaterialprogress_p.h \
        SDK/MaterialSDK/components/qtmaterialradiobutton.h \
        SDK/MaterialSDK/components/qtmaterialradiobutton_p.h \
        SDK/MaterialSDK/components/qtmaterialraisedbutton.h \
        SDK/MaterialSDK/components/qtmaterialraisedbutton_p.h \
        SDK/MaterialSDK/components/qtmaterialscrollbar.h \
        SDK/MaterialSDK/components/qtmaterialscrollbar_internal.h \
        SDK/MaterialSDK/components/qtmaterialscrollbar_p.h \
        SDK/MaterialSDK/components/qtmaterialslider.h \
        SDK/MaterialSDK/components/qtmaterialslider_internal.h \
        SDK/MaterialSDK/components/qtmaterialslider_p.h \
        SDK/MaterialSDK/components/qtmaterialsnackbar.h \
        SDK/MaterialSDK/components/qtmaterialsnackbar_internal.h \
        SDK/MaterialSDK/components/qtmaterialsnackbar_p.h \
        SDK/MaterialSDK/components/qtmaterialtable.h \
        SDK/MaterialSDK/components/qtmaterialtable_p.h \
        SDK/MaterialSDK/components/qtmaterialtabs.h \
        SDK/MaterialSDK/components/qtmaterialtabs_internal.h \
        SDK/MaterialSDK/components/qtmaterialtabs_p.h \
        SDK/MaterialSDK/components/qtmaterialtextfield.h \
        SDK/MaterialSDK/components/qtmaterialtextfield_internal.h \
        SDK/MaterialSDK/components/qtmaterialtextfield_p.h \
        SDK/MaterialSDK/components/qtmaterialtoggle.h \
        SDK/MaterialSDK/components/qtmaterialtoggle_internal.h \
        SDK/MaterialSDK/components/qtmaterialtoggle_p.h \
    consume.h \
    customer.h \
    editdialog.h \
    employee.h \
    hairdressing.h \
    mainwindow.h \
    tablelist.h

    #import Material SDK(导入Material组件库的SDK)
    LIBS += F:/QtProject/YSU_Hairdresser/SDK/MaterialSDK/staticlib/libcomponents.a
    INCLUDEPATH += F:/QtProject/YSU_Hairdresser/SDK/MaterialSDK/components
    PRE_TARGETDEPS += F:/QtProject/YSU_Hairdresser/SDK/MaterialSDK/staticlib/libcomponents.a

    //subdirs模板告诉qmake生成一个makefile，它可以进入到特定子目录并为这个目录中的项目文件生成makefile并且为它调用make。
    SUBDIRS += \
        SDK/MaterialSDK/components/components.pro

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Icons/resource.qrc
