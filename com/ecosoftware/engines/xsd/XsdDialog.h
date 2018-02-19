#ifndef XSDDIALOG_H
#define XSDDIALOG_H

// Librerías Internas
#include "xsd_global.h"
#include "XsdFormCreator.h"

// Librerías Externas

// Librerías Qt
#include <QDialog>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QObject>
#include <QVBoxLayout>

#include <QDomDocument>
#include <QDomElement>
#include <QFile>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT XsdDialog {

          public:
            XsdDialog ( XsdElement *xsdElement, QWidget *parent );
            QDialog *getFormDialog () const;
            void cargarDatos ( QDomElement element, QObjectList objectList );

          private:
            QDialog *formDialog;
            QGridLayout *mainLayout;
        };
      }
    }
  }
}

#endif // XSDDIALOG_H
