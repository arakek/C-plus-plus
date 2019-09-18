#include <iostream>                             
#include <string>                               
#include <map>                                  
#include <cctype>                               
#include <sstream>                              
#include <conio.h>
#include <math.h>
 
using namespace std;
 

int no_of_errors;
map<string, double> table;
 
double number_value;                           
string string_value;                            
 
int no_of_strings;
 
enum Token_value                                    
{
    NAME, NUMBER, END, PLUS = '+', MINUS = '-', MUL = '*', DIV = '/',
    PRINT = ',', ASSIGN = '=', LP = '(', RP = ')', ST = '^'
};
 
Token_value curr_tok;   
double term(bool get);                              
double prim(bool get);                               
double expr(bool get);                              
int error(const string s);                         
Token_value get_token();

class Calculator
{
private:
   string q;
public:
    
    double expr(bool get);
    double term(bool get);
    double prim(bool get);
    Token_value get_token();
    int error(const string s);
    friend  ostream& operator<< ( ostream &ost, Calculator &z);
    friend istream& operator>> (istream &ist, Calculator &z);
};

ostream &operator<<( ostream&ost, Calculator &z)
{

    ost << z.q;
    return ost;
}
istream &operator>>( istream&ist,  Calculator &z)
{
    ist >> z.q;   
    return ist;
}

double Calculator::expr(bool get)                               
{
    double left = term(get);
    for (;;)                                        
    {
        switch (curr_tok)                           
        {
        case PLUS:
           left += term(true);
        break;     
        case MINUS:
           left -= term(true); 
        break;       
        default:   
            return left;                    
        };
    };
};
 
double Calculator::term(bool get)                               
{
    double left = prim(get);
    for (;;)                                        
    {
        switch (curr_tok)
        {
        case MUL:
           left *= prim(true);
        break;      
        case DIV:   
            if (double d = prim(true))      
            {
            left /= d;
            break;
            };
                return error(" DIVIZION BY ZERO");   
        case ST:
           left = pow(left,prim(true));
        break;
        default:  
            return left;
        };
    };
};
 
double Calculator::prim(bool get)                               
{
    if (get) get_token();                            
    switch (curr_tok)
    {
    case NUMBER:                                    
    {
        get_token();
        return number_value;
    };
    case NAME:
    {
        double&v = table[string_value];
        
        if ((string_value == "sin") && (get_token() == LP)){
            v = sin(expr(true));
        }
        else if ((string_value == "cos") && (get_token() == LP)){
            v = cos(expr(true));
        }
        else if ((string_value == "tg") && (get_token() == LP)){
            v = tan(expr(true));
        }
        else if ((string_value == "ln") && (get_token() == LP)){
            v = log(expr(true));
        }
        else if (get_token() == ASSIGN){
            v = expr(true);
        }
        return v;
    };
    case MINUS:   
        return -prim(true);
    case LP:
    {
        double e = expr(true);
        if (curr_tok != RP)return error(") EXPECTED");
        get_token();
        return e;
    };
    default:   
        return error(" SHOULD BE PRIMARY");
    };
};
 
Token_value Calculator::get_token()                             
{
    char ch;
    
    do { 
        if (!cin.get(ch))return curr_tok = END; } 
    while (ch != '\n'&&isspace(ch));
    
    switch (ch)
    {
    
    case ':': case '*': case '/': case '+':
    case '-': case '^': case '(': case ')':
    case '=':
        return curr_tok = Token_value(ch);

    case '0': case '1': case '2': case '3':
    case '4': case '5': case '6': case '7':
    case '8': case '9':
    case '.':
        cin.putback(ch);
        cin >> number_value;
        return curr_tok = NUMBER;

    case ';':
    case '\n':
        no_of_strings++;
        return curr_tok = PRINT;
 
    default:
        if (isalpha(ch))
        {
            string_value = ch;
            while (cin.get(ch) && isalnum(ch))
                string_value.push_back(ch);
            cin.putback(ch);
            return curr_tok = NAME;
        };
        error(" INCORECT WORD");
        return curr_tok = PRINT;
    };
};
 
int Calculator:: error(const string s)
{
    
    cerr << no_of_strings << " - ERROR:" << s << '\n';
    no_of_errors++;
    return 1;
};
 
int main()
{
    
    Calculator a;

    table["pi"] = 3.1415926535897932385;
    table["e"] = 2.7128272824590452354;
 
    while (cin)
    {
        a.get_token();
        if (curr_tok == END)break;
        if (curr_tok == PRINT)continue;
        cout << a.expr(false) << '\n';
    };
    
    return no_of_errors;
};