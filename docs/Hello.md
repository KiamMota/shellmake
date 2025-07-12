# ShellMake Syntax And Rules

Shellmake uses **special comment directives** that called **meta-commments** to preprocess shell scripts. 

### Any command that ShellMake have to process must start with the **ShellMake Directive** -> `# @shm`

## Synopsis

ShellMake uses a simple pattern to make any meta-command

### `# <metac_caller> <command>: <parameter(s)>`

## Structural Elements

- `@shm`: meta-command caller prefix.
- `<command> :` marks the command block.
- `parameter` syntax for commands.
- Quotes are required around arguments that contain spaces or special characters.

> [!IMPORTANT]  
> The default case in ShellMake is snake_case, that's worth to all preprocessing logic.
