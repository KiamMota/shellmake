# Shellmake Environment Variables

Shellmake uses environment variables denoted by `${VAR_NAME}` within its directives to enable dynamic behavior during preprocessing.

## What Are Shellmake Variables?

These variables represent values available at **runtime** or set in the environment where shellmake runs. They allow conditions and commands to adapt based on the current context, such as the target system, user settings, or other external parameters.

## Usage

By referencing `${VAR_NAME}`, shellmake scripts become flexible, reacting to the environment dynamically without hardcoding values.

## Environment Variables Space

`DISTRO`      -> returns a lowercase string with the name of the Linux distribution or operating system

`USER_NAME`   -> returns the current user's username as a string

`SUPER_USER`  -> returns "true" if the user has root or sudo privileges, otherwise "false"

`HOSTNAME`    -> returns the system's hostname as a string

`ARCH`        -> returns the system architecture as a string (e.g., "x86_64", "arm64")

`SHELL`       -> returns the path or name of the current shell in use (e.g., "/bin/bash")
