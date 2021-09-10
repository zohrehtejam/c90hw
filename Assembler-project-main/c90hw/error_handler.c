#include "error_handler.h"


void printError(Error error, Boolean * hasError)
{
    static char *filename;

    if (error.code == INITIALIZE)
    {
        filename = (char *)calloc(strlen(error.filename) + 1, sizeof(char));
        strcpy(filename, error.filename);
        filename[-1] = '\0';
        return;
    }
    else if (error.code == FINISH_FILE)
    {
        printf("File %s finished\n", filename);
        return;
    }
    
    *hasError = TRUE;

    printf("\nERROR - ");

    switch (error.code)
    {
    case MISSING_FILENAME:
        printf("Please provid a valid filename");
        break;
    case CANT_FIND_FILE:
        printf("Cant find file '%s'", error.filename);
        break;
    case MAX_LINE_SIZE:
        printf("Line too long at file '%s' line %d", filename, error.lineNumber);
        break;
    case INVALID_LABEL_NAME:
        printf("Invalid label name '%s' at file '%s' line %d", error.message, filename, error.lineNumber);
        break;
    case INVALID_LABEL_POSITION:
        printf("Invalid label position at file '%s' line %d", filename, error.lineNumber);
        break;
    case INVALID_COMMAND_NAME:
        printf("Invalid command name -'%s' at file '%s' line %d", error.message, filename, error.lineNumber);
        break;
    case EMPTY_OPERAND:
        printf("Invalid operand at file '%s' line %d", filename, error.lineNumber);
        break;
    case INVALID_OPERNAD:
        printf("Invalid operand at file '%s' line %d", filename, error.lineNumber);
        break;
    case INVALID_STRING:
        printf("Invalid string - %s at file %s line %d", error.message, filename, error.lineNumber);
        break;
    case LINE_ERROR:
        printf("Line %d at file '%s'", error.lineNumber, filename);
        break;
    case LABEL_EXISTS:
        printf("Duplicate label name at file '%s' line %d", filename, error.lineNumber);
        break;
    case SYMBOL_NOT_FOUND:
        printf("Symbol not found but was use in file '%s' line %d", filename, error.lineNumber);
        break;
    case CODE_ROW_NOT_FOUND:
        printf("Couldnt find code row at file '%s' line %d", filename, error.lineNumber);
        break;
    case REGISTRY_OUT_OF_RANGE:
        printf("Invalid value of registry provided at file '%s' line %d", filename, error.lineNumber);
        break;
    case NUMBER_OF_OPERANDS:
        printf("Incompatible number of arguments '%s' line %d", filename, error.lineNumber);
        break;
    case EXTERNAL_LABEL_IN_CONDITIONAL_CMD:
        printf("Using external label in conditional command is not allowed at file '%s' line %d", filename, error.lineNumber);
        break;
    default:
        printf("Unknown Error");
        break;
    }
    printf("\n");
}