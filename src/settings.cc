#include "settings.h"

#include <QSettings>
#include <QStringList>

namespace {

void CopyGroup(QSettings& settings_source, QSettings& settings_destination,
               const QString& settings_group_name) {
  settings_source.beginGroup(settings_group_name);
  settings_destination.beginGroup(settings_group_name);

  const auto keys{settings_source.childKeys()};
  for (const QString& key : keys) {
    const auto value{settings_source.value(key)};
    settings_destination.setValue(key, value);
  }

  settings_source.endGroup();
  settings_destination.endGroup();
}

}  // namespace

namespace settings {

void CopyGroups(QSettings& settings_source, QSettings& settings_destination,
                const QStringList& settings_group_names) {
  for (const auto& settings_group_name : settings_group_names) {
    CopyGroup(settings_source, settings_destination, settings_group_name);
  }
  settings_destination.sync();
}

}  // namespace settings
