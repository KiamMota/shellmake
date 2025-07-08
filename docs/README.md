# Shellmake Syntax Documentation

Shellmake uses special comment directives to preprocess shell scripts with conditional and line-editing commands.

## Syntax Overview

- Directives begin with the meta-command caller `@shm`.
- If a condition is used (e.g., `if`), it ends with a colon `:` to start a block.
- Inside a conditional block, one or more commands are specified.
- Commands start with `>` followed by the command name, optional parameters in parentheses, and arguments in quotes.
- Conditional blocks must be closed with `endif;` (semicolon mandatory).
- For single commands without condition, no `endif;` is required.
- The general base syntax for single commands is:

  `meta_command_caller <command>: <command>`

## Structural Elements

- `@shm`: meta-command caller prefix.
- `<condition> :` marks the start of a conditional block.
- `>command(options) "arguments"` syntax for commands.
- Quotes are required around arguments that contain spaces or special characters.
- `endif;` ends conditional blocks.

## Summary

Shellmake syntax is designed to enable precise and conditional script editing using comment directives. Blocks and commands follow a strict pattern with explicit starts and ends, supporting robust and maintainable dynamic scripting.
