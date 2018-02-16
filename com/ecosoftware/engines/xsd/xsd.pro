#-------------------------------------------------
#
# Project created by QtCreator 2017-11-17T13:52:43
#
#-------------------------------------------------

QT       -= gui

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml xmlpatterns

TARGET = xsd
TEMPLATE = lib

DEFINES += XSD_LIBRARY

SOURCES += \
  Xsd.cpp \
  XsdEngine.cpp \
  XsdAttribute.cpp \
  core/ElementAbs.cpp \
  core/FacetAbs.cpp \
  core/PropertyAbs.cpp \
  core/TypeAbs.cpp \
  core/elements/All.cpp \
  core/elements/Alternative.cpp \
  core/elements/Annotation.cpp \
  core/elements/Any.cpp \
  core/elements/AnyAttribute.cpp \
  core/elements/AppInfo.cpp \
  core/elements/Assert.cpp \
  core/elements/Attribute.cpp \
  core/elements/AttributeGroup.cpp \
  core/elements/Choice.cpp \
  core/elements/ComplexContent.cpp \
  core/elements/ComplexType.cpp \
  core/elements/DefaultOpenContent.cpp \
  core/elements/Documentation.cpp \
  core/elements/Element.cpp \
  core/elements/Extension.cpp \
  core/elements/Field.cpp \
  core/elements/Group.cpp \
  core/elements/Import.cpp \
  core/elements/Include.cpp \
  core/elements/Key.cpp \
  core/elements/Keyref.cpp \
  core/elements/List.cpp \
  core/elements/Notation.cpp \
  core/elements/Opencontent.cpp \
  core/elements/Override.cpp \
  core/elements/Redefine.cpp \
  core/elements/Restriction.cpp \
  core/elements/Schema.cpp \
  core/elements/Selector.cpp \
  core/elements/Sequence.cpp \
  core/elements/SimpleContent.cpp \
  core/elements/SimpleType.cpp \
  core/elements/Union.cpp \
  core/elements/Unique.cpp \
  core/facets/AssertionsFacet.cpp \
  core/facets/EnumerationFacet.cpp \
  core/facets/ExplicitTimeZoneFacet.cpp \
  core/facets/FractionDigitsFacet.cpp \
  core/facets/LengthFacet.cpp \
  core/facets/MaxExclusiveFacet.cpp \
  core/facets/MaxInclusiveFacet.cpp \
  core/facets/MaxLengthFacet.cpp \
  core/facets/MinExclusiveFacet.cpp \
  core/facets/MinInclusiveFacet.cpp \
  core/facets/MinLengthFacet.cpp \
  core/facets/PatternFacet.cpp \
  core/facets/TotalDigitsFacet.cpp \
  core/facets/WhitespaceFacet.cpp \
  core/properties/AbstractProperty.cpp \
  core/properties/AppliesToEmptyProperty.cpp \
  core/properties/AttributeFormDefaultProperty.cpp \
  core/properties/BaseProperty.cpp \
  core/properties/BlockDefaultProperty.cpp \
  core/properties/BlockProperty.cpp \
  core/properties/DefaultAttributesApplyProperty.cpp \
  core/properties/DefaultAttributesProperty.cpp \
  core/properties/ElementFormDefaultProperty.cpp \
  core/properties/FinalDefaultProperty.cpp \
  core/properties/FinalProperty.cpp \
  core/properties/FixedProperty.cpp \
  core/properties/FormProperty.cpp \
  core/properties/IdProperty.cpp \
  core/properties/InheritableProperty.cpp \
  core/properties/ItemTypeProperty.cpp \
  core/properties/MaxOccursProperty.cpp \
  core/properties/MemberTypesProperty.cpp \
  core/properties/MinOccursProperty.cpp \
  core/properties/MixedProperty.cpp \
  core/properties/ModeProperty.cpp \
  core/properties/NameProperty.cpp \
  core/properties/NamespaceProperty.cpp \
  core/properties/NillableProperty.cpp \
  core/properties/NotNamespaceProperty.cpp \
  core/properties/NotQNameProperty.cpp \
  core/properties/ProcessContentsProperty.cpp \
  core/properties/PublicProperty.cpp \
  core/properties/ReferProperty.cpp \
  core/properties/RefProperty.cpp \
  core/properties/SchemaLocationProperty.cpp \
  core/properties/SourceProperty.cpp \
  core/properties/SubstitutionGroupProperty.cpp \
  core/properties/SystemProperty.cpp \
  core/properties/TargetNamespaceProperty.cpp \
  core/properties/TestProperty.cpp \
  core/properties/TypeProperty.cpp \
  core/properties/UseProperty.cpp \
  core/properties/VersionProperty.cpp \
  core/properties/XmlLangProperty.cpp \
  core/properties/XPathDefaultNamespaceProperty.cpp \
  core/properties/XPathProperty.cpp \
  core/types/AnyUriType.cpp \
  core/types/Base64BinaryType.cpp \
  core/types/BooleanType.cpp \
  core/types/ByteType.cpp \
  core/types/DateTimeStampType.cpp \
  core/types/DateTimeType.cpp \
  core/types/DateType.cpp \
  core/types/DayTimeDurationType.cpp \
  core/types/DecimalType.cpp \
  core/types/DoubleType.cpp \
  core/types/DurationType.cpp \
  core/types/EntitiesType.cpp \
  core/types/EntityType.cpp \
  core/types/FloatType.cpp \
  core/types/GDayType.cpp \
  core/types/GMonthDayType.cpp \
  core/types/GMonthType.cpp \
  core/types/GYearMonthType.cpp \
  core/types/GYearType.cpp \
  core/types/HexBinaryType.cpp \
  core/types/IdRefsType.cpp \
  core/types/IdRefType.cpp \
  core/types/IdType.cpp \
  core/types/IntegerType.cpp \
  core/types/IntType.cpp \
  core/types/LanguageType.cpp \
  core/types/LongType.cpp \
  core/types/NameType.cpp \
  core/types/NCNameType.cpp \
  core/types/NegativeIntegerType.cpp \
  core/types/NMTokensType.cpp \
  core/types/NMTokenType.cpp \
  core/types/NonNegativeIntegerType.cpp \
  core/types/NonPositiveIntegerType.cpp \
  core/types/NormalizedStringType.cpp \
  core/types/NotationType.cpp \
  core/types/PositiveIntegerType.cpp \
  core/types/QNameType.cpp \
  core/types/ShortType.cpp \
  core/types/StringType.cpp \
  core/types/TimeType.cpp \
  core/types/TokenType.cpp \
  core/types/UnsignedByteType.cpp \
  core/types/UnsignedIntType.cpp \
  core/types/UnsignedLongType.cpp \
  core/types/UnsignedShortType.cpp \
  core/types/YearMonthDurationType.cpp \
    core/properties/DefaultProperty.cpp \
    XsdElement.cpp \
    XsdFormCreator.cpp \
    XsdDialog.cpp

HEADERS += \
  xsd_global.h \
  Xsd.h \
  XsdEngine.h \
  core/ElementAbs.h \
  core/FacetAbs.h \
  core/PropertyAbs.h \
  core/TypeAbs.h \
  core/elements/All.h \
  core/elements/Alternative.h \
  core/elements/Annotation.h \
  core/elements/Any.h \
  core/elements/AnyAttribute.h \
  core/elements/AppInfo.h \
  core/elements/Assert.h \
  core/elements/Attribute.h \
  core/elements/AttributeGroup.h \
  core/elements/Choice.h \
  core/elements/ComplexContent.h \
  core/elements/ComplexType.h \
  core/elements/DefaultOpenContent.h \
  core/elements/Documentation.h \
  core/elements/Element.h \
  core/elements/Extension.h \
  core/elements/Field.h \
  core/elements/Group.h \
  core/elements/Import.h \
  core/elements/Include.h \
  core/elements/Key.h \
  core/elements/Keyref.h \
  core/elements/List.h \
  core/elements/Notation.h \
  core/elements/Opencontent.h \
  core/elements/Override.h \
  core/elements/Redefine.h \
  core/elements/Restriction.h \
  core/elements/Schema.h \
  core/elements/Selector.h \
  core/elements/Sequence.h \
  core/elements/SimpleContent.h \
  core/elements/SimpleType.h \
  core/elements/Union.h \
  core/elements/Unique.h \
  core/facets/AssertionsFacet.h \
  core/facets/EnumerationFacet.h \
  core/facets/ExplicitTimeZoneFacet.h \
  core/facets/FractionDigitsFacet.h \
  core/facets/LengthFacet.h \
  core/facets/MaxExclusiveFacet.h \
  core/facets/MaxInclusiveFacet.h \
  core/facets/MaxLengthFacet.h \
  core/facets/MinExclusiveFacet.h \
  core/facets/MinInclusiveFacet.h \
  core/facets/MinLengthFacet.h \
  core/facets/PatternFacet.h \
  core/facets/TotalDigitsFacet.h \
  core/facets/WhitespaceFacet.h \
  core/properties/AbstractProperty.h \
  core/properties/AppliesToEmptyProperty.h \
  core/properties/AttributeFormDefaultProperty.h \
  core/properties/BaseProperty.h \
  core/properties/BlockDefaultProperty.h \
  core/properties/BlockProperty.h \
  core/properties/DefaultAttributesApplyProperty.h \
  core/properties/DefaultAttributesProperty.h \
  core/properties/ElementFormDefaultProperty.h \
  core/properties/FinalDefaultProperty.h \
  core/properties/FinalProperty.h \
  core/properties/FixedProperty.h \
  core/properties/FormProperty.h \
  core/properties/IdProperty.h \
  core/properties/InheritableProperty.h \
  core/properties/ItemTypeProperty.h \
  core/properties/MaxOccursProperty.h \
  core/properties/MemberTypesProperty.h \
  core/properties/MinOccursProperty.h \
  core/properties/MixedProperty.h \
  core/properties/ModeProperty.h \
  core/properties/NameProperty.h \
  core/properties/NamespaceProperty.h \
  core/properties/NillableProperty.h \
  core/properties/NotNamespaceProperty.h \
  core/properties/NotQNameProperty.h \
  core/properties/ProcessContentsProperty.h \
  core/properties/PublicProperty.h \
  core/properties/ReferProperty.h \
  core/properties/RefProperty.h \
  core/properties/SchemaLocationProperty.h \
  core/properties/SourceProperty.h \
  core/properties/SubstitutionGroupProperty.h \
  core/properties/SystemProperty.h \
  core/properties/TargetNamespaceProperty.h \
  core/properties/TestProperty.h \
  core/properties/TypeProperty.h \
  core/properties/UseProperty.h \
  core/properties/VersionProperty.h \
  core/properties/XmlLangProperty.h \
  core/properties/XPathDefaultNamespaceProperty.h \
  core/properties/XPathProperty.h \
  core/types/AnyUriType.h \
  core/types/Base64BinaryType.h \
  core/types/BooleanType.h \
  core/types/ByteType.h \
  core/types/DateTimeStampType.h \
  core/types/DateTimeType.h \
  core/types/DateType.h \
  core/types/DayTimeDurationType.h \
  core/types/DecimalType.h \
  core/types/DoubleType.h \
  core/types/DurationType.h \
  core/types/EntitiesType.h \
  core/types/EntityType.h \
  core/types/FloatType.h \
  core/types/GDayType.h \
  core/types/GMonthDayType.h \
  core/types/GMonthType.h \
  core/types/GYearMonthType.h \
  core/types/GYearType.h \
  core/types/HexBinaryType.h \
  core/types/IdRefsType.h \
  core/types/IdRefType.h \
  core/types/IdType.h \
  core/types/IntegerType.h \
  core/types/IntType.h \
  core/types/LanguageType.h \
  core/types/LongType.h \
  core/types/NameType.h \
  core/types/NCNameType.h \
  core/types/NegativeIntegerType.h \
  core/types/NMTokensType.h \
  core/types/NMTokenType.h \
  core/types/NonNegativeIntegerType.h \
  core/types/NonPositiveIntegerType.h \
  core/types/NormalizedStringType.h \
  core/types/NotationType.h \
  core/types/PositiveIntegerType.h \
  core/types/QNameType.h \
  core/types/ShortType.h \
  core/types/StringType.h \
  core/types/TimeType.h \
  core/types/TokenType.h \
  core/types/UnsignedByteType.h \
  core/types/UnsignedIntType.h \
  core/types/UnsignedLongType.h \
  core/types/UnsignedShortType.h \
  core/types/YearMonthDurationType.h \
    core/properties/DefaultProperty.h \
    XsdAttribute.h \
    XsdElement.h \
    XsdFormCreator.h \
    XsdDialog.h

DESTDIR = ../

UI_DIR = ../../../../ui

win32:CONFIG(release, debug|release): LIBS += \
  -L$$OUT_PWD/../../ -lresources \
  -L$$OUT_PWD/../../ -lutils
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$OUT_PWD/../../ -lresources \
  -L$$OUT_PWD/../../ -lutils
else:unix: LIBS += \
  -L$$OUT_PWD/../../ -lresources \
  -L$$OUT_PWD/../../ -lutils

INCLUDEPATH += \
  $$PWD/../../resources \
  $$PWD/../../utils

DEPENDPATH += \
  $$PWD/../../resources \
  $$PWD/../../utils

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    DEFINICIONES_DE_ELEMENTOS.txt \
    DEFINICIONES_DE_DATATYPES.txt \
    DEFINICIONES_DE_FACETS.txt
