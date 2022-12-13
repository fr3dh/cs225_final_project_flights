#include <string>
#include <vector>
#include <fstream>

<<<<<<< HEAD

    
    /**
=======
/**
>>>>>>> main
 * @brief Take a filename and read in all the text from the file.
 * @param filename The name of the file that will fill the string
 * @return A string containing the whole text of the given file
 */
std::string file_to_string(const std::string & filename);

/**
* @brief Functions for the removal of whitespace to the left or right of a string (or both)
* @param str The string being processed
* @return The processed string
*/
std::string TrimRight(const std::string & str);
std::string TrimLeft(const std::string & str);
std::string Trim(const std::string & str);
<<<<<<< HEAD
std::string TrimChar(const std::string & str, char toremove);
=======
>>>>>>> main

/**
 * @brief Given a string and character, split the string by the character and store in a vector
 *        A 'split' string treats the character as a breakpoint and creates a separate item
 *        in the output vector for each substring.
 * 
 * NOTE: The separator character is not included in the substrings.
 *
 * @param str1 The string being split
 * @param sep The separator character
 * @param fields The string vector storing all substrings created by the split
 * @return The number of substrings created
 */
<<<<<<< HEAD
int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields);


=======
int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields);
>>>>>>> main
