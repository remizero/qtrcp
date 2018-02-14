#ifndef XSDFORMCREATOR_H
#define XSDFORMCREATOR_H

// Librerías Internas
#include "xsd_global.h"
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

// Librerías Externas

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

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT XsdFormCreator {

          public:
            XsdFormCreator ();
            // TODO: Como cargar el archivo config.xml y asignar los valores al formulario.
            void createForm ( XsdElement *xsdElement, QWidget *parent );
            void createGroup ( QWidget *widget, XsdElement *xsdElement );
            void createParam ( QWidget *widget, XsdElement *xsdElement );
            void createParams ( QWidget *widget, QList<XsdElement *> xsdElementList );
            void createTab ( XsdElement *tabElement );
            void createTabs ( QList<XsdElement *> xsdElementList );
            void createType ( QWidget *widget, XsdElement *xsdElement );
            void createTypes ( QWidget *widget, QList<XsdElement *> xsdElementList );
            QTabWidget *getForm () const;

          private:
            QTabWidget *tabsDialog;
            //QDialog *formDialog;
            //QGridLayout *mainLayout;
        };
      }
    }
  }
}

#endif // XSDFORMCREATOR_H
