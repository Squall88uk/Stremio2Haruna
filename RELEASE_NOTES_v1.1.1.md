# Stremio2Haruna v1.1.1 Release Notes

## 🎉 New Features

### Enhanced Configuration Dialog
- **Enable Monitoring Checkbox**: Toggle monitoring directly from the settings dialog
- **Quit Application Button**: Close the application without needing the tray menu
- **Complete Control**: All core functionality accessible from a single interface

## 🐛 Bug Fixes

### Icon Stability
- **Fixed**: Tray icon no longer changes when toggling enabled/disabled state
- The application icon now remains consistent at all times

### Power Efficiency  
- **Fixed**: Clipboard polling timer now stops completely when disabled
- No background `wl-paste` polling when monitoring is off
- Significantly reduced CPU usage when disabled
- Application remains in background ready to be re-enabled

## 🔄 Changes

- Left-click on tray icon opens enhanced configuration dialog
- Right-click on tray icon continues to show Enable/Disable and Quit menu
- Enable/disable state synchronized between dialog and tray menu
- Version bumped from 1.1.0 to 1.1.1

## 📦 Installation

### Binary Release (Recommended)
1. Download `Stremio2Haruna-v1.1.1-linux-x86_64.tar.gz`
2. Extract the archive:
   ```bash
   tar -xzf Stremio2Haruna-v1.1.1-linux-x86_64.tar.gz
   cd v1.1.1
   ```
3. Run the application:
   ```bash
   ./stremio2haruna
   ```

### Optional: Install System-Wide
```bash
sudo cp stremio2haruna /usr/local/bin/
sudo cp Stremio2Haruna.png /usr/share/pixmaps/
sudo cp stremio2haruna.desktop ~/.local/share/applications/
```

## 🔐 Verification

Verify the download integrity using SHA256:
```bash
sha256sum -c Stremio2Haruna-v1.1.1-linux-x86_64.tar.gz.sha256
```

Expected checksum: `c0178b2dcbfdaf7af66df8b9f06e39b648bce55eceb9fd1fec44063e86769763`

## ⚙️ System Requirements

- **OS**: Linux with Wayland (tested on CachyOS)
- **Desktop Environment**: KDE Plasma
- **Dependencies**:
  - Qt6 (Core, Widgets, Gui, DBus)
  - wl-clipboard
  - kdotool
  - Stremio
  - Haruna media player

## 📝 Usage

After starting the application:
1. **Configure**: Left-click the tray icon to access all settings
   - Adjust polling rate and launch delay
   - Enable/disable monitoring with a checkbox
   - Quit the application with a button click
2. **Quick Toggle**: Right-click the tray icon for fast enable/disable
3. **Use**: Copy URLs in Stremio and they'll automatically launch in Haruna

## 🐛 Bug Reports

Report issues at: https://github.com/Jen88uk/Stremio2Haruna/issues

## 📜 Full Changelog

### Added (v1.1.1)
- Enable Monitoring checkbox in configuration dialog
- Quit Application button in configuration dialog
- State synchronization between dialog and tray menu checkbox

### Fixed (v1.1.1)
- Tray icon no longer changes when toggling enabled state (keeps original icon)
- Clipboard polling timer stops when disabled (no background wl-paste activity)
- Improved CPU efficiency when monitoring is disabled

### Added (v1.1.0)
- Configuration dialog with QDoubleSpinBox widgets for seconds-based input
- QSettings integration for persistent configuration storage
- Left-click handler on system tray icon
- Real-time application of setting changes
- Comprehensive documentation in README

### Modified (v1.1.0)
- Polling rate now configurable (previously hardcoded to 3.5s)
- Launch delay now configurable (previously hardcoded to 2.5s)
- Enhanced README with configuration instructions

### Technical Details
- Modified files: `configdialog.h/cpp`, `stremio2haruna.cpp`, `CMakeLists.txt`, `main.cpp`
- Settings stored in `~/.config/Stremio2Haruna/Stremio2Haruna.conf`
- Timer management improved for better resource efficiency

---

**Previous Releases**:
- [v1.1.0](https://github.com/Jen88uk/Stremio2Haruna/releases/tag/v1.1.0)
- [v1.0.0](https://github.com/Jen88uk/Stremio2Haruna/releases/tag/v1.0.0)
