
# Shellmake Build System

Shellmake uses a json build file  to guide how a script should be preprocessed across different Linux environments.

## Purpose

The build file defines:
- Which distros the script targets
- Which distros to exclude
- Required Shellmake version
- Script output name

It separates logic from configuration and makes scripts portable and adaptable.

## How to Use

In your shell script, add this directive:

```sh
# @shm extends: YouShellMakeBuildFile.json
```


### Distro Build Keys

These define which distributions the script supports, targets, or excludes:

| cmd              | type          | description                                                             |
|------------------|---------------|-------------------------------------------------------------------------|
| `distro_origins` | arr[string] | indicator of which source distribution(s) the scripts were written for. |
| `distro_targets` | arr[string] | indicator of which distribution(s) will be manufactured.                |

### Other Build Commands

| cmd                        	| type        	| description                                                                              	|
|----------------------------	|-------------	|------------------------------------------------------------------------------------------	|
| `minimum_version_required` 	| string      	| minimum version of shellmake in your environment required to run.                        	|
| `out_filename`             	| string      	| root name of the output files (does not count the additional ones from the builds made). 	|
| `shell_targets`            	| arr[string] 	| indicates which shell the manufactured scripts output to.                                	|
| `required_root`            	| boolean     	| fail if the user is not root or lacks sudo.                                              	|
