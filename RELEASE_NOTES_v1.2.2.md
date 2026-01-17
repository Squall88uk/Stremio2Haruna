# Stremio2Haruna v1.2.2 Release Notes

**Release Date**: January 17, 2026

## 🐛 Critical Bug Fix

### Fixed: Infinite Haruna Loop When Opening Config Dialog

This patch release fixes a critical bug that caused Haruna to repeatedly open and close in an infinite loop when the config dialog was opened, regardless of user interaction.

**Symptoms of the bug:**
- Opening config dialog triggered infinite Haruna launches
- Application became unresponsive
- Required force-killing the application
- IOT instruction crash on termination

**Root Cause:**
The application had TWO clipboard monitoring paths that both could trigger Haruna launches:
1. `checkClipboard()` - Timer-based polling (every 3.5 seconds)
2. `onClipboardChanged()` - Qt clipboard signal handler

When the config dialog opened, the `QClipboard::dataChanged` signal would fire (due to focus changes), which triggered `onClipboardChanged()` → `launchHaruna()`. The launched Haruna process would immediately exit (or fail), triggering the `finished` signal, which would restart clipboard monitoring, firing `dataChanged` again, creating an infinite loop.

**The previous fix attempts (v1.2.2-alpha) failed because:**
- Only added protection to `checkClipboard()` but forgot `onClipboardChanged()`
- Complex timer management caused race conditions and crashes
- Process deletion timing issues caused IOT instruction crashes

## 🔧 Technical Details

### Files Modified

- **stremio2haruna.h**
  - Added `bool m_dialogOpen;` flag (line 49)

- **stremio2haruna.cpp**
  - Constructor: Initialize `m_dialogOpen = false` (line 19)
  - `onClipboardChanged()`: Added early return if dialog is open (lines 77-80)
  - `checkClipboard()`: Added early return if dialog is open (lines 289-292)
  - `openConfigDialog()`: Set/clear dialog flag (lines 372, 407)

### The Fix

**Simple flag-based protection:**

```cpp
// In header
bool m_dialogOpen;  // Prevents processing while dialog is open

// In constructor
m_dialogOpen(false)

// In BOTH clipboard handlers
void Stremio2Haruna::onClipboardChanged() {
    if (m_dialogOpen) {
        return;  // Skip all processing
    }
    // ... normal logic ...
}

void Stremio2Haruna::checkClipboard() {
    if (m_dialogOpen) {
        return;  // Skip all processing
    }
    // ... normal logic ...
}

// In dialog open/close
void Stremio2Haruna::openConfigDialog() {
    m_dialogOpen = true;  // Block clipboard processing
    // ... show dialog ...
    m_dialogOpen = false; // Resume processing
}
```

**Why this works:**
- Protects BOTH code paths that can trigger Haruna
- No complex timer manipulation
- No race conditions with Qt's event loop
- Qt signals can fire, but immediately return
- Simple, clean, and foolproof

## 📝 Version Details

- **Version**: 1.2.2
- **Previous Version**: 1.2.1
- **Release Type**: Patch (critical bug fix)

## 🔄 Upgrade Notes

### Breaking Changes
None. This release is fully backward compatible.

### Behavioral Changes
- Config dialog now completely blocks clipboard monitoring while open (intentional fix)
- No other behavioral changes

### Upgrade Recommendation
> [!IMPORTANT]
> **All users should upgrade immediately.** This fixes a critical bug that makes the config dialog completely unusable and requires force-killing the application.

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
mkdir -p ~/.local/bin ~/.local/share/applications ~/.local/share/icons
cp build/stremio2haruna ~/.local/bin/
cp stremio2haruna.desktop ~/.local/share/applications/
cp Stremio2Haruna.png ~/.local/share/icons/
update-desktop-database ~/.local/share/applications/
```

## 🧪 Testing

### Verified Scenarios

#### ✅ Config Dialog Opens Normally
1. Copy a valid streaming URL to clipboard
2. Open config dialog (left-click tray icon)
3. **Result**: Dialog opens normally, no Haruna launches

#### ✅ Toggle Works Normally  
1. Open config dialog
2. Toggle "Enable Monitoring" checkbox
3. **Result**: Checkbox toggles, no infinite loop

#### ✅ Normal Operation Still Works
1. Clear clipboard
2. Start Stremio
3. Copy a streaming URL from Stremio
4. **Result**: Haruna launches normally after delay

## 🐛 Known Issues

None reported.

## 📋 What's New in v1.2.x Series

- **v1.2.2** (this release) - Config dialog infinite loop fixes
- **v1.2.1** - Quit bug fix (application hang on quit)
- **v1.2.0** - Clipboard URL clearing on launch
- See previous release notes for details

## ⚙️ System Requirements

- **OS**: Linux with Wayland
- **Desktop Environment**: KDE Plasma (or compatible)
- **Dependencies**:
  - Qt6 (Core, Widgets, Gui, DBus)
  - wl-clipboard
  - kdotool
  - Stremio
  - Haruna media player

---

**Full Changelog**: v1.2.1...v1.2.2

**Previous Releases**:
- [v1.2.1](RELEASE_NOTES_v1.2.1.md) - Quit bug fix
- [v1.2.0](RELEASE_NOTES_v1.2.0.md) - Clipboard URL clearing
- [v1.1.2](RELEASE_NOTES_v1.1.2.md) - Security improvements
