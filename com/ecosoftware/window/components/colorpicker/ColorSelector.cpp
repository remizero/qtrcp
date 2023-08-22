#include "ColorSelector.h"

using namespace NAMESPACE_LIBRARY_COLORPICKER;


ColorSelector::ColorSelector ( QWidget *parent ) : QSlider ( parent ) {

  //change current color when value changes
  connect ( this, &QSlider::valueChanged, this, &ColorSelector::grabCurrentColor );
}

void ColorSelector::grabCurrentColor () {

  this->currentColor = grab ().toImage ().pixel ( this->currentColorPosition );
  emit this->colorChanged ( this->currentColor );
}

void ColorSelector::paintEvent ( QPaintEvent *event ) {

  QSlider::paintEvent ( event );
  QPainter painter ( this );
  painter.setRenderHint ( QPainter::Antialiasing );
  painter.setBrush ( Qt::white );
  int y;
  //10 is margin-top + margin-bottom
  if ( this->invertedAppearance () ) {

    y = this->value () * ( this->height () - 10 ) / this->maximum ();

  } else {

    int position = this->maximum () - this->value ();
    y = position * ( this->height () - 10 ) / this->maximum ();
  }

  QPolygon rightTriangle,leftTriangle;

  //x is center, y is the position of the currently pointed at color
  this->currentColorPosition = QPoint ( this->width () / 2, y + 5 );

  //first point is the head that points at the color
  //the last 2 are of the base
  rightTriangle << QPoint ( this->rect ().right () - 5, y + 5 )
                << QPoint ( this->rect ().right (), y )
                << QPoint ( this->rect ().right (), y + 10 );

  leftTriangle << QPoint ( this->rect ().left () + 5, y + 5 )
               << QPoint ( this->rect ().left (), y )
               << QPoint ( this->rect ().left (), y + 10 );

  painter.drawPolygon ( rightTriangle );
  painter.drawPolygon ( leftTriangle );
}

void ColorSelector::mousePressEvent ( QMouseEvent *ev ) {

  QRect r ( this->currentColorPosition - QPoint ( this->currentColorPosition.x (), 5 ),
            this->currentColorPosition + QPoint ( +this->currentColorPosition.x (), 5 ) );
  if ( !r.contains ( ev->position ().toPoint () ) ) {

    if ( this->invertedAppearance () ) {

      this->setValue ( this->maximum () - ( this->minimum () + ( ( this->maximum () - this->minimum () ) * ( this->height () - ev->position ().toPoint ().y () ) ) / this->height () ) );

    } else {

      this->setValue ( this->minimum () + ( ( this->maximum ()-this->minimum () ) * ( this->height ()-ev->position ().toPoint ().y () ) ) / this->height () ) ;
    }
  } else {

    QSlider::mousePressEvent ( ev );
  }
}
