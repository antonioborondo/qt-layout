#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <QSettings>
#include <QStringList>

namespace settings {

void CopyGroups(QSettings& settings_source, QSettings& settings_destination,
                const QStringList& settings_group_names);

}

#endif
