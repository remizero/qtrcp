# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../qmakeSupportFiles/buildPaths.prf)

# Se define la estructura de directorios del proyecto final compilado.
# The directory structure of the final compiled project is defined.
include(../../qmakeSupportFiles/createDirectoryStructure.prf)

# Se definen los parámetros de configuración del compilador.
# Compiler configuration parameters are defined.
include(../../qmakeSupportFiles/buildConfiguration.prf)

TEMPLATE = subdirs

SUBDIRS += \
  macros \
  resources \
  app \
  logger \
  utils \
  console \
  singleinstance \
  splashscreen \
  engines \
  window

macros.subdir = macros
resources.subdir = resources
resources.depends = macros
app.subdir = app
app.depends = macros
logger.subdir = logger
logger.depends = macros app
utils.subdir = utils
utils.depends = macros
console.subdir = console
console.depends = macros
singleinstance.subdir = singleinstance
singleinstance.depends = macros
splashscreen.subdir = splashscreen
splashscreen.depends = macros app
engines.subdir = engines
engines.depends = macros
window.subdir = window
window.depends = macros app utils resources engines

#examples.subdir = examples
#examples.file = examples/examples.pro
#examples.depends = com

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../qmakeSupportFiles/deploymentRulesBin.prf)
