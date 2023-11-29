// Megan Howell, Final Project, ITT-310
#include <stdio.h>
#include <string.h>

// initial UDF definitions
int projectEntry();
int mainMenu();


// name and student ID check
int projectEntry() {
	char* inName[1024];
	char* inNum[1024];
	printf("Please enter the name: \n");
	fgets(inName, 1024, stdin);
	printf("Please enter the student ID: \n");
	fgets(inNum, 1024, stdin);
	if (strcmp(inName, "Megan Howell") == 0) {
		printf("Name check passed");
		if (strcmp(inNum, "20863303") == 0) {
			printf("Student ID check passed");
			printf("All checks passed. Entering the program...");
			mainMenu();
		}
		else {
			printf("Student ID check failed. Try again.");
			projectEntry();
		}
	}
	else {
		printf("Name check failed. Try again.");
		projectEntry();
	}
}

// project main menu
int mainMenu() {
	printf("CyberQueenMeg Cipher");
	printf("Please type 'e' to encode text, 'd' to decode text, or 'q' to quit the program");


int main() {
	projectEntry();
}