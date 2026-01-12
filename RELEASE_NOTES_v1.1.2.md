# Stremio2Haruna v1.1.2 Release Notes

## 🔒 Security Patch Release

This release focuses entirely on security improvements and vulnerability fixes.

## 🛡️ Security Improvements

### Defense in Depth - URL Validation
- **Added double-layer URL validation** before launching external applications
- **Explicit rejection of `file://` URLs** to prevent local file access
- **Restricted URL schemes** to network protocols only (http, https, rtmp, rtsp)
- **Proper URL encoding** using `QUrl::toString()` before process execution

### Input Validation & Sanitization
- **Added bounds checking** for loaded settings (prevents integer overflow)
  - Polling rate: 500ms - 10,000ms
  - Launch delay: 0ms - 10,000ms
- **Warning logs** when configuration values are clamped for security

### Process Timeout Handling
- **Added timeout error handling** for `kdotool` process (500ms timeout)
- **Added timeout error handling** for `wl-paste` process (100ms timeout)
- **Automatic process termination** on timeout to prevent resource leaks
- **Early return** on process failures with warning logs

### Security Logging
- Added comprehensive security event logging:
  - Rejected unsafe URLs
  - Rejected non-network URL schemes
  - Clamped configuration values
  - Process timeouts

## 📦 Installation

### Binary Release (Recommended)
1. Download `Stremio2Haruna-v1.1.2-linux-x86_64.tar.gz`
2. Extract the archive:
   ```bash
   tar -xzf Stremio2Haruna-v1.1.2-linux-x86_64.tar.gz
   cd v1.1.2
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
sha256sum -c Stremio2Haruna-v1.1.2-linux-x86_64.tar.gz.sha256
```

## 📜 Full Changelog

### Security Fixes (v1.1.2)
- **Fixed**: Potential command injection via malicious URLs
- **Fixed**: Integer overflow in settings configuration
- **Fixed**: Process timeout handling (kdotool, wl-paste)
- **Fixed**: Missing validation for file:// URLs
- **Added**: Double-layer URL validation in `launchHaruna()`
- **Added**: Bounds checking with `qBound()` for all settings
- **Added**: Timeout error handling for all external processes
- **Added**: Comprehensive security event logging

### Technical Details
- Modified: `stremio2haruna.cpp`
  - Enhanced `isValidUrl()` - explicit file:// rejection
  - Enhanced `launchHaruna()` - additional URL sanitization
  - Enhanced `loadSettings()` - bounds validation
  - Enhanced `isStremioActive()` - timeout handling
  - Enhanced `checkClipboard()` - timeout handling
- Security code additions: 57 lines of validation and error handling
- All security issues identified in internal audit resolved

## 📊 Security Rating

**Previous**: B+ (Good)  
**Current**: A (Excellent)

All known security vulnerabilities have been addressed.

## ⚙️ System Requirements

- **OS**: Linux with Wayland (tested on CachyOS)
- **Desktop Environment**: KDE Plasma
- **Dependencies**:
  - Qt6 (Core, Widgets, Gui, DBus)
  - wl-clipboard
  - kdotool
  - Stremio
  - Haruna media player

## 🐛 Bug Reports

Report security issues privately through GitHub's Security tab.  
Report other issues at: https://github.com/Jen88uk/Stremio2Haruna/issues

---

**Previous Releases**:
- [v1.1.1](https://github.com/Jen88uk/Stremio2Haruna/releases/tag/v1.1.1) - Enhanced Configuration Dialog
- [v1.1.0](https://github.com/Jen88uk/Stremio2Haruna/releases/tag/v1.1.0) - Configurable Settings
- [v1.0.0](https://github.com/Jen88uk/Stremio2Haruna/releases/tag/v1.0.0) - Initial Release

**Upgrade Recommendation**: All users are strongly encouraged to upgrade to v1.1.2 for security improvements.
