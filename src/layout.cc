#include "layout.h"

#include <QCoreApplication>
#include <QSettings>

#include "settings.h"

namespace layout {

QStringList kLayoutGroups{"NavigationLeft", "OutputPanePlaceHolder"};

void Save(const QString& layout_name) {
  QSettings qt_settings(QSettings::IniFormat, QSettings::UserScope, "QtProject",
                        "QtCreator");

  QSettings settings_backup(QSettings::IniFormat, QSettings::UserScope,
                            QCoreApplication::applicationName(), layout_name);

  settings::CopyGroups(qt_settings, settings_backup, kLayoutGroups);
}

void Load(const QString& layout_name) {
  QSettings qt_settings(QSettings::IniFormat, QSettings::UserScope, "QtProject",
                        "QtCreator");

  QSettings settings_backup(QSettings::IniFormat, QSettings::UserScope,
                            QCoreApplication::applicationName(), layout_name);

  settings::CopyGroups(settings_backup, qt_settings, kLayoutGroups);
}

}  // namespace layout
