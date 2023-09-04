#include "ColorBox.h"

using namespace NAMESPACE_LIBRARY_COLORBOX;

ColorBox::ColorBox ( QWidget *parent ) : QLineEdit ( parent ) {

  this->setPlaceholderText ( "#000000" );
  this->setInputMask ( "#hhhhhh" );
  // this->setReadOnly ( true );
  this->action = new QAction ( this );
  this->setColor ( QColor ( Qt::black ) );
  // this->setClearButtonEnabled ( false );
  this->addAction ( this->action, QLineEdit::TrailingPosition );
  connect ( this->action, SIGNAL ( triggered () ), this, SLOT ( launchColorDialog () ) );
}

QColor ColorBox::getColor () const {

  return this->m_color;
}

QString ColorBox::getTextColor () {

  return this->m_color.name ().toUpper ();
}

void ColorBox::setColor ( const QColor &color ) {

  this->m_color = color;
  this->action->setIcon ( this->getIcon ( this->m_color ) );
  this->setText ( this->m_color.name ().toUpper () );
}

void ColorBox::launchColorDialog () {

  QColor color = QColorDialog::getColor ( this->m_color, this, tr ( "Select color" ) );
  // NAMESPACE_LIBRARY_COLORPICKER::ColorPickerDialog ( this->m_color, this, tr ( "Select color" ) );
  NAMESPACE_LIBRARY_COLORPICKER::ColorPickerDialog ( this, this->m_color );
  if ( color.isValid () ) {

    this->setColor ( color );
  }
}

void ColorBox::keyPressEvent ( QKeyEvent *event ) {

  QKeyEvent subEvent ( event->type (),
                       event->key (),
                       event->modifiers (),
                       event->nativeScanCode (),
                       event->nativeVirtualKey (),
                       event->nativeModifiers (),
                       event->text ().toUpper (),
                       event->isAutoRepeat (),
                       event->count () );
  QLineEdit::keyPressEvent ( &subEvent );
  if ( subEvent.isAccepted () ) {

    event->accept ();
  }
}

const QIcon ColorBox::getIcon ( const QColor &color ) {

  QPixmap pixmap ( 100, 100 );
  pixmap.fill ( color );
  const QIcon icon ( pixmap.copy () );
  return icon;
}
