#ifndef XSDFORMCREATOR_H
#define XSDFORMCREATOR_H

// Librerías Internas
#include "xsdengine_global.h"
#include "XsdEngine.h"
#include "XsdFormElement.h"

// Librerías Externas

// Librerías Qt
#include <QComboBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QList>
#include <QObject>
#include <QPushButton>
#include <QScrollArea>
#include <QSpinBox>
#include <QTabWidget>
#include <QVBoxLayout>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace XsdEngine {

        class XSDENGINESHARED_EXPORT XsdFormCreator : public QObject {

            Q_OBJECT

          public:
            explicit XsdFormCreator ();
            // TODO: Como cargar el archivo config.xml y asignar los valores al formulario.
            void createForm ( XsdFormElement *xsdFormElement, QWidget *parent );
            void createGroup ( QWidget *widget, XsdFormElement *xsdFormElement );
            void createParam ( QWidget *widget, XsdFormElement *xsdFormElement );
            void createParams ( QWidget *widget, QList<XsdFormElement *> xsdFormElementList );
            void createTab ( XsdFormElement *tabElement );
            void createTabs ( QList<XsdFormElement *> xsdFormElementList );
            void createType ( QWidget *widget, XsdFormElement *xsdFormElement );
            void createTypes ( QWidget *widget, QList<XsdFormElement *> xsdFormElementList );
            void showForm ();

          private:
            QTabWidget *tabsDialog;
            QDialog *formDialog;
            QGridLayout *mainLayout;
        };
      }
    }
  }
}

#endif // XSDFORMCREATOR_H
