#ifndef XSDENGINE_H
#define XSDENGINE_H

// Librerías Internas
#include "xsd_global.h"
#include "XsdEngine.h"
#include "XsdElement.h"
#include "core/ElementAbs.h"
#include "core/FacetAbs.h"
#include "core/PropertyAbs.h"
#include "core/TypeAbs.h"
#include "core/elements/All.h"
#include "core/elements/Alternative.h"
#include "core/elements/Annotation.h"
#include "core/elements/Any.h"
#include "core/elements/AnyAttribute.h"
#include "core/elements/AppInfo.h"
#include "core/elements/Assert.h"
#include "core/elements/Attribute.h"
#include "core/elements/AttributeGroup.h"
#include "core/elements/Choice.h"
#include "core/elements/ComplexContent.h"
#include "core/elements/ComplexType.h"
#include "core/elements/DefaultOpenContent.h"
#include "core/elements/Documentation.h"
#include "core/elements/Element.h"
#include "core/elements/Extension.h"
#include "core/elements/Field.h"
#include "core/elements/Group.h"
#include "core/elements/Import.h"
#include "core/elements/Include.h"
#include "core/elements/Key.h"
#include "core/elements/Keyref.h"
#include "core/elements/List.h"
#include "core/elements/Notation.h"
#include "core/elements/Opencontent.h"
#include "core/elements/Override.h"
#include "core/elements/Redefine.h"
#include "core/elements/Restriction.h"
#include "core/elements/Schema.h"
#include "core/elements/Selector.h"
#include "core/elements/Sequence.h"
#include "core/elements/SimpleContent.h"
#include "core/elements/SimpleType.h"
#include "core/elements/Union.h"
#include "core/elements/Unique.h"
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
#include "core/properties/AbstractProperty.h"
#include "core/properties/AppliesToEmptyProperty.h"
#include "core/properties/AttributeFormDefaultProperty.h"
#include "core/properties/BaseProperty.h"
#include "core/properties/BlockDefaultProperty.h"
#include "core/properties/BlockProperty.h"
#include "core/properties/DefaultAttributesApplyProperty.h"
#include "core/properties/DefaultAttributesProperty.h"
#include "core/properties/DefaultProperty.h"
#include "core/properties/ElementFormDefaultProperty.h"
#include "core/properties/FinalDefaultProperty.h"
#include "core/properties/FinalProperty.h"
#include "core/properties/FixedProperty.h"
#include "core/properties/FormProperty.h"
#include "core/properties/IdProperty.h"
#include "core/properties/InheritableProperty.h"
#include "core/properties/ItemTypeProperty.h"
#include "core/properties/MaxOccursProperty.h"
#include "core/properties/MemberTypesProperty.h"
#include "core/properties/MinOccursProperty.h"
#include "core/properties/MixedProperty.h"
#include "core/properties/ModeProperty.h"
#include "core/properties/NameProperty.h"
#include "core/properties/NamespaceProperty.h"
#include "core/properties/NillableProperty.h"
#include "core/properties/NotNamespaceProperty.h"
#include "core/properties/NotQNameProperty.h"
#include "core/properties/ProcessContentsProperty.h"
#include "core/properties/PublicProperty.h"
#include "core/properties/ReferProperty.h"
#include "core/properties/RefProperty.h"
#include "core/properties/SchemaLocationProperty.h"
#include "core/properties/SourceProperty.h"
#include "core/properties/SubstitutionGroupProperty.h"
#include "core/properties/SystemProperty.h"
#include "core/properties/TargetNamespaceProperty.h"
#include "core/properties/TestProperty.h"
#include "core/properties/TypeProperty.h"
#include "core/properties/UseProperty.h"
#include "core/properties/VersionProperty.h"
#include "core/properties/XmlLangProperty.h"
#include "core/properties/XPathDefaultNamespaceProperty.h"
#include "core/properties/XPathProperty.h"
#include "core/types/AnyUriType.h"
#include "core/types/Base64BinaryType.h"
#include "core/types/BooleanType.h"
#include "core/types/ByteType.h"
#include "core/types/DateTimeStampType.h"
#include "core/types/DateTimeType.h"
#include "core/types/DateType.h"
#include "core/types/DayTimeDurationType.h"
#include "core/types/DecimalType.h"
#include "core/types/DoubleType.h"
#include "core/types/DurationType.h"
#include "core/types/EntitiesType.h"
#include "core/types/EntityType.h"
#include "core/types/FloatType.h"
#include "core/types/GDayType.h"
#include "core/types/GMonthDayType.h"
#include "core/types/GMonthType.h"
#include "core/types/GYearMonthType.h"
#include "core/types/GYearType.h"
#include "core/types/HexBinaryType.h"
#include "core/types/IdRefsType.h"
#include "core/types/IdRefType.h"
#include "core/types/IdType.h"
#include "core/types/IntegerType.h"
#include "core/types/IntType.h"
#include "core/types/LanguageType.h"
#include "core/types/LongType.h"
#include "core/types/NameType.h"
#include "core/types/NCNameType.h"
#include "core/types/NegativeIntegerType.h"
#include "core/types/NMTokensType.h"
#include "core/types/NMTokenType.h"
#include "core/types/NonNegativeIntegerType.h"
#include "core/types/NonPositiveIntegerType.h"
#include "core/types/NormalizedStringType.h"
#include "core/types/NotationType.h"
#include "core/types/PositiveIntegerType.h"
#include "core/types/QNameType.h"
#include "core/types/ShortType.h"
#include "core/types/StringType.h"
#include "core/types/TimeType.h"
#include "core/types/TokenType.h"
#include "core/types/UnsignedByteType.h"
#include "core/types/UnsignedIntType.h"
#include "core/types/UnsignedLongType.h"
#include "core/types/UnsignedShortType.h"
#include "core/types/YearMonthDurationType.h"

// Librerías Externas
#include "Strings.h"
#include "Utils.h"

// Librerías Qt
#include <QByteArrayView>
#include <QDialog>
#include <QDirIterator>
#include <QDomDocument>
#include <QDomElement>
#include <QFile>
#include <QFileInfo>
#include <QList>
#include <QListIterator>
#include <QMetaType>
#include <QObject>
#include <QUrl>
#include <QXmlStreamReader>
///#include <QXmlSchema>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT XsdEngine : public QObject {

            Q_OBJECT

          public :
            XsdEngine ();

            XsdElement *getXsdElementModel () const;
            void load ( QString xsdFile );
            void parse ();
            void parse ( QDomElement docElement, XsdElement *xsdElement = nullptr, QString nodeName = "" );
            void registerTypes ();
            QDomDocument *toDomDocument ();
            QString toString ();
            QString toXml ();
            void listarElementos ( XsdElement *XsdElement = nullptr );

          private :
            ElementAbs::elements currentElement;
            QDomDocument *doc;
            //XsdFormCreator *formDialog;
            //XsdFormElement *xsdFormElementModel;
            XsdElement *xsdElementModel;

            void defineElementLevel ( XsdElement *xsdElement ); // LISTO
            QMetaObject getMetaObject ( QString className );
            QMetaObject getMetaObjectElements ( QString className );
            QMetaObject getMetaObjectFacets ( QString className );
            QMetaObject getMetaObjectProperties ( QString className );
            QMetaObject getMetaObjectTypes ( QString className );
            bool isElementToFind ( QDomElement docElement, QString nodeName );
            void processElement ( QDomElement docElement, XsdElement *xsdElement );
            void processProperties ( QDomElement docElement, XsdElement *xsdElement );
            void parseAttribute ( QDomNamedNodeMap nodeMap, XsdElement *xsdElement );
            void parseFacets ( QDomElement docElement, XsdElement *xsdElement );
        };
      }
    }
  }
}

#endif // XSDENGINE_H
