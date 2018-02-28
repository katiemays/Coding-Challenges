/* ************************* *  
*  WELL-FORMED STRING
*
*  Written by: Kathryn Mays
*  Date: 27 Feb 2018
*  Known bugs: none
*
*  ***********************
*/

#include <iostream>
using namespace std;

//Prototypes

/*
* Displays a string by outputing each character in sequential order.
*/
void DisplayString(string s);

/*
* Checks string in two ways.
*
* First:
* Looks at first character in string and determines it's paired character.
* Then checks for its paired character in the string.
*
* Second:
* Compares first half of string to second half of string in reverse.
*/
bool IsWellFormed(string s);

int main()
{       
        //Variables
        string s={0};

        cout << "Please enter a string of these characters: ";
        cout << " '{','[', '(', '}', ']', ')'\n";
        cin  >> s;

        DisplayString (s);
        IsWellFormed(s);

        if (IsWellFormed(s) == true)
          cout << "String is well formed." << endl;
        else    
          cout << "String is NOT well-formed." << endl;


       return 0;

}
 
//Functions

void DisplayString(string s)
{
      cout << "You entered:" << endl;
      for (int i =0; i < s.length(); i++)
                cout << s.at(i);

      cout << endl;

}

bool IsWellFormed(string s)
{

       bool wellFormed = false;
       char temp_char = '0';
       int half_size = 0;
 
       if (s.length()%2 == 0)
                 half_size = s.length()/2;
 
       //checks for matching characters side by side
       for (int i=0; i < s.length(); i++)
       {
                if (s.at(i) == '{')
                        temp_char = '}';
                else if (s.at(i) == '}')
                        temp_char = '{';
                else if (s.at(i) == '(')
                        temp_char - ')';
                else if (s.at(i) == ')')
                        temp_char = '(';
                else if (s.at(i) == '[')
                        temp_char = ']';
                else if (s.at(i) == ']')
                         temp_char = '[';
                for (int j=0; j < s.length(); j++)
                {
                        if (s.at(j) == temp_char && i == j+1)
                        {
                               wellFormed = true;
                               break;
                         }
                        else if (s.at(j) == temp_char && j == i+1)
                        {
                                wellFormed = true;
                                break;
                        }
               }
       }
       
    //checks for mirrored balanced string
    for (int k=0; k < half_size; k++)
    {
           if (s.at(k) == s.at(s.length()-k-1))
                  wellFormed = true;
    }

 if (wellFormed == true)
             return true;
        else
             return false;
}
