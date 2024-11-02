# random_clipboard

## The application performs the following steps:
1. Generates a random string of a predefined length (16 characters).
2. Allocates global memory for the string to be copied.
3. Locks the memory and stores the random string within it.
4. Opens the system clipboard, and clears existing content.
5. Sets the clipboard data to the newly generated random string.
6. Closes the clipboard.

## Requirements
This application requires a Windows OS due to the use of Windows-specific APIs (`Windows.h`). The code assumes access to a development environment set up for compiling C++ code using Windows API.

## Usage
Compile and run the project. Upon execution, a random alphanumeric string inclusive of characters `-` and `_` will be copied to the clipboard. You can then paste this string into documents or text fields using the standard paste operation (usually `Ctrl + V`).

use the ROBUSTNESS_TEST to produce big sequence in order to check the true randomness of the pasted value.

## Future Improvements
- Add more customization options, such as varying the string length.
- Implement error handling robustly to cover all possible failure modes.
- Extend functionality to work on different operating systems.
- Test the randomness against NIST https://nvlpubs.nist.gov/nistpubs/legacy/sp/nistspecialpublication800-22r1a.pdf

## Notes
For efficient operation, it is assumed that the necessary privileges to access the clipboard are granted, and no other application interrupts clipboard operations during the execution of this program.
