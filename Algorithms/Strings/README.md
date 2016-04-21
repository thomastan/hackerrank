Solutions here to string problems are typically done in C++ and not C.

This is due to the fact that C++'s stream handling allows reading of strings into the string type without having to worry about its length.  This is different to C, where reading is done into a character array that needs a size specified when created.  This can be troublesome because the (maximum size of the) string is not always known beforehand so the character array allocated might not be not large enough to hold the string of interest.

Note that

```
cin.getline(s);
```

will not pick up the last line in an input file if there is no newline at the end of the input file.  To ensure reading the last line, use

```
getline(cin, s);
```

instead.
