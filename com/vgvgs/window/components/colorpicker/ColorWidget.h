#ifndef COLORWIDGET_H
#define COLORWIDGET_H

// Librerías Internas
// Internal Libraries
#include "colorpicker_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías Qt
// Qt Libraries
#include <QtWidgets>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_COMPONENTS {

        namespace NAMESPACE_COLORPICKER {

          class COLORPICKER_EXPORT ColorWidget : public QWidget {

              Q_OBJECT

            protected :
              const int maxH          = 360;
              const int maxSV         = 255;
              const int pointerR      = 5;
              const int pointerBorder = 2;

            protected :
              bool middlePresed;
              bool selectorDrawn;
              bool shiftHeld;
              bool ctrlHeld;
              QPixmap hSelectorPixmap;
              QImage hueLayerImage;
              QColor color;
              int h, s, v;
              qreal hf, sf, vf;
              int pointerX;
              int pointerY;

            public :
              explicit ColorWidget ( QWidget *parent = nullptr );

            protected :
              void drawCircle ( QPainter &p );
              void hideCursor ( QMouseEvent *event );
              void restoreCursor ();

            signals :
              void middlePressedSignal ( QMouseEvent *event );

            public slots :
              void shiftPressed ();
              void shiftReleased ();
              void ctrlPressed ();
              void ctrlReleased ();
          };
        }
      }
    }
  }
}

#endif // COLORWIDGET_H
