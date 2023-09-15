TEMPLATE = subdirs

SUBDIRS += \
  components \
  mainwindow

components.subdir = components
mainwindow.subdir = mainwindow
mainwindow.depends = components
