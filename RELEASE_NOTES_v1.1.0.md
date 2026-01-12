# Stremio2Haruna v1.1.0 Release Notes

## 🎉 New Features

### Configuration Dialog
- **User-configurable settings** accessible via left-click on system tray icon
- **Clipboard Polling Rate**: Adjust from 0.5s to 10.0s (default: 3.5s)
- **Launch Delay**: Adjust from 0.0s to 10.0s (default: 2.5s)
- Settings automatically saved and persist between application restarts
- User-friendly interface with seconds-based values and decimal precision

## 🔄 Changes

- Left-click on tray icon now opens configuration dialog
- Right-click on tray icon continues to show Enable/Disable and Quit menu
- Version bumped from 1.0.0 to 1.1.0

## 📦 Installation

### Binary Release (Recommended)
1. Download `Stremio2Haruna-v1.1.0-linux-x86_64.tar.gz`
2. Extract the archive:
   ```bash
   tar -xzf Stremio2Haruna-v1.1.0-linux-x86_64.tar.gz
   cd v1.1.0
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
sha256sum -c Stremio2Haruna-v1.1.0-linux-x86_64.tar.gz.sha256
```

Expected checksum: `40098ea83bcf4115a70bebe06ea0fce436c23d01893bce714ec3c4282afb4535`

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
1. **Configure**: Left-click the tray icon to adjust polling rate and launch delay
2. **Enable/Disable**: Right-click the tray icon to toggle functionality
3. **Use**: Copy URLs in Stremio and they'll automatically launch in Haruna

## 🐛 Bug Reports

Report issues at: https://github.com/Jen88uk/Stremio2Haruna/issues

## 📜 Full Changelog

### Added
- Configuration dialog with QDoubleSpinBox widgets for seconds-based input
- QSettings integration for persistent configuration storage
- Left-click handler on system tray icon
- Real-time application of setting changes
- Comprehensive documentation in README

### Modified
- Polling rate now configurable (previously hardcoded to 3.5s)
- Launch delay now configurable (previously hardcoded to 2.5s)
- Enhanced README with configuration instructions

### Technical Details
- New files: `configdialog.h`, `configdialog.cpp`
- Modified files: `stremio2haruna.h/cpp`, `main.cpp`, `CMakeLists.txt`, `README.md`
- Build system updated to version 1.1.0
- Settings stored in `~/.config/Stremio2Haruna/Stremio2Haruna.conf`

---

**Previous Release**: [v1.0.0](https://github.com/Jen88uk/Stremio2Haruna/releases/tag/v1.0.0)
