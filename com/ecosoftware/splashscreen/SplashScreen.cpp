#include "SplashScreen.h"
#include <QDebug>

using namespace Com::Ecosoftware::SplashScreen;

SplashScreen::SplashScreen ( QSettings *settings ) {

  this->textColor = QColor ( "#" + settings->value ( "splashscreen/font/color" ).toString () );
  QSplashScreen::setPixmap ( QPixmap ( App::AppPaths::getInstance ().getApplicationImagePath () + settings->value ( "splashscreen/imagesplash" ).toString () ) );
  this->setMessageRect ( QRect ( settings->value ( "splashscreen/messagebox/x" ).toInt (), settings->value ( "splashscreen/messagebox/y" ).toInt (), settings->value ( "splashscreen/messagebox/w" ).toInt (), settings->value ( "splashscreen/messagebox/h" ).toInt () ), settings->value ( "splashscreen/messagebox/alignment" ).toInt () );
  this->configFont ( settings->value ( "splashscreen/font/family" ).toString (),  settings->value ( "splashscreen/font/bold" ).toBool (),  settings->value ( "splashscreen/font/size" ).toInt (), settings->value ( "splashscreen/font/stretch" ).toInt () );
  this->configProgressBar ( settings->value ( "splashscreen/progressbar/textvisible" ).toBool (), settings->value ( "splashscreen/progressbar/textalignment" ).toString (), settings->value ( "splashscreen/progressbar/invertedappearance" ).toBool (), settings->value ( "splashscreen/progressbar/x" ).toInt (), settings->value ( "splashscreen/progressbar/y" ).toInt (), settings->value ( "splashscreen/progressbar/w" ).toInt (), settings->value ( "splashscreen/progressbar/h" ).toInt (), settings->value ( "splashscreen/progressbar/orientation" ).toString (), settings->value ( "splashscreen/progressbar/textdirection" ).toInt (), settings->value ( "splashscreen/progressbar/format" ).toString (), settings->value ( "splashscreen/progressbar/max" ).toInt (), settings->value ( "splashscreen/progressbar/min" ).toInt (), "#" + settings->value ( "splashscreen/progressbar/backgroundcolor" ).toString () );
  connect ( this, SIGNAL ( updateProgressValueSignal ( int ) ), this, SLOT ( updateProgressValue ( int ) ) );
}

SplashScreen::~SplashScreen () {}

void SplashScreen::configFont ( QString family, bool bold, int fontSize, int fontStretch ) {

  QFont splashFont;
  splashFont.setFamily ( family );
  splashFont.setBold ( bold );
  splashFont.setPixelSize ( fontSize );
  splashFont.setStretch ( fontStretch );
  this->setFont ( splashFont );
}

void SplashScreen::configProgressBar ( bool textvisible, QString textalignment, bool invertedappearance, int x, int y, int w, int h, QString orientation, int textdirection, QString format, int max, int min, QString backgroundcolor ) {

  this->progressBar = new QProgressBar ( this );
  this->progressBar->setMinimum ( min );
  this->progressBar->setMaximum ( max );
  this->progressBar->setTextVisible ( textvisible );
  if ( this->progressBar->isTextVisible () ) {

    this->progressBar->setStyleSheet ( "QProgressBar { text-align: " + textalignment + "; }" );
    this->progressBar->setInvertedAppearance ( invertedappearance );
    this->progressBar->setFormat ( format );
  }
  this->progressBar->setValue ( 0 );
  if ( ( orientation == "V" ) || ( orientation == "v" ) ) {

    this->progressBar->setOrientation ( Qt::Vertical );

  } else {

    this->progressBar->setOrientation ( Qt::Horizontal );
  }
  if ( textdirection == 0 ) {

    this->progressBar->setTextDirection ( QProgressBar::TopToBottom );

  } else if ( textdirection == 1 ) {

    this->progressBar->setTextDirection ( QProgressBar::BottomToTop );
  }
  QString st = QString ( "QProgressBar::chunk { background-color: " + backgroundcolor + "; }");
  this->progressBar->setStyleSheet ( st );
  this->progressBar->setGeometry ( QRect ( QPoint ( x, y ), QSize ( w, h ) ) );
}

void SplashScreen::drawContents ( QPainter *painter ) {

  QPixmap textPix = QSplashScreen::pixmap ();
  painter->setPen ( this->textColor );
  painter->drawText ( this->rect, this->alignement, this->message );
}

void SplashScreen::showStatusMessage ( const QString &message ) {

  this->message = message;
  this->showMessage ( this->message, this->alignement, this->textColor );
}

void SplashScreen::setMessageRect ( QRect rect, int alignement ) {

  this->rect = rect;
  this->alignement = alignement;
}

void SplashScreen::updateProgressValue ( int value ) {

  this->progressBar->setValue ( value );
}
