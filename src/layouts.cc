#include "layouts.h"

#include <QCoreApplication>
#include <QDir>
#include <QSettings>
#include <QStandardPaths>

#include "settings.h"

namespace layouts {

QStringList kLayoutGroups{"NavigationLeft", "OutputPanePlaceHolder",
                          "StatusBar"};

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

QStringList List() {
  const QDir app_config_dir(
      QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation));

  const auto ini_files{app_config_dir.entryList(
      QStringList() << "*.ini", QDir::Files | QDir::NoDotAndDotDot)};

  QStringList layouts_list;
  for (QString ini_file : ini_files) {
    const auto layout_name{QFileInfo(ini_file).completeBaseName()};
    layouts_list.append(layout_name);
  }

  return layouts_list;
}

}  // namespace layouts
