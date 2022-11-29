#include "./src/headers/header.h"

/**
 *main - main function
 *@argc: argument.
 *@argv: array of argument.
 *Return - Always success 0.
 */
int main(int argc, char *argv[])
{
	App app;
	init(&app);
	display(&app);
	return (0);
}
