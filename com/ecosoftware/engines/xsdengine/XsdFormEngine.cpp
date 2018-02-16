#include "XsdFormEngine.h"
#include <QDebug>

using namespace Com::Ecosoftware::Engines::XsdEngine;

XsdFormEngine::XsdFormEngine () {}

XsdFormElement *XsdFormEngine::getXsdFormElementModel () const {

  return this->xsdFormElementModel;
}

void XsdFormEngine::loadXsd ( QString xsdFile ) {

  QFile file ( xsdFile );
  if ( file.open ( QIODevice::ReadOnly ) ) {

    QXmlSchema schema;
    schema.load ( &file, QUrl::fromLocalFile ( file.fileName () ) );
    if ( schema.isValid () ) {

      this->doc = new QDomDocument ( "xsdDocument" );
      this->xsdFormElementModel = new XsdFormElement ();
      this->xsdFormElementModel->setFormElementType ( XsdEngine::ROOT );
      QFile auxFile ( xsdFile );
      if ( !this->doc->setContent ( &auxFile ) ) {

        file.close ();
        auxFile.close ();
        return;
      }
    } else {

      file.close ();
      return;
    }
  } else {

    return;
  }
  file.close ();
}

void XsdFormEngine::parseXsd () {

  this->parseXsd ( this->doc->documentElement ().firstChildElement (), this->xsdFormElementModel, "settings" );
  //this->parseXsd ( this->doc->documentElement ().firstChildElement (), "settings" );
  //this->parseXsd ( this->doc->documentElement ().firstChildElement (), "settings", this->xsdElementModel );
}

void XsdFormEngine::parseXsd ( QDomElement docElement, XsdFormElement *xsdFormElement, QString rootNodeName ) {

  // TODO: Terminar de definir todos los elementos que componen un archivo XSD.
  if ( !docElement.isNull () ) {

    if ( docElement.nodeName ().compare ( "xs:all" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:all";

    } else if ( docElement.nodeName ().compare ( "xs:annotation" ) == 0 ) {

      qDebug () << "Es un elemento tipo xs:annotation";
      this->parseXsd ( docElement.firstChildElement (), xsdFormElement, rootNodeName );

    } else if ( docElement.nodeName ().compare ( "xs:any" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:any";

    } else if ( docElement.nodeName ().compare ( "xs:anyAttribute" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:anyAttribute";

    } else if ( docElement.nodeName ().compare ( "xs:appInfo" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:appInfo";

    } else if ( docElement.nodeName ().compare ( "xs:attribute" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:attribute";

    } else if ( docElement.nodeName ().compare ( "xs:attributeGroup" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:attributeGroup";

    } else if ( docElement.nodeName ().compare ( "xs:choice" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:choice";

    } else if ( docElement.nodeName ().compare ( "xs:complexContent" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:complexContent";

    } else if ( docElement.nodeName ().compare ( "xs:complexType" ) == 0 ) {

      this->parseXsd ( docElement.firstChildElement (), xsdFormElement, rootNodeName );

    } else if ( docElement.nodeName ().compare ( "xs:documentation" ) == 0 ) {

      qDebug () << "Es un elemento tipo xs:documentation";
      xsdFormElement->setElementComment ( docElement.nodeValue () );

    } else if ( docElement.nodeName ().compare ( "xs:element" ) == 0 ) {

      if ( docElement.hasAttribute ( "name" ) ) {

        if ( ( docElement.attribute ( "name" ).compare ( rootNodeName ) == 0 ) ) {

          xsdFormElement->setElementName ( docElement.attribute ( "name" ) );
          if ( xsdFormElement->getParent () != nullptr ) {

            if ( xsdFormElement->getParent ()->getFormElementType () == XsdEngine::ROOT ) {

              xsdFormElement->setFormElementType ( XsdEngine::TAB );

            } else if ( xsdFormElement->getParent ()->getFormElementType () == XsdEngine::TAB ) {

              xsdFormElement->setFormElementType ( XsdEngine::PARAM );

            } else if ( xsdFormElement->getParent ()->getFormElementType () == XsdEngine::PARAM ) {

              xsdFormElement->getParent ()->setFormElementType ( XsdEngine::GROUP );
              xsdFormElement->setFormElementType ( XsdEngine::PARAM );
            }
            xsdFormElement->getParent ()->setElementList ( xsdFormElement );
          }
          if ( docElement.hasChildNodes () ) {

            this->parseXsd ( docElement.firstChildElement (), xsdFormElement, rootNodeName );

          } else if ( docElement.hasAttribute ( "type" ) ) {

            xsdFormElement->setElementType ( docElement.attribute ( "type" ) );
          }
        } else {

          this->parseXsd ( docElement.nextSiblingElement (), xsdFormElement, rootNodeName );
        }
      } else if ( docElement.hasAttribute ( "ref" ) ) {

        this->parseXsd ( this->doc->documentElement ().firstChildElement (), new XsdFormElement ( xsdFormElement ), docElement.attribute ( "ref" ) );
        this->parseXsd ( docElement.nextSiblingElement (), xsdFormElement, rootNodeName );
      }
    } else if ( docElement.nodeName ().compare ( "xs:enumeration" ) == 0 ) {

      if ( docElement.hasAttribute ( "value" ) ) {

        XsdFormElement *xsdFormElementChild = new XsdFormElement ( xsdFormElement );
        xsdFormElementChild->setElementName ( "value" );
        xsdFormElementChild->setFormElementType ( XsdEngine::VALUE );
        xsdFormElementChild->setElementType ( docElement.nodeName () );
        xsdFormElementChild->setElementValue ( docElement.attribute ( "value" ) );
        xsdFormElement->setElementList ( xsdFormElementChild );
        this->parseXsd ( docElement.nextSiblingElement (), xsdFormElement, rootNodeName );
      }
    } else if ( docElement.nodeName ().compare ( "xs:extension" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:extension";

    } else if ( docElement.nodeName ().compare ( "xs:field" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:field";

    } else if ( docElement.nodeName ().compare ( "xs:group" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:group";

    } else if ( docElement.nodeName ().compare ( "xs:import" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:import";

    } else if ( docElement.nodeName ().compare ( "xs:include" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:include";

    } else if ( docElement.nodeName ().compare ( "xs:key" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:key";

    } else if ( docElement.nodeName ().compare ( "xs:keyref" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:keyref";

    } else if ( docElement.nodeName ().compare ( "xs:list" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:list";

    } else if ( docElement.nodeName ().compare ( "xs:maxExclusive" ) == 0 ) {

      if ( docElement.hasAttribute ( "value" ) ) {

        XsdFormElement *xsdFormElementChild = new XsdFormElement ( xsdFormElement );
        xsdFormElementChild->setElementName ( "value" );
        xsdFormElementChild->setFormElementType ( XsdEngine::VALUE );
        xsdFormElementChild->setElementType ( docElement.nodeName () );
        xsdFormElementChild->setElementValue ( docElement.attribute ( "value" ) );
        xsdFormElement->setElementList ( xsdFormElementChild );
        this->parseXsd ( docElement.nextSiblingElement (), xsdFormElement, rootNodeName );
      }
    } else if ( docElement.nodeName ().compare ( "xs:maxInclusive" ) == 0 ) {

      if ( docElement.hasAttribute ( "value" ) ) {

        XsdFormElement *xsdFormElementChild = new XsdFormElement ( xsdFormElement );
        xsdFormElementChild->setElementName ( "value" );
        xsdFormElementChild->setFormElementType ( XsdEngine::VALUE );
        xsdFormElementChild->setElementType ( docElement.nodeName () );
        xsdFormElementChild->setElementValue ( docElement.attribute ( "value" ) );
        xsdFormElement->setElementList ( xsdFormElementChild );
        this->parseXsd ( docElement.nextSiblingElement (), xsdFormElement, rootNodeName );
      }
    } else if ( docElement.nodeName ().compare ( "xs:minExclusive" ) == 0 ) {

      if ( docElement.hasAttribute ( "value" ) ) {

        XsdFormElement *xsdFormElementChild = new XsdFormElement ( xsdFormElement );
        xsdFormElementChild->setElementName ( "value" );
        xsdFormElementChild->setFormElementType ( XsdEngine::VALUE );
        xsdFormElementChild->setElementType ( docElement.nodeName () );
        xsdFormElementChild->setElementValue ( docElement.attribute ( "value" ) );
        xsdFormElement->setElementList ( xsdFormElementChild );
        this->parseXsd ( docElement.nextSiblingElement (), xsdFormElement, rootNodeName );
      }
    } else if ( docElement.nodeName ().compare ( "xs:minInclusive" ) == 0 ) {

      if ( docElement.hasAttribute ( "value" ) ) {

        XsdFormElement *xsdFormElementChild = new XsdFormElement ( xsdFormElement );
        xsdFormElementChild->setElementName ( "value" );
        xsdFormElementChild->setFormElementType ( XsdEngine::VALUE );
        xsdFormElementChild->setElementType ( docElement.nodeName () );
        xsdFormElement->setElementList ( xsdFormElementChild );
        this->parseXsd ( docElement.nextSiblingElement (), xsdFormElement, rootNodeName );
      }
    } else if ( docElement.nodeName ().compare ( "xs:redefine" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:redefine";

    } else if ( docElement.nodeName ().compare ( "xs:restriction" ) == 0 ) {

      xsdFormElement->setElementType ( docElement.attribute ( "base" ) );
      this->parseXsd ( docElement.firstChildElement (), xsdFormElement, rootNodeName );

    } else if ( docElement.nodeName ().compare ( "xs:schema" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:schema";

    } else if ( docElement.nodeName ().compare ( "xs:selector" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:selector";

    } else if ( docElement.nodeName ().compare ( "xs:sequence" ) == 0 ) {

      this->parseXsd ( docElement.firstChildElement (), xsdFormElement, rootNodeName );

    } else if ( docElement.nodeName ().compare ( "xs:simpleContent" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:simpleContent";

    } else if ( docElement.nodeName ().compare ( "xs:simpleType" ) == 0 ) {

      this->parseXsd ( docElement.firstChildElement (), xsdFormElement, rootNodeName );

    } else if ( docElement.nodeName ().compare ( "xs:union" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:union";

    } else if ( docElement.nodeName ().compare ( "xs:unique" ) == 0 ) {

      //qDebug () << "Es un elemento tipo xs:unique";

    }/* else if ( docElement.nodeName ().compare ( "xs:" ) == 0 ) {

      qDebug () << "Es un elemento tipo xs:element";

    } else if ( docElement.nodeName ().compare ( "xs:" ) == 0 ) {

      qDebug () << "Es un elemento tipo xs:element";

    } else if ( docElement.nodeName ().compare ( "xs:" ) == 0 ) {

      qDebug () << "Es un elemento tipo xs:element";

    } else if ( docElement.nodeName ().compare ( "xs:" ) == 0 ) {

      qDebug () << "Es un elemento tipo xs:element";

    } else if ( docElement.nodeName ().compare ( "xs:" ) == 0 ) {

      qDebug () << "Es un elemento tipo xs:element";

    } else if ( docElement.nodeName ().compare ( "xs:" ) == 0 ) {

      qDebug () << "Es un elemento tipo xs:element";

    } else if ( docElement.nodeName ().compare ( "xs:" ) == 0 ) {

      qDebug () << "Es un elemento tipo xs:element";

    } else if ( docElement.nodeName ().compare ( "xs:" ) == 0 ) {

      qDebug () << "Es un elemento tipo xs:element";

    } else if ( docElement.nodeName ().compare ( "xs:" ) == 0 ) {

      qDebug () << "Es un elemento tipo xs:element";

    } else if ( docElement.nodeName ().compare ( "xs:" ) == 0 ) {

      qDebug () << "Es un elemento tipo xs:element";

    } else if ( docElement.nodeName ().compare ( "xs:" ) == 0 ) {

      qDebug () << "Es un elemento tipo xs:element";

    } else if ( docElement.nodeName ().compare ( "xs:" ) == 0 ) {

      qDebug () << "Es un elemento tipo xs:element";

    } else if ( docElement.nodeName ().compare ( "xs:" ) == 0 ) {

      qDebug () << "Es un elemento tipo xs:element";

    } else if ( docElement.nodeName ().compare ( "xs:" ) == 0 ) {

      qDebug () << "Es un elemento tipo xs:element";

    } else if ( docElement.nodeName ().compare ( "xs:" ) == 0 ) {

      qDebug () << "Es un elemento tipo xs:element";

    } else if ( docElement.nodeName ().compare ( "xs:" ) == 0 ) {

      qDebug () << "Es un elemento tipo xs:element";

    }*/
  }
}

void XsdFormEngine::parseXsd ( QDomElement docElement, QString rootNodeName, Element *xsdElement ) {

  if ( docElement.nodeName ().compare ( "xs:element" ) == 0 ) {

    if ( docElement.hasAttributes () ) {

      if ( docElement.hasAttribute ( "name" ) ) {

        if ( docElement.attribute ( "name" ).compare ( rootNodeName ) == 0 ) {

          Element *element = new Element ();
          element->setName ( docElement.attribute ( "name" ) );
          // TODO: Que más hacer en este punto.

        } else {

          // TODO: Que hacer si el atributo name no es igual al nombre del nodo indicado.
        }
      } else {

        // TODO: Que hacer si no tiene atributo name.
      }
    } else {

      // TODO: Que hacer si no tiene atributos.
    }
  }
}

QDomDocument *XsdFormEngine::toDomDocument () {

  return this->doc;
}

QWidget *XsdFormEngine::toForm () {

  // TODO: Como devolver solamente el formulario.
  return new QWidget ();
}

QDialog *XsdFormEngine::toFormDialog () {

  // TODO: Como devolver la ventana de dialogo generada.
  return new QDialog ();
}

QString XsdFormEngine::toString () {

  return this->doc->toString ();
}

QString XsdFormEngine::toXml () {

  // TODO: Que diferencia hay con el método toString?.
  return this->doc->toString ();
}
