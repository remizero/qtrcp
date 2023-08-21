#include "AppSettings.h"


using namespace NAMESPACE_LIBRARY_APP;


/*QSettings AppSettings::loadSettingsXML ( QString fileName ) {
  
  const QSettings::Format XmlFormat = QSettings::registerFormat ( "xml", ( QSettings::ReadFunc ) AppSettings::readXmlFile, ( QSettings::WriteFunc ) AppSettings::writeXmlFile );
  QSettings settings ( AppPaths::getInstance ().getApplicationDataPath () + fileName, XmlFormat );

  return settings;
}*/

QSettings::Format AppSettings::getXmlFormat () {

  const QSettings::Format XmlFormat = QSettings::registerFormat ( "xml", ( QSettings::ReadFunc ) AppSettings::readXmlFile, ( QSettings::WriteFunc ) AppSettings::writeXmlFile );
  return XmlFormat;
}

bool AppSettings::readXmlFile ( QIODevice &device, QSettings::SettingsMap &map ) {

  QXmlStreamReader xmlReader ( &device );
  QStringList elements;
  while ( !xmlReader.isEndDocument () && !xmlReader.hasError () ) {

    xmlReader.readNext ();
    if ( xmlReader.isStartElement () && xmlReader.name ().compare ( QString::fromUtf8 ( "settings" )  ) != 0 ) {

      elements.append ( xmlReader.name ().toString () );

    } else if ( xmlReader.isEndElement () ) {

      if ( !elements.isEmpty () ) {

        elements.removeLast ();
      }
    } else if ( xmlReader.isCharacters () && !xmlReader.isWhitespace () ) {

      QString key;
      for ( int i = 0; i < elements.size (); i++ ) {

        if ( i != 0 ) {

          key += "/";
        }
        key += elements.at ( i ).toUtf8 ();
      }
      map [ key ] = xmlReader.text ().toString ();
    }
  }
  if ( xmlReader.hasError () ) {

    qWarning () << xmlReader.errorString ();
    return false;
  }
  return true;
}

void AppSettings::saveRecent ( const QString &recentGroup, int maxItemsRecentGroup, const QString &key, const QString &value ) {

  const QSettings::Format XmlFormat = QSettings::registerFormat ( "xml", ( QSettings::ReadFunc ) AppSettings::readXmlFile, ( QSettings::WriteFunc ) AppSettings::writeXmlFile );
  QSettings settings ( NAMESPACE_LIBRARY_APP::AppPaths::getInstance ().getApplicationConfigPath () + "config.xml", XmlFormat );

  settings.beginGroup ( recentGroup );
  QStringList recentListKeys = settings.childKeys ();
  QStringList recentListValues;
  for ( int i = 0; i < recentListKeys.count (); i++ ) {

    recentListValues.append ( settings.value ( recentListKeys.at ( i ) ).toString () );
  }
  settings.endGroup ();

  if ( recentListValues.count () < maxItemsRecentGroup ) {

    if ( recentListValues.contains ( value ) ) {

      int indexValue = recentListValues.indexOf ( value );
      recentListKeys.removeAt ( indexValue );
      recentListValues.removeAt ( indexValue );
      settings.remove ( recentGroup );
    }
    settings.setValue ( recentGroup + "/" + key + "0", value );
    for ( int i = 0; i < recentListKeys.count (); i++ ) {

      settings.setValue ( recentGroup + "/" + key + QString::number ( i + 1 ), recentListValues.at ( i ) );
    }
  } else {

    settings.remove ( recentGroup );
    settings.setValue ( recentGroup + "/" + key + "0", value );
    for ( int i = 1; i < recentListKeys.count (); i++ ) {

      settings.setValue ( recentGroup + "/" + key + QString::number ( i + 1 ), recentListValues.at ( i ) );
    }
  }
}

void AppSettings::saveRecentFile ( const QString &value ) {

  AppSettings::saveRecent ( "recentFiles", 20, "file", value );
}

void AppSettings::saveRecentProject ( const QString &value ) {

  AppSettings::saveRecent ( "recentProjects", 10, "project", value );
}

bool AppSettings::writeXmlFile ( QIODevice &device, const QSettings::SettingsMap &map ) {

  QXmlStreamWriter xmlWriter ( &device );
  xmlWriter.setAutoFormatting ( true );
  xmlWriter.writeStartDocument ();
  xmlWriter.writeStartElement ( "settings" );

  QStringList prev_elements;
  QSettings::SettingsMap::ConstIterator map_i;
  for ( map_i = map.begin (); map_i != map.end (); map_i++ ) {

    QStringList elements = map_i.key ().split ( "/" );
    int x = 0;
    while ( x < prev_elements.size () && elements.at ( x ) == prev_elements.at ( x ) ) {

      x++;
    }
    for ( int i = prev_elements.size () - 1; i >= x; i-- ) {

      xmlWriter.writeEndElement ();
    }
    for ( int i = x; i < elements.size (); i++ ) {

      xmlWriter.writeStartElement ( elements.at ( i ) );
    }
    xmlWriter.writeCharacters ( map_i.value ().toString () );
    prev_elements = elements;
  }
  for ( int i = 0; i < prev_elements.size (); i++ ) {

    xmlWriter.writeEndElement ();
  }
  xmlWriter.writeEndElement ();
  xmlWriter.writeEndDocument ();
  return true;
}
