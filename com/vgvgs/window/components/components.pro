TEMPLATE = subdirs

SUBDIRS += \
  actions \
  colorpicker \
  colorbox \
  menubar \
  statusbar \
  systemtrayicon \
  xsdform

colorpicker.subdir = colorpicker
# colorpicker.depends = macros
statusbar.subdir = statusbar
# statusbar.depends = macros
systemtrayicon.subdir = systemtrayicon
# systemtrayicon.depends = macros
colorbox.subdir = colorbox
colorbox.depends = colorpicker
xsdform.subdir = xsdform
xsdform.depends = colorpicker colorbox
actions.subdir = actions
actions.depends = colorpicker colorbox xsdform
menubar.subdir = menubar
menubar.depends = actions colorpicker colorbox xsdform
