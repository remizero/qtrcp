#ifndef XSDELEMENT_H
#define XSDELEMENT_H

// Librerías Internas
#include "xsd_global.h"

// Librerías Externas
#include "macros_global.h"
#include "XsdAttribute.h"
#include "core/FacetAbs.h"
#include "core/PropertyAbs.h"
#include "core/TypeAbs.h"
#include "core/facets/AssertionsFacet.h"
#include "core/facets/EnumerationFacet.h"
#include "core/facets/ExplicitTimeZoneFacet.h"
#include "core/facets/FractionDigitsFacet.h"
#include "core/facets/LengthFacet.h"
#include "core/facets/MaxExclusiveFacet.h"
#include "core/facets/MaxInclusiveFacet.h"
#include "core/facets/MaxLengthFacet.h"
#include "core/facets/MinExclusiveFacet.h"
#include "core/facets/MinInclusiveFacet.h"
#include "core/facets/MinLengthFacet.h"
#include "core/facets/PatternFacet.h"
#include "core/facets/TotalDigitsFacet.h"
#include "core/facets/WhitespaceFacet.h"
#include "core/properties/NameProperty.h"
#include "core/properties/TypeProperty.h"
#include "Xsd.h"

// Librerías Qt
#include <QList>
#include <QObject>
#include <QDebug>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_ENGINES {

      namespace NAMESPACE_XSD {

        class XSDSHARED_EXPORT XsdElement : public QObject {

            Q_OBJECT

          public :
            XsdElement ();

            //QList<XsdAttribute *> getAttributes () const;
            Xsd::indicatorEnum getElementIndicator () const;
            Xsd::levelEnum getElementLevel () const;
            QList<XsdElement *> getElementsList () const;
            QList<FacetAbs *> getFacets () const;
            XsdElement *getParent () const;
            QList<PropertyAbs *> getProperties () const;
            PropertyAbs *getProperty ( QString property ) const;
            bool hasRestriction () const;
            bool isEnumerate () const;
            bool isSimpleType () const;
            //void setAttribute ( XsdAttribute *value );
            //void setAttributes ( const QList<XsdAttribute *> &value );
            void setElementIndicator ( const Xsd::indicatorEnum &value );
            void setElementLevel ( const Xsd::levelEnum &value );
            void setElement ( XsdElement *value );
            void setElementsList ( const QList<XsdElement *> &value );
            void setEnumerate ( bool value );
            void setFacet ( FacetAbs *value );
            void setFacets ( const QList<FacetAbs *> &value );
            void setParent ( XsdElement *value );
            void setProperties ( const QList<PropertyAbs *> &value );
            void setProperty ( PropertyAbs *property );
            void setRestriction ( bool value );
            void setSimpleType ( bool value );

          private :
            //QList<XsdAttribute *> attributes;
            Xsd::indicatorEnum elementIndicator; // DEFINITIVO // Representa la forma como seran creados, el orden y la cantidad de elementos que contendrá un elemento XML.
            QList<XsdElement *> elementsList;
            Xsd::levelEnum elementLevel; // DEFINITIVO
            bool enumerate = false; // DEFINITIVO
            QList<FacetAbs *> facets; // Son las restricciones de los tipos de los elementos.
            XsdElement *parent; // DEFINITIVO
            QList<PropertyAbs *> properties; // DEFINITIVO
            bool restriction = false; // DEFINITIVO
            bool simpleType = true; // DEFINITIVO
        };
      }
    }
  }
}

#endif // XSDELEMENT_H
