#ifndef XSDDIALOG_H
#define XSDDIALOG_H

// Librerías Internas
// Internal Libraries
#include "xsdform_global.h"
#include "XsdFormCreator.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "ColorBox.h"

// Librerías Externas
// External Libraries
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
// Qt Libraries
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


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_COMPONENTS {

        namespace NAMESPACE_XSDFORM {

          class XSDFORMSHARED_EXPORT XsdDialog : public QObject {

              Q_OBJECT

            public :
              XsdDialog ( QWidget *parent );

              QDialog *getFormDialog () const;

            public slots :
              void acceptSlot ();
              void applySlot ();

            private :
                               QDialogButtonBox *buttonBox;
                                   QDomDocument domDocument;
                                        QDialog *formDialog;
                                    QVBoxLayout *formDialogLayout;
                                    QGridLayout *mainLayout;
              NAMESPACE_LIBRARY_XSD::XsdElement *xsdElement;
                                 XsdFormCreator *xsdFormCreator;

              QString getNameInput ( QDomElement element );
              QWidget *getWidget ( QString objectName, QWidget *widget );
              NAMESPACE_LIBRARY_XSD::XsdElement *getXsdElement ( QDomElement element , NAMESPACE_LIBRARY_XSD::XsdElement *xsdElement );
              void loadData ( QDomNode element, QWidget *widget );
              QDomDocument loadXml ();
              void saveData ( QDomNode element, QWidget *widget );
          };
        }
      }
    }
  }
}

#endif // XSDDIALOG_H
