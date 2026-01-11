# Stremio2Haruna v1.2.0 Release Notes

**Release Date**: January 11, 2026

## 🎉 New Feature

### Clipboard URL Clearing on Launch

Starting with v1.2.0, Stremio2Haruna now **automatically clears URLs from the clipboard when the application launches**. This prevents unwanted Haruna launches from URLs that were copied before starting the application.

**How it works:**
- On startup, the application checks the clipboard for URLs
- If a URL is detected, it's automatically cleared
- This process repeats until no URLs remain
- Normal clipboard monitoring then begins
- Non-URL clipboard content is preserved

**Why this matters:**
- Prevents false triggers from previously copied streaming URLs
- Ensures clean application startup
- Works seamlessly with clipboard managers (KDE Klipper, copyq, etc.)

> [!WARNING]
> **Important**: This application now clears URLs from your clipboard on launch. If you have a URL you want to keep, ensure it's saved elsewhere before launching Stremio2Haruna.

## 🔧 Technical Improvements

### Clipboard Manager Compatibility

- Fixed infinite loop issue when clipboard managers auto-restore content
- Solution: Replace URL with empty string instead of using `--clear` flag
- Successfully tested with KDE Klipper and clipboard history features

### Clean Operation

- Removed debug logging for silent operation
- No terminal output during normal use
- Application runs completely in the background

## 📝 Version Details

- **Version**: 1.2.0
- **Previous Version**: 1.1.2
- **Release Type**: Minor version bump (new feature added)

## 🔄 Upgrade Notes

### Breaking Changes
None. This release is fully backward compatible.

### Behavioral Changes
- **Clipboard clearing on launch**: URLs in clipboard are now cleared when the application starts
- This is the only behavioral change from v1.1.2

## 📦 Installation

Same installation process as previous versions:

```bash
# Build
mkdir build && cd build
cmake ..
make

# Install (optional)
sudo make install

# Or install to user directory
cp stremio2haruna ~/.local/bin/
cp stremio2haruna.desktop ~/.local/share/applications/
update-desktop-database ~/.local/share/applications/
```

## 🧪 Testing

All features have been thoroughly tested:
- ✅ URL clearing on launch
- ✅ Normal operation after clearing
- ✅ Non-URL content preservation
- ✅ Clipboard manager compatibility
- ✅ Silent operation (no debug output)

## 📋 Files Changed

### Modified Files
- `stremio2haruna.h` - Added `clearClipboardUrls()` method declaration
- `stremio2haruna.cpp` - Implemented clipboard URL clearing logic
- `main.cpp` - Updated version to 1.2.0
- `README.md` - Added clipboard clearing documentation and warnings

### New Files
- `RELEASE_NOTES_v1.2.0.md` - This document

## 🐛 Known Issues

None reported.

## 🙏 Acknowledgments

Thanks to all users who tested the clipboard clearing feature and provided feedback on the clipboard manager compatibility!

---

**Full Changelog**: v1.1.2...v1.2.0
