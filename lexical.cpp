#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<ctype.h>
#include<fstream>
using namespace std;

string arr[] = { "void", "using", "namespace", "int", "include", "iostream", "std", "main",
"cin", "cout", "return", "float", "double", "string" };

bool
isKeyword (string a)
{
  for (int i = 0; i < 14; i++)
    {
      if (arr[i] == a)
	{
	  return true;
	}
    }
  return false;
}

int main() 
{ 
	ofstream operators,keyword,symbol,constant,identifier ;
	fstream file; 
	string s, filename; 

	filename = "./input.txt";
		identifier.open("identifier.txt");
		operators.open ("operators.txt");
		keyword.open ("keyword.txt");
		symbol.open("symbol.txt");
		constant.open("constant.txt");

	// operators = "./operators.txt" 
	// keyword = "./keyword.txt" 
	// symbol = "./symbol.txt" 
	// constant = "./constant.txt" 
	// identifier = "./identifier.txt" 
	// // operators = "./operators.txt" 

	file.open(filename.c_str()); 

	while (file >> s) 
	{
        if (s == "+" || s == "-" || s == "" || s == "/" || s == "^" || s == "&&" || s == "||" || s == "=" || s == "==" || s == "&" || s == "|" || s == "%" || s == "++" || s == "--" || s == "+=" || s == "-=" || s == "/=" || s == "=" || s == "%=")
	    {
	      operators << s << endl;
		  
	      s = "";
	    }
	  else if (isKeyword (s))
	    {
	      keyword << s << endl;
	      s = "";
	    }
	  else if (s == "(" || s == "{" || s == "[" || s == ")" || s == "}" || s == "]" || s == "<" || s == ">" || s == "()" || s == ";" || s == "<<" || s == ">>" || s == "," || s == "#")
	    {
	      symbol << s << endl;
	      s = "";

	    }
	  else if (s == "\n" || s == " " || s == "")
	    {
	      s = "";

	    }
	  else if (isdigit (s[0]))
	    {
	      int x = 0;
	      if (!isdigit (s[x++]))
		{
		  continue;
		}
	      else
		{
		  constant << s << endl;
		  s = "";
		}
	    }
	  else
	    {
	      identifier << s << endl;
	      s = "";
	    } 
	} 
operators.close();
identifier.close();
constant.close();
symbol.close();
keyword.close();

	return 0; 
} 