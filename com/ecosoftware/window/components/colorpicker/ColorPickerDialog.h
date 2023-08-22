#ifndef COLORPICKERDIALOG_H
#define COLORPICKERDIALOG_H

// Librerías internas
#include "colorpicker_global.h"
#include "ui_ColorPickerDialog.h"
#include "SVSelector.h"

// Librerías Externas
#include "macros_global.h"

// Librerías Qt
#include <QDialog>
#include <QtWidgets>


namespace Ui {
  class ColorPickerDialog;
}

namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_COMPONENTS {

        namespace NAMESPACE_COLORPICKER {

          class COLORPICKER_EXPORT ColorPickerDialog : public QDialog {

              Q_OBJECT

            public :
              explicit ColorPickerDialog ( QWidget *parent = nullptr, QColor color = QColor ( "#ffffff" ) );
              ~ColorPickerDialog ();
              void updateHSV ( QColor color );
              void updateRGB ( QColor color );
              void updateCMY ( QColor color );
              void updateHexLabel ( QColor color );
              void CMYKUpdatesColor ( QColor color );

            private slots :
              void on_hexLineEdit_textEdited ( const QString &arg1 );
              void on_saveNewColorBtn_clicked ();
              void on_pickScreenColorBtn_clicked ();
              void setNewColor ( QColor color );
              void setColorUnderCursor ( QColor color );
              void on_cancelBtn_clicked ();
              void on_currentColorLabel_clicked();

            signals :
              void saveNewColor ( QColor color );
              void newColorUnderCursor ( QColor color );

            private :
              Ui::ColorPickerDialog *ui;
              QDialog *dummyWidget;
              QColor currentColor;

            protected :
              bool eventFilter ( QObject *obj, QEvent *event ) override;
              void resizeEvent ( QResizeEvent *event ) override;
          };
        }
      }
    }
  }
}

#endif // COLORPICKERDIALOG_H
