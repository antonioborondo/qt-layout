#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QCoreApplication>
#include <QString>

#include "layout.h"
#include "version.h"

int main(int argc, char** argv) {
  QCoreApplication app(argc, argv);

  QCoreApplication::setApplicationName("qtcreator-layout");
  QCoreApplication::setApplicationVersion(
      QString::fromStdString(kVersion.data()));

  QCommandLineParser parser;
  parser.addHelpOption();
  parser.addVersionOption();

  QCommandLineOption save_option({"s", "save"}, "Save layout.", "LAYOUT_NAME");
  parser.addOption(save_option);

  QCommandLineOption load_option({"l", "load"}, "Load layout.", "LAYOUT_NAME");
  parser.addOption(load_option);

  parser.process(app);

  if (parser.isSet(save_option)) {
    const auto layout_name{parser.value(save_option)};
    layout::Save(layout_name);
  } else if (parser.isSet(load_option)) {
    const auto layout_name{parser.value(load_option)};
    layout::Load(layout_name);
  } else {
    parser.showHelp();
  }

  return 0;
}
