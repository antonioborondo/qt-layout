#ifndef LAYOUTS_H_
#define LAYOUTS_H_

#include <QString>
#include <QStringList>

namespace layouts {

void Save(const QString& layout_name);

void Load(const QString& layout_name);

QStringList List();

}  // namespace layouts

#endif
