# Random Clipboard

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


## Results 

Methodology :

-Enable ROBUSTNESS_TEST , then run / paste in a text file the result.
-Do it enough times in order to allow some test to be functionnal ( Ie. 09 requires > 370k ) 

| Type of Test                                    | P-Value              | Conclusion   |
|-------------------------------------------------|----------------------|--------------|
| 01. Frequency (Monobit) Test                    | 0.13552379942285117  | Random       |
| 02. Frequency Test within a Block               | 0.5212655792267176   | Random       |
| 03. Runs Test                                   | 0.9621318385491681   | Random       |
| 04. Test for the Longest Run of Ones in a Block | 0.37460409559848307  | Random       |
| 05. Binary Matrix Rank Test                     | 0.8085222442038765   | Random       |
| 06. Discrete Fourier Transform (Spectral) Test  | 2.772205500503962e-170 | Non-Random   |
| 07. Non-overlapping Template Matching Test      | 0.19822531994447531  | Random       |
| 08. Overlapping Template Matching Test          | 0.2979594702189787   | Random       |
| 09. Maurer's "Universal Statistical" Test       | 0.2761824430297729   | Random       |
| 10. Linear Complexity Test                      | 0.4695357776957204   | Random       |
| 11. Serial Test:                                |                      |              |
|                                                 | 0.0                  | Non-Random   |
|                                                 | 0.0                  | Non-Random   |
| 12. Approximate Entropy Test                    | 1.7404908037152792e-52 | Non-Random   |
| 13. Cumulative Sums Test (Forward)              | 0.24764160329458745  | Random       |
| 14. Cumulative Sums Test (Backward)             | 0.13379936272269785  | Random       |


|  |                      | | Conclusion   |
|----------------|----------------------|----------------------|--------------|
| 15. Random Excursions Test:           |                      |              |
|     State      | Chi Squared          | P-Value              | Conclusion   |
|     -4         | 8.550496946855022    | 0.12839336780792332  | Random       |
|     -3         | 2.4550032786885247   | 0.783255891773456    | Random       |
|     -2         | 3.5217567294070027   | 0.6200981454832732   | Random       |
|     -1         | 1.8852459016393441   | 0.8647847032448897   | Random       |
|     +1         | 5.28415300546448     | 0.3821947962552052   | Random       |
|     +2         | 3.796195102206031    | 0.5791159965934577   | Random       |
|     +3         | 5.350373770491801    | 0.3746319416989386   | Random       |
|     +4         | 6.359861442067627    | 0.2727603307270486   | Random       |
| 16. Random Excursions Variant Test:   |                      |              |
|     State      | COUNTS               | P-Value              | Conclusion   |
|     -9.0       | 112                  | 0.3680641866673753   | Random       |
|     -8.0       | 112                  | 0.33794410862828206  | Random       |
|     -7.0       | 125                  | 0.4004349594929455   | Random       |
|     -6.0       | 123                  | 0.34434497686429477  | Random       |
|     -5.0       | 115                  | 0.23609429952843575  | Random       |
|     -4.0       | 117                  | 0.1922573527503768   | Random       |
|     -3.0       | 118                  | 0.12864803395403868  | Random       |
|     -2.0       | 146                  | 0.26416216867088027  | Random       |
|     -1.0       | 170                  | 0.496807878801794    | Random       |
|     +1.0       | 178                  | 0.7938193831730679   | Random       |
|     +2.0       | 192                  | 0.7859240333961771   | Random       |
|     +3.0       | 238                  | 0.19855036446382535  | Random       |
|     +4.0       | 292                  | 0.031282495449488024 | Random       |
|     +5.0       | 323                  | 0.01471551203791618  | Random       |
|     +6.0       | 308                  | 0.04883478271923523  | Random       |
|     +7.0       | 308                  | 0.06996066926864757  | Random       |
|     +8.0       | 297                  | 0.12390807901734655  | Random       |
|     +9.0       | 270                  | 0.2700506171080861   | Random       |

## Addendum

- Discrete fourier transform test isn't working on my test suite.
- Did not check serial test.
