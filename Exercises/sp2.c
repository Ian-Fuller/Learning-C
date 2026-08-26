/*
How will I do exercise 6-2?
Requirements:
- Reads a C program
- ONLY cares about variable names
- Puts them into groups if the first 6 characters match
- Prints them out in alphabetical order
How will I do this?
- Read the program line by line
- Put all variable names into the tree, which is alphabetical by
  default
- The program will detect this by looking for a data type and
  optional *
- Since these are in alphabetical order, that should make it easy
  to group them
- Have a string that stores the first 6 chars of the last
  variable and compares it with the current one. If they don't
  match, print out a newline, any maybe a label like 
  "Group ------:"
*/