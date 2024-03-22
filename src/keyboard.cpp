// keyboard.cpp

#include "keyboard.hpp"

void init_keyboard()
{
    Wire.begin(BOARD_I2C_SDA, BOARD_I2C_SCL);

    // Check keyboard
    Wire.requestFrom(LILYGO_KB_SLAVE_ADDRESS, 1);
    if (Wire.read() == -1)
    {
        while (1)
        {
            serialPtr->println("LILYGO Keyboad not online .");
            delay(1000);
        }
    }
}

unsigned char get_alternative_char(struct KeyMapping mappings[], int size, unsigned char original) {
    for (int i = 0; i < size; ++i) {
        if (mappings[i].original == original) {
            return mappings[i].alternative;
        }
    }
    // Return the original character if no alternative is found
    return original;
}

unsigned char get_keyboard_key()
{
    // Static variables retain their values across function calls
    static bool alt_toggle = false;
    static bool ctrl_toggle = false;
    static bool lock_table = false;
    static int alt_number_list[5];
    static int alt_number_index = 0;
    static int alt_char_table_mode = 0;
    unsigned char key_value;
    // Read key value from esp32c3
    Wire.requestFrom(LILYGO_KB_SLAVE_ADDRESS, 1);
    while (Wire.available() > 0)
    {
        key_value = Wire.read();
        if (key_value != NULL_CHAR)                  // This function is called within the main loop, without this check 
                                                     // the below code would be next in line and get executed after enabling
                                                     // any of the toggles above and before any key can be pressed. This 
                                                     // would result in a null character being returned but more importantly 
                                                     // the following checks would be true, thus disabling any of the 
                                                     // toggles before the user can use them
        {
            if (key_value == ALT_C)
            {                                        // <alt+c> on keyboard
                alt_char_table_mode++;               // Cycle through different character tables
                if (alt_char_table_mode > 3) {
                    alt_char_table_mode = 0;
                }
                key_value = NULL_CHAR;               // Return the first character in the font (NULL) to print nothing
            }
            else if (alt_char_table_mode > 0) 
            {
                if (key_value == CTRL_TOGGLE || key_value == ALT_TOGGLE)
                {
                    // Enable or disable the table_lock, this will NOT disable/enable the alt/ctrl toggles
                    lock_table = !lock_table;
                    key_value = NULL_CHAR;
                }
                else if (alt_char_table_mode == 1) 
                {
                    key_value = get_alternative_char(alt_characters_table_one, alt_characters_table_one_size, key_value);
                }
                else if (alt_char_table_mode == 2) 
                {
                    key_value = get_alternative_char(alt_characters_table_two, alt_characters_table_two_size, key_value);
                }
                else if (alt_char_table_mode == 3) 
                {
                    key_value = get_alternative_char(alt_characters_table_three, alt_characters_table_three_size, key_value);
                }
                if (lock_table == false) 
                {
                    alt_char_table_mode = 0;         // Reset to default table after selecting an alternative character
                }
            }
            else if (key_value == CTRL_TOGGLE)
            {                                        // <shift+mic> on keyboard
                ctrl_toggle = !ctrl_toggle;          // Toggle CTRL
                key_value = NULL_CHAR;               // Return the first character in the font (NULL) to print nothing
            }
            else if (key_value == ALT_TOGGLE) 
            {                                        // <shift+$> on keyboard
                alt_toggle = !alt_toggle;            // Toggle ALT
                key_value = NULL_CHAR;               // Return the first character in the font (NULL) to print nothing
            }
            else if (ctrl_toggle == true) 
            {
                key_value = get_alternative_char(ctrl_characters, ctrl_characters_size, key_value);
                ctrl_toggle = false;
            }
            else if (alt_toggle == true)
            {
                // Combine individual digits received in to one number until a CR is encountered and then set
                // key_value to the font_character from that position
                if (isdigit(key_value)) 
                {
                    // Store numbers in the list for alt key
                    alt_number_list[alt_number_index++] = key_value - '0';
                    key_value = NULL_CHAR;
                } 
                else if (key_value == CARRIAGE_RETURN) 
                {
                    // Send the combined number when carriage return is encountered
                    int combined_number = 0;
                    for (int i = 0; i < alt_number_index; ++i) 
                    {
                        combined_number = combined_number * 10 + alt_number_list[i];
                    }
                    key_value = font_characters[combined_number];
                    alt_toggle = false;              // Reset toggle after sending
                    alt_number_index = 0;            // Reset the index
                }
            }
        }
    }
    return key_value;
}