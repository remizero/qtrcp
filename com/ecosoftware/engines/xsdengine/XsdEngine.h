#ifndef XSDENGINE_H
#define XSDENGINE_H

// Librerías Internas
#include "xsdengine_global.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace XsdEngine {

        class XSDENGINESHARED_EXPORT XsdEngine : public QObject {

            Q_OBJECT
            Q_ENUMS ( xsdLevelEnum )

          public:
            XsdEngine ();

            enum xsdLevelEnum {

              EMPTY = -1,
              ROOT,
              TAB,
              GROUP,
              PARAM,
              TYPE,
              VALUE
            };
            Q_ENUM ( xsdLevelEnum )

            enum xsdAttributesEnum {

              ABSTRACT = 0,
              ATTRIBUTEFORMDEFAULT,
              BASE,
              BLOCK,
              BLOCKDEFAULT,
              DEFAULT,
              ELEMENTFORMDEFAULT,
              FINAL,
              FINALDEFAULT,
              FIXED,
              FORM,
              ITEMTYPE,
              MEMBERTYPES,
              MAXOCCURS,
              MINOCCURS,
              MIXED,
              NAME,
              NAMESPACE,
              NONAMESPACESCHEMALOCATION,
              NILLABLE,
              PROCESSCONTENTS,
              REF,
              SCHEMALOCATION,
              SUBSTITUTIONGROUP,
              TARGETNAMESPACE,
              //TYPE,
              USE,
              //VALUE,
              NIL


              /*string
              normalizedString
              token
              base64Binary
              hexBinary
              integer
              positiveInteger
              negativeInteger
              nonNegativeInteger
              nonPositiveInteger
              long
              unsignedLong
              int
              unsignedInt
              short
              unsignedShort
              byte
              unsignedByte
              decimal
              float
              double
              boolean
              duration
              dateTime
              date
              time
              gYear
              gYearMonth
              gMonth
              gMonthDay
              gDay
              Name
              QName
              NCName
              anyURI
              language
              ID
              IDREF
              IDREFS
              ENTITY
              ENTITIES
              NOTATION
              NMTOKEN
              NMTOKENS*/
            };
            Q_ENUM ( xsdAttributesEnum )

            enum xsdElementsEnum {

              ALL = 0,
              ANNOTATION,
              ANY,
              ANYATTRIBUTE,
              APPINFO,
              ATTRIBUTE,
              ATTRIBUTEGROUP,
              CHOICE,
              COMPLEXCONTENT,
              COMPLEXTYPE,
              DOCUMENTATION,
              ELEMENT,
              ENUMERATION,
              EXTENSION,
              FIELD,
              //GROUP,
              IMPORT,
              INCLUDE,
              KEY,
              KEYREF,
              LENGTH,
              LIST,
              MAXINCLUSIVE,
              MAXLENGTH,
              MININCLUSIVE,
              MINLENGTH,
              PATTERN,
              REDEFINE,
              RESTRICTION,
              SCHEMA,
              SELECTOR,
              SEQUENCE,
              SIMPLECONTENT,
              SIMPLETYPE,
              UNION,
              UNIQUE
            };
            Q_ENUM ( xsdElementsEnum )

            enum xsdTypesEnum {


            };
            Q_ENUM ( xsdTypesEnum )

            enum xsdFacetsEnum {

              enumeration = 0,
              fractionDigits,
              length,
              maxExclusive,
              maxInclusive,
              maxLength,
              minExclusive,
              minInclusive,
              minLength,
              pattern,
              totalDigits,
              whiteSpace
            };
            Q_ENUM ( xsdFacetsEnum )



            QString xsdTypeEnumToString ( XsdEngine::xsdLevelEnum enumType );// LISTO
            int indexOfXsdTypeEnum ( QString type );// LISTO

          private:
            int indexOf ( QString type, QString enumName );// LISTO
        };
      }
    }
  }
}

#endif // XSDENGINE_H
