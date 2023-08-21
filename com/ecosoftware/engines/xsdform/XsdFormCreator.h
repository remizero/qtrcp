#ifndef XSDFORMCREATOR_H
#define XSDFORMCREATOR_H

// Librerías Internas
#include "xsdform_global.h"

// Librerías Externas
#include "macros_global.h"

// Librerías Externas
#include "XsdElement.h"
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

// Librerías Qt
#include <QComboBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QObject>
#include <QScrollArea>
#include <QSpinBox>
#include <QTabWidget>
#include <QVBoxLayout>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_ENGINES {

      namespace NAMESPACE_XSDFORM {

        class XSDFORMSHARED_EXPORT XsdFormCreator {

          public :
            XsdFormCreator ();

            void createForm ( Com::Vgvgs::Engines::Xsd::XsdElement *xsdElement, QWidget *parent );
            QTabWidget *getForm () const;

          private :
            QTabWidget *tabsDialog;

            void createGroup ( QWidget *widget, Com::Vgvgs::Engines::Xsd::XsdElement *xsdElement );
            void createHexbinaryInput ( QWidget *widget, Com::Vgvgs::Engines::Xsd::XsdElement *xsdElement );
            void createInputType ( QWidget *widget, Com::Vgvgs::Engines::Xsd::XsdElement *xsdElement );
            void createIntegerInput ( QWidget *widget, Com::Vgvgs::Engines::Xsd::XsdElement *xsdElement );
            void createParam ( QWidget *widget, Com::Vgvgs::Engines::Xsd::XsdElement *xsdElement );
            void createParams ( QWidget *widget, QList<Com::Vgvgs::Engines::Xsd::XsdElement *> xsdElementList );
            void createStringInput ( QWidget *widget, Com::Vgvgs::Engines::Xsd::XsdElement *xsdElement );
            void createTab ( Com::Vgvgs::Engines::Xsd::XsdElement *tabElement );
            void createTabs ( QList<Com::Vgvgs::Engines::Xsd::XsdElement *> xsdElementList );
            QString getNameInput ( Com::Vgvgs::Engines::Xsd::XsdElement *xsdElement );
        };
      }
    }
  }
}

#endif // XSDFORMCREATOR_H
