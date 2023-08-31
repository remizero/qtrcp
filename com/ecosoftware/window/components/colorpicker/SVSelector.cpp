#include "SVSelector.h"

using namespace NAMESPACE_LIBRARY_COLORPICKER;


SVSelector::SVSelector ( QWidget *parent ) : ColorWidget ( parent ) {

  this->pointerX = 0;
  this->color = this->grab ().toImage ().pixel ( this->pointerX, this->pointerY );
  this->changeHue ( color );
  this->movePointer ( 0, 0 );
}

void SVSelector::paintEvent ( QPaintEvent *event ) {

  QColor color;
  QPainter p ( this );
  p.setRenderHint ( QPainter::Antialiasing );
  if ( !this->selectorDrawn ) {

    this->hueLayerImage = QImage ( this->maxSV + 1, this->maxSV + 1, QImage::Format_RGB32 );
    for ( int s = 0; s <= maxSV; s++ ) {

      for ( int v = 0; v <= maxSV; v++ ) {

        this->color.setHsv ( h, s, v );
        this->hueLayerImage.setPixel ( s, this->maxSV - v, this->color.rgb () );
      }
    }
    this->selectorDrawn = true;
  }
  p.drawImage ( 5, 5, this->hueLayerImage.scaled ( this->size ().width () - 10, this->size ().height () - 10 ) );
  this->drawPointer ( p );
}

void SVSelector::drawPointer ( QPainter &p ) {

  this->correctPointer ();

  //pointer should be black on lighter areas
  //and vice versa
  if ( this->color.black () < 127 ) {

    p.setPen ( Qt::black );

  } else {

    p.setPen ( Qt::white );
  }
  p.drawEllipse ( QPoint ( this->pointerX, this->pointerY ), this->pointerR, this->pointerR );
}

void SVSelector::mousePressEvent ( QMouseEvent *event ) {

  if ( event->button () == Qt::MiddleButton ) {

    this->middlePresed = true;
    event->ignore ();

  } else {

    this->middlePresed = false;
    this->hideCursor ( event );
    this->movePointer( event->position ().x (), event->position ().y () );
    this->updateColor ();
  }
}

void SVSelector::mouseMoveEvent ( QMouseEvent *event ) {

  if ( this->middlePresed ) {

    event->ignore ();

  } else {

    this->hideCursor ( event );
    this->movePointer ( event->position ().x (), event->position ().y () );
    this->updateColor ();
  }
}

void SVSelector::mouseReleaseEvent ( QMouseEvent *event ) {

  this->restoreCursor ();
  event->ignore ();
}

void SVSelector::wheelEvent ( QWheelEvent *event ) {

  QPoint p = event->angleDelta ();
  int y = p.y ();
  int val = 1;
  if ( this->ctrlHeld ) {

    val = 10;
  }
  if ( this->shiftHeld ) {

    if ( y > 0 ) {

      this->incPointerX ( val );
    }
    if ( y < 0 ) {

      this->decPointerX ( val );
    }
  } else {

    if ( y < 0 ) {

      this->incPointerY ( val );
    }
    if ( y > 0 ) {

      this->decPointerY ( val );
    }
  }
  this->updateColor ();
  event->accept ();
}

void SVSelector::incPointerX ( int val ) {

  this->movePointer ( this->pointerX + val, this->pointerY );
}

void SVSelector::decPointerX ( int val ) {

  this->movePointer ( this->pointerX - val, this->pointerY );
}

void SVSelector::incPointerY ( int val ) {

  this->movePointer ( this->pointerX, this->pointerY + val );
}

void SVSelector::decPointerY ( int val ) {

  this->movePointer ( this->pointerX, this->pointerY - val );
}

void SVSelector::correctPointer ()
{
    //restrict pointer to be kept inside the widget's rect
    //the center of the pointer must touch all 4 edges since it's used to detect current color
    this->pointerX = qMax ( 5, this->pointerX );
    this->pointerX = qMin ( this->geometry ().right () - 5 - 11, this->pointerX );

    this->pointerY = qMax( 5, this->pointerY );
    this->pointerY = qMin( this->geometry ().bottom () - 5 - 11, this->pointerY );
}

void SVSelector::movePointer ( int x, int y ) {

  //update current coordinates
  this->pointerX = x;
  this->pointerY = y;
  //pointer moved, meaning color changed, so update it
  this->color = this->grab ().toImage ().pixel ( this->pointerX, this->pointerY );
  //notify the change
  //be careful what this signal triggers
  emit this->colorChanged ( this->color );
  this->update (); // if pointer doesn't move, move update () to both mousePress () and mouseMove () events
}

void SVSelector::updateColor () {

  this->color = this->grab ().toImage ().pixel ( this->pointerX, this->pointerY );
  this->s = this->color.saturation ();
  this->v = this->color.value ();
  //color.setHsv(color.hue (), color.saturation (), color.value ());
  emit this->colorChanged ( this->color );
  emit this->saturationChanged ( this->color );
  emit this->valueChanged ( this->color );
}

void SVSelector::changeHue ( QColor color ) {

  //This gets also called when RGB values change
  //so it should change saturation and value as well
  this->selectorDrawn = false;
  this->h = this->color.hue ();
  this->s = this->color.saturation ();
  this->v = this->color.value ();
  this->correctPointer ();
  this->color.setHsv ( this->h, this->s, this->v );
  this->update ();
  //call this if necessary but update is mor advised in the Qt docs
  //repaint ();
}

//instead of sending v as the x coordinate to the pointer
//flipt it around by minusing it from 255 (max value)
//this is because SVSelector is resiazble, so if v value increases
//it should go up not down
void SVSelector::setS ( QColor color ) {

  this->s = this->color.saturation ();
  this->movePointer ( this->s * this->width () / 255, ( 255 - this->v ) * this->height () / 255 );
  this->correctPointer ();
  this->update ();
}

void SVSelector::setV ( QColor color ) {

  this->v = this->color.value ();
  this->movePointer ( this->s * this->width () / 255, ( 255 - this->v ) * this->height () / 255 );
  this->correctPointer ();
  this->update ();
}

void SVSelector::setSV ( int s, int v ) {

  this->s = s;
  this->v = v;
  this->blockSignals ( true );
  this->movePointer ( this->s * this->width () / 255, ( 255 - this->v ) * this->height () / 255 );
  this->blockSignals ( false );
  this->correctPointer ();
  this->update ();
}
