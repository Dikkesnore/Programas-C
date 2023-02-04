typedef enum
{
	false, true
}
bool;

// Prototypes
void toLower(char *word);
void toUpper(char *word);
void capitalize(char *word);
void title(char *word);

int lenght(char *word);

bool isAlphaChar(char letter);
bool isAlpha(char *word);
bool isAlphaNumericChar(char letter);
bool isAlphaNumeric(char *word);
bool compare(char word1[], char word2[]);
bool compareBrute(char word1[], char word2[]); // Ignores diferences like upper and lower case