#ifndef SATVALUESELECTOR_H
#define SATVALUESELECTOR_H

// Librerías internas
#include "colorpicker_global.h"
#include "ColorWidget.h"

// Librerías Externas
#include "macros_global.h"

// Librerías Qt
#include <QtWidgets>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_COMPONENTS {

        namespace NAMESPACE_COLORPICKER {

          class COLORPICKER_EXPORT SVSelector : public ColorWidget {

              Q_OBJECT

            public :
              explicit SVSelector ( QWidget *parent = nullptr );
              void setS ( QColor color );
              void setV ( QColor color );
              void setSV ( int s, int v );

            protected :
              void paintEvent ( QPaintEvent *e );
              void mousePressEvent ( QMouseEvent *e );
              void mouseMoveEvent ( QMouseEvent *e );
              void mouseReleaseEvent ( QMouseEvent *e );
              void wheelEvent ( QWheelEvent *e );

            private :
              void updateColor ();
              void drawPointer ( QPainter &p );
              void correctPointer ();
              void movePointer ( int x, int y );
              void incPointerX ( int val );
              void decPointerX ( int val );
              void decPointerY ( int val );
              void incPointerY ( int val );
              void drawBorder ( QPainter &p );

            signals :
              void colorChanged ( QColor );
              void saturationChanged ( QColor );
              void valueChanged ( QColor );

            public slots :
              void changeHue ( QColor color );
          };
        }
      }
    }
  }
}

#endif // SATVALUESELECTOR_H
