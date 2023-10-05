# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
# include(../../qmakeSupportFiles/buildPaths.prf)

# Se define la estructura de directorios del proyecto final compilado.
# The directory structure of the final compiled project is defined.
# include(../../qmakeSupportFiles/createDirectoryStructure.prf)

# Se definen los parámetros de configuración del compilador.
# Compiler configuration parameters are defined.
# include(../../qmakeSupportFiles/buildConfiguration.prf)

TEMPLATE = subdirs

SUBDIRS += \
  macros \
  app \
  core \
  resources \
  utils \
  console \
  singleinstance \
  splashscreen \
  patternify \
  logger \
  engines \
  window

macros.subdir = macros
app.subdir = app
app.depends = macros
core.subdir = core
core.depends = macros
resources.subdir = resources
resources.depends = macros
utils.subdir = utils
utils.depends = macros
console.subdir = console
console.depends = macros
singleinstance.subdir = singleinstance
singleinstance.depends = macros
patternify.subdir = patternify
patternify.depends = macros app
logger.subdir = logger
logger.depends = macros app patternify core
splashscreen.subdir = splashscreen
splashscreen.depends = macros app
engines.subdir = engines
engines.depends = macros app resources utils 
window.subdir = window
window.depends = macros app resources utils engines

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
# include (../../qmakeSupportFiles/deploymentRulesBin.prf)
