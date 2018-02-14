#ifndef XSDFORMELEMENT_H
#define XSDFORMELEMENT_H

// Librerías Internas
#include "xsdengine_global.h"
#include "XsdEngine.h"

// Librerías Externas

// Librerías Qt
#include <QList>
#include <QObject>
#include <QString>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace XsdEngine {

        class XSDENGINESHARED_EXPORT XsdFormElement : public QObject {

            Q_OBJECT

          public:
            XsdFormElement ( XsdFormElement *xsdFormElement = nullptr );

            QString getElementComment () const;
            QList<XsdFormElement *> getElementsList () const;
            QString getElementName () const;
            QString getElementType () const;
            QString getElementValue () const;
            XsdEngine::xsdLevelEnum getFormElementType () const;
            XsdFormElement *getParent () const;
            void setElementComment ( const QString &value );
            void setElementList ( XsdFormElement *value );
            void setElementsList ( const QList<XsdFormElement *> &value );
            void setElementName ( const QString &value );
            void setElementType ( const QString &value );
            void setElementValue ( const QString &value );
            void setFormElementType ( const XsdEngine::xsdLevelEnum &value );
            void setParent ( XsdFormElement *value );

          private:
                             QString elementComment;
             QList<XsdFormElement *> elementsList;
                             QString elementName;
                             QString elementType;
                             QString elementValue;
             XsdEngine::xsdLevelEnum formElementType;
                      XsdFormElement *parent;
        };
      }
    }
  }
}

#endif // XSDFORMELEMENT_H
