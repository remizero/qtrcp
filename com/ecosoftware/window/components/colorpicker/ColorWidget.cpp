#include "ColorWidget.h"

using namespace NAMESPACE_LIBRARY_COLORPICKER;


ColorWidget::ColorWidget ( QWidget *parent ) : QWidget ( parent ) {

  this->selectorDrawn = false;
  this->middlePresed = false;
  this->shiftHeld = false;
  this->ctrlHeld = false;
  this->pointerY = 0;
  this->h = 0;
  this->s = this->maxSV;
  this->v = this->maxSV;
  this->color.setHsv ( this->h, this->s, this->v );
}

void ColorWidget::drawCircle ( QPainter &p ) {

  QPen pen ( Qt::transparent, this->pointerBorder );
  if ( v > 127 ) {

    p.setPen ( Qt::black );

  } else {

    p.setPen ( Qt::white );
  }
  p.drawEllipse ( QPoint ( this->pointerX, this->pointerY ), this->pointerR, this->pointerR );
}

void ColorWidget::hideCursor ( QMouseEvent *event ) {

  int x = event->position ().x ();
  int y = event->position ().y ();

  if ( !this->geometry ().contains ( event->position ().toPoint () ) ) {

    this->restoreCursor ();
    return;
  }
  this->setCursor ( QCursor ( Qt::BlankCursor ) );
}

void ColorWidget::restoreCursor () {

  this->setCursor ( QCursor ( Qt::ArrowCursor ) );
}

//This are from th eused class but are not used
//I'll keep them in case they are needed
void ColorWidget::shiftPressed () {

  this->shiftHeld = true;
}

void ColorWidget::shiftReleased () {

  this->shiftHeld = false;
}

void ColorWidget::ctrlPressed () {

  this->ctrlHeld = true;
}

void ColorWidget::ctrlReleased () {

  this->ctrlHeld = false;
}
