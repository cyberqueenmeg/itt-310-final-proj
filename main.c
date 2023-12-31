// Megan Howell, Final Project, ITT-310

//This project is a modified caesar cipher

//include necessary c libraries
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// initial UDF definitions
void mainMenu();
void encode();
void decode();
int quit();

// project main menu
void mainMenu() {
	char menOpt[10];
	printf(" ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ _________ ____ ____ ____ ____ ____ ____\n");
	printf("||C |||y |||b |||e |||r |||Q |||u |||e |||e |||n |||M |||e |||g |||       |||C |||i |||p |||h |||e |||r ||\n");
	printf("||__|||__|||__|||__|||__|||__|||__|||__|||__|||__|||__|||__|||__|||_______|||__|||__|||__|||__|||__|||__||\n");
	printf("|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/_______\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|\n\n\n\n\n");
	printf("Please type 'e' to encode text, 'd' to decode text, or 'q' to quit the program\n");
	scanf_s("%s", &menOpt, 10);
	if (strcmp(menOpt, "e") == 0) { //enter encoding menu if user chooses to encode
		encode();
	}
	else if (strcmp(menOpt, "d") == 0) { //enter decoding menu if user chooses to encode
		decode();
	}
	else if (strcmp(menOpt, "q") == 0) { //quit if user chooses to quit
		quit();
	}
	else { //rerun menu if user does not enter valid input
		printf("Invalid input. Please follow the directions in the main menu\n\n");
		mainMenu();
	}
}

void encode() {
	char message[1024];
	int shift = 4;

	// Input message and shift value
	printf("Enter a word to encode or q to quit: \n");
	scanf_s("%s", &message, 1024);

	if (strcmp(message, "q") == 0) {
		quit(); //quit if quit char is called
	}
	else {
		size_t length = strlen(message);

		char alphabet[] = "rnuvpiwjhxzalfoygbmqctekdsRNUVPIWJHXZALFOYGBMQCTEKDS"; //define alphabet

		for (int i = 0; i < length; i++) {
			char currentChar = message[i]; //loop through string and encode each character
			char* charPosition = strchr(alphabet, currentChar);

			if (charPosition != NULL) { //do for non-null characters
				int index = charPosition - alphabet; 
				message[i] = alphabet[(index + shift) % 52];
			}
		}

		printf("Encrypted message: %s\n\n\n", message); //print message
		mainMenu(); //enter menu again
	}


}

void decode() {
	char encMessage[1024];
	int encShift = 4;

	// Input message and shift value
	printf("Enter a word to decode or q to quit: \n");
	scanf_s("%s", &encMessage, 1024);

	if (strcmp(encMessage, "q") == 0) { //check to see if the quit character is entered
		quit();
	}
	else { //else decrypt the message
		size_t enclength = strlen(encMessage);

		char decAlphabet[] = "rnuvpiwjhxzalfoygbmqctekdsRNUVPIWJHXZALFOYGBMQCTEKDS"; //define the alphabet

		for (int i = 0; i < enclength; i++) {
			char deccurrentChar = encMessage[i]; //loop through each char of the message and decode it
			char* deccharPosition = strchr(decAlphabet, deccurrentChar);

			if (deccharPosition != NULL) { //do for all non-null characters
				int index = deccharPosition - decAlphabet;
				encMessage[i] = decAlphabet[(index - encShift) % 52];
			}
		}

		printf("Decrypted message: %s\n\n\n", encMessage); //print message
		mainMenu(); //enter menu again
	}

}

int quit() {
	system("cls");
	//quit program
	printf("Quitting...\n\n");
	return 0;
}

int main() {
	//call main menu UDF
	mainMenu();
}
