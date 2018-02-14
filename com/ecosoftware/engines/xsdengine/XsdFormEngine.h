#ifndef XSDFORMENGINE_H
#define XSDFORMENGINE_H

// Librerías Internas
#include "xsdengine_global.h"
#include "Element.h"
#include "XsdFormElement.h"
#include "XsdFormCreator.h"

// Librerías Externas

// Librerías Qt
#include <QDialog>
#include <QDomDocument>
#include <QDomElement>
#include <QFile>
#include <QList>
#include <QListIterator>
#include <QObject>
#include <QUrl>
#include <QXmlSchema>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace XsdEngine {

        class XSDENGINESHARED_EXPORT XsdFormEngine : public QObject {

            Q_OBJECT

          public:
            XsdFormEngine ();

            XsdFormElement *getXsdFormElementModel () const;
            void loadXsd ( QString xsdFile );
            void parseXsd ();
            void parseXsd ( QDomElement docElement, XsdFormElement *xsdFormElement, QString rootNodeName );
            void parseXsd ( QDomElement docElement, QString rootNodeName, Element *xsdElement = nullptr );
            QDomDocument *toDomDocument ();
            QWidget *toForm ();
            QDialog *toFormDialog ();
            QString toString ();
            QString toXml ();

          private:
            QDomDocument *doc;
            XsdFormCreator *formDialog;
            XsdFormElement *xsdFormElementModel;
            Element *xsdElementModel;
        };
      }
    }
  }
}

#endif // XSDFORMENGINE_H
