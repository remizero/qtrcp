#ifndef XSDDIALOG_H
#define XSDDIALOG_H

// Librerías Internas
#include "xsdform_global.h"
#include "XsdFormCreator.h"

// Librerías Externas
#include "AppPaths.h"
#include "Files.h"
#include "Xml.h"
#include "XsdElement.h"
#include "XsdEngine.h"
#include "core/PropertyAbs.h"
#include "core/TypeAbs.h"
#include "core/properties/NameProperty.h"
#include "core/properties/TypeProperty.h"

// Librerías Qt
#include <QComboBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>
#include <QFile>
#include <QGridLayout>
#include <QLineEdit>
#include <QObject>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace XsdForm {

        class XSDFORMSHARED_EXPORT XsdDialog : public QObject {

            Q_OBJECT

          public:
            XsdDialog ( QWidget *parent );

            QDialog *getFormDialog () const;

          public slots:
            void acceptSlot ();
            void applySlot ();

          private:
            QDialogButtonBox *buttonBox;
                QDomDocument domDocument;
                     QDialog *formDialog;
                 QVBoxLayout *formDialogLayout;
                 QGridLayout *mainLayout;
             Xsd::XsdElement *xsdElement;
              XsdFormCreator *xsdFormCreator;

            QString getNameInput ( QDomElement element );
            QWidget *getWidget ( QString objectName, QWidget *widget );
            Com::Ecosoftware::Engines::Xsd::XsdElement *getXsdElement ( QDomElement element , Com::Ecosoftware::Engines::Xsd::XsdElement *xsdElement );
            void loadData ( QDomNode element, QWidget *widget );
            QDomDocument loadXml ();
            void saveData ( QDomNode element, QWidget *widget );
        };
      }
    }
  }
}

#endif // XSDDIALOG_H
