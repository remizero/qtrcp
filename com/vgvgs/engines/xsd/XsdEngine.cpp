#include "XsdEngine.h"
#include <QDebug>


using namespace NAMESPACE_LIBRARY_XSD;

XsdEngine::XsdEngine () {

  this->registerTypes ();
}

void XsdEngine::defineElementLevel ( XsdElement *xsdElement ) {

  if ( xsdElement->getParent () != nullptr ) {

    if ( xsdElement->getParent ()->getElementLevel () == Xsd::levelEnum::ROOTFORM ) {

      xsdElement->setElementLevel ( Xsd::levelEnum::TABFORM );

    } else if ( xsdElement->getParent ()->getElementLevel () == Xsd::levelEnum::TABFORM ) {

      xsdElement->setElementLevel ( Xsd::levelEnum::PARAMFORM );

    } else if ( xsdElement->getParent ()->getElementLevel () == Xsd::levelEnum::PARAMFORM ) {

      xsdElement->getParent ()->setElementLevel ( Xsd::levelEnum::GROUPFORM );
      xsdElement->setElementLevel ( Xsd::levelEnum::PARAMFORM );
    }
  }
}

QMetaObject XsdEngine::getMetaObject ( QString className ) {

  QMetaObject metaObject;

  metaObject = this->getMetaObjectElements ( className );
  if ( QString::fromLatin1 ( metaObject.className () ).isEmpty () ) {

    metaObject = this->getMetaObjectFacets ( className.append ( "Facets" ) );
    if ( QString::fromLatin1 ( metaObject.className () ).isEmpty () ) {

      metaObject = this->getMetaObjectProperties ( className.append ( "Properties" ) );
      if ( QString::fromLatin1 ( metaObject.className () ).isEmpty () ) {

        metaObject = this->getMetaObjectTypes ( className.append ( "Types" ) );
      }
    }
  }
  return metaObject;
}

QMetaObject XsdEngine::getMetaObjectElements ( QString className ) {

  QMetaObject metaObject;
  if ( className.compare ( "All" ) == 0 ) {

    metaObject = All::staticMetaObject;

  } else if ( className.compare ( "Alternative" ) == 0 ) {

    metaObject = Alternative::staticMetaObject;

  } else if ( className.compare ( "Annotation" ) == 0 ) {

    metaObject = Annotation::staticMetaObject;

  } else if ( className.compare ( "Any" ) == 0 ) {

    metaObject = Any::staticMetaObject;

  } else if ( className.compare ( "AnyAttribute" ) == 0 ) {

    metaObject = AnyAttribute::staticMetaObject;

  } else if ( className.compare ( "AppInfo" ) == 0 ) {

    metaObject = AppInfo::staticMetaObject;

  } else if ( className.compare ( "Assert" ) == 0 ) {

    metaObject = Assert::staticMetaObject;

  } else if ( className.compare ( "Attribute" ) == 0 ) {

    metaObject = Attribute::staticMetaObject;

  } else if ( className.compare ( "AttributeGroup" ) == 0 ) {

    metaObject = AttributeGroup::staticMetaObject;

  } else if ( className.compare ( "Choice" ) == 0 ) {

    metaObject = Choice::staticMetaObject;

  } else if ( className.compare ( "ComplexContent" ) == 0 ) {

    metaObject = ComplexContent::staticMetaObject;

  } else if ( className.compare ( "ComplexType" ) == 0 ) {

    metaObject = ComplexType::staticMetaObject;

  } else if ( className.compare ( "DefaultOpenContent" ) == 0 ) {

    metaObject = DefaultOpenContent::staticMetaObject;

  } else if ( className.compare ( "Documentation" ) == 0 ) {

    metaObject = Documentation::staticMetaObject;

  } else if ( className.compare ( "Element" ) == 0 ) {

    metaObject = Element::staticMetaObject;

  } else if ( className.compare ( "Extension" ) == 0 ) {

    metaObject = Extension::staticMetaObject;

  } else if ( className.compare ( "Field" ) == 0 ) {

    metaObject = Field::staticMetaObject;

  } else if ( className.compare ( "Group" ) == 0 ) {

    metaObject = Group::staticMetaObject;

  } else if ( className.compare ( "Import" ) == 0 ) {

    metaObject = Import::staticMetaObject;

  } else if ( className.compare ( "Include" ) == 0 ) {

    metaObject = Include::staticMetaObject;

  } else if ( className.compare ( "Key" ) == 0 ) {

    metaObject = Key::staticMetaObject;

  } else if ( className.compare ( "Keyref" ) == 0 ) {

    metaObject = Keyref::staticMetaObject;

  } else if ( className.compare ( "List" ) == 0 ) {

    metaObject = List::staticMetaObject;

  } else if ( className.compare ( "Notation" ) == 0 ) {

    metaObject = Notation::staticMetaObject;

  } else if ( className.compare ( "Opencontent" ) == 0 ) {

    metaObject = Opencontent::staticMetaObject;

  } else if ( className.compare ( "Override" ) == 0 ) {

    metaObject = Override::staticMetaObject;

  } else if ( className.compare ( "Redefine" ) == 0 ) {

    metaObject = Redefine::staticMetaObject;

  } else if ( className.compare ( "Restriction" ) == 0 ) {

    metaObject = Restriction::staticMetaObject;

  } else if ( className.compare ( "Schema" ) == 0 ) {

    metaObject = Schema::staticMetaObject;

  } else if ( className.compare ( "Selector" ) == 0 ) {

    metaObject = Selector::staticMetaObject;

  } else if ( className.compare ( "Sequence" ) == 0 ) {

    metaObject = Sequence::staticMetaObject;

  } else if ( className.compare ( "SimpleContent" ) == 0 ) {

    metaObject = SimpleContent::staticMetaObject;

  } else if ( className.compare ( "SimpleType" ) == 0 ) {

    metaObject = SimpleType::staticMetaObject;

  } else if ( className.compare ( "Union" ) == 0 ) {

    metaObject = Union::staticMetaObject;

  } else if ( className.compare ( "Unique" ) == 0 ) {

    metaObject = Unique::staticMetaObject;
  }
  return metaObject;
}

QMetaObject XsdEngine::getMetaObjectFacets ( QString className ) {

  QMetaObject metaObject;
  if ( className.compare ( "AssertionsFacet" ) == 0 ) {

    metaObject = AssertionsFacet::staticMetaObject;

  } else if ( className.compare ( "EnumerationFacet" ) == 0 ) {

    metaObject = EnumerationFacet::staticMetaObject;

  } else if ( className.compare ( "ExplicitTimeZoneFacet" ) == 0 ) {

    metaObject = ExplicitTimeZoneFacet::staticMetaObject;

  } else if ( className.compare ( "FractionDigitsFacet" ) == 0 ) {

    metaObject = FractionDigitsFacet::staticMetaObject;

  } else if ( className.compare ( "LengthFacet" ) == 0 ) {

    metaObject = LengthFacet::staticMetaObject;

  } else if ( className.compare ( "MaxExclusiveFacet" ) == 0 ) {

    metaObject = MaxExclusiveFacet::staticMetaObject;

  } else if ( className.compare ( "MaxInclusiveFacet" ) == 0 ) {

    metaObject = MaxInclusiveFacet::staticMetaObject;

  } else if ( className.compare ( "MaxLengthFacet" ) == 0 ) {

    metaObject = MaxLengthFacet::staticMetaObject;

  } else if ( className.compare ( "MinExclusiveFacet" ) == 0 ) {

    metaObject = MinExclusiveFacet::staticMetaObject;

  } else if ( className.compare ( "MinInclusiveFacet" ) == 0 ) {

    metaObject = MinInclusiveFacet::staticMetaObject;

  } else if ( className.compare ( "MinLengthFacet" ) == 0 ) {

    metaObject = MinLengthFacet::staticMetaObject;

  } else if ( className.compare ( "PatternFacet" ) == 0 ) {

    metaObject = PatternFacet::staticMetaObject;

  } else if ( className.compare ( "TotalDigitsFacet" ) == 0 ) {

    metaObject = TotalDigitsFacet::staticMetaObject;

  } else if ( className.compare ( "WhitespaceFacet" ) == 0 ) {

    metaObject = WhitespaceFacet::staticMetaObject;
  }
  return metaObject;
}

QMetaObject XsdEngine::getMetaObjectProperties ( QString className ) {

  QMetaObject metaObject;
  if ( className.compare ( "AbstractProperty" ) == 0 ) {

    metaObject = AbstractProperty::staticMetaObject;

  } else if ( className.compare ( "AppliesToEmptyProperty" ) == 0 ) {

    metaObject = AppliesToEmptyProperty::staticMetaObject;

  } else if ( className.compare ( "AttributeFormDefaultProperty" ) == 0 ) {

    metaObject = AttributeFormDefaultProperty::staticMetaObject;

  } else if ( className.compare ( "BaseProperty" ) == 0 ) {

    metaObject = BaseProperty::staticMetaObject;

  } else if ( className.compare ( "BlockDefaultProperty" ) == 0 ) {

    metaObject = BlockDefaultProperty::staticMetaObject;

  } else if ( className.compare ( "BlockProperty" ) == 0 ) {

    metaObject = BlockProperty::staticMetaObject;

  } else if ( className.compare ( "DefaultAttributesApplyProperty" ) == 0 ) {

    metaObject = DefaultAttributesApplyProperty::staticMetaObject;

  } else if ( className.compare ( "DefaultAttributesProperty" ) == 0 ) {

    metaObject = DefaultAttributesProperty::staticMetaObject;

  } else if ( className.compare ( "ElementFormDefaultProperty" ) == 0 ) {

    metaObject = ElementFormDefaultProperty::staticMetaObject;

  } else if ( className.compare ( "FinalDefaultProperty" ) == 0 ) {

    metaObject = FinalDefaultProperty::staticMetaObject;

  } else if ( className.compare ( "FinalProperty" ) == 0 ) {

    metaObject = FinalProperty::staticMetaObject;

  } else if ( className.compare ( "FixedProperty" ) == 0 ) {

    metaObject = FixedProperty::staticMetaObject;

  } else if ( className.compare ( "FormProperty" ) == 0 ) {

    metaObject = FormProperty::staticMetaObject;

  } else if ( className.compare ( "IdProperty" ) == 0 ) {

    metaObject = IdProperty::staticMetaObject;

  } else if ( className.compare ( "InheritableProperty" ) == 0 ) {

    metaObject = InheritableProperty::staticMetaObject;

  } else if ( className.compare ( "ItemTypeProperty" ) == 0 ) {

    metaObject = ItemTypeProperty::staticMetaObject;

  } else if ( className.compare ( "MaxOccursProperty" ) == 0 ) {

    metaObject = MaxOccursProperty::staticMetaObject;

  } else if ( className.compare ( "MemberTypesProperty" ) == 0 ) {

    metaObject = MemberTypesProperty::staticMetaObject;

  } else if ( className.compare ( "MinOccursProperty" ) == 0 ) {

    metaObject = MinOccursProperty::staticMetaObject;

  } else if ( className.compare ( "MixedProperty" ) == 0 ) {

    metaObject = MixedProperty::staticMetaObject;

  } else if ( className.compare ( "ModeProperty" ) == 0 ) {

    metaObject = ModeProperty::staticMetaObject;

  } else if ( className.compare ( "NameProperty" ) == 0 ) {

    metaObject = NameProperty::staticMetaObject;

  } else if ( className.compare ( "NamespaceProperty" ) == 0 ) {

    metaObject = NamespaceProperty::staticMetaObject;

  } else if ( className.compare ( "NillableProperty" ) == 0 ) {

    metaObject = NillableProperty::staticMetaObject;

  } else if ( className.compare ( "NotNamespaceProperty" ) == 0 ) {

    metaObject = NotNamespaceProperty::staticMetaObject;

  } else if ( className.compare ( "NotQNameProperty" ) == 0 ) {

    metaObject = NotQNameProperty::staticMetaObject;

  } else if ( className.compare ( "ProcessContentsProperty" ) == 0 ) {

    metaObject = ProcessContentsProperty::staticMetaObject;

  } else if ( className.compare ( "PublicProperty" ) == 0 ) {

    metaObject = PublicProperty::staticMetaObject;

  } else if ( className.compare ( "ReferProperty" ) == 0 ) {

    metaObject = ReferProperty::staticMetaObject;

  } else if ( className.compare ( "RefProperty" ) == 0 ) {

    metaObject = RefProperty::staticMetaObject;

  } else if ( className.compare ( "SchemaLocationProperty" ) == 0 ) {

    metaObject = SchemaLocationProperty::staticMetaObject;

  } else if ( className.compare ( "SourceProperty" ) == 0 ) {

    metaObject = SourceProperty::staticMetaObject;

  } else if ( className.compare ( "SubstitutionGroupProperty" ) == 0 ) {

    metaObject = SubstitutionGroupProperty::staticMetaObject;

  } else if ( className.compare ( "SystemProperty" ) == 0 ) {

    metaObject = SystemProperty::staticMetaObject;

  } else if ( className.compare ( "TargetNamespaceProperty" ) == 0 ) {

    metaObject = TargetNamespaceProperty::staticMetaObject;

  } else if ( className.compare ( "TestProperty" ) == 0 ) {

    metaObject = TestProperty::staticMetaObject;

  } else if ( className.compare ( "TypeProperty" ) == 0 ) {

    metaObject = TypeProperty::staticMetaObject;

  } else if ( className.compare ( "UseProperty" ) == 0 ) {

    metaObject = UseProperty::staticMetaObject;

  } else if ( className.compare ( "VersionProperty" ) == 0 ) {

    metaObject = VersionProperty::staticMetaObject;

  } else if ( className.compare ( "XmlLangProperty" ) == 0 ) {

    metaObject = XmlLangProperty::staticMetaObject;

  } else if ( className.compare ( "XPathDefaultNamespaceProperty" ) == 0 ) {

    metaObject = XPathDefaultNamespaceProperty::staticMetaObject;

  } else if ( className.compare ( "XPathProperty" ) == 0 ) {

    metaObject = XPathProperty::staticMetaObject;
  }
  return metaObject;
}

QMetaObject XsdEngine::getMetaObjectTypes ( QString className ) {

  QMetaObject metaObject;
  if ( className.compare ( "AnyUriType" ) == 0 ) {

    metaObject = AnyUriType::staticMetaObject;

  } else if ( className.compare ( "Base64BinaryType" ) == 0 ) {

    metaObject = Base64BinaryType::staticMetaObject;

  } else if ( className.compare ( "BooleanType" ) == 0 ) {

    metaObject = BooleanType::staticMetaObject;

  } else if ( className.compare ( "ByteType" ) == 0 ) {

    metaObject = ByteType::staticMetaObject;

  } else if ( className.compare ( "DateTimeStampType" ) == 0 ) {

    metaObject = DateTimeStampType::staticMetaObject;

  } else if ( className.compare ( "DateTimeType" ) == 0 ) {

    metaObject = DateTimeType::staticMetaObject;

  } else if ( className.compare ( "DateType" ) == 0 ) {

    metaObject = DateType::staticMetaObject;

  } else if ( className.compare ( "DayTimeDurationType" ) == 0 ) {

    metaObject = DayTimeDurationType::staticMetaObject;

  } else if ( className.compare ( "DecimalType" ) == 0 ) {

    metaObject = DecimalType::staticMetaObject;

  } else if ( className.compare ( "DoubleType" ) == 0 ) {

    metaObject = DoubleType::staticMetaObject;

  } else if ( className.compare ( "DurationType" ) == 0 ) {

    metaObject = DurationType::staticMetaObject;

  } else if ( className.compare ( "EntitiesType" ) == 0 ) {

    metaObject = EntitiesType::staticMetaObject;

  } else if ( className.compare ( "EntityType" ) == 0 ) {

    metaObject = EntityType::staticMetaObject;

  } else if ( className.compare ( "FloatType" ) == 0 ) {

    metaObject = FloatType::staticMetaObject;

  } else if ( className.compare ( "GDayType" ) == 0 ) {

    metaObject = GDayType::staticMetaObject;

  } else if ( className.compare ( "GMonthDayType" ) == 0 ) {

    metaObject = GMonthDayType::staticMetaObject;

  } else if ( className.compare ( "GMonthType" ) == 0 ) {

    metaObject = GMonthType::staticMetaObject;

  } else if ( className.compare ( "GYearMonthType" ) == 0 ) {

    metaObject = GYearMonthType::staticMetaObject;

  } else if ( className.compare ( "GYearType" ) == 0 ) {

    metaObject = GYearType::staticMetaObject;

  } else if ( className.compare ( "HexBinaryType" ) == 0 ) {

    metaObject = HexBinaryType::staticMetaObject;

  } else if ( className.compare ( "IdRefsType" ) == 0 ) {

    metaObject = IdRefsType::staticMetaObject;

  } else if ( className.compare ( "IdRefType" ) == 0 ) {

    metaObject = IdRefType::staticMetaObject;

  } else if ( className.compare ( "IdType" ) == 0 ) {

    metaObject = IdType::staticMetaObject;

  } else if ( className.compare ( "IntegerType" ) == 0 ) {

    metaObject = IntegerType::staticMetaObject;

  } else if ( className.compare ( "IntType" ) == 0 ) {

    metaObject = IntType::staticMetaObject;

  } else if ( className.compare ( "LanguageType" ) == 0 ) {

    metaObject = LanguageType::staticMetaObject;

  } else if ( className.compare ( "LongType" ) == 0 ) {

    metaObject = LongType::staticMetaObject;

  } else if ( className.compare ( "NameType" ) == 0 ) {

    metaObject = NameType::staticMetaObject;

  } else if ( className.compare ( "NCNameType" ) == 0 ) {

    metaObject = NCNameType::staticMetaObject;

  } else if ( className.compare ( "NegativeIntegerType" ) == 0 ) {

    metaObject = NegativeIntegerType::staticMetaObject;

  } else if ( className.compare ( "NMTokensType" ) == 0 ) {

    metaObject = NMTokensType::staticMetaObject;

  } else if ( className.compare ( "NMTokenType" ) == 0 ) {

    metaObject = NMTokenType::staticMetaObject;

  } else if ( className.compare ( "NonNegativeIntegerType" ) == 0 ) {

    metaObject = NonNegativeIntegerType::staticMetaObject;

  } else if ( className.compare ( "NonPositiveIntegerType" ) == 0 ) {

    metaObject = NonPositiveIntegerType::staticMetaObject;

  } else if ( className.compare ( "NormalizedStringType" ) == 0 ) {

    metaObject = NormalizedStringType::staticMetaObject;

  } else if ( className.compare ( "NotationType" ) == 0 ) {

    metaObject = NotationType::staticMetaObject;

  } else if ( className.compare ( "PositiveIntegerType" ) == 0 ) {

    metaObject = PositiveIntegerType::staticMetaObject;

  } else if ( className.compare ( "QNameType" ) == 0 ) {

    metaObject = QNameType::staticMetaObject;

  } else if ( className.compare ( "ShortType" ) == 0 ) {

    metaObject = ShortType::staticMetaObject;

  } else if ( className.compare ( "StringType" ) == 0 ) {

    metaObject = StringType::staticMetaObject;

  } else if ( className.compare ( "TimeType" ) == 0 ) {

    metaObject = TimeType::staticMetaObject;

  } else if ( className.compare ( "TokenType" ) == 0 ) {

    metaObject = TokenType::staticMetaObject;

  } else if ( className.compare ( "UnsignedByteType" ) == 0 ) {

    metaObject = UnsignedByteType::staticMetaObject;

  } else if ( className.compare ( "UnsignedIntType" ) == 0 ) {

    metaObject = UnsignedIntType::staticMetaObject;

  } else if ( className.compare ( "UnsignedLongType" ) == 0 ) {

    metaObject = UnsignedLongType::staticMetaObject;

  } else if ( className.compare ( "UnsignedShortType" ) == 0 ) {

    metaObject = UnsignedShortType::staticMetaObject;

  } else if ( className.compare ( "YearMonthDurationType" ) == 0 ) {

    metaObject = YearMonthDurationType::staticMetaObject;
  }
  return metaObject;
}

bool XsdEngine::isElementToFind ( QDomElement docElement, QString nodeName ) {

  if ( docElement.hasAttribute ( "name" ) ) {

    if ( nodeName.compare ( "" ) != 0  ) {

      if ( docElement.attribute ( "name" ).compare ( nodeName ) == 0 ) {

        return true;
      }
    }
  }
  return false;
}

XsdElement *XsdEngine::getXsdElementModel () const {

  return this->xsdElementModel;
}

void XsdEngine::load ( QString xsdFile ) {

  QFile file ( xsdFile );
  if ( file.open ( QIODevice::ReadOnly ) ) {

    this->doc = new QDomDocument ( "xsdDocument" );
    this->xsdElementModel = new XsdElement ();
    this->xsdElementModel->setElementLevel ( Xsd::levelEnum::ROOTFORM );
    if ( !this->doc->setContent ( file.readAll () ) ) {

      file.close ();
      return;
    }
  } else {

    return;
  }
  file.close ();
}

void XsdEngine::parse () {

  this->parse ( this->doc->documentElement ().firstChildElement (), this->xsdElementModel, "settings" );
}

void XsdEngine::parse ( QDomElement docElement, XsdElement *xsdElement, QString nodeName ) {

  if ( !docElement.isNull () ) {

    this->currentElement = static_cast<ElementAbs::elements> ( ElementAbs::indexOfEnum ( docElement.nodeName () ) );
    switch ( this->currentElement ) {

      case ElementAbs::elements::ALL:

/*
<all
  id = ID
  maxOccurs = (0 | 1) : 1
  minOccurs = (0 | 1) : 1
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, (element | any | group)*)
</all>
*/
        qDebug () << "Es un elemento tipo xs:all";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {

          xsdElement->setElementIndicator ( Xsd::indicatorEnum::ALL );
          this->processElement ( docElement, xsdElement );
          if ( docElement.hasChildNodes () ) {

            this->parse ( docElement.firstChildElement (), xsdElement );
          }
        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::ALTERNATIVE:

/*
<alternative
  id = ID
  test = an XPath expression
  type = QName
  xpathDefaultNamespace = (anyURI | (##defaultNamespace | ##targetNamespace | ##local))
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, (simpleType | complexType)?)
</alternative>
*/
        qDebug () << "Es un elemento tipo xs:alternative";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::ANNOTATION:

/*
<annotation
  id = ID
  {any attributes with non-schema namespace . . .}>
  Content: (appinfo | documentation)*
</annotation>
*/
        qDebug () << "Es un elemento tipo xs:annotation";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        // TODO: ¿Qué hacer en este caso? ¿Qué modificaciones hace?
        if ( docElement.hasChildNodes () ) {

          this->parse ( docElement.firstChildElement (), xsdElement );
        }
        break;

      case ElementAbs::elements::ANY:

/*
<any
  id = ID
  maxOccurs = (nonNegativeInteger | unbounded)  : 1
  minOccurs = nonNegativeInteger : 1
  namespace = ((##any | ##other) | List of (anyURI | (##targetNamespace | ##local)) )
  notNamespace = List of (anyURI | (##targetNamespace | ##local))
  notQName = List of (QName | (##defined | ##definedSibling))
  processContents = (lax | skip | strict) : strict
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?)
</any>
*/
        qDebug () << "Es un elemento tipo xs:any";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::ANYATTRIBUTE:

/*
<anyAttribute
  id = ID
  namespace = ((##any | ##other) | List of (anyURI | (##targetNamespace | ##local)) )
  notNamespace = List of (anyURI | (##targetNamespace | ##local))
  notQName = List of (QName | ##defined)
  processContents = (lax | skip | strict) : strict
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?)
</anyAttribute>
*/
        qDebug () << "Es un elemento tipo xs:anyattribute";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::APPINFO:

/*
<appinfo
  source = anyURI
  {any attributes with non-schema namespace . . .}>
  Content: ({any})*
</appinfo>
*/
        qDebug () << "Es un elemento tipo xs:appinfo";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::ASSERT:

/*
<assert
  id = ID
  test = an XPath expression
  xpathDefaultNamespace = (anyURI | (##defaultNamespace | ##targetNamespace | ##local))
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?)
</assert>
*/
        qDebug () << "Es un elemento tipo xs:assert";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::ATTRIBUTE:

/*
<attribute
  default = string
  fixed = string
  form = (qualified | unqualified)
  id = ID
  name = NCName
  ref = QName
  targetNamespace = anyURI
  type = QName
  use = (optional | prohibited | required) : optional
  inheritable = boolean
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, simpleType?)
</attribute>
*/
        qDebug () << "Es un elemento tipo xs:attribute";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::ATTRIBUTEGROUP:

/*
<attributeGroup
  id = ID
  name = NCName
  ref = QName
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, ((attribute | attributeGroup)*, anyAttribute?))
</attributeGroup>
*/
        qDebug () << "Es un elemento tipo xs:attributegroup";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {

          xsdElement->setElementIndicator ( Xsd::indicatorEnum::ATTRIBUTEGROUP );

        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::CHOICE:

/*
<choice
  id = ID
  maxOccurs = (nonNegativeInteger | unbounded)  : 1
  minOccurs = nonNegativeInteger : 1
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, (element | group | choice | sequence | any)*)
</choice>
*/
        qDebug () << "Es un elemento tipo xs:choice";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {

          xsdElement->setElementIndicator ( Xsd::indicatorEnum::CHOICE );
          this->processElement ( docElement, xsdElement );
          //this->processProperties ( docElement, xsdElement );
          if ( docElement.hasChildNodes () ) {

            this->parse ( docElement.firstChildElement (), xsdElement );
          }

        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::COMPLEXCONTENT:

/*
<complexContent
  id = ID
  mixed = boolean
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, (restriction | extension))
</complexContent>
*/
        qDebug () << "Es un elemento tipo xs:complexcontent";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        // TODO: hasta que punto la propiedad mixed afecta el complexType y el elemento.
        this->processProperties ( docElement, xsdElement );
        if ( docElement.hasChildNodes () ) {

          this->parse ( docElement.firstChildElement (), xsdElement );
        }
        break;

      case ElementAbs::elements::COMPLEXTYPE:

/*
<complexType
  abstract = boolean : false
  block = (#all | List of (extension | restriction))
  final = (#all | List of (extension | restriction))
  id = ID
  mixed = boolean
  name = NCName
  defaultAttributesApply = boolean : true
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, (simpleContent | complexContent | (openContent?, (group | all | choice | sequence)?, ((attribute | attributeGroup)*, anyAttribute?), assert*)))
</complexType>
*/
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {

          xsdElement->setSimpleType ( false );
          this->processProperties ( docElement, xsdElement );
          if ( docElement.hasChildNodes () ) {

            this->parse ( docElement.firstChildElement (), xsdElement );
          }
        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::DEFAULTOPENCONTENT:

/*
<defaultOpenContent
  appliesToEmpty = boolean : false
  id = ID
  mode = (interleave | suffix) : interleave
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, any)
</defaultOpenContent>
*/
        qDebug () << "Es un elemento tipo xs:defaultopencontent";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::DOCUMENTATION:

/*
<documentation
  source = anyURI
  xml:lang = language
  {any attributes with non-schema namespace . . .}>
  Content: ({any})*
</documentation>
*/
        qDebug () << "Es un elemento tipo xs:documentation";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::ELEMENT:

/*
<element
  abstract = boolean : false
  block = (#all | List of (extension | restriction | substitution))
  default = string
  final = (#all | List of (extension | restriction))
  fixed = string
  form = (qualified | unqualified)
  id = ID
  maxOccurs = (nonNegativeInteger | unbounded)  : 1
  minOccurs = nonNegativeInteger : 1
  name = NCName
  nillable = boolean : false
  ref = QName
  substitutionGroup = List of QName
  targetNamespace = anyURI
  type = QName
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, ((simpleType | complexType)?, alternative*, (unique | key | keyref)*))
</element>
*/
        if ( docElement.hasAttribute ( "name" ) ) {

          if ( this->isElementToFind ( docElement, nodeName ) ) {

            this->processElement ( docElement, xsdElement );
            if ( docElement.hasAttribute ( "type" ) ) {

              if ( !TypeAbs::inEmun ( docElement.attribute ( "type" ) ) ) {

                xsdElement->setSimpleType ( false );
                this->parse ( this->doc->firstChildElement (), xsdElement, docElement.attribute ( "type" ) );
              }
            }
            if ( docElement.hasChildNodes () ) {

              this->parse ( docElement.firstChildElement (), xsdElement );
            }
          } else {

            this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
          }
        } else if ( docElement.hasAttribute ( "ref" ) ) {

          XsdElement *newXsdElement = new XsdElement ();
          xsdElement->setElement ( newXsdElement );
          newXsdElement->setParent ( xsdElement );
          this->parse ( this->doc->documentElement ().firstChildElement (), newXsdElement, docElement.attribute ( "ref" ) );
          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::EXTENSION:

/*
<extension
  base = QName
  id = ID
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, ((attribute | attributeGroup)*, anyAttribute?), assert*)
</extension>
*/
        qDebug () << "Es un elemento tipo xs:extension";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        // TODO: Las propiedades de un extension afectan directamente al elemento
        // así que hay que buscar una estrategia para asignar esos valores al
        // elemento
        this->processProperties ( docElement, xsdElement );
        if ( docElement.hasChildNodes () ) {

          this->parse ( docElement.firstChildElement (), xsdElement );
        }
        break;

      case ElementAbs::elements::FIELD:

/*
<field
  id = ID
  xpath = a subset of XPath expression, see below
  xpathDefaultNamespace = (anyURI | (##defaultNamespace | ##targetNamespace | ##local))
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?)
</field>
*/
        qDebug () << "Es un elemento tipo xs:field";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::GROUP:

/*
<group
  id = ID
  maxOccurs = (nonNegativeInteger | unbounded)  : 1
  minOccurs = nonNegativeInteger : 1
  name = NCName
  ref = QName
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, (all | choice | sequence)?)
</group>
*/
        qDebug () << "Es un elemento tipo xs:group";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {

          xsdElement->setElementIndicator ( Xsd::indicatorEnum::GROUP );

        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::IMPORT:

/*
<import
  id = ID
  namespace = anyURI
  schemaLocation = anyURI
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?)
</import>
*/
        qDebug () << "Es un elemento tipo xs:import";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::INCLUDE:

/*
<include
  id = ID
  schemaLocation = anyURI
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?)
</include>
*/
        qDebug () << "Es un elemento tipo xs:include";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::KEY:

/*
<key
  id = ID
  name = NCName
  ref = QName
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, (selector, field+)?)
</key>
*/
        qDebug () << "Es un elemento tipo xs:key";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::KEYREF:

/*
<keyref
  id = ID
  name = NCName
  ref = QName
  refer = QName
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, (selector, field+)?)
</keyref>
*/
        qDebug () << "Es un elemento tipo xs:keyref";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::LIST:

/*
<list
  id = ID
  itemType = QName
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, simpleType?)
</list>
*/
        qDebug () << "Es un elemento tipo xs:list";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::NOTATION:

/*
<notation
  id = ID
  name = NCName
  public = token
  system = anyURI
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?)
</notation>
*/
        qDebug () << "Es un elemento tipo xs:notation";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::OPENCONTENT:

/*
<openContent
  id = ID
  mode = (none | interleave | suffix) : interleave
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, any?)
</openContent>
*/
        qDebug () << "Es un elemento tipo xs:opencontent";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::OVERRIDE:

/*
<Q_DECL_OVERRIDE
  id = ID
  schemaLocation = anyURI
  {any attributes with non-schema namespace . . .}>
  Content: (annotation | (simpleType | complexType | group | attributeGroup | element | attribute | notation))*
</Q_DECL_OVERRIDE>
*/
        qDebug () << "Es un elemento tipo xs:overryde";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::REDEFINE:

/*
<redefine
  id = ID
  schemaLocation = anyURI
  {any attributes with non-schema namespace . . .}>
  Content: (annotation | (simpleType | complexType | group | attributeGroup))*
</redefine>
*/
        qDebug () << "Es un elemento tipo xs:redefine";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::RESTRICTION:

/*
<restriction
  base = QName
  id = ID
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, (simpleType?, (minExclusive | minInclusive | maxExclusive | maxInclusive | totalDigits | fractionDigits | length | minLength | maxLength | enumeration | whiteSpace | pattern | assertion | explicitTimezone | {any with namespace: ##other})*))
</restriction>
*/
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {

          xsdElement->setRestriction ( true );
          this->processProperties ( docElement, xsdElement );
          this->parseFacets ( docElement.firstChildElement (), xsdElement );
          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
          // TODO: Las propiedades de un extension afectan directamente al elemento
          // o al tipo del elemento así que hay que buscar una estrategia para
          // asignar esos valores al elemento o al tipo del elemento
          // TODO: Como procesar los elementos annotation y simpleType

        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::SCHEMA:

/*
<schema
  attributeFormDefault = (qualified | unqualified) : unqualified
  blockDefault = (#all | List of (extension | restriction | substitution))  : ''
  defaultAttributes = QName
  xpathDefaultNamespace = (anyURI | (##defaultNamespace | ##targetNamespace | ##local))  : ##local
  elementFormDefault = (qualified | unqualified) : unqualified
  finalDefault = (#all | List of (extension | restriction | list | union))  : ''
  id = ID
  targetNamespace = anyURI
  version = token
  xml:lang = language
  {any attributes with non-schema namespace . . .}>
  Content: ((include | import | redefine | Q_DECL_OVERRIDE | annotation)*, (defaultOpenContent, annotation*)?, ((simpleType | complexType | group | attributeGroup | element | attribute | notation), annotation*)*)
</schema>
*/
        qDebug () << "Es un elemento tipo xs:schema";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::SELECTOR:

/*
<selector
  id = ID
  xpath = a subset of XPath expression, see below
  xpathDefaultNamespace = (anyURI | (##defaultNamespace | ##targetNamespace | ##local))
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?)
</selector>
*/
        qDebug () << "Es un elemento tipo xs:selector";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::SEQUENCE:

/*
<sequence
  id = ID
  maxOccurs = (nonNegativeInteger | unbounded)  : 1
  minOccurs = nonNegativeInteger : 1
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, (element | group | choice | sequence | any)*)
</sequence>
*/
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {

          xsdElement->setElementIndicator ( Xsd::indicatorEnum::SEQUENCE );
          this->processElement ( docElement, xsdElement );
          if ( docElement.hasChildNodes () ) {

            this->parse ( docElement.firstChildElement (), xsdElement );
          }
        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::SIMPLECONTENT:

/*
<simpleContent
  id = ID
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, (restriction | extension))
</simpleContent>
*/
        qDebug () << "Es un elemento tipo xs:simplecontent";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      case ElementAbs::elements::SIMPLETYPE:

/*
<simpleType
  final = (#all | List of (list | union | restriction | extension))
  id = ID
  name = NCName
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, (restriction | list | union))
</simpleType>
*/
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {

          xsdElement->setSimpleType ( true );
          this->parse ( docElement.firstChildElement (), xsdElement, nodeName );

        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        // TODO: Las propiedades de un simpletype afectan directamente al elemento
        // y a los atributos según corresponda, así que hay que buscar una
        // estrategia para asignar esos valores al elemento o a los atributos
        // según corresponda.
        break;

      case ElementAbs::elements::UNION:

/*
<union
  id = ID
  memberTypes = List of QName
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, simpleType*)
</union>
*/
        qDebug () << "Es un elemento tipo xs:union";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        this->processProperties ( docElement, xsdElement );
        if ( docElement.hasChildNodes () ) {

          this->parse ( docElement.firstChildElement (), xsdElement );

        } else {

          // TODO: Si no tiene hijos, separar la lista de memberTypes por espacios
          // y buscar cada unos de los simpleType
          this->parse ( this->doc->firstChildElement (), xsdElement );
        }
        break;

      case ElementAbs::elements::UNIQUE:

/*
<unique
  id = ID
  name = NCName
  ref = QName
  {any attributes with non-schema namespace . . .}>
  Content: (annotation?, (selector, field+)?)
</unique>
*/
        qDebug () << "Es un elemento tipo xs:unique";
        if ( nodeName.isEmpty () ^ this->isElementToFind ( docElement, nodeName ) ) {


        } else {

          this->parse ( docElement.nextSiblingElement (), xsdElement, nodeName );
        }
        break;

      default:
        break;
    }
  }
}

void XsdEngine::parseFacets ( QDomElement docElement, XsdElement *xsdElement ) {

  if ( !docElement.isNull () ) {

    switch ( FacetAbs::indexOfFacetsEnum ( docElement.nodeName () ) ) {

      case FacetAbs::facets::ASSERTIONS:

        qDebug () << "Es un elemento tipo xs:assertions";
        xsdElement->setFacet ( new AssertionsFacet ( docElement.nodeValue () ) );
        break;

      case FacetAbs::facets::ENUMERATION:

        xsdElement->setFacet ( new EnumerationFacet ( docElement.attribute ( "value" ) ) );
        xsdElement->setEnumerate ( true );
        break;

      case FacetAbs::facets::EXPLICITTIMEZONE:

        qDebug () << "Es un elemento tipo xs:explicitimezone";
        xsdElement->setFacet ( new ExplicitTimeZoneFacet ( docElement.nodeValue () ) );
        break;

      case FacetAbs::facets::FRACTIONDIGITS:

        qDebug () << "Es un elemento tipo xs:fractiondigits";
        xsdElement->setFacet ( new FractionDigitsFacet ( docElement.nodeValue () ) );
        break;

      case FacetAbs::facets::LENGTH:

        xsdElement->setFacet ( new LengthFacet ( docElement.nodeValue () ) );
        break;

      case FacetAbs::facets::MAXEXCLUSIVE:

        xsdElement->setFacet ( new MaxExclusiveFacet ( docElement.nodeValue () ) );
        break;

      case FacetAbs::facets::MAXINCLUSIVE:

        xsdElement->setFacet ( new MaxInclusiveFacet ( docElement.nodeValue () ) );
        break;

      case FacetAbs::facets::MAXLENGTH:

        xsdElement->setFacet ( new MaxLengthFacet ( docElement.nodeValue () ) );
        break;

      case FacetAbs::facets::MINEXCLUSIVE:

        xsdElement->setFacet ( new MinExclusiveFacet ( docElement.nodeValue () ) );
        break;

      case FacetAbs::facets::MININCLUSIVE:

        xsdElement->setFacet ( new MinInclusiveFacet ( docElement.nodeValue () ) );
        break;

      case FacetAbs::facets::MINLENGTH:

        xsdElement->setFacet ( new MinLengthFacet ( docElement.nodeValue () ) );
        break;

      case FacetAbs::facets::PATTERN:

        qDebug () << "Es un elemento tipo xs:pattern";
        xsdElement->setFacet ( new PatternFacet ( docElement.nodeValue () ) );
        break;

      case FacetAbs::facets::TOTALDIGITS:

        qDebug () << "Es un elemento tipo xs:totaldigits";
        xsdElement->setFacet ( new TotalDigitsFacet ( docElement.nodeValue () ) );
        break;

      case FacetAbs::facets::WHITESPACE:

        qDebug () << "Es un elemento tipo xs:whitespace";
        xsdElement->setFacet ( new WhitespaceFacet ( docElement.nodeValue () ) );
        break;

      default:
        break;
    }
    this->parseFacets ( docElement.nextSiblingElement (), xsdElement );
  }
}

void XsdEngine::processElement ( QDomElement docElement, XsdElement *xsdElement ) {

  this->defineElementLevel ( xsdElement );
  this->processProperties ( docElement, xsdElement );
}

void XsdEngine::processProperties ( QDomElement docElement, XsdElement *xsdElement ) {

  if ( docElement.hasAttributes () ) {

    QString normalizedClassName = Utils::Strings::capitalize ( Utils::Strings::normalizeClassName ( docElement.nodeName () ) );
    QMetaType metaType = QMetaType::fromName ( QByteArrayView ( normalizedClassName.toLatin1 () ) );
    if ( metaType.id () != QMetaType::UnknownType ) {

      const QMetaObject metaObject = this->getMetaObject ( normalizedClassName );
      const int index = metaObject.indexOfEnumerator ( "properties" );
      const QMetaEnum metaenum = metaObject.enumerator ( index );
      QDomNamedNodeMap nodeMap = docElement.attributes ();
      const int nodeMapCount = nodeMap.count ();
      for ( int i = 0; i < nodeMapCount; i++ ) {

        QString keyNormalized = Utils::Enumeration::normalizeEnumValue ( nodeMap.item ( i ).nodeName () );
        switch ( metaenum.keyToValue ( keyNormalized.toUtf8 ().data () ) ) {

          case PropertyAbs::properties::ABSTRACT:

            xsdElement->setProperty ( new AbstractProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::APPLIESTOEMPTY:

            //xsdElement->setProperty ( new AppliesToEmptyProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::ATTRIBUTEFORMDEFAULT:

            //xsdElement->setProperty ( new AttributeFormDefaultProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::BASE:

            xsdElement->setProperty ( new TypeProperty ( Utils::Enumeration::normalizeEnumValue ( nodeMap.item ( i ).nodeValue ().toUtf8 () ) ) );
            break;

          case PropertyAbs::properties::BLOCK:

            xsdElement->setProperty ( new BlockProperty ( QString::fromUtf8 ( nodeMap.item ( i ).nodeValue ().toUtf8 () ) ) );
            break;

          case PropertyAbs::properties::BLOCKDEFAULT:

            //xsdElement->setProperty ( new BlockDefaultProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::DEFAULT:

            xsdElement->setProperty ( new DefaultProperty ( QString::fromUtf8 ( nodeMap.item ( i ).nodeValue ().toUtf8 () ) ) );
            break;

          case PropertyAbs::properties::DEFAULTATTRIBUTES:

            //xsdElement->setProperty ( new DefaultAttributesProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::DEFAULTATTRIBUTESAPPLY:

            //xsdElement->setProperty ( new DefaultAttributesApplyProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::ELEMENTFORMDEFAULT:

            //xsdElement->setProperty ( new ElementFormDefaultProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::FINAL:

            xsdElement->setProperty ( new FinalProperty ( QString::fromUtf8 ( nodeMap.item ( i ).nodeValue ().toUtf8 () ) ) );
            break;

          case PropertyAbs::properties::FINALDEFAULT:

            //xsdElement->setProperty ( new FinalDefaultProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::FIXED:

            xsdElement->setProperty ( new FixedProperty ( QString::fromUtf8 ( nodeMap.item ( i ).nodeValue ().toUtf8 () ) ) );
            break;

          case PropertyAbs::properties::FORM:

            xsdElement->setProperty ( new FormProperty ( QString::fromUtf8 ( nodeMap.item ( i ).nodeValue ().toUtf8 () ) ) );
            break;

          case PropertyAbs::properties::ID:

            xsdElement->setProperty ( new IdProperty ( QString::fromUtf8 ( nodeMap.item ( i ).nodeValue ().toUtf8 () ) ) );
            break;

          case PropertyAbs::properties::INHERITABLE:

            //xsdElement->setProperty ( new InheritableProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::ITEMTYPE:

            //xsdElement->setProperty ( new ItemTypeProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::MAXOCCURS:

            xsdElement->setElementIndicator ( Xsd::indicatorEnum::MAXOCCURS );
            xsdElement->setProperty ( new MaxOccursProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::MEMBERTYPES:

            //xsdElement->setProperty ( new MemberTypesProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::MINOCCURS:

            xsdElement->setElementIndicator ( Xsd::indicatorEnum::MINOCCURS );
            xsdElement->setProperty ( new MinOccursProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::MIXED:

            //xsdElement->setProperty ( new MixedProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::MODE:

            //xsdElement->setProperty ( new ModeProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::NAME:

            xsdElement->setProperty ( new NameProperty ( QString::fromUtf8 ( nodeMap.item ( i ).nodeValue ().toUtf8 () ) ) );
            break;

          case PropertyAbs::properties::NAMESPACE:

            //xsdElement->setProperty ( new NamespaceProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::NILLABLE:

            xsdElement->setProperty ( new NillableProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::NOTNAMESPACE:

            //xsdElement->setProperty ( new NotNamespaceProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::NOTQNAME:

            //xsdElement->setProperty ( new NotQNameProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::PROCESSCONTENTS:

            //xsdElement->setProperty ( new ProcessContentsProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::PUBLIC:

            //xsdElement->setProperty ( new PublicProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::REF:

            xsdElement->setProperty ( new RefProperty ( QString::fromUtf8 ( nodeMap.item ( i ).nodeValue ().toUtf8 () ) ) );
            break;

          case PropertyAbs::properties::REFER:

            //xsdElement->setProperty ( new ReferProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::SCHEMALOCATION:

            //xsdElement->setProperty ( new SchemaLocationProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::SOURCE:

            //xsdElement->setProperty ( new SourceProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::SUBSTITUTIONGROUP:

            xsdElement->setProperty ( new SubstitutionGroupProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::SYSTEM:

            //xsdElement->setProperty ( new SystemProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::TARGETNAMESPACE:

            xsdElement->setProperty ( new TargetNamespaceProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::TEST:

            //xsdElement->setProperty ( new TestProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::TYPE:

            if ( this->currentElement == ElementAbs::RESTRICTION ) {

              XsdElement *xsdElementParent = xsdElement->getParent ();
              xsdElementParent->setProperty ( new TypeProperty ( Utils::Enumeration::normalizeEnumValue ( nodeMap.item ( i ).nodeValue ().toUtf8 () ) ) );

            } else {

              xsdElement->setProperty ( new TypeProperty ( Utils::Enumeration::normalizeEnumValue ( nodeMap.item ( i ).nodeValue ().toUtf8 () ) ) );
            }
            break;

          case PropertyAbs::properties::USE:

            //xsdElement->setProperty ( new UseProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::VERSION:

            //xsdElement->setProperty ( new VersionProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::XMLLANG:

            //xsdElement->setProperty ( new XmlLangProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::XPATH:

            //xsdElement->setProperty ( new XPathProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          case PropertyAbs::properties::XPATHDEFAULTNAMESPACE:

            //xsdElement->setProperty ( new XPathDefaultNamespaceProperty ( nodeMap.item ( i ).nodeValue ().toInt () ) );
            break;

          default:

            // TODO: ¿Qué hacer en este caso?
            // Aquí se debería paralizar todo el proceso y mostrar el error ocurrido
            break;
        }
      }
    }
  }
}

void XsdEngine::registerTypes () {

  qRegisterMetaType<All>( "All" );
  qRegisterMetaType<Alternative>( "Alternative" );
  qRegisterMetaType<Annotation>( "Annotation" );
  qRegisterMetaType<Any>( "Any" );
  qRegisterMetaType<AnyAttribute>( "AnyAttribute" );
  qRegisterMetaType<AppInfo>( "AppInfo" );
  qRegisterMetaType<Assert>( "Assert" );
  qRegisterMetaType<Attribute>( "Attribute" );
  qRegisterMetaType<AttributeGroup>( "AttributeGroup" );
  qRegisterMetaType<Choice>( "Choice" );
  qRegisterMetaType<ComplexContent>( "ComplexContent" );
  qRegisterMetaType<ComplexType>( "ComplexType" );
  qRegisterMetaType<DefaultOpenContent>( "DefaultOpenContent" );
  qRegisterMetaType<Documentation>( "Documentation" );
  qRegisterMetaType<Element>( "Element" );
  qRegisterMetaType<Extension>( "Extension" );
  qRegisterMetaType<Field>( "Field" );
  qRegisterMetaType<Group>( "Group" );
  qRegisterMetaType<Import>( "Import" );
  qRegisterMetaType<Include>( "Include" );
  qRegisterMetaType<Key>( "Key" );
  qRegisterMetaType<Keyref>( "Keyref" );
  qRegisterMetaType<List>( "List" );
  qRegisterMetaType<Notation>( "Notation" );
  qRegisterMetaType<Opencontent>( "Opencontent" );
  qRegisterMetaType<Override>( "Override" );
  qRegisterMetaType<Redefine>( "Redefine" );
  qRegisterMetaType<Restriction>( "Restriction" );
  qRegisterMetaType<Schema>( "Schema" );
  qRegisterMetaType<Selector>( "Selector" );
  qRegisterMetaType<Sequence>( "Sequence" );
  qRegisterMetaType<SimpleContent>( "SimpleContent" );
  qRegisterMetaType<SimpleType>( "SimpleType" );
  qRegisterMetaType<Union>( "Union" );
  qRegisterMetaType<Unique>( "Unique" );
  qRegisterMetaType<AssertionsFacet>( "AssertionsFacet" );
  qRegisterMetaType<EnumerationFacet>( "EnumerationFacet" );
  qRegisterMetaType<ExplicitTimeZoneFacet>( "ExplicitTimeZoneFacet" );
  qRegisterMetaType<FractionDigitsFacet>( "FractionDigitsFacet" );
  qRegisterMetaType<LengthFacet>( "LengthFacet" );
  qRegisterMetaType<MaxExclusiveFacet>( "MaxExclusiveFacet" );
  qRegisterMetaType<MaxInclusiveFacet>( "MaxInclusiveFacet" );
  qRegisterMetaType<MaxLengthFacet>( "MaxLengthFacet" );
  qRegisterMetaType<MinExclusiveFacet>( "MinExclusiveFacet" );
  qRegisterMetaType<MinInclusiveFacet>( "MinInclusiveFacet" );
  qRegisterMetaType<MinLengthFacet>( "MinLengthFacet" );
  qRegisterMetaType<PatternFacet>( "PatternFacet" );
  qRegisterMetaType<TotalDigitsFacet>( "TotalDigitsFacet" );
  qRegisterMetaType<WhitespaceFacet>( "WhitespaceFacet" );
}

QDomDocument *XsdEngine::toDomDocument () {

  return this->doc;
}

QString XsdEngine::toString () {

  return this->doc->toString ();
}

QString XsdEngine::toXml () {

  // TODO: Que diferencia hay con el método toString?.
  return this->doc->toString ();
}

void XsdEngine::listarElementos ( XsdElement *XsdElement ) {

    Q_UNUSED ( XsdElement )
/*
  if ( XsdElement == nullptr ) {

    XsdElement = this->xsdElementModel;
  }

  const int propertyListCount = XsdElement->getProperties ().count ();
  if ( propertyListCount > 0 ) {

    for ( int i = 0; i < propertyListCount; i++ ) {

      PropertyAbs *property = XsdElement->getProperties ().at ( i );

      AbstractProperty *abstractProperty = qobject_cast<AbstractProperty *> ( property );
      if ( abstractProperty != nullptr ) {

        qDebug () << "El AbstractProperty del elemento es: " << abstractProperty->getValue ();

      } else {

        AppliesToEmptyProperty *appliesToEmptyProperty = qobject_cast<AppliesToEmptyProperty *> ( property );
        if ( appliesToEmptyProperty != nullptr ) {

          qDebug () << "El AppliesToEmptyProperty del elemento es: " << appliesToEmptyProperty->getValue ();

        } else {

          AttributeFormDefaultProperty *attributeFormDefaultProperty = qobject_cast<AttributeFormDefaultProperty *> ( property );
          if ( attributeFormDefaultProperty != nullptr ) {

            qDebug () << "El AttributeFormDefaultProperty del elemento es: " << attributeFormDefaultProperty->getValue ();

          } else {

            BaseProperty *baseProperty = qobject_cast<BaseProperty *> ( property );
            if ( baseProperty != nullptr ) {

              qDebug () << "El BaseProperty del elemento es: " << baseProperty->getValue ();

            } else {

              BlockDefaultProperty *blockDefaultProperty = qobject_cast<BlockDefaultProperty *> ( property );
              if ( blockDefaultProperty != nullptr ) {

                qDebug () << "El BlockDefaultProperty del elemento es: " << blockDefaultProperty->getValue ();

              } else {

                BlockProperty *blockProperty = qobject_cast<BlockProperty *> ( property );
                if ( blockProperty != nullptr ) {

                  qDebug () << "El BlockProperty del elemento es: " << blockProperty->getValue ();

                } else {

                  DefaultAttributesApplyProperty *defaultAttributesApplyProperty = qobject_cast<DefaultAttributesApplyProperty *> ( property );
                  if ( defaultAttributesApplyProperty != nullptr ) {

                    qDebug () << "El DefaultAttributesApplyProperty del elemento es: " << defaultAttributesApplyProperty->getValue ();

                  } else {

                    DefaultAttributesProperty *defaultAttributesProperty = qobject_cast<DefaultAttributesProperty *> ( property );
                    if ( defaultAttributesProperty != nullptr ) {

                      qDebug () << "El DefaultAttributesProperty del elemento es: " << defaultAttributesProperty->getValue ();

                    } else {

                      DefaultProperty *defaultProperty = qobject_cast<DefaultProperty *> ( property );
                      if ( defaultProperty != nullptr ) {

                        qDebug () << "El DefaultProperty del elemento es: " << defaultProperty->getValue ();

                      } else {

                        ElementFormDefaultProperty *elementFormDefaultProperty = qobject_cast<ElementFormDefaultProperty *> ( property );
                        if ( elementFormDefaultProperty != nullptr ) {

                          qDebug () << "El ElementFormDefaultProperty del elemento es: " << elementFormDefaultProperty->getValue ();

                        } else {

                          FinalDefaultProperty *finalDefaultProperty = qobject_cast<FinalDefaultProperty *> ( property );
                          if ( finalDefaultProperty != nullptr ) {

                            qDebug () << "El FinalDefaultProperty del elemento es: " << finalDefaultProperty->getValue ();

                          } else {

                            FinalProperty *finalProperty = qobject_cast<FinalProperty *> ( property );
                            if ( finalProperty != nullptr ) {

                              qDebug () << "El FinalProperty del elemento es: " << finalProperty->getValue ();

                            } else {

                              FixedProperty *fixedProperty = qobject_cast<FixedProperty *> ( property );
                              if ( fixedProperty != nullptr ) {

                                qDebug () << "El FixedProperty del elemento es: " << fixedProperty->getValue ();

                              } else {

                                FormProperty *formProperty = qobject_cast<FormProperty *> ( property );
                                if ( formProperty != nullptr ) {

                                  qDebug () << "El FormProperty del elemento es: " << formProperty->getValue ();

                                } else {

                                  IdProperty *idProperty = qobject_cast<IdProperty *> ( property );
                                  if ( idProperty != nullptr ) {

                                    qDebug () << "El IdProperty del elemento es: " << idProperty->getValue ();

                                  } else {

                                    InheritableProperty *inheritableProperty = qobject_cast<InheritableProperty *> ( property );
                                    if ( inheritableProperty != nullptr ) {

                                      qDebug () << "El InheritableProperty del elemento es: " << inheritableProperty->getValue ();

                                    } else {

                                      ItemTypeProperty *itemTypeProperty = qobject_cast<ItemTypeProperty *> ( property );
                                      if ( itemTypeProperty != nullptr ) {

                                        qDebug () << "El ItemTypeProperty del elemento es: " << itemTypeProperty->getValue ();

                                      } else {

                                        MaxOccursProperty *maxOccursProperty = qobject_cast<MaxOccursProperty *> ( property );
                                        if ( maxOccursProperty != nullptr ) {

                                          qDebug () << "El MaxOccursProperty del elemento es: " << maxOccursProperty->getValue ();

                                        } else {

                                          MemberTypesProperty *memberTypesProperty = qobject_cast<MemberTypesProperty *> ( property );
                                          if ( memberTypesProperty != nullptr ) {

                                            qDebug () << "El MemberTypesProperty del elemento es: " << memberTypesProperty->getValue ();

                                          } else {

                                            MinOccursProperty *minOccursProperty = qobject_cast<MinOccursProperty *> ( property );
                                            if ( minOccursProperty != nullptr ) {

                                              qDebug () << "El MinOccursProperty del elemento es: " << minOccursProperty->getValue ();

                                            } else {

                                              MixedProperty *mixedProperty = qobject_cast<MixedProperty *> ( property );
                                              if ( mixedProperty != nullptr ) {

                                                qDebug () << "El MixedProperty del elemento es: " << mixedProperty->getValue ();

                                              } else {

                                                ModeProperty *modeProperty = qobject_cast<ModeProperty *> ( property );
                                                if ( modeProperty != nullptr ) {

                                                  qDebug () << "El ModeProperty del elemento es: " << modeProperty->getValue ();

                                                } else {

                                                  NameProperty *nameProperty = qobject_cast<NameProperty *> ( property );
                                                  if ( nameProperty != nullptr ) {

                                                    qDebug () << "El NameProperty del elemento es: " << nameProperty->getValue ();

                                                  } else {

                                                    NamespaceProperty *namespaceProperty = qobject_cast<NamespaceProperty *> ( property );
                                                    if ( namespaceProperty != nullptr ) {

                                                      qDebug () << "El NamespaceProperty del elemento es: " << namespaceProperty->getValue ();

                                                    } else {

                                                      NillableProperty *nillableProperty = qobject_cast<NillableProperty *> ( property );
                                                      if ( nillableProperty != nullptr ) {

                                                        qDebug () << "El NillableProperty del elemento es: " << nillableProperty->getValue ();

                                                      } else {

                                                        NotNamespaceProperty *notNamespaceProperty = qobject_cast<NotNamespaceProperty *> ( property );
                                                        if ( notNamespaceProperty != nullptr ) {

                                                          qDebug () << "El NotNamespaceProperty del elemento es: " << notNamespaceProperty->getValue ();

                                                        } else {

                                                          NotQNameProperty *notQNameProperty = qobject_cast<NotQNameProperty *> ( property );
                                                          if ( notQNameProperty != nullptr ) {

                                                            qDebug () << "El NotQNameProperty del elemento es: " << notQNameProperty->getValue ();

                                                          } else {

                                                            ProcessContentsProperty *processContentsProperty = qobject_cast<ProcessContentsProperty *> ( property );
                                                            if ( processContentsProperty != nullptr ) {

                                                              qDebug () << "El ProcessContentsProperty del elemento es: " << processContentsProperty->getValue ();

                                                            } else {

                                                              PublicProperty *publicProperty = qobject_cast<PublicProperty *> ( property );
                                                              if ( publicProperty != nullptr ) {

                                                                qDebug () << "El PublicProperty del elemento es: " << publicProperty->getValue ();

                                                              } else {

                                                                ReferProperty *referProperty = qobject_cast<ReferProperty *> ( property );
                                                                if ( referProperty != nullptr ) {

                                                                  qDebug () << "El ReferProperty del elemento es: " << referProperty->getValue ();

                                                                } else {

                                                                  RefProperty *refProperty = qobject_cast<RefProperty *> ( property );
                                                                  if ( refProperty != nullptr ) {

                                                                    qDebug () << "El RefProperty del elemento es: " << refProperty->getValue ();

                                                                  } else {

                                                                    SchemaLocationProperty *schemaLocationProperty = qobject_cast<SchemaLocationProperty *> ( property );
                                                                    if ( schemaLocationProperty != nullptr ) {

                                                                      qDebug () << "El SchemaLocationProperty del elemento es: " << schemaLocationProperty->getValue ();

                                                                    } else {

                                                                      SourceProperty *sourceProperty = qobject_cast<SourceProperty *> ( property );
                                                                      if ( sourceProperty != nullptr ) {

                                                                        qDebug () << "El SourceProperty del elemento es: " << sourceProperty->getValue ();

                                                                      } else {

                                                                        SubstitutionGroupProperty *substitutionGroupProperty = qobject_cast<SubstitutionGroupProperty *> ( property );
                                                                        if ( substitutionGroupProperty != nullptr ) {

                                                                          qDebug () << "El SubstitutionGroupProperty del elemento es: " << substitutionGroupProperty->getValue ();

                                                                        } else {

                                                                          SystemProperty *systemProperty = qobject_cast<SystemProperty *> ( property );
                                                                          if ( systemProperty != nullptr ) {

                                                                            qDebug () << "El SystemProperty del elemento es: " << systemProperty->getValue ();

                                                                          } else {

                                                                            TargetNamespaceProperty *targetNamespaceProperty = qobject_cast<TargetNamespaceProperty *> ( property );
                                                                            if ( targetNamespaceProperty != nullptr ) {

                                                                              qDebug () << "El TargetNamespaceProperty del elemento es: " << targetNamespaceProperty->getValue ();

                                                                            } else {

                                                                              TestProperty *testProperty = qobject_cast<TestProperty *> ( property );
                                                                              if ( testProperty != nullptr ) {

                                                                                qDebug () << "El TestProperty del elemento es: " << testProperty->getValue ();

                                                                              } else {

                                                                                TypeProperty *typeProperty = qobject_cast<TypeProperty *> ( property );
                                                                                if ( typeProperty != nullptr ) {

                                                                                  qDebug () << "El TypeProperty del elemento es: " << typeProperty->getValue ();

                                                                                } else {

                                                                                  UseProperty *useProperty = qobject_cast<UseProperty *> ( property );
                                                                                  if ( useProperty != nullptr ) {

                                                                                    qDebug () << "El UseProperty del elemento es: " << useProperty->getValue ();

                                                                                  } else {

                                                                                    VersionProperty *versionProperty = qobject_cast<VersionProperty *> ( property );
                                                                                    if ( versionProperty != nullptr ) {

                                                                                      qDebug () << "El VersionProperty del elemento es: " << versionProperty->getValue ();

                                                                                    } else {

                                                                                      XmlLangProperty *xmlLangProperty = qobject_cast<XmlLangProperty *> ( property );
                                                                                      if ( xmlLangProperty != nullptr ) {

                                                                                        qDebug () << "El XmlLangProperty del elemento es: " << xmlLangProperty->getValue ();

                                                                                      } else {

                                                                                        XPathDefaultNamespaceProperty *xPathDefaultNamespaceProperty = qobject_cast<XPathDefaultNamespaceProperty *> ( property );
                                                                                        if ( xPathDefaultNamespaceProperty != nullptr ) {

                                                                                          qDebug () << "El XPathDefaultNamespaceProperty del elemento es: " << xPathDefaultNamespaceProperty->getValue ();

                                                                                        } else {

                                                                                          XPathProperty *xPathProperty = qobject_cast<XPathProperty *> ( property );
                                                                                          if ( xPathProperty != nullptr ) {

                                                                                            qDebug () << "El XPathProperty del elemento es: " << xPathProperty->getValue ();

                                                                                          }
                                                                                        }
                                                                                      }
                                                                                    }
                                                                                  }
                                                                                }
                                                                              }
                                                                            }
                                                                          }
                                                                        }
                                                                      }
                                                                    }
                                                                  }
                                                                }
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    //qDebug () << "Se busca la propiedad Name del elemento";
    //NameProperty *nameProperty = ( NameProperty * ) XsdElement->getProperty ( "NameProperty" );
    //if ( nameProperty != nullptr ) {

//      qDebug () << "El nombre del elemento es: " << nameProperty->getValue ();
//    }
  } else {

    //qDebug () << "El elemento actual no tiene propiedades";
  }
  const int elementListCount = XsdElement->getElementsList ().count ();
  if ( elementListCount > 0 ) {

    //qDebug () << "El elemento tiene " << elementListCount << " hijos";
    for ( int i = 0; i < elementListCount; i++ ) {

      this->listarElementos ( XsdElement->getElementsList ().at ( i ) );
    }
  } else {

    //qDebug () << "El elemento no tiene hijos";
  }*/
}
