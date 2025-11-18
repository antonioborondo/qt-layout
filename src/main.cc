#include <iostream>

#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QCoreApplication>
#include <QString>

#include "layouts.h"
#include "version.h"

int main(int argc, char** argv) {
  QCoreApplication app(argc, argv);

  QCoreApplication::setApplicationName("qtcreator-layout");
  QCoreApplication::setApplicationVersion(kVersion);

  QCommandLineParser parser;
  parser.addHelpOption();
  parser.addVersionOption();

  QCommandLineOption save_option{{"s", "save"}, "Save layout.", "LAYOUT_NAME"};
  parser.addOption(save_option);

  QCommandLineOption restore_option{
      {"r", "restore"}, "Restore layout.", "LAYOUT_NAME"};
  parser.addOption(restore_option);

  QCommandLineOption delete_option{
      {"d", "delete"}, "Delete layout.", "LAYOUT_NAME"};
  parser.addOption(delete_option);

  QCommandLineOption list_option{{"l", "list"}, "List layouts."};
  parser.addOption(list_option);

  parser.process(app);

  if (parser.isSet(save_option)) {
    const auto layout_name{parser.value(save_option)};
    layouts::Save(layout_name);
  } else if (parser.isSet(restore_option)) {
    const auto layout_name{parser.value(restore_option)};
    layouts::Restore(layout_name);
  } else if (parser.isSet(delete_option)) {
    const auto layout_name{parser.value(delete_option)};
    layouts::Delete(layout_name);
  } else if (parser.isSet(list_option)) {
    const auto layouts_list{layouts::List()};
    std::cout << "Layouts:" << std::endl;
    for (const auto& layout : layouts_list) {
      std::cout << "- " << layout.toStdString() << std::endl;
    }
  } else {
    parser.showHelp();
  }

  return 0;
}
