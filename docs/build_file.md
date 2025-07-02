# Shellmake Build System

Shellmake uses a build configuration file (in JSON format) to guide how a script should be preprocessed across different Linux environments.

## Purpose

The build file defines:
- Which distros the script targets
- Which distros to exclude
- Required Shellmake version
- Script output name
- Runtime conditions (e.g., required variables, root access)
- Optional shell environment targeting

It separates logic from configuration and makes scripts portable and adaptable.

## How to Use

In your shell script, add this directive:

```sh
# @shm extends: YouShellMakeBuildFile.json
```

Build File: ShellMake.json
This JSON file includes key-value pairs that define build behavior.

| Key                        | Type             | Description                                               |
| -------------------------- | ---------------- | --------------------------------------------------------- |
| `minimum_version_required` | string           | Minimum required Shellmake version (e.g., `"0.9.1"`)      |
| `distros`                  | array of strings | List of supported distros (e.g., `["arch", "debian"]`)    |
| `exclude`                  | array of strings | Distros to skip during processing                         |
| `target_env`               | string           | Environment type (e.g., `"linux"`, `"bsd"`)               |
| `output`                   | string           | Output file name (e.g., `"setup.sh"`)                     |
| `shell`                    | string           | (Future) target shell (e.g., `"bash"`)                    |
| `debug_mode`               | boolean          | Enables verbose logging                                   |
| `require_root`             | boolean          | Fails if user is not root or has no sudo                  |
| `enforce_variables`        | array of strings | Variables that must exist at runtime (e.g., `["DISTRO"]`) |

