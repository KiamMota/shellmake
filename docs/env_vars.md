# Shellmake Environment Variables

Shellmake uses environment variables denoted by `${variable}` within its directives to enable dynamic behavior during preprocessing.

## What Are Shellmake Variables?

These variables represent values available at **runtime** or set in the environment where shellmake runs. They allow conditions and commands to adapt based on the current context, such as the target system, user settings, or other external parameters.

## When and How Are They Set?

- Variables inside `${}` are **evaluated during shellmake's preprocessing phase**, before the script execution.
- They can be inherited from the environment or explicitly defined before running shellmake.
- Their values control conditional blocks (`if ${distro} == "arch" :`) and influence command behavior.

## Usage

By referencing `${variable}`, shellmake scripts become flexible, reacting to the environment dynamically without hardcoding values.

---

## Environment Variables Space

Here is the section reserved for listing all available shellmake environment variables:

*(Insert shellmake environment variables list here)*

