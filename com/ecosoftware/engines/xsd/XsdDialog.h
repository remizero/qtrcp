#ifndef XSDDIALOG_H
#define XSDDIALOG_H

// Librerías Internas
#include "xsd_global.h"
#include "XsdElement.h"
#include "XsdFormCreator.h"
#include "core/PropertyAbs.h"
#include "core/TypeAbs.h"
#include "core/properties/NameProperty.h"
#include "core/properties/TypeProperty.h"

// Librerías Externas

// Librerías Qt
#include <QDialog>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QObject>
#include <QVBoxLayout>

#include <QComboBox>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>
#include <QFile>
#include <QLineEdit>
#include <QSpinBox>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT XsdDialog {

          public:
            XsdDialog ( XsdElement *xsdElement, QWidget *parent );
            QDialog *getFormDialog () const;
            QWidget *getWidget ( QString objectName, QWidget *widget );
            void cargarDatos ( QDomNode element, QWidget *widget );
            QString getNameInput ( QDomElement element );
            XsdElement *getXsdElement ( QDomElement element , XsdElement *xsdElement );

          private:
            QDialog *formDialog;
            QGridLayout *mainLayout;
            XsdElement *xsdElement;
        };
      }
    }
  }
}

#endif // XSDDIALOG_H
