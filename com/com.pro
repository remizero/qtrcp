# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
# include(../qmakeSupportFiles/buildPaths.prf)

# Se define la estructura de directorios del proyecto final compilado.
# The directory structure of the final compiled project is defined.
# include(../qmakeSupportFiles/createDirectoryStructure.prf)

# Se definen los parámetros de configuración del compilador.
# Compiler configuration parameters are defined.
# include(../qmakeSupportFiles/buildConfiguration.prf)

TEMPLATE = subdirs

SUBDIRS += \
  vgvgs

vgvgs.subdir = vgvgs

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
# include (../qmakeSupportFiles/deploymentRulesBin.prf)
