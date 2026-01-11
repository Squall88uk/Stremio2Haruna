#include "stremio2haruna.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  // Set application information
  QApplication::setApplicationName("Stremio2Haruna");
  QApplication::setApplicationVersion("1.2.0");
  QApplication::setOrganizationName("Stremio2Haruna");

  // Don't quit when last window closes (we're a tray app)
  QApplication::setQuitOnLastWindowClosed(false);

  // Create the main application object
  Stremio2Haruna stremio2haruna;

  return app.exec();
}
