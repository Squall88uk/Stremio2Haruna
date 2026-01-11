# Security Policy

## Supported Versions

We are committed to addressing security vulnerabilities in the following versions:

| Version | Supported          |
| ------- | ------------------ |
| 1.1.x   | :white_check_mark: |
| 1.0.x   | :x:                |
| < 1.0   | :x:                |

We recommend always using the latest version for the best security and features.

## Reporting a Vulnerability

We take security seriously. If you discover a security vulnerability in Stremio2Haruna, please report it responsibly.

### How to Report

**Please do NOT report security vulnerabilities through public GitHub issues.**

Instead, please report security vulnerabilities by:

1. **Email**: Contact the maintainer through GitHub's private vulnerability reporting feature
2. **Private Report**: Use GitHub's "Security" tab → "Report a vulnerability" (preferred method)

### What to Include

When reporting a vulnerability, please provide:

- A clear description of the vulnerability
- Steps to reproduce the issue
- Potential impact of the vulnerability
- Any suggested fixes (if you have them)
- Your contact information for follow-up

### What to Expect

After submitting a vulnerability report:

1. **Acknowledgment**: You will receive a response within 48 hours acknowledging receipt
2. **Assessment**: We will investigate and assess the severity and impact
3. **Updates**: You will receive regular updates on the progress
4. **Fix**: We will work on a fix and prepare a security release
5. **Disclosure**: Once fixed, we will coordinate public disclosure with you
6. **Credit**: You will receive credit for the discovery (unless you prefer to remain anonymous)

## Security Best Practices

When using Stremio2Haruna:

### Safe Usage
- Download releases only from the official GitHub repository
- Verify checksums (SHA256) of downloaded releases
- Keep your system and dependencies up to date

### Dependencies
- Ensure Qt6 is up to date with security patches
- Keep `wl-clipboard` and `kdotool` updated
- Use the latest stable version of KDE Plasma

### Permissions
- The application requires clipboard access via `wl-paste`
- The application can launch external processes (Haruna media player)
- The application uses D-Bus for system integration
- No network access is required or used

## Known Limitations

- This application is designed for single-user desktop environments
- It monitors clipboard content when Stremio is running
- It launches external applications with user-copied URLs
- It uses system tools (`wl-paste`, `kdotool`) which require appropriate permissions

## Security Updates

Security updates will be released as:
- Patch versions (e.g., 1.1.2) for minor security fixes
- Minor versions (e.g., 1.2.0) for moderate security improvements
- Security advisories will be published through GitHub Security Advisories

## Scope

This security policy applies to:
- The Stremio2Haruna application code
- Official binary releases
- Documentation that may impact security

This policy does NOT cover:
- Third-party dependencies (report to their respective projects)
- User system configuration issues
- Issues in Stremio or Haruna applications

## Contact

For security-related questions or concerns that are not vulnerabilities, you may open a public issue on GitHub.

---

Thank you for helping keep Stremio2Haruna and its users safe! 🛡️
