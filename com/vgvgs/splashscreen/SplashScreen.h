/**
 * Basado en el ejemplo Custom splashscreen with text de
 * https://wiki.qt.io/Custom_splashscreen_with_text
 */
#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

// Librerías Internas
#include "splashscreen_global.h"

// Librerías Externas
#include "macros_global.h"
#include "AppPaths.h"

// Librerías Qt
#include <QDebug>
#include <QDir>
#include <QPainter>
#include <QProgressBar>
#include <QSettings>
#include <QSplashScreen>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_SPLASHSCREEN {

      class SPLASHSCREENSHARED_EXPORT SplashScreen : public QSplashScreen {

          Q_OBJECT

        public :
          explicit SplashScreen ( QSettings *settings );
          ~SplashScreen ();

          void showStatusMessage ( const QString &message );

        public slots :
          void updateProgressValue ( int value );

        signals:
          void updateProgressValueSignal ( int value );

        private :
                   int alignement;
                QColor textColor;
               QString message;
                 QRect rect;
          QProgressBar *progressBar;
          void configFont ( QString family, bool bold, int fontSize, int fontStretch );
          void configProgressBar ( bool textvisible, QString textalignment, bool invertedappearance, int x, int y, int w, int h, QString orientation, int textdirection, QString format, int max, int min, QString backgroundcolor );
          void setMessageRect ( QRect rect, int alignement = Qt::AlignLeft );
          virtual void drawContents ( QPainter *painter );
      };
    }
  }
}

#endif // SPLASHSCREEN_H
