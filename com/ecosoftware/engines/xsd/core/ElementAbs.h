#ifndef ELEMENTABS_H
#define ELEMENTABS_H

// Librerías Internas
#include "xsd_global.h"
#include "core/ElementAbs.h"
#include "core/PropertyAbs.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT ElementAbs : public QObject {

            Q_OBJECT
            Q_ENUMS ( elements )

          public:
            Q_INVOKABLE ElementAbs ();
            Q_INVOKABLE ElementAbs ( const ElementAbs& );
            Q_INVOKABLE ~ElementAbs ();

            enum elements {

              ALL = 1, //	Specifies that the child elements can appear in any order. Each child element can occur 0 or 1 time
              ALTERNATIVE,
              ANNOTATION, //	Specifies the top-level element for schema comments
              ANY, //	Enables the author to extend the XML document with elements not specified by the schema
              ANYATTRIBUTE, // Enables the author to extend the XML document with attributes not specified by the schema
              APPINFO, //	Specifies information to be used by the application (must go inside annotation)
              ASSERT,
              ATTRIBUTE, //	Defines an attribute
              ATTRIBUTEGROUP, //	Defines an attribute group to be used in complex type definitions
              CHOICE, //	Allows only one of the elements contained in the <choice> declaration to be present within the containing element
              COMPLEXCONTENT, //	Defines extensions or restrictions on a complex type that contains mixed content or elements only
              COMPLEXTYPE, //	Defines a complex type element
              DEFAULTOPENCONTENT,
              DOCUMENTATION, //	Defines text comments in a schema (must go inside annotation)
              ELEMENT, //	Defines an element
              EXTENSION, //	Extends an existing simpleType or complexType element
              FIELD, //	Specifies an XPath expression that specifies the value used to define an identity constraint
              GROUP, //	Defines a group of elements to be used in complex type definitions
              IMPORT, //	Adds multiple schemas with different target namespace to a document
              INCLUDE, //	Adds multiple schemas with the same target namespace to a document
              KEY, //	Specifies an attribute or element value as a key (unique, non-nullable, and always present) within the containing element in an instance document
              KEYREF, //	Specifies that an attribute or element value correspond to those of the specified key or unique element
              LIST, //	Defines a simple type element as a list of values
              NOTATION, //	Describes the format of non-XML data within an XML document
              OPENCONTENT,
              OVERRIDE,
              REDEFINE, //	Redefines simple and complex types, groups, and attribute groups from an external schema
              RESTRICTION, //	Defines restrictions on a simpleType, simpleContent, or a complexContent
              SCHEMA, //	Defines the root element of a schema
              SELECTOR, //	Specifies an XPath expression that selects a set of elements for an identity constraint
              SEQUENCE, //	Specifies that the child elements must appear in a sequence. Each child element can occur from 0 to any number of times
              SIMPLECONTENT, //	Contains extensions or restrictions on a text-only complex type or on a simple type as content and contains no elements
              SIMPLETYPE, //	Defines a simple type and specifies the constraints and information about the values of attributes or text-only elements
              UNION, //	Defines a simple type as a collection (union) of values from specified simple data types
              UNIQUE //	Defines that an element or an attribute value must be unique within the scope
            };
            Q_ENUM ( elements )

            Q_INVOKABLE static int indexOfEnum ( QString enumKey );
            Q_INVOKABLE static bool inEmun ( QString enumKey );
            Q_INVOKABLE static QString enumToString ( elements enumValue );
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::ElementAbs )

#endif // ELEMENTABS_H
