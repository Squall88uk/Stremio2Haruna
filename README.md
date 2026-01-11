# Stremio2Haruna

A Qt6-based system tray application for KDE Plasma (Wayland) that automatically detects when you copy URLs in Stremio and launches them in Haruna media player.

## Features

- 🧹 **Clears URLs from clipboard on launch** (prevents unwanted auto-launches from previously copied content)
- 🎯 Monitors clipboard for URLs when Stremio is running
- ⚙️ **Configurable polling rate and launch delay via settings dialog**
- ✅ **Enable/Disable monitoring from settings dialog or tray menu**
- 🚪 **Quit application directly from settings dialog**
- ⏱️ Default 2.5s delay before launching Haruna (gives you time to close/pause Stremio)
- 🎬 Automatically pauses monitoring while Haruna is playing (no fullscreen interference)
- 🔄 Auto-resumes monitoring when you close Haruna
- 💤 Stops all background activity when disabled (saves CPU)
- 🚀 Launches Haruna media player with the copied URL
- 💻 Native Qt6 application optimized for KDE Plasma on Wayland

> [!WARNING]
> **Clipboard Behavior**: Starting with v1.2.0, this application **automatically clears any URLs from your clipboard when it launches**. This prevents the application from detecting and processing URLs that were copied before the app started. Non-URL clipboard content is preserved.

## System Requirements

- **OS**: Linux with Wayland (tested on CachyOS)
- **Desktop Environment**: KDE Plasma
- **Dependencies**:
  - Qt6 (Core, Widgets, Gui, DBus)
  - wl-clipboard (for Wayland clipboard access)
  - kdotool (for window detection on Wayland)
  - CMake (for building)
  - Stremio (the application to monitor)
  - Haruna (media player to launch)

## Prerequisites

### 1. Install kdotool (for window detection)

`kdotool` is required for detecting the active window on KDE Plasma Wayland.

Install from AUR:
```bash
yay -S kdotool-git
```

Or manually from GitHub: https://github.com/jinliu/kdotool

### 2. Install wl-clipboard (for clipboard access)

`wl-clipboard` is required for Qt to access the Wayland clipboard.

```bash
sudo pacman -S wl-clipboard
```

## Building

```bash
# Create build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build
make

# Optionally install
sudo make install
```

## Usage

1. Start the application:
   ```bash
   ./stremio2haruna
   ```

2. The application will run in the background with a system tray icon

3. **Configure settings (v1.1.0+):**
   - Left-click the tray icon to open settings dialog
   - Adjust **Clipboard Polling Rate** (0.5s - 10.0s, default: 3.5s)
   - Adjust **Launch Delay** (0.0s - 10.0s, default: 2.5s)
   - Toggle **Enable Monitoring** checkbox to enable/disable
   - Click **Quit Application** to close the app
   - Click Save to apply changes
   - Settings are saved automatically and persist between sessions

4. Right-click the tray icon to:
   - Toggle enabled/disabled state
   - Quit the application

5. When enabled and Stremio is running:
   - Copy any URL to your clipboard (e.g., from Stremio's video player menu)
   - The app will wait (configurable delay, default 2.5s), then launch Haruna with the URL

## How It Works

1. **Clipboard URL Clearing on Launch**: On startup, checks clipboard for URLs and clears them to prevent false triggers from previously copied content
2. **Clipboard Monitoring**: Uses `wl-paste` polling (default every 3.5s, configurable) to detect clipboard changes on Wayland
3. **Stremio Detection**: Uses `kdotool` to check if Stremio is running
4. **URL Validation**: Checks if the clipboard content is a valid URL with supported schemes  
5. **Delay**: Waits (default 2.5s, configurable) to give you time to close/pause Stremio
6. **Haruna Launch**: Launches Haruna media player with the URL and monitors the process
7. **Auto Pause/Resume**: Stops clipboard polling while Haruna is running (prevents fullscreen glitches), automatically resumes when you close Haruna
8. **Persistent Settings**: All configuration is saved using QSettings and persists between application restarts

## Known Limitations

- **KDE-specific**: Uses `kdotool` which requires KDE Plasma/KWin
- **Wayland-only**: Designed for Wayland; X11 may work but is untested
- **Polling interval**: Uses polling-based clipboard detection (configurable from 0.5s to 10s)

## Troubleshooting

### Clipboard not detected
- Ensure `wl-clipboard` is installed: `which wl-paste`
- The default polling interval is 3.5s - you can adjust this in settings (left-click tray icon)
- Try reducing the polling rate for faster detection

### Stremio detection not working
- Ensure `kdotool` is installed: `which kdotool`
- Test manually: `kdotool search --class com.stremio.stremio`

### Haruna doesn't launch
- Verify Haruna is installed: `which haruna`
- Test manually: `haruna <some-url>`

## License

This project is licensed under the **GNU General Public License v3.0** (GPLv3).

You are free to:
- Use this software for any purpose
- Study and modify the source code
- Distribute copies
- Distribute modified versions

All derivative works must also be licensed under GPLv3. See the [LICENSE](LICENSE) file for full details.

## Contributing

Contributions, bug reports, and feature requests are welcome! Please read our [Contributing Guidelines](CONTRIBUTING.md) before submitting pull requests.

For questions or discussions, feel free to open an issue on GitHub.

