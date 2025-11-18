#include "layouts.h"

#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QSettings>
#include <QStandardPaths>
#include <QString>
#include <QStringList>

#include "settings.h"

namespace layouts {

const QStringList kLayoutGroups{"NavigationLeft", "OutputPanePlaceHolder",
                                "StatusBar"};

void Save(const QString& layout_name) {
  QSettings qt_settings{QSettings::IniFormat, QSettings::UserScope, "QtProject",
                        "QtCreator"};

  QSettings settings_backup{QSettings::IniFormat, QSettings::UserScope,
                            QCoreApplication::applicationName(), layout_name};

  settings::CopyGroups(qt_settings, settings_backup, kLayoutGroups);
}

void Restore(const QString& layout_name) {
  QSettings qt_settings{QSettings::IniFormat, QSettings::UserScope, "QtProject",
                        "QtCreator"};

  QSettings settings_backup{QSettings::IniFormat, QSettings::UserScope,
                            QCoreApplication::applicationName(), layout_name};

  settings::CopyGroups(settings_backup, qt_settings, kLayoutGroups);
}

void Delete(const QString& layout_name) {
  const QDir app_config_dir{
      QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation)};
  const QString filename{layout_name + ".ini"};
  const QFileInfo file_info{app_config_dir, filename};
  QFile file{file_info.canonicalFilePath()};
  file.remove();
}

QStringList List() {
  const QDir app_config_dir{
      QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation)};

  const auto ini_files{app_config_dir.entryList(
      QStringList() << "*.ini", QDir::Files | QDir::NoDotAndDotDot)};

  QStringList layouts_list;
  for (const auto& ini_file : ini_files) {
    const auto layout_name{QFileInfo(ini_file).completeBaseName()};
    layouts_list.append(layout_name);
  }

  return layouts_list;
}

}  // namespace layouts
