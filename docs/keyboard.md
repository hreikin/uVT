# Keyboard

## Overview

This keyboard implementation provides various functionalities including:

- Default character input
- Alternative character tables
- Control character input
- Toggle mechanisms for ALT and CTRL modes

## Usage Instructions

### Default Character Input

Press any key to input the default character associated with that key.

### Alternative Character Tables

Press `<alt+c>` to cycle through the alternative character tables. At present there are 3 alternative character tables. The `shift` and `sym` keys can be used to access the additional characters in each table.

After selecting an alternative character table, press the relevant key to input the alternative character. Once a key has been pressed, the keyboard will revert to the default character table.

While in any alternative character table mode, press `<shift+mic>` or `<shift+$>` to lock or unlock the current character table. When locked, the selected character table will remain active until explicitly unlocked.

| Key       | Normal                                           | Shift                 | Symbol                         |
|-----------|--------------------------------------------------|-----------------------|--------------------------------|
| q         | `` ` `` (Grave Accent)                           |                       | `⌠` (Top Half Integral)        |
| w         | `%` (Percent)                                    |                       | `⌡` (Bottom Half Integral)     |
| e         | `&` (Ampersand)                                  |                       | `÷` (Division)                 |
| r         | `£` (Pound Sterling)                             | `₧` (Peseta)          | `¥` (Yen)                      |
| t         | `{` (Left Curly Brace)                           |                       | `[` (Left Square Bracket)      |
| y         | `}` (Right Curly Brace)                          |                       | `]` (Right Square Bracket)     |
| u         | `^` (Caret)                                      |                       | `±` (Plus-Minus)               |
| i         | `<` (Less Than)                                  |                       | `≤` (Less Than or Equal To)    |
| o         | `>` (Greater Than)                               |                       | `≥` (Greater Than or Equal To) |
| p         | `=` (Equals)                                     | `≈` (Almost Equal To) | `≡` (Identical To)             |
| a         | `ª` (Feminine Ordinal Indicator)                 |                       | `°` (Degree)                   |
| s         | `º` (Masculine Ordinal Indicator)                |                       | `∙` (Bullet Operator)          |
| d         | `⌐` (Reversed Not Sign)                          |                       | `·` (Middle Dot)               |
| f         | `¬` (Negation)                                   |                       | `√` (Square Root)              |
| g         | `\` (Backslash)                                  |                       | `\|`(Vertical Line)            |
| h         | `½` (One Half)                                   |                       |                                |
| j         | `¼` (One Quarter)                                |                       |                                |
| k         | `«` (Left-Pointing Double Angle Quotation Mark)  |                       |                                |
| l         | `»` (Right-Pointing Double Angle Quotation Mark) |                       |                                |
| z         | `µ` (Micro Sign)                                 |                       |                                |
| x         | `∞` (Infinity)                                   |                       |                                |
| c         | `²` (Superscript Two)                            |                       | `ⁿ` (Superscript N)            |
| v         | `¿` (Inverted Question Mark)                     |                       |                                |
| b         | `¡` (Inverted Exclamation Mark)                  |                       |                                |
| n         | `∩` (Intersection)                               |                       | `DEL` (Delete)                 |
| m         | `~` (Tilde)                                      |                       |                                |
| $         | `¢` (Cent Sign)                                  | n/a                   | n/a                            |
| \<mic\>   | n/a                                              | n/a                   |                                |
| \<space\> | `NBSP` (Non-Breaking Space)                      | n/a                   | n/a                            |

| Key       | Normal                            | Shift | Symbol                            |
|-----------|-----------------------------------|-------|-----------------------------------|
| q         | `â` (Lowercase A with Circumflex) |       | `Ö` (Uppercase O with Diaeresis)  |
| w         | `ä` (Lowercase A with Diaeresis)  |       | `ó` (Lowercase O with Acute)      |
| e         | `à` (Lowercase A with Grave)      |       | `ü` (Lowercase U with Diaeresis)  |
| r         | `å` (Lowercase A with Ring Above) |       | `û` (Lowercase U with Circumflex) |
| t         | `á` (Lowercase A with Acute)      |       | `ù` (Lowercase U with Grave)      |
| y         | `Ä` (Uppercase A with Diaeresis)  |       | `Ü` (Uppercase U with Diaeresis)  |
| u         | `Å` (Uppercase A with Ring Above) |       | `ú` (Lowercase U with Acute)      |
| i         | `æ` (Lowercase AE)                |       | `ÿ` (Lowercase Y with Diaeresis)  |
| o         | `Æ` (Uppercase AE)                |       | `α` (Greek Small Letter Alpha)    |
| p         | `ç` (Lowercase C with Cedilla)    |       | `Γ` (Greek Capital Letter Gamma)  |
| a         | `Ç` (Uppercase C with Cedilla)    |       | `π` (Greek Small Letter Pi)       |
| s         | `ß` (Sharp S)                     |       | `Σ` (Greek Capital Letter Sigma)  |
| d         | `é` (Lowercase E with Acute)      |       | `σ` (Greek Small Letter Sigma)    |
| f         | `ê` (Lowercase E with Circumflex) |       | `τ` (Greek Small Letter Tau)      |
| g         | `ë` (Lowercase E with Diaeresis)  |       | `Φ` (Greek Capital Letter Phi)    |
| h         | `è` (Lowercase E with Grave)      |       | `Θ` (Greek Capital Letter Theta)  |
| j         | `É` (Uppercase E with Acute)      |       | `Ω` (Greek Capital Letter Omega)  |
| k         | `ï` (Lowercase I with Diaeresis)  |       | `δ` (Greek Small Letter Delta)    |
| l         | `î` (Lowercase I with Circumflex) |       | `φ` (Greek Small Letter Phi)      |
| z         | `ì` (Lowercase I with Grave)      |       | `ε` (Greek Small Letter Epsilon)  |
| x         | `í` (Lowercase I with Acute)      |       |                                   |
| c         | `ñ` (Lowercase N with Tilde)      |       |                                   |
| v         | `Ñ` (Uppercase N with Tilde)      |       |                                   |
| b         | `ô` (Lowercase O with Circumflex) |       |                                   |
| n         | `ö` (Lowercase O with Diaeresis)  |       |                                   |
| m         | `ò` (Lowercase O with Grave)      |       |                                   |
| $         |                                   | n/a   | n/a                               |
| \<mic\>   | n/a                               | n/a   |                                   |
| \<space\> |                                   | n/a   | n/a                               |

| Key       | Normal                                 | Shift | Symbol                                      |
|-----------|----------------------------------------|-------|---------------------------------------------|
| q         | `│` (Box Light Vertical)               |       | `╬` (Box Double Vertical Horizontal)        |
| w         | `┤` (Box Light Vertical Left)          |       | `╧` (Box Up Single Horizontal Double)       |
| e         | `╡` (Box Vertical Single Left Double)  |       | `╨` (Box Up Double Horizontal Single)       |
| r         | `╢` (Box Vertical Double Left Single)  |       | `╤` (Box Down Single Horizontal Double)     |
| t         | `╖` (Box Down Double Left Single)      |       | `╥` (Box Down Double Horizontal Single)     |
| y         | `╕` (Box Down Single Left Double)      |       | `╙` (Box Up Double Right Single)            |
| u         | `╣` (Box Double Vertical Left)         |       | `╘` (Box Up Single Right Double)            |
| i         | `║` (Box Double Vertical)              |       | `╒` (Box Down Single Right Double)          |
| o         | `╗` (Box Double Down Left)             |       | `╓` (Box Down Double Right Single)          |
| p         | `╝` (Box Double Up Left)               |       | `╫` (Box Vertical Double Horizontal Single) |
| a         | `╜` (Box Up Double Left Single)        |       | `╪` (Box Vertical Single Horizontal Double) |
| s         | `╛` (Box Up Single Left Double)        |       | `┘` (Box Light Up Left)                     |
| d         | `┐` (Box Light Down Left)              |       | `┌` (Box Light Down Right)                  |
| f         | `└` (Box Light Up Right)               |       | `█` (Full Block)                            |
| g         | `┴` (Box Light Up Horizontal)          |       | `▄` (Lower Half Block)                      |
| h         | `┬` (Box Light Down Horizontal)        |       | `▌` (Left Half Block)                       |
| j         | `├` (Box Light Vertical Right)         |       | `▐` (Right Half Block)                      |
| k         | `─` (Box Light Horizontal)             |       | `▀` (Upper Half Block)                      |
| l         | `┼` (Box Light Vertical Horizontal)    |       | `■` (Black Square)                          |
| z         | `╞` (Box Vertical Single Right Double) |       | `░` (Light Shade)                           |
| x         | `╟` (Box Vertical Double Right Single) |       | `▒` (Medium Shade)                          |
| c         | `╚` (Box Double Up Right)              |       | `▓` (Dark Shade)                            |
| v         | `╔` (Box Double Down Right)            |       |                                             |
| b         | `╩` (Box Double Up Horizontal)         |       |                                             |
| n         | `╦` (Box Double Down Horizontal)       |       |                                             |
| m         | `╠` (Box Double Vertical Right)        |       |                                             |
| $         | `═` (Box Double Horizontal)            | n/a   | n/a                                         |
| \<mic\>   | n/a                                    | n/a   |                                             |
| \<space\> |                                        | n/a   | n/a                                         |

### Supported Control Character Codes

Press `<shift+mic>` to toggle CTRL mode. In this mode, pressing a key will input the corresponding control character. The table below lists the supported control codes.

| Key       | Control Code |
|-----------|--------------|
| q         | `CTRL+Q`     |
| w         | `CTRL+W`     |
| e         | `CTRL+E`     |
| r         | `CTRL+R`     |
| t         | `CTRL+T`     |
| y         | `CTRL+Y`     |
| u         | `CTRL+U`     |
| i         | `CTRL+I`     |
| o         | `CTRL+O`     |
| p         | `CTRL+P`     |
| a         | `CTRL+A`     |
| s         | `CTRL+S`     |
| d         | `CTRL+D`     |
| f         | `CTRL+F`     |
| g         | `CTRL+G`     |
| h         | `CTRL+H`     |
| j         | `CTRL+J`     |
| k         | `CTRL+K`     |
| l         | `CTRL+L`     |
| z         | `CTRL+Z`     |
| x         | `CTRL+X`     |
| c         | `CTRL+C`     |
| v         | `CTRL+V`     |
| b         | `CTRL+B`     |
| n         | `CTRL+N`     |
| m         | `CTRL+M`     |
| $         | `CTRL+$`     |
| \<space\> | `CTRL+Space` |

### ALT Mode

Press `<shift+$>` to toggle ALT mode. In this mode, you can input characters by typing their numeric codes followed by `<Enter>`. For example, to input the character `A` (code 65), press `6`, `5`, and then `<Enter>`. Please note that not all characters are available, only the ones provided by the font `CP437`.
