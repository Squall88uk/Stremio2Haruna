# Stremio2Haruna v1.2.1 Release Notes

**Release Date**: January 15, 2026

## 🐛 Critical Bug Fix

### Fixed: Application Hang and Infinite Loop on Quit

This patch release fixes a critical bug that caused the application to hang and enter an infinite loop when quitting from the configuration dialog.

**Symptoms of the bug:**
- Application becomes unresponsive when clicking "Quit Application"
- Haruna launches the most recent URL unexpectedly
- Haruna repeatedly opens and closes in an infinite loop
- Configuration dialog stops responding
- Requires force-killing the application

**Root Cause:**
A race condition between the clipboard monitoring timer and the application quit sequence. When quitting, the clipboard timer continued firing, triggering new Haruna launches while the application was shutting down.

**The Fix:**
Implemented comprehensive cleanup logic in the quit handler:

1. ✅ Stops clipboard timer immediately
2. ✅ Disables monitoring flag to prevent in-flight callbacks
3. ✅ Disconnects all clipboard signals
4. ✅ Terminates Haruna process if running (graceful then forced)
5. ✅ Prevents timer restart during shutdown

This ensures clean, orderly shutdown without race conditions.

## 🔧 Technical Details

### Files Modified

- **stremio2haruna.cpp**
  - Enhanced `onQuit()` method with 5-step cleanup sequence (lines 114-153)
  - Added safety check in `launchHaruna()` to prevent timer restart during shutdown (lines 225-233)
  - Total changes: ~40 lines of defensive cleanup code

### Code Improvements

**Before:**
```cpp
void Stremio2Haruna::onQuit() { 
    QApplication::quit(); 
}
```

**After:**
```cpp
void Stremio2Haruna::onQuit() {
  // 1. Stop clipboard monitoring immediately
  if (m_clipboardTimer) {
    m_clipboardTimer->stop();
  }
  
  // 2. Disable monitoring flag
  m_enabled = false;
  
  // 3. Disconnect clipboard signals
  if (m_clipboard) {
    disconnect(m_clipboard, &QClipboard::dataChanged, this,
               &Stremio2Haruna::onClipboardChanged);
    disconnect(m_clipboard, &QClipboard::selectionChanged, this,
               &Stremio2Haruna::onClipboardChanged);
  }
  
  // 4. Terminate Haruna process
  if (m_harunaProcess) {
    disconnect(m_harunaProcess, nullptr, this, nullptr);
    if (m_harunaProcess->state() != QProcess::NotRunning) {
      m_harunaProcess->terminate();
      if (!m_harunaProcess->waitForFinished(1000)) {
        m_harunaProcess->kill();
        m_harunaProcess->waitForFinished(500);
      }
    }
  }
  
  // 5. Now safe to quit
  QApplication::quit();
}
```

## 📝 Version Details

- **Version**: 1.2.1
- **Previous Version**: 1.2.0
- **Release Type**: Patch (bug fix only)

## 🔄 Upgrade Notes

### Breaking Changes
None. This release is fully backward compatible.

### Behavioral Changes
- **Improved quit reliability**: Application now shuts down cleanly from config dialog
- No other behavioral changes

### Upgrade Recommendation
> [!IMPORTANT]
> **All users experiencing quit issues should upgrade immediately.** This fixes a critical bug that could require force-killing the application.

## 📦 Installation

### Quick Install (Update Existing Installation)

```bash
# Navigate to project directory
cd ~/Projects/Stremio2Haruna

# Pull latest changes (if using git)
git pull

# Build
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release -j$(nproc)

# Install to user directory
cp build/stremio2haruna ~/.local/bin/

# Restart the application
killall stremio2haruna
stremio2haruna &
```

### Fresh Installation

```bash
# Clone repository
git clone https://github.com/Jen88uk/Stremio2Haruna.git
cd Stremio2Haruna

# Build
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release -j$(nproc)

# Install
cp build/stremio2haruna ~/.local/bin/
cp stremio2haruna.desktop ~/.local/share/applications/
cp Stremio2Haruna.png ~/.local/share/icons/
update-desktop-database ~/.local/share/applications/
```

## 🧪 Testing

### Validation Steps

To verify the fix works correctly, test these scenarios:

1. **Normal quit flow**:
   - Open config dialog (left-click tray icon)
   - Click "Quit Application"
   - ✅ Verify clean shutdown with no hanging

2. **Quit with Haruna running**:
   - Copy a URL to launch Haruna
   - While Haruna is running, open config dialog
   - Click "Quit Application"
   - ✅ Verify both Haruna and app terminate cleanly

3. **Quit with URL in clipboard**:
   - Ensure clipboard contains a valid URL
   - Open config dialog
   - Click "Quit Application"
   - ✅ Verify app quits without launching Haruna again

4. **Rapid quit attempts**:
   - Click quit during active clipboard polling
   - ✅ Verify no race conditions occur

All test scenarios passed successfully ✅

## 🐛 Known Issues

None reported.

## 📋 What's New in v1.2.x Series

- **v1.2.1** (this release) - Critical quit bug fix
- **v1.2.0** - Clipboard URL clearing on launch
- See [RELEASE_NOTES_v1.2.0.md](RELEASE_NOTES_v1.2.0.md) for details

## ⚙️ System Requirements

- **OS**: Linux with Wayland (tested on CachyOS)
- **Desktop Environment**: KDE Plasma
- **Dependencies**:
  - Qt6 (Core, Widgets, Gui, DBus)
  - wl-clipboard
  - kdotool
  - Stremio
  - Haruna media player

---

**Full Changelog**: v1.2.0...v1.2.1

**Previous Releases**:
- [v1.2.0](RELEASE_NOTES_v1.2.0.md) - Clipboard URL clearing
- [v1.1.2](RELEASE_NOTES_v1.1.2.md) - Security improvements
- [v1.1.1](RELEASE_NOTES_v1.1.1.md) - Enhanced configuration dialog
- [v1.1.0](RELEASE_NOTES_v1.1.0.md) - Configurable settings
