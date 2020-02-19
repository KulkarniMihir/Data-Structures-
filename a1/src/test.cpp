//============================================================================
// Name        : test.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include<cstring>
using namespace std;
#include"stk.h"
//#include"stk.cpp"
stk k;

class expression
{
	public:
		//char infix[30],postfix[30],prefix[30];
		void input();
		void infix_to_postfix(char infix[30],char postfix[30]);
		void infix_to_prefix(char infix[30],char prefix[30]);
		int precedence(char x);
		void disp();
		int associativity();
		void eval_prefix(char prefix[30]);
	    void eval_postfix(char postfix[30]);
	    int evaluate(char x,int op1,int op2);
};

/*void expression::input()
{
	cout<<"\nEnter string to check : ";
	cin>>infix;
	cout<<"\n";
}*/

void expression::infix_to_postfix(char infix[30],char postfix[30])
{
//	node p;
	char x;
	int i=0,j=0;
	char token;
	//k.push('#');
	for(i=0;infix[i]!='\0';i++)
	{
	  token=infix[i];
	  if((token >='A' && token <='Z') || (token>='a' && token<='z'))		//if operand put into postfix
	  {
	      postfix[j++]=token;
	  }
	  else if(token=='(')		//if left parenthesis push into stack
	     {
	       k.push('(');
	     }
	     else if(token==')')		//if right parenthesis pop until left occurs
	       {
	          while((x=k.pop())!='(')
	          {
	             postfix[j++]=x;
	          }
	       }
	     else					//else check precedence of operator
	     {
	    	 x=k.peek();
	    /*	 cout<<x<<"\n";
	    	 cout<<precedence(token)<<"\n";
	    	 cout<<precedence(x)<<"\n";
	    	 */
	    	 if(precedence(token)==precedence(x) && !k.empty() && token=='^')
	    	 {
	    		 /*if(precedence(token)=='^')
	    		 {
	    			 k.push(token);
	    		 }
	    		 else
	    		 {
	    			 x=k.pop();
	 	    	 	 postfix[j++]=x;
	    		 }*/
	    		 k.push(token);
	  		 }
	    	 else
	    	 {
	    		 while(precedence(token)<=precedence(x) && !k.empty() )
	    		 {
	    			 x=k.pop();
	    		 	 postfix[j++]=x;
	    		 }
				 k.push(token);
	    	 }

	     }
	}
	   // while(k.peek()!='#')
		while(!k.empty())
		 {
	        x=k.pop();
	        postfix[j++]=x;
	     }
		k.pop();
	    postfix[j]='\0';
}

void expression::infix_to_prefix(char infix[30],char prefix[30])
{
	int i,j;
	char temp,in1[30];
	 cout<<"\n1.Infix expression entered :";
	 for(i=0;i<=strlen(infix)-1;i++)
	 {
	  cout<<infix[i];
	 }
	 for(i=strlen(infix)-1,j=0;i>=0;i--,j++)
		 in1[j]=infix[i];
	 in1[j]='\0';

	 cout<<"\n2.Swapping brackets & reversing : ";
	 for(i=0;i<=strlen(in1)-1;i++)
	 {
	  cout<<in1[i];
	 }

	 for(i=0;in1[i]!='\0';i++)
	 {
		 if(in1[i]=='(')
			 in1[i]=')';
	     else
	         if(in1[i]==')')
	             in1[i]='(';
	    }
	 cout<<"\n3. New infix expression for conversion : ";
	 for(i=0;i<=strlen(in1)-1;i++)
	 {
	  cout<<in1[i];
	 }
	 cout<<"\n4. Prefix is : ";
	 infix_to_postfix(in1,prefix);
	 for(i=0,j=strlen(prefix)-1;i<j;i++,j--)
	 {
		 temp=prefix[i];
	     prefix[i]=prefix[j];
	     prefix[j]=temp;
	 }
}

int expression::precedence(char x)
{
   if(x=='(')
   {
      return(0);
   }
   else if(x=='+'||x=='-')
   {
       return(1);
   }
   else  if(x=='*'||x=='/'||x=='%')
   {
     return(2);
   }
   else  if(x=='^')
   {
	  return(3);
   }
   else
	   return(-1);
}


void expression::eval_prefix(char prefix[30])
{
  char x;
  int op1,op2,val,i;
  for(i=strlen(prefix);i>=0;i--)
   {
     x=prefix[i];
     if((x >='A' && x <='Z') || (x>='a' && x<='z'))
      {
         cout<<"\nEnter the value of "<<x<<":";
         cin>>val;
         k.push(val);
      }
    else
     {
       op1=k.pop();
       op2=k.pop();
       val=evaluate(x,op1,op2);
       k.push(val);
     }
   }
  val=k.pop();
  cout<<"\nValue of expression is "<<val;
}

void expression::eval_postfix(char postfix[30])
{
  char x;
  int op1,op2,val,i;

  for(i=0;postfix[i]!='\0';i++)
   {
     x=postfix[i];
     if((x >='A' && x <='Z') || (x>='a' && x<='z'))
      {
         cout<<"\nEnter the value of "<<x<<":";
         cin>>val;
         k.push(val);
      }
    else
     {
       op2=k.pop();
       op1=k.pop();
       val=evaluate(x,op1,op2);
       k.push(val);
     }
   }
val=k.pop();
cout<<"\nValue of expression is "<<val;
}

int expression::evaluate(char x,int op1,int op2)
{
	if(x == '+')
		return(op1+op2);
	if(x == '-')
		return(op1-op2);
	if(x == '*')
		return(op1*op2);
	if(x == '/')
		return(op1/op2);
	if(x == '%')
		return(op1%op2);
	if(x == '^')
		return(op1^op2);
}

int main()
{
	char infix[30],postfix[30],prefix[30];
	int ch;
	expression e;

	do
	{
		cout<<"\nEXPRESSION EVALUATION\n1.INPUT STRING\n2.InfixToPostfix\n3.InfixToPrefix\n0.EXIT";
		cout<<"\nEnter your choice :";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter string to check : ";
					cin>>infix;
					cout<<"\n";
				break;
			case 2:
				cout<<"\nInfix expression entered :"<<infix;
				e.infix_to_postfix(infix,postfix);
				cout<<"\nPostfix expression :"<<postfix;
				cout<<"\n\nEvaluation of Postfix expression :";
				e.eval_postfix(postfix);
				cout<<"\n";
				break;
			case 3:
				cout<<"\nInfix expression entered :"<<infix;
				e.infix_to_prefix(infix,prefix);
				cout<<"\nPrefix expression :"<<prefix;
				cout<<"\n\nEvaluation of Prefix expression :";
				e.eval_prefix(prefix);
				cout<<"\n";
				break;
			case 0:
				cout<<"\nProgram Closed\n";
				break;
			default:
				cout<<"\n---Invalid entry ! Re-enter :";
			}
		}while(ch!=0);

	return 0;
}
