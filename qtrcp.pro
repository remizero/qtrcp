# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(qmakeSupportFiles/buildPaths.prf)

# Se define la estructura de directorios del proyecto final compilado.
# The directory structure of the final compiled project is defined.
include(qmakeSupportFiles/createDirectoryStructure.prf)

# Se definen los parámetros de configuración del compilador.
# Compiler configuration parameters are defined.
include(qmakeSupportFiles/buildConfiguration.prf)

TEMPLATE = subdirs

SUBDIRS += \
  shadow \
  third-party \
  com \
  examples \

# Se definen las rutas, archivos pro y dependencias de los subproyectos.
# The paths, pro files and dependencies of the subprojects are defined.
shadow.subdir = shadow
third-party.subdir = third-party
third-party.depends = shadow
com.subdir = com
com.depends = shadow third-party
examples.subdir = examples
examples.depends = shadow com third-party

# CONFIG += ordered

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (qmakeSupportFiles/deploymentRulesBin.prf)

DISTFILES += \
  Agradecimientos.txt \
  qmakeSupportFiles/buildConfiguration.prf \
  qmakeSupportFiles/buildPaths.prf \
  qmakeSupportFiles/copyBinaries.prf \
  qmakeSupportFiles/copyConfigFiles.prf \
  qmakeSupportFiles/copyDataFiles.prf \
  qmakeSupportFiles/copyExternLibraries.prf \
  qmakeSupportFiles/copyIncludeFiles.prf \
  qmakeSupportFiles/copyLibraries.prf \
  qmakeSupportFiles/copyMediaFiles.prf \
  qmakeSupportFiles/copyPlugins.prf \
  qmakeSupportFiles/copyResourcesFiles.prf \
  qmakeSupportFiles/copyTranslatioFiles.prf \
  qmakeSupportFiles/copyVendorLibFiles.prf \
  qmakeSupportFiles/createDirectoryStructure.prf \
  qmakeSupportFiles/deploymentRulesBin.prf \
  qmakeSupportFiles/deploymentRulesLib.prf \
  qmakeSupportFiles/frameworkVersion.prf \
  qmakeSupportFiles/normalizeProjectName.prf \
  qmakeSupportFiles/projectBinConfiguration.prf \
  qmakeSupportFiles/projectLibConfiguration.prf

# LISTA DE ARTICULOS INTERESANTES PARA IMPLEMENTAR EN QTRCP
#
# https://wiki.qt.io/How_to_make_an_Application_restartable
# https://wiki.qt.io/How_to_catch_enter_key
# https://wiki.qt.io/How_to_create_a_multi_language_application
# https://wiki.qt.io/How_to_create_a_library_with_Qt_and_use_it_in_an_application
# https://wiki.qt.io/How_to_do_dynamic_translation_in_QML
# https://wiki.qt.io/How_to_get_applications_running_with_root_privileges
# https://wiki.qt.io/How_to_get_snapshot_via_online_installer
# https://wiki.qt.io/ModelEditor
# https://wiki.qt.io/Model-View-Presenter(MVP)_Design_Pattern_in_Qt_Application
# https://wiki.qt.io/How_to_Add_Holidays_to_QCalendarWidget
# https://wiki.qt.io/JSONListModel
# https://wiki.qt.io/JSON
# https://wiki.qt.io/Plugins
# https://wiki.qt.io/Progress_Bar
# https://wiki.qt.io/Progress_Bar
# https://wiki.qt.io/Show_tooltips_for_long_entries_of_your_custom_model
# https://wiki.qt.io/Show_library_dependencies
# https://wiki.qt.io/Select_an_Entry_or_Add_a_New_One_ComboBox
# https://wiki.qt.io/Sandbox
# https://wiki.qt.io/QSplashScreen-Replacement-for-Semitransparent-Images
# https://wiki.qt.io/User_Login_Dialog
# https://wiki.qt.io/WestonTouchScreenIssues
# https://wiki.qt.io/Using_CMake_build_system
# https://wiki.qt.io/Unit_Testing/es
# https://wiki.qt.io/API_Design_Principles
# https://wiki.qt.io/Application_Scripting_with_QJSEngine
# https://wiki.qt.io/Application_Start-up_Patterns
# https://wiki.qt.io/C%2B%2B_Documentation_Style
# https://wiki.qt.io/SQL_example/es
# https://wiki.qt.io/Drag_and_Drop_within_a_GridView
# https://wiki.qt.io/Drag_and_Drop_of_files
# https://wiki.qt.io/QList_Drag_and_Drop_Example
# https://wiki.qt.io/Colors_and_Font_Guidelines
# https://wiki.qt.io/Color_palette_generator
# https://wiki.qt.io/PySide_Collapsable_Dock_Windows
# https://wiki.qt.io/Clickable_QLabel
# https://wiki.qt.io/Custom_splashscreen_with_text
# https://wiki.qt.io/Custom_TabBar
# https://wiki.qt.io/Date_in_File_Name
# https://wiki.qt.io/Custom_TabBar
# https://wiki.qt.io/Main
#
#
# https://wiki.qt.io/JavaScript
# https://wiki.qt.io/QML_for_JavaScript_programmers
# https://wiki.qt.io/Integrating_Qt_Examples
