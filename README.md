# µVT - A VT100 Inspired Micro Terminal

In development.

## TODO

- [x] Move CANSID and VT100 to submodules like TFT_eSPI. Fork the repositories and add any changes (unsure if there will be any as of yet) to the forked repositories.
- [x] Write basic documentation for current keyboard implementation to understand the current state before refactor.
- [ ] Simplify the keyboard implementation to only use the basic keys in alternative character tables, e.g. no `shift` or `sym`, add more tables to compensate.
- [ ] Ensure ANSI escape sequences and control codes are correctly parsed and handled by the keyboard.
- [ ] Implement a basic file system to store configuration and basic user data.
- [ ] Implement support for SD cards to store the users files.
- [ ] Implement basic commands to interact with the file system:
    - [ ] `ls`
    - [ ] `cd`
    - [ ] `cat`
    - [ ] `echo`
    - [ ] `rm`
    - [ ] `mv`
    - [ ] `cp`
    - [ ] `mkdir`
    - [ ] `rmdir`
    - [ ] `touch`
    - [ ] `edit`
    - [ ] `clear`
    - [ ] `reset`
    - [ ] `reboot`
    - [ ] `shutdown`
    - [ ] `help`
    - [ ] `man`
    - [ ] `info`
    - [ ] `about`
    - [ ] `version`
    - [ ] `exit`
- [ ] Implement uVT wrapper (terminal emulator):
    - [ ] Wrap VT100 to update the serial output so it matches the display.
    - [ ] Wrap TFT_eSPI to update the display.
    - [ ] Wrap CANSID to parse any incoming ANSI escape sequences or control codes either from the serial connection, keyboard or the terminal emulators included programs.