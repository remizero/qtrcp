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
              QColor getColor ();

            private slots :
              void onHexLineEditTextEdited ( const QString &arg1 );
              void onSaveNewColorBtnClicked ();
              void onPickScreenColorBtnClicked ();
              void setNewColor ( QColor color );
              void setColorUnderCursor ( QColor color );
              void onCancelBtnClicked ();
              void onCurrentColorLabelClicked ();

            signals :
              void saveNewColor ( QColor color );
              void newColorUnderCursor ( QColor color );

            private :
              Ui::ColorPickerDialog *ui;
              QDialog *dummyWidget;
              QColor currentColor;

            protected :
              bool eventFilter ( QObject *obj, QEvent *event ) Q_DECL_OVERRIDE;
              void resizeEvent ( QResizeEvent *event ) Q_DECL_OVERRIDE;
          };
        }
      }
    }
  }
}

#endif // COLORPICKERDIALOG_H
