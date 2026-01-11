#ifndef STREMIO2HARUNA_H
#define STREMIO2HARUNA_H

#include "configdialog.h"
#include <QAction>
#include <QClipboard>
#include <QMenu>
#include <QObject>
#include <QProcess>
#include <QSystemTrayIcon>
#include <QTimer>

class Stremio2Haruna : public QObject {
  Q_OBJECT

public:
  explicit Stremio2Haruna(QObject *parent = nullptr);
  ~Stremio2Haruna();

private slots:
  void onClipboardChanged();
  void onToggleEnabled(bool enabled);
  void onQuit();
  void checkClipboard(); // Timer-based polling
  void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);
  void openConfigDialog();

private:
  bool isStremioActive();
  bool isValidUrl(const QString &text);
  void launchHaruna(const QString &url);
  void setupSystemTray();
  void loadSettings();
  void saveSettings();
  void clearClipboardUrls();

  QSystemTrayIcon *m_trayIcon;
  QMenu *m_trayMenu;
  QAction *m_enabledAction;
  QAction *m_quitAction;
  QClipboard *m_clipboard;
  bool m_enabled;
  QTimer *m_clipboardTimer;
  QString m_lastClipboardText;
  QProcess *m_harunaProcess;
  int m_pollingRate; // milliseconds
  int m_launchDelay; // milliseconds
};

#endif // STREMIO2HARUNA_H
