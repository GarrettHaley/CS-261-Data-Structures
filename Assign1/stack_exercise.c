#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"


int in_stack(DynArr * s,char tofind){
  /* 
     Returns 1 if the element `tofind` is present in DynArr `s`, 0
     otherwise.  Upon returning `s` should have its elements in the
     same order as when the function is called. In other words, you
     may modify `s` but must return it to its original state

     You may only call the following funcitons

        DynArr *createDynArr(int cap);
        int isEmptyDynArr(DynArr *v);
        void pushDynArr(DynArr *v, TYPE val);
        TYPE topDynArr(DynArr *v);
        void popDynArr(DynArr *v);


     Hint: use another stack to hold elements while you search
     and then restore the initial state of `s`
  */ 	
	TYPE * temp;
	temp = createDynArr(s->size);
	int returnValue = 0;
	char oldTop = ' ';
 	while(isEmptyDynArr(s) != 1){
		oldTop = topDynArr(s);
		pushDynArr(temp,oldTop);
		popDynArr(s);
		if(tofind == oldTop)
			returnValue = 1;
	} 
	while(isEmptyDynArr(temp) != 1){
		oldTop = topDynArr(temp);
		popDynArr(temp);
		pushDynArr(s,oldTop);
	}
	deleteDynArr(temp);
	return returnValue;
}






int valid_bracket(char * str){
  /*
    str contains only bracking characters - parenthesis ( '(' and ')'
    ), square brackets ('[' and ']') and squiggly brackets ('{' and
    '}')

    This function returns 1 if str contains a set of balanced
    bracketing characters and zero otherwise.  A string is said to
    have balanced bracketing characters if each opening bracket ( '(',
    '{' and '[') contains a correspodniniig closing bracket
    (')','}',']') of the same type and brackets are closed in the
    reverse order that they are opened.

    For example 

    valid_bracket("{}[]()") returns 1
    valid_bracket("{][}(]") returns 0, the brackets do not match
    valid_bracket("(([]))") returns 1
    valid_bracket("(([)])") returns 0, 
          because the '(' at index 1 is closed by the ')' at index 3
	  before the '[' at index 2 is closed

    valid_bracket("}") returns 0 because there is no opening bracket for '{'

    valid_bracket("({}[])") returns 1
    valid_bracket("({}([]))") returns 1
    valid_bracket("({}([]){([])})") returns 1
    valid_bracket("({([]))") returns 0
	
  */
  	int returnValue = 0;
	int counter = 0;
	TYPE *Temp; 
        Temp = createDynArr(10);
	pushDynArr(Temp,' ');
	int arraySize = strlen(str);
   	while(str[counter] != '\0'){
		if(str[counter] == '{' || str[counter] == '[' || str[counter] == '(')
			pushDynArr(Temp,str[counter]);
		if((str[counter] == '}'&& topDynArr(Temp) == '{')||(str[counter] == ']' && topDynArr(Temp) == '[') ||( str[counter] == ')' && topDynArr(Temp) == '(')) 
			popDynArr(Temp);
		counter++;
	}
	if(topDynArr(Temp) == ' '|| isEmptyDynArr(Temp) == 1)
		returnValue = 1;
	deleteDynArr(Temp);
	if(arraySize % 2 != 0)
	returnValue = 0;
 	return returnValue;
 
}

