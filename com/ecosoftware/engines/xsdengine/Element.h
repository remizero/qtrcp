#ifndef ELEMENT_H
#define ELEMENT_H

// Librerías Internas
#include "xsdengine_global.h"
#include "Attribute.h"
#include "Facet.h"
#include "Type.h"
#include "Property.h"
#include "XsdEngine.h"

// Librerías Qt
#include <QList>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace XsdEngine {

        class XSDENGINESHARED_EXPORT Element : public QObject {

            Q_OBJECT

          public:
            Element ();

            QList<Attribute *> getAttributes () const;
            QString getDescription () const;
            QList<Element *> getElementsList () const;
            QString getName () const;
            Type *getType () const;
            Element *getParent () const;
            QList<Facet *> getProperties () const;
            void setAttribute ( Attribute *value );
            void setAttributes ( const QList<Attribute *> &value );
            void setDescription ( const QString &value );
            void setElementsList ( const QList<Element *> &value );
            void setName ( const QString &value );
            void setType ( Type *value );
            void setParent ( Element *value );
            void setProperty ( Facet *value );
            void setProperties ( const QList<Facet *> &value );

          private:
            QList<Attribute *> attributes; // DEFINITIVO
            QString description; // DEFINITIVO
            QList<Element *> elementsList;
            XsdEngine::xsdLevelEnum elementLevel; // DEFINITIVO
            QString name; // DEFINITIVO
            Type *type;
            Element *parent; // DEFINITIVO
            QList<Facet *> properties; // DEFINITIVO // Son todos los atributos que puede recibir el elemento xsd
        };
      }
    }
  }
}

#endif // ELEMENT_H
