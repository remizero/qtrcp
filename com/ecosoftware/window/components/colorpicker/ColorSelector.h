#ifndef COLORSELECTOR_H
#define COLORSELECTOR_H

// Librerías internas
#include "colorpicker_global.h"

// Librerías Externas
#include "macros_global.h"

/*
 *  the slider has a range of 0-360, sane as hue range
 *  so there is no need to convert the hue value passed to it
 *  It has a margin of 5 to give sapce for the triangle poniter
 */

// Librerías Qt
#include <QMouseEvent>
#include <QPainter>
#include <QSlider>
#include <QStyleOptionSlider>
#include <QWidget>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_COMPONENTS {

        namespace NAMESPACE_COLORPICKER {

          class COLORPICKER_EXPORT ColorSelector : public QSlider {

              Q_OBJECT

            public :
              QPoint currentColorPosition;
              QColor currentColor;
              ColorSelector ( QWidget *parent = nullptr );

              void grabCurrentColor ();

            signals :
              void colorChanged ( QColor color );

            protected :
              void paintEvent ( QPaintEvent *event );
              void mousePressEvent ( QMouseEvent *event ) override;
          };
        }
      }
    }
  }
}

#endif // COLORSELECTOR_H
