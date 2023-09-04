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
  window/components/colorpicker \
  window/components/colorbox \
  engines \
  window

CONFIG += ordered

UI_DIR = ../../ui
