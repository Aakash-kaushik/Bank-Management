
#include <fstream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
class openacc
{
public:
char securityquestion[100],securityanswer[100],name[100],newname[100],adr[200],newadr[200],dob[15],newdob[15],typeofacc[10],phone[20],newphone[20],aadhar[13],newaadhar[13],idproof[50],newidproof[50],adrproof[50],newadrproof[50],nationality[30],newnationality[30],mothername[100],newmothername[100],fathername[100],newfathername[100],addofbirth[200],newaddofbirth[200],email[50],newemail[50],religion[20],newreligion[20],occupation[30],newoccupation[30];
int age,newage,randomloop,pin,userpin,securityloop,attempt;
float balance;
openacc()
{
	balance=0;
	attempt=3;
}

int create()
{
	clrscr();
	cout<<"Enter your name: "; gets(name);
	cout<<"Enter your phone number: "; gets(phone);
	cout<<"Enter your address: "; gets(adr);
	cout<<"Enter your date of birth in format DD/MM/YYY: "; gets(dob);
	cout<<"Enter age: "; cin>>age;
	cout<<"Enter your aadhar number: "; gets(aadhar);
	cout<<"Enter mother's name: "; gets(mothername);
	cout<<"Enter father's name: "; gets(fathername);	
	cout<<"ID proof: "; gets(idproof);
	cout<<"Residential proof: "; gets(adrproof);
	cout<<"Enter your nationality: "; gets(nationality);
	cout<<"Enter your religion: "; gets(religion);
	cout<<"Enter email address: "; gets(email);
	cout<<"Occupation: "; gets(occupation);
	cout<<"Enter the type of account you want to open:"<<"\n"<<"i.e saving or current: "; gets(typeofacc);	
	cout<<"Security question: used to reset your pin in case you forget it.!"<<endl<<"NOTE: The answer is case sensitive.!"<<endl;
	cout<<"Who's your childhood superhero: "; gets(securityquestion);
	cout<<"Dear "; printf(name); cout<<" XYZ family welcomes you.!!"<<endl;	
	cout<<"Your "; printf(typeofacc); cout<<" account has been created"<<endl;
	pin_gen();
	return 0;
}

int pin_forget()
{
	clrscr();
	cout<<"NOTE: more number of attempts than allowed will result in termination of the program.!"<<endl;
	cout<<"who's your childhood superhero: "; gets(securityanswer);
	resecurity:
	for(securityloop=0;securityloop<='\0';securityloop++)
	if(securityanswer[securityloop]==securityquestion[securityloop])
	{
		cout<<"Enter new pin: "; cin>>userpin;
		pin=userpin;
		cout<<"Pin changed successfully.!"<<endl;
		break;
	}
	else
	{
		cout<<"!!.Wrong answer.!!"<<endl;
		cout<<"Number of attempts left:"<<attempt<<endl;
		attempt=attempt-1;
		if(attempt==0)
		{
			break;
		}
		else
		{
			char choice_security;
			cout<<"1. Try agin"<<endl;
			cout<<"2. exit"<<endl;
			cout<<"Enter your choice: "; cin>>choice_security; cout<<endl;
			switch(choice_security)
			{
				case '1':cout<<"Who's your childhood hero: "; gets(securityanswer);
		   		         goto resecurity;
		              		 break;
		 		case '2':ofstream fout;
		   			 fout.open("bank_database",ios::out);
		   			 fout.write((char*)&info,sizeof(info));
				   	 fout.close();
					 exit(0);
					 break;
			}
		}
	}
	return 0;
}

int withdraw()
{
	clrscr();
	float withdraw_amount;
	cout<<"your current balance is: "<<balance<<" rs"<<endl;
	cout<<"How much money do you want to withdraw: "; cin>>withdraw_amount;
	balance=balance-withdraw_amount;
	cout<<"The remaining amount is: "<<balance<<endl;
	cout<<"Please collect your cash through cash slot"<<endl;
	return 0;
}

int deposit()
{
	clrscr();
	float deposit_amount;
	cout<<"your current balance is: "<<balance<<" rs"<<endl;
	cout<<"How much amount do you want to deposit: "; cin>>deposit_amount;
	balance=balance+deposit_amount;
	cout<<"The new balance in your account is: "<<balance<<endl;
	return 0;
}

int bal_enquiry()
{
	clrscr();
	cout<<"Dear "; printf(name); cout<<" You have "<<balance<<" Rs left in your account"<<endl;
	return 0;
}

int pin_gen()
{
	srand(time(0));
	for(randomloop=0;randomloop<1;randomloop++)
		pin=rand();
	cout<<"Your pin is: "<<pin<<"\n";
	cout<<"Kindly note it down or remember it as it will be used to access your account"<<"\n";
	return 0;
}

int access_account()
{
	clrscr();
	char choice3;
	cout<<"Enter your pin: "; cin>>userpin;
	repin1:
	if(userpin==pin)
		{
			cout<<"welcome "; printf(name); cout<<" .!!"<<endl;
			cout<<"1. Withdraw money"<<endl;
			cout<<"2. Deposit money"<<endl;
			cout<<"3. Balance enquiry"<<endl;
			cout<<"4. exit"<<endl;
			cout<<"Enter your choice: "; cin>>choice3;
			switch(choice3)
				{
					case '1': withdraw();
						  break;
					case '2': deposit();
						  break;
					case '3': bal_enquiry();
						  break;
					case '4': exit(0);
						  break;
				}
		}
	else
		{
			char choice_pin1;
			cout<<"1. Try agin"<<endl;
			cout<<"2. exit"<<endl;
			cout<<"Enter your choice: "; cin>>choice_pin1; cout<<endl;
			switch(choice_pin1)
				{
					case '1':cout<<"Re-Enter your pin: "; cin>>userpin;
						 goto repin1;
		   			         break;
					case '2':ofstream fout;
						 fout.open("bank_database",ios::out||ios::binary);
						 fout.write((char*)&info,sizeof(info));
						 fout.close();
						 exit(0);
						 break;
				}
		}
	return 0;
}

int modify()
{
	clrscr();
	int choice4;
	cout<<"Enter your pin: "; cin>>userpin;
	repin2:
	if(userpin==pin)
		{
			cout<<"What do you want to change: "<<endl;
			cout<<"1. Name"<<endl;
			cout<<"2. Phone number"<<endl;
			cout<<"3. Address"<<endl;
			cout<<"4. Date of birth"<<endl;
			cout<<"5. Age"<<endl;
			cout<<"6. Aadhar number"<<endl;
			cout<<"7. Mother's name"<<endl;	
			cout<<"8. Father's name"<<endl;
			cout<<"9. Id proof"<<endl;
			cout<<"10. Residential proof"<<endl;
			cout<<"11. Nationality"<<endl;
			cout<<"12. Religion"<<endl;
			cout<<"13. Email"<<endl;
			cout<<"14. Occupation"<<endl;
			cout<<"15. Pin"<<endl;
			cout<<"16. Exit"<<endl;
			cout<<"Enter choice: "; cin>>choice4;
			switch(choice4)
				{
					case 1: cout<<"Enter new name: "; gets(newname);
						strcpy(name,newname);
						break;
					case 2: cout<<"Enter new phone number: "; gets(newphone);
						strcpy(phone,newphone);
						break;
					case 3: cout<<"Enter new address: "; gets(newadr);
						strcpy(adr,newadr);
						break;
					case 4: cout<<"Enter new date of birth: "; gets(newdob);
						strcpy(dob,newdob);
						break;
					case 5: cout<<"Enter new age: "; cin>>newage;
						age=newage;
						break;
					case 6: cout<<"Enter new aadhar number:"; gets(newaadhar);
						strcpy(aadhar,newaadhar);
						break;
					case 7: cout<<"Enter new Mother's name: "; gets(newmothername);
						strcpy(mothername,newmothername);
						break;
					case 8: cout<<"Enter new Father's name: "; gets(newfathername);
						strcpy(fathername,newfathername);
						break;
					case 9: cout<<"Enter new Id proof: "; gets(newidproof);
						strcpy(idproof,newidproof);
						break;
					case 10:cout<<"Enter new residential proof: "; gets(newadrproof);
						strcpy(adrproof,newadrproof);
						break;
					case 11:cout<<"Enter new nationality: "; gets(newnationality);
						strcpy(nationality,newnationality);
						break;
					case 12:cout<<"Enter new religion: "; gets(newreligion);
						strcpy(religion,newreligion);
						break;
					case 13:cout<<"Enter new Email: "; gets(newemail);
						strcpy(email,newemail);
						break;
					case 14:cout<<"Enter new occupation: "; gets(newoccupation);
						strcpy(occupation,newoccupation);
						break;
					case 15:cout<<"Enter old pin: "; cin>>userpin;
						if(userpin==pin);
							{
								cout<<"Enter the new pin: "; cin>>userpin;
								pin=userpin;
							}
	       					break;
					case 16: ofstream fout;
					         fout.open("bank_database",ios::out||ios::binary);
						 fout.write((char*)&info,sizeof(info));
					         fout.close();
					         exit(0);
					         break;
				}
	cout<<"Details successfully modified.!!"<<endl;
		}
	else
		{
			char choice_pin2;
			cout<<"1. Try agin"<<endl;
			cout<<"2. exit"<<endl;
			cout<<"Enter your choice: "; cin>>choice_pin2; cout<<endl;
			switch(choice_pin2)
				{
					case '1':cout<<"Re-Enter your pin: "; cin>>userpin;
					         goto repin2;
					         break;
					case '2':ofstream fout;
					         fout.open("bank_database",ios::out||ios::binary);
					         fout.write((char*)&info,sizeof(info));
					         fout.close();
					         exit(0);
					         break;
				}
		}
	return 0;
}

int show_data()
{
	cout<<"Enter pin: "; cin>>userpin; cout<<endl;
	repin3:
	if(pin==userpin)
		{
			cout<<"Name: "; puts(name);
			cout<<"Phone number: "; puts(phone);
			cout<<"Address: "; puts(adr);
			cout<<"Date of birth: "; puts(dob);
			cout<<"Age: "<<age;
			cout<<"Aadhar number: "; puts(aadhar);
			cout<<"Mother's name: "; puts(mothername);
			cout<<"Father's name: "; puts(fathername);
			cout<<"ID proof: "; puts(idproof);	
			cout<<"Residential proof: "; puts(adrproof);
			cout<<"Nationality: "; puts(nationality);
			cout<<"Religion: "; puts(religion);
			cout<<"Email address: "; puts(email);
			cout<<"Occupation: "; puts(occupation);		
			cout<<"You have a "; printf(typeofacc); cout<<" account in our bank"<<endl;
		}
	else
		{
			char choice_pin3;
			cout<<"1. Try agin"<<endl;
			cout<<"2. exit"<<endl;
			cout<<"Enter your choice: "; cin>>choice_pin3; cout<<endl;
			switch(choice_pin3)
				{
					case '1':cout<<"Re-Enter your pin: "; cin>>userpin;
						 goto repin3;
						 break;
					case '2':ofstream fout;
						 fout.open("bank_database",ios::out||ios::binary);
						 fout.write((char*)&info,sizeof(info));
						 fout.close();
						 exit(0);
						 break;
				}
		}
	return 0;
}

}; //CLOSING CLASS
openacc info; //CREATION OF CLASS OBJECT

int main()
{
		char choice1;
		char choice2;
		ifstream fin("Bank_database",ios::in||ios::binary); //OPENING THE FILE FOR READING
		fin.read((char*)&info,sizeof(info));
		fin.close();
		clrscr();
		repeat:
		cout<<"\t"<<"WELCOME TO XYZ BANK"<<endl;
		cout<<"\t"<<"1. Create account"<<endl;
		cout<<"\t"<<"2. Access your account"<<endl;
		cout<<"\t"<<"3. Modify account"<<endl;
		cout<<"\t"<<"4. Show my account"<<endl;
		cout<<"\t"<<"5. Forgot pin"<<endl;
		cout<<"\t"<<"6. Exit"<<endl;
		cout<<"\t"<<"Enter your choice: "; cin>>choice1;
		switch(choice1)
			{
				case '1': info.create();
					   break;
				case '2': info.access_account();
					    break;
				case '3': info.modify();
					    break;
				case '4': info.show_data();
					    break;
				case '5': info.pin_forget();
					    break;
				case '6': exit(0);
					    break;
			}
		cout<<"Do you want to continue (Y/N): "; cin>>choice2; cout<<endl;
		if(choice2=='Y'||choice2=='y')
			{
				clrscr();
				goto repeat;
			}
		else
			{
				ofstream fout;
				fout.open("bank_database",ios::out||ios::binary);
				fout.write((char*)&info,sizeof(info));
				fout.close();
				exit(0);
			}
	getch();
	return 0;
}



