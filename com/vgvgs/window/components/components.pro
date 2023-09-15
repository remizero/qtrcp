TEMPLATE = subdirs

SUBDIRS += \
  actions \
  colorpicker \
  colorbox \
  menubar \
  statusbar \
  systemtrayicon \
  xsdform

actions.subdir = actions
actions.depends = colorpicker colorbox xsdform
colorpicker.subdir = colorpicker
# colorpicker.depends = macros
colorbox.subdir = colorbox
colorbox.depends = colorpicker
menubar.subdir = menubar
menubar.depends = actions colorpicker colorbox xsdform
statusbar.subdir = statusbar
# statusbar.depends = macros
systemtrayicon.subdir = systemtrayicon
# systemtrayicon.depends = macros
xsdform.subdir = xsdform
xsdform.depends = colorpicker colorbox
