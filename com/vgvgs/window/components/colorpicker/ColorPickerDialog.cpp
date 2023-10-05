#include "ColorPickerDialog.h"

// Librerías Internas
// Internal Libraries
#include "ui_ColorPickerDialog.h"

using namespace NAMESPACE_LIBRARY_COLORPICKER;


ColorPickerDialog::ColorPickerDialog ( QWidget *parent, QColor color ) :
  QDialog ( parent ),
  ui ( new Ui::ColorPickerDialog ) {

  this->ui->setupUi ( this );
  this->currentColor = color;
  this->setNewColor ( color );

  //This widget is used to get mouse click event and get the pixel color there
  this->dummyWidget = new QDialog ( this );
  this->dummyWidget->setAttribute ( Qt::WA_TranslucentBackground, true );
  this->dummyWidget->setWindowFlag ( Qt::FramelessWindowHint, true );
  this->dummyWidget->installEventFilter ( this );
  this->dummyWidget->setMouseTracking ( true );
  connect ( this, &ColorPickerDialog::saveNewColor, this, &ColorPickerDialog::setNewColor );
  connect ( this, &ColorPickerDialog::newColorUnderCursor, this, &ColorPickerDialog::setColorUnderCursor );

  //Color Selector updating other widgets
  connect ( this->ui->colorSelector, &ColorSelector::colorChanged, [ this ] ( QColor color )
  {
    this->ui->hSpinBox->blockSignals ( true );
    this->ui->hSpinBox->setValue ( this->ui->colorSelector->value () );
    this->ui->hSpinBox->blockSignals ( false );
    this->ui->colorsShades->changeHue ( color );
  });
  connect ( this->ui->colorSelector, &ColorSelector::colorChanged, [ this ] ()
  {
    //QColor accepts hue range of 0-359
    int hue = this->ui->hSpinBox->value ();
    if ( hue > 359 ) {

      hue = 359;
    }
    QColor color = QColor::fromHsv ( hue,
                                     this->ui->sSpinBox->value () * 255 / 100,
                                     this->ui->vSpinBox->value () * 255 / 100);
    this->updateHexLabel ( color );
    this->updateRGB ( color );
    this->updateRGB ( color );
  });

  //update new color label
  connect ( this->ui->colorsShades, &SVSelector::colorChanged, [ this ] ( QColor color )
  {
    this->updateHexLabel ( color );
  });

  //colorShades updates spin boxes
  //HSV
  //values are of 0-255 range so they must be converted to percentage
  connect ( this->ui->colorsShades, &SVSelector::colorChanged,this->ui->hSpinBox, [ this ] ( QColor color )
  {
    this->ui->hSpinBox->blockSignals ( true );
    this->ui->hSpinBox->setValue ( color.toHsv ().hue () );
    this->ui->hSpinBox->blockSignals ( false );
  });
  connect ( this->ui->colorsShades, &SVSelector::saturationChanged, [ this ] ( QColor color )
  {
    this->ui->sSpinBox->blockSignals ( true );
    this->ui->sSpinBox->setValue ( color.toHsv ().saturation () * 100 / 255 );
    this->ui->sSpinBox->blockSignals ( false );
  });
  connect ( this->ui->colorsShades, &SVSelector::valueChanged, [ this ] ( QColor color )
  {
    this->ui->vSpinBox->blockSignals ( true );
    this->ui->vSpinBox->setValue ( color.toHsv ().value () * 100 / 255 );
    this->ui->vSpinBox->blockSignals ( false );
  });

  //RGB
  connect ( this->ui->colorsShades, &SVSelector::colorChanged, this, &ColorPickerDialog::updateRGB );
  //CMYK
  //values are of 0-255 range so they must be converted to percentage
  connect ( this->ui->colorsShades, &SVSelector::colorChanged, this, &ColorPickerDialog::updateRGB );
  connect ( this->ui->colorsShades, &SVSelector::colorChanged, [ this ] ( QColor color )
  {
    this->ui->kSpinBox->blockSignals ( true );
    this->ui->kSpinBox->setValue ( color.toCmyk ().black () * 100 / 255 );
    this->ui->kSpinBox->blockSignals ( false );
  });

  //spinboxes update colorShades

  //HSV
  //values are by percentage so they must be converted to 0-255 range
  connect ( this->ui->hSpinBox, &QSpinBox::valueChanged, [ this ] ( int i )
  {
    //QColor accepts hue range of 0-359
    if ( i > 359 ) {

      i = 359;
    }
    QColor color = QColor::fromHsv ( i,
                                     this->ui->sSpinBox->value () * 255 / 100,
                                     this->ui->vSpinBox->value () * 255 / 100);
    this->ui->colorsShades->changeHue ( color );
    this->updateRGB ( color );
    this->updateHexLabel ( color );
    this->ui->colorSelector->blockSignals ( true );
    this->ui->colorSelector->setValue ( color.hue () );
    this->ui->colorSelector->blockSignals ( false );
    this->updateRGB ( color );
  });
  connect ( this->ui->sSpinBox, &QSpinBox::valueChanged, [ this ] ( int i )
  {
    int hue = this->ui->hSpinBox->value ();
    if ( hue > 359 ) {

      hue = 359;
    }
    QColor color = QColor::fromHsv ( hue,
                                     i * 255 / 100,
                                     this->ui->vSpinBox->value () * 255 / 100 );
    this->ui->colorsShades->setS ( color.toHsv () );
    this->updateRGB ( color );
  });
  connect ( this->ui->vSpinBox, &QSpinBox::valueChanged, [ this ] ( int i )
  {
    int hue = this->ui->hSpinBox->value ();
    if ( hue > 359 ) {

      hue = 359;
    }
    QColor color = QColor::fromHsv ( hue,
                                     this->ui->sSpinBox->value () * 255 / 100,
                                     i * 255 / 100 );
    this->ui->colorsShades->setV ( color.toHsv () );
    this->updateRGB ( color );
  });

  //RGB
  connect ( this->ui->rSpinBox, &QSpinBox::valueChanged, [ this ] ( int i )
  {
    QColor color = QColor::fromRgb ( i,
                                     this->ui->gSpinBox->value (),
                                     this->ui->bSpinBox->value () );
    if ( color.black () == 255 || color.name () == "#ffffff" ) {

      this->ui->colorsShades->changeHue ( Qt::red );

    } else {

      this->ui->colorsShades->changeHue ( color );
    }
    this->updateHSV ( color );
    this->ui->kSpinBox->blockSignals ( true );
    this->ui->kSpinBox->setValue ( color.black () * 100 / 255 );
    this->ui->kSpinBox->blockSignals ( false );
    this->ui->colorsShades->setSV ( color.saturation (),color.value () );
    this->updateHexLabel ( color );
    this->updateRGB ( color );
  });
  connect ( this->ui->gSpinBox, &QSpinBox::valueChanged, [ this ] ( int i )
  {
    QColor color = QColor::fromRgb ( this->ui->rSpinBox->value (),
                                     i,
                                     this->ui->bSpinBox->value () );
    if ( color.black () == 255 || color.name () == "#ffffff" ) {

      this->ui->colorsShades->changeHue ( Qt::red );

    } else {

      this->ui->colorsShades->changeHue ( color );
    }
    this->updateHSV ( color );
    this->ui->kSpinBox->blockSignals ( true );
    this->ui->kSpinBox->setValue ( color.black () * 100 / 255 );
    this->ui->kSpinBox->blockSignals ( false );
    this->ui->colorsShades->setSV ( color.saturation (),color.value () );
    this->updateHexLabel ( color );
    this->updateRGB ( color );
  });
  connect ( this->ui->bSpinBox, &QSpinBox::valueChanged, [ this ] ( int i )
  {
    QColor color = QColor::fromRgb ( this->ui->rSpinBox->value (),
                                     this->ui->gSpinBox->value (),
                                     i );
    if ( color.black () == 255 || color.name () == "#ffffff" ) {

      this->ui->colorsShades->changeHue ( Qt::red );

    } else {

      this->ui->colorsShades->changeHue ( color );
    }
    this->updateHSV ( color );
    this->ui->kSpinBox->blockSignals ( true );
    this->ui->kSpinBox->setValue ( color.black () * 100 / 255 );
    this->ui->kSpinBox->blockSignals ( false );
    this->ui->colorsShades->setSV ( color.saturation (),color.value () );
    this->updateHexLabel ( color );
    this->updateRGB ( color );
  });

  //CMYK
  //values are by percentage so they must be converted to 0-255 range
  connect ( this->ui->cSpinBox, &QSpinBox::valueChanged, [ this ] ( int i )
  {
    QColor color = QColor::fromCmyk ( i * 255 / 100,
                                      this->ui->mSpinBox->value () * 255 / 100,
                                      this->ui->ySpinBox->value () * 255 / 100,
                                      this->ui->kSpinBox->value () * 255 / 100);
    CMYKUpdatesColor ( color );
  });
  connect ( this->ui->mSpinBox, &QSpinBox::valueChanged, [ this ] ( int i )
  {
    QColor color = QColor::fromCmyk ( this->ui->cSpinBox->value () * 255 / 100,
                                      i * 255 / 100,
                                      this->ui->ySpinBox->value () * 255 / 100,
                                      this->ui->kSpinBox->value () * 255 / 100);
    CMYKUpdatesColor ( color );
  });
  connect ( this->ui->ySpinBox, &QSpinBox::valueChanged, [ this ] ( int i )
  {
    QColor color = QColor::fromCmyk ( this->ui->cSpinBox->value () * 255 / 100,
                                      this->ui->mSpinBox->value () * 255 / 100,
                                      i * 255 / 100,
                                      this->ui->kSpinBox->value () * 255 / 100);
    CMYKUpdatesColor ( color );
  });
  connect ( this->ui->kSpinBox, &QSpinBox::valueChanged, [ this ] ( int i )
  {
    QColor color = QColor::fromCmyk ( this->ui->cSpinBox->value () * 255 / 100,
                                      this->ui->mSpinBox->value () * 255 / 100,
                                      this->ui->ySpinBox->value () * 255 / 100,
                                      i * 255 / 100);
    this->ui->vSpinBox->blockSignals ( true );
    this->ui->vSpinBox->setValue ( color.toHsv().value () * 100 / 255 );
    this->ui->vSpinBox->blockSignals ( false );
    this->ui->sSpinBox->blockSignals ( true );
    this->ui->sSpinBox->setValue ( color.toHsv().saturation () * 100 / 255 );
    this->ui->sSpinBox->blockSignals ( false );
    this->updateRGB ( color );
    this->ui->colorsShades->setSV ( color.saturation (),color.value () );
    this->updateHexLabel ( color );
  });
  this->ui->colorSelector->setValue ( 180 );
}

ColorPickerDialog::~ColorPickerDialog () {

  delete ui;
}

bool ColorPickerDialog::eventFilter ( QObject *obj, QEvent *event ) {

  if ( event->type () == QEvent::MouseButtonPress ) {

    QMouseEvent *mouseEvent = static_cast< QMouseEvent * > ( event );

    if ( mouseEvent->button () == Qt::LeftButton ) {

      //get the color under cursor when clicking left mouse button
      QPoint p = mouseEvent->globalPosition ().toPoint ();
      QScreen *screen = QGuiApplication::screenAt ( p );

      if ( !screen ) {

        screen = QGuiApplication::primaryScreen ();
      }
      const QPixmap pixmap = screen->grabWindow ( 0,
                                                  0,//p.x() - screenRect.x(),
                                                  0,//p.y() - screenRect.y(),
                                                  screen->size ().width (),
                                                  screen->size ().height () );
      const QImage i = pixmap.toImage ();
      QColor color = i.pixel ( p );
      emit this->saveNewColor ( color );
      static_cast< QDialog * > ( obj )->hide ();
    }
  }
  if ( event->type () == QEvent::MouseMove ) {

    //update current color under cursor
    QMouseEvent *mouseEvent = static_cast< QMouseEvent * > ( event );
    QPoint p = mouseEvent->globalPosition ().toPoint ();
    QScreen *screen = QGuiApplication::screenAt ( p );
    if ( !screen ) {

      screen = QGuiApplication::primaryScreen ();
    }
    const QPixmap pixmap = screen->grabWindow ( 0,
                                                0,
                                                0,
                                                screen->size ().width (),
                                                screen->size ().height () );
    emit this->newColorUnderCursor ( pixmap.toImage ().pixel ( p ) );
  }
  return QWidget::eventFilter ( obj, event );
}

void ColorPickerDialog::resizeEvent ( QResizeEvent *event ) {

  //when resizing the pointer should stay above the same color
  //meaning it has to be moved
  //comment the following if block to understand what that means
  if ( this->ui->colorsShades ) {

    int s = this->ui->sSpinBox->value () * 255 / 100 ;
    int v = this->ui->vSpinBox->value () * 255 / 100 ;
    int x = s * event->size ().width () / 255 ;
    int y = ( 255 - v ) * event->size ().height () / 255;
    this->ui->colorsShades->setSV ( s, v );
  }
}

void ColorPickerDialog::updateHSV ( QColor color ) {

  this->ui->hSpinBox->blockSignals ( true );
  this->ui->hSpinBox->setValue ( color.toHsv ().hue () );
  this->ui->hSpinBox->blockSignals ( false );

  this->ui->sSpinBox->blockSignals ( true );
  this->ui->sSpinBox->setValue ( color.toHsv ().saturation () * 100 / 255 );
  this->ui->sSpinBox->blockSignals ( false );

  this->ui->vSpinBox->blockSignals ( true );
  this->ui->vSpinBox->setValue ( color.toHsv ().value () * 100 / 255 );
  this->ui->vSpinBox->blockSignals ( false );
}

void ColorPickerDialog::updateRGB ( QColor color ) {

  this->ui->rSpinBox->blockSignals ( true );
  this->ui->rSpinBox->setValue ( color.toRgb ().red () );
  this->ui->rSpinBox->blockSignals ( false );

  this->ui->gSpinBox->blockSignals ( true );
  this->ui->gSpinBox->setValue ( color.toRgb ().green () );
  this->ui->gSpinBox->blockSignals ( false );

  this->ui->bSpinBox->blockSignals ( true );
  this->ui->bSpinBox->setValue ( color.toRgb ().blue () );
  this->ui->bSpinBox->blockSignals ( false );
}

void ColorPickerDialog::updateCMY ( QColor color ) {

  this->ui->cSpinBox->blockSignals ( true );
  this->ui->cSpinBox->setValue ( color.cyan () * 100 / 255 );
  this->ui->cSpinBox->blockSignals ( false );

  this->ui->mSpinBox->blockSignals ( true );
  this->ui->mSpinBox->setValue ( color.magenta () * 100 / 255 );
  this->ui->mSpinBox->blockSignals ( false );

  this->ui->ySpinBox->blockSignals ( true );
  this->ui->ySpinBox->setValue ( color.yellow () * 100 / 255 );
  this->ui->ySpinBox->blockSignals ( false );
}

void ColorPickerDialog::onHexLineEditTextEdited ( const QString &arg1 ) {

  QColor color ( "#" + arg1 );
  if ( color.isValid () ) {

    this->ui->colorsShades->changeHue ( color );
    this->updateRGB ( color );
    this->ui->kSpinBox->blockSignals ( true );
    this->ui->kSpinBox->setValue ( color.black () * 100 / 255 );
    this->ui->kSpinBox->blockSignals ( false );
    this->updateHSV ( color );
    this->updateRGB ( color );
    this->ui->newColorLabel->setStyleSheet (
            this->ui->newColorLabel->styleSheet ().replace (
            QRegularExpression ( "#[0-9A-Fa-f]{6}\\b" ),
            color.name ()
          )
    );
    this->ui->colorSelector->blockSignals ( true );
    this->ui->colorSelector->setValue ( color.hue () );
    this->ui->colorSelector->blockSignals ( false );
    this->ui->colorsShades->setSV ( color.toHsv ().saturation (), color.toHsv ().value () );
  }
}

void ColorPickerDialog::updateHexLabel ( QColor color ) {

  this->ui->newColorLabel->setStyleSheet (
          this->ui->newColorLabel->styleSheet ().replace (
          QRegularExpression ( "#[0-9A-Fa-f]{6}\\b" ),
          color.name ()
        )
  );
  this->ui->hexLineEdit->blockSignals ( true );
  this->ui->hexLineEdit->setText ( color.name () );
  this->ui->hexLineEdit->blockSignals ( false );
}

void ColorPickerDialog::CMYKUpdatesColor ( QColor color ) {

  if ( color.black () == 255 || color.name () == "#ffffff" ) {

    this->ui->colorsShades->changeHue ( Qt::red );

  } else {

    this->ui->colorsShades->changeHue ( color );
  }
  this->updateHSV ( color );
  this->updateRGB ( color );
  this->updateHexLabel ( color );
  this->ui->colorSelector->blockSignals ( true );
  this->ui->colorSelector->setValue ( color.hue () );
  this->ui->colorSelector->blockSignals ( false );
  this->ui->colorsShades->setSV ( color.toHsv ().saturation (), color.toHsv ().value () );
  }

QColor ColorPickerDialog::getColor () {

  return this->currentColor;
}

void ColorPickerDialog::onSaveNewColorBtnClicked () {

  QColor color ( "#" + this->ui->hexLineEdit->text () );
  emit this->saveNewColor ( color );
  this->close ();
}

void ColorPickerDialog::onPickScreenColorBtnClicked () {

  this->dummyWidget->setFixedSize ( QGuiApplication::screenAt ( QCursor::pos () )->size () );
  this->dummyWidget->setCursor ( Qt::CrossCursor );
  this->dummyWidget->exec ();

}

void ColorPickerDialog::setNewColor ( QColor color ) {

  this->currentColor = color;
  this->ui->currentColorLabel->setStyleSheet (
          this->ui->currentColorLabel->styleSheet ().replace (
          QRegularExpression ( "#[0-9A-Fa-f]{6}\\b" ),
          color.name ()
        )
  );
  if ( "#" + this->ui->hexLineEdit->text () != color.name () ) {

    this->ui->hexLineEdit->setText ( color.name ().remove ( '#' ) );
  }
}

void ColorPickerDialog::setColorUnderCursor ( QColor color ) {

  if ( color.black () == 255 || color.name () == "#ffffff" ) {

    this->ui->colorsShades->changeHue ( Qt::red );

  } else {

    this->ui->colorsShades->changeHue ( color );
  }
  this->updateHSV ( color );
  this->updateRGB ( color );
  this->updateRGB ( color );
  this->ui->kSpinBox->blockSignals ( true );
  this->ui->kSpinBox->setValue ( color.black () * 100 / 255 );
  this->ui->kSpinBox->blockSignals ( false );
  this->updateHexLabel ( color );
  this->ui->colorSelector->blockSignals ( true );
  this->ui->colorSelector->setValue ( color.hue () );
  this->ui->colorSelector->blockSignals ( false );
  this->ui->colorsShades->setSV ( color.toHsv ().saturation (), color.toHsv ().value () );
}

void ColorPickerDialog::onCancelBtnClicked () {

  this->close ();
}

void ColorPickerDialog::onCurrentColorLabelClicked () {

  if ( this->currentColor.black () == 255 || this->currentColor.name () == "#ffffff" ) {

    this->ui->colorsShades->changeHue ( Qt::red );

  } else {

    this->ui->colorsShades->changeHue ( this->currentColor );
  }
  this->updateHSV ( this->currentColor );
  this->updateRGB ( this->currentColor );
  this->updateRGB ( this->currentColor );
  this->ui->kSpinBox->blockSignals ( true );
  this->ui->kSpinBox->setValue ( this->currentColor.black () * 100 / 255 );
  this->ui->kSpinBox->blockSignals ( false );
  this->updateHexLabel ( this->currentColor );
  this->ui->colorSelector->blockSignals ( true );
  this->ui->colorSelector->setValue ( this->currentColor.hue () );
  this->ui->colorSelector->blockSignals ( false );
  this->ui->colorsShades->setSV ( this->currentColor.toHsv ().saturation (), this->currentColor.toHsv ().value () );
}
