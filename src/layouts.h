#ifndef LAYOUTS_H_
#define LAYOUTS_H_

#include <QString>
#include <QStringList>

namespace layouts {

void Save(const QString& layout_name);

void Restore(const QString& layout_name);

void Delete(const QString& layout_name);

QStringList List();

}  // namespace layouts

#endif
