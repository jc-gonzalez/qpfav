#############################################################################
# Makefile for building: qpfav
# Generated by qmake (3.1) (Qt 5.9.2)
# Project:  qpfav.pro
# Template: subdirs
# Command: /usr/bin/qmake-qt5 -o Makefile qpfav.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
#############################################################################

MAKEFILE      = Makefile

first: make_first
QMAKE         = /usr/bin/qmake-qt5
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /usr/bin/qmake-qt5 -install qinstall
QINSTALL_PROGRAM = /usr/bin/qmake-qt5 -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = qpfav1.0.0
DISTDIR = /home/eucops/Work/Euclid/QPF/qpfav/.tmp/qpfav1.0.0
SUBTARGETS    =  \
		sub-qslog-qslog-pro \
		sub-qpfav-qpfav-pro


sub-qslog-qslog-pro-qmake_all:  FORCE
	@test -d qslog/ || mkdir -p qslog/
	cd qslog/ && $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qslog/qslog.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
	cd qslog/ && $(MAKE) -f Makefile qmake_all
sub-qslog-qslog-pro: FORCE
	@test -d qslog/ || mkdir -p qslog/
	cd qslog/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qslog/qslog.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile
sub-qslog-qslog-pro-make_first: FORCE
	@test -d qslog/ || mkdir -p qslog/
	cd qslog/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qslog/qslog.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile 
sub-qslog-qslog-pro-all: FORCE
	@test -d qslog/ || mkdir -p qslog/
	cd qslog/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qslog/qslog.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile all
sub-qslog-qslog-pro-clean: FORCE
	@test -d qslog/ || mkdir -p qslog/
	cd qslog/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qslog/qslog.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile clean
sub-qslog-qslog-pro-distclean: FORCE
	@test -d qslog/ || mkdir -p qslog/
	cd qslog/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qslog/qslog.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile distclean
sub-qslog-qslog-pro-install_subtargets: FORCE
	@test -d qslog/ || mkdir -p qslog/
	cd qslog/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qslog/qslog.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile install
sub-qslog-qslog-pro-uninstall_subtargets: FORCE
	@test -d qslog/ || mkdir -p qslog/
	cd qslog/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qslog/qslog.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile uninstall
sub-qpfav-qpfav-pro-qmake_all:  FORCE
	@test -d qpfav/ || mkdir -p qpfav/
	cd qpfav/ && $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qpfav/qpfav.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
	cd qpfav/ && $(MAKE) -f Makefile qmake_all
sub-qpfav-qpfav-pro: FORCE
	@test -d qpfav/ || mkdir -p qpfav/
	cd qpfav/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qpfav/qpfav.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile
sub-qpfav-qpfav-pro-make_first: FORCE
	@test -d qpfav/ || mkdir -p qpfav/
	cd qpfav/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qpfav/qpfav.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile 
sub-qpfav-qpfav-pro-all: FORCE
	@test -d qpfav/ || mkdir -p qpfav/
	cd qpfav/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qpfav/qpfav.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile all
sub-qpfav-qpfav-pro-clean: FORCE
	@test -d qpfav/ || mkdir -p qpfav/
	cd qpfav/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qpfav/qpfav.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile clean
sub-qpfav-qpfav-pro-distclean: FORCE
	@test -d qpfav/ || mkdir -p qpfav/
	cd qpfav/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qpfav/qpfav.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile distclean
sub-qpfav-qpfav-pro-install_subtargets: FORCE
	@test -d qpfav/ || mkdir -p qpfav/
	cd qpfav/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qpfav/qpfav.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile install
sub-qpfav-qpfav-pro-uninstall_subtargets: FORCE
	@test -d qpfav/ || mkdir -p qpfav/
	cd qpfav/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qpfav/qpfav.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile uninstall

Makefile: qpfav.pro /usr/lib64/qt5/mkspecs/linux-g++/qmake.conf /usr/lib64/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib64/qt5/mkspecs/common/unix.conf \
		/usr/lib64/qt5/mkspecs/common/linux.conf \
		/usr/lib64/qt5/mkspecs/common/sanitize.conf \
		/usr/lib64/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib64/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib64/qt5/mkspecs/common/g++-base.conf \
		/usr/lib64/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib64/qt5/mkspecs/qconfig.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3danimation.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3danimation_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dcore.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dcore_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dextras.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dextras_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dinput.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dinput_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dlogic.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dlogic_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquick.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquick_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickanimation.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickanimation_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickextras.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickextras_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickinput.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickinput_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickrender.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickrender_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickscene2d.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickscene2d_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3drender.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_3drender_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_bluetooth.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_bluetooth_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_declarative.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_declarative_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_designer.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_designer_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_designercomponents_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_enginio.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_enginio_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_help.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_help_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_location.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_location_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_multimedia.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_multimedia_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_nfc.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_nfc_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_positioning.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_positioning_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qml_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmldebug_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quick_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickcontrols2.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_script.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_script_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_scripttools.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_scripttools_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sensors.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sensors_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_serialbus.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_serialbus_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_serialport.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_serialport_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_svg.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_svg_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_uiplugin.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_uitools.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_uitools_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandclient.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandclient_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandcompositor.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandcompositor_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_webchannel.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_webchannel_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_webkit.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_webkit_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_webkitwidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_websockets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_websockets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_x11extras.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_x11extras_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xmlpatterns.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		/usr/lib64/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt5/mkspecs/features/qt_config.prf \
		/usr/lib64/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib64/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib64/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt5/mkspecs/features/toolchain.prf \
		/usr/lib64/qt5/mkspecs/features/default_pre.prf \
		/usr/lib64/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib64/qt5/mkspecs/features/default_post.prf \
		/usr/lib64/qt5/mkspecs/features/qml_debug.prf \
		/usr/lib64/qt5/mkspecs/features/warn_on.prf \
		/usr/lib64/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib64/qt5/mkspecs/features/file_copies.prf \
		/usr/lib64/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib64/qt5/mkspecs/features/exceptions.prf \
		/usr/lib64/qt5/mkspecs/features/yacc.prf \
		/usr/lib64/qt5/mkspecs/features/lex.prf \
		qpfav.pro
	$(QMAKE) -o Makefile qpfav.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
/usr/lib64/qt5/mkspecs/features/spec_pre.prf:
/usr/lib64/qt5/mkspecs/common/unix.conf:
/usr/lib64/qt5/mkspecs/common/linux.conf:
/usr/lib64/qt5/mkspecs/common/sanitize.conf:
/usr/lib64/qt5/mkspecs/common/gcc-base.conf:
/usr/lib64/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib64/qt5/mkspecs/common/g++-base.conf:
/usr/lib64/qt5/mkspecs/common/g++-unix.conf:
/usr/lib64/qt5/mkspecs/qconfig.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3danimation.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3danimation_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dcore.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dcore_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dextras.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dextras_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dinput.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dinput_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dlogic.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dlogic_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquick.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquick_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickanimation.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickanimation_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickextras.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickextras_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickinput.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickinput_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickrender.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickrender_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickscene2d.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickscene2d_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3drender.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_3drender_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_bluetooth.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_bluetooth_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_declarative.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_declarative_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_designer.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_designer_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_designercomponents_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_egl_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_enginio.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_enginio_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_fb_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_glx_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_help.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_help_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_input_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_kms_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_location.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_location_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_multimedia.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_multimedia_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_multimediawidgets.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_nfc.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_nfc_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_packetprotocol_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_positioning.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_positioning_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qml.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qml_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qmldebug_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quick.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quick_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quickcontrols2.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quickcontrols2_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quickparticles_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quicktemplates2_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quickwidgets.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quickwidgets_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_script.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_script_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_scripttools.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_scripttools_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_sensors.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_sensors_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_serialbus.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_serialbus_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_serialport.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_serialport_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_service_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_svg.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_svg_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_theme_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_uiplugin.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_uitools.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_uitools_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandclient.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandclient_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandcompositor.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandcompositor_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_webchannel.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_webchannel_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_webkit.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_webkit_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_webkitwidgets.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_webkitwidgets_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_websockets.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_websockets_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_x11extras.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_x11extras_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xmlpatterns.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
/usr/lib64/qt5/mkspecs/features/qt_functions.prf:
/usr/lib64/qt5/mkspecs/features/qt_config.prf:
/usr/lib64/qt5/mkspecs/linux-g++/qmake.conf:
/usr/lib64/qt5/mkspecs/features/spec_post.prf:
.qmake.stash:
/usr/lib64/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib64/qt5/mkspecs/features/toolchain.prf:
/usr/lib64/qt5/mkspecs/features/default_pre.prf:
/usr/lib64/qt5/mkspecs/features/resolve_config.prf:
/usr/lib64/qt5/mkspecs/features/default_post.prf:
/usr/lib64/qt5/mkspecs/features/qml_debug.prf:
/usr/lib64/qt5/mkspecs/features/warn_on.prf:
/usr/lib64/qt5/mkspecs/features/qmake_use.prf:
/usr/lib64/qt5/mkspecs/features/file_copies.prf:
/usr/lib64/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib64/qt5/mkspecs/features/exceptions.prf:
/usr/lib64/qt5/mkspecs/features/yacc.prf:
/usr/lib64/qt5/mkspecs/features/lex.prf:
qpfav.pro:
qmake: FORCE
	@$(QMAKE) -o Makefile qpfav.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug

qmake_all: sub-qslog-qslog-pro-qmake_all sub-qpfav-qpfav-pro-qmake_all FORCE

make_first: sub-qslog-qslog-pro-make_first sub-qpfav-qpfav-pro-make_first  FORCE
all: sub-qslog-qslog-pro-all sub-qpfav-qpfav-pro-all  FORCE
clean: sub-qslog-qslog-pro-clean sub-qpfav-qpfav-pro-clean  FORCE
distclean: sub-qslog-qslog-pro-distclean sub-qpfav-qpfav-pro-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash
install_subtargets: sub-qslog-qslog-pro-install_subtargets sub-qpfav-qpfav-pro-install_subtargets FORCE
uninstall_subtargets: sub-qslog-qslog-pro-uninstall_subtargets sub-qpfav-qpfav-pro-uninstall_subtargets FORCE

sub-qslog-qslog-pro-check:
	@test -d qslog/ || mkdir -p qslog/
	cd qslog/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qslog/qslog.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile check
sub-qpfav-qpfav-pro-check:
	@test -d qpfav/ || mkdir -p qpfav/
	cd qpfav/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qpfav/qpfav.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile check
check: sub-qslog-qslog-pro-check sub-qpfav-qpfav-pro-check

sub-qslog-qslog-pro-benchmark:
	@test -d qslog/ || mkdir -p qslog/
	cd qslog/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qslog/qslog.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile benchmark
sub-qpfav-qpfav-pro-benchmark:
	@test -d qpfav/ || mkdir -p qpfav/
	cd qpfav/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qpfav/qpfav.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile benchmark
benchmark: sub-qslog-qslog-pro-benchmark sub-qpfav-qpfav-pro-benchmark
install:install_subtargets  FORCE

uninstall: uninstall_subtargets FORCE

FORCE:

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: sub-qslog-qslog-pro-distdir sub-qpfav-qpfav-pro-distdir FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents /usr/lib64/qt5/mkspecs/features/spec_pre.prf /usr/lib64/qt5/mkspecs/common/unix.conf /usr/lib64/qt5/mkspecs/common/linux.conf /usr/lib64/qt5/mkspecs/common/sanitize.conf /usr/lib64/qt5/mkspecs/common/gcc-base.conf /usr/lib64/qt5/mkspecs/common/gcc-base-unix.conf /usr/lib64/qt5/mkspecs/common/g++-base.conf /usr/lib64/qt5/mkspecs/common/g++-unix.conf /usr/lib64/qt5/mkspecs/qconfig.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3danimation.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3danimation_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dcore.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dcore_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dextras.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dextras_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dinput.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dinput_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dlogic.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dlogic_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dquick.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dquick_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickanimation.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickanimation_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickextras.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickextras_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickinput.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickinput_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickrender.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickrender_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickscene2d.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3dquickscene2d_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3drender.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_3drender_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_bluetooth.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_bluetooth_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_core.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_core_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_dbus.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_dbus_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_declarative.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_declarative_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_designer.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_designer_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_designercomponents_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_egl_support_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_enginio.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_enginio_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_fb_support_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_glx_support_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_gui.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_gui_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_help.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_help_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_input_support_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_kms_support_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_location.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_location_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_multimedia.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_multimedia_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_multimediawidgets.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_multimediawidgets_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_network.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_network_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_nfc.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_nfc_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_opengl.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_opengl_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_packetprotocol_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_positioning.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_positioning_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_qml.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_qml_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_qmldebug_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_quick.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_quick_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_quickcontrols2.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_quickcontrols2_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_quickparticles_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_quicktemplates2_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_quickwidgets.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_quickwidgets_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_script.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_script_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_scripttools.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_scripttools_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_sensors.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_sensors_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_serialbus.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_serialbus_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_serialport.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_serialport_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_service_support_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_sql.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_sql_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_svg.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_svg_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_testlib.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_testlib_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_theme_support_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_uiplugin.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_uitools.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_uitools_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_waylandclient.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_waylandclient_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_waylandcompositor.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_waylandcompositor_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_webchannel.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_webchannel_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_webkit.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_webkit_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_webkitwidgets.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_webkitwidgets_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_websockets.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_websockets_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_widgets.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_widgets_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_x11extras.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_x11extras_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_xml.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_xml_private.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_xmlpatterns.pri /usr/lib64/qt5/mkspecs/modules/qt_lib_xmlpatterns_private.pri /usr/lib64/qt5/mkspecs/features/qt_functions.prf /usr/lib64/qt5/mkspecs/features/qt_config.prf /usr/lib64/qt5/mkspecs/linux-g++/qmake.conf /usr/lib64/qt5/mkspecs/features/spec_post.prf .qmake.stash /usr/lib64/qt5/mkspecs/features/exclusive_builds.prf /usr/lib64/qt5/mkspecs/features/toolchain.prf /usr/lib64/qt5/mkspecs/features/default_pre.prf /usr/lib64/qt5/mkspecs/features/resolve_config.prf /usr/lib64/qt5/mkspecs/features/default_post.prf /usr/lib64/qt5/mkspecs/features/qml_debug.prf /usr/lib64/qt5/mkspecs/features/warn_on.prf /usr/lib64/qt5/mkspecs/features/qmake_use.prf /usr/lib64/qt5/mkspecs/features/file_copies.prf /usr/lib64/qt5/mkspecs/features/testcase_targets.prf /usr/lib64/qt5/mkspecs/features/exceptions.prf /usr/lib64/qt5/mkspecs/features/yacc.prf /usr/lib64/qt5/mkspecs/features/lex.prf qpfav.pro $(DISTDIR)/

sub-qslog-qslog-pro-distdir: FORCE
	@test -d qslog/ || mkdir -p qslog/
	cd qslog/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qslog/qslog.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -e -f Makefile distdir DISTDIR=$(DISTDIR)/qslog

sub-qpfav-qpfav-pro-distdir: FORCE
	@test -d qpfav/ || mkdir -p qpfav/
	cd qpfav/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/eucops/Work/Euclid/QPF/qpfav/qpfav/qpfav.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -e -f Makefile distdir DISTDIR=$(DISTDIR)/qpfav

