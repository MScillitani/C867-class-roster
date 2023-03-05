#pragma once
#include <string> 

//part C: Define an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE.
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE }; //enumerated data type DegreeProgram defining SECURITY, NETWORK, and SOFTWARE

//creates an array of strings for each degree & outputs string values
static const std::string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };

/*
Change log
Sep 8 - created
Sep 9 - checked for accuracy
*/