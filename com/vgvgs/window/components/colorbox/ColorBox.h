#ifndef COLORBOX_H
#define COLORBOX_H

// Librerías internas
#include "colorbox_global.h"

// Librerías Externas
#include "macros_global.h"
#include "ColorPickerDialog.h"

// Librerías Qt
#include <QColor>
#include <QColorDialog>
#include <QEvent>
#include <QKeyEvent>
#include <QLineEdit>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_COMPONENTS {

        namespace NAMESPACE_COLORBOX {

          class COLORBOX_EXPORT ColorBox : public QLineEdit {

              Q_OBJECT
              Q_PROPERTY ( QColor color READ getColor WRITE setColor USER true NOTIFY colorChanged )

            public :
              ColorBox ( QWidget *parent = nullptr );

              QColor getColor () const;
              QString getTextColor ();
              void setColor ( const QColor &color );

            public slots :
              void launchColorDialog ();

            signals :
              bool colorChanged ();

            protected :
              void keyPressEvent ( QKeyEvent *event ) Q_DECL_OVERRIDE;

            private :
              QColor m_color;
              QAction *action;
              const QIcon getIcon ( const QColor &color );
          };
        }
      }
    }
  }
}

#endif // COLORBOX_H
