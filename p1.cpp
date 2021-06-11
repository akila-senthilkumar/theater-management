
#include<string.h>
#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<fstream>
#include "p1.h"
int main() 
{

	int choice,c,b,d;
	string a,s,p;
    char *pw;
    pw = new char[25];
	string item;
	avlTree avl;

    while (1) 
	{
		cout<<"\n-----------------------------------------------------------------------------------------------------";
		cout<<"--------------------------------------------------------------------------------------------------"<<endl;
		cout<<"\n\t\t\t\t\t\t\t   _____ ____ ________     __     _____ _____ _   _ ______ __  __          ";
		cout<<"\n\t\t\t\t\t\t\t  / ____/ __ \\___  /\\ \\   / /    / ____|_   _| \\ | |  ____|  \\/  |   /\\    ";
		cout<<"\n\t\t\t\t\t\t\t | |   | |  | | / /  \\ \\_/ /    | |      | | |  \\| | |__  | \\  / |  /  \\   ";
		cout<<"\n\t\t\t\t\t\t\t | |   | |  | |/ /    \\   /     | |      | | | . ` |  __| | |\\/| | / /\\ \\ ";
		cout<<"\n\t\t\t\t\t\t\t | |___| |__| / /__    | |      | |____ _| |_| |\\  | |____| |  | |/ ____ \\ ";
		cout<<"\n\t\t\t\t\t\t\t  \\_____\\____/_____|   |_|       \\_____|_____|_| \\_|______|_|  |_/_/    \\_\\";
		cout<<"\n\n----------------------------------------------------------------------------------------------------";
		cout<<"---------------------------------------------------------------------------------------------------"<<endl;
		logout:
		cout<<"\n\n\nLogin as Admin? 0/1: ";
        cin>>c;
        if(c==1) //admin 
        {
            cout<<"Enter password: ";
            cin>>pw;
            if(strcmp("Caramel",pw)==0)
            {
                while(c==1)
                {
					
					cout<<"\n\n";
					cout<<"\n\t\t\t+-----------------------+";
					cout<<"\n\t\t\t|         MENU          |";
					cout<<"\n\t\t\t+-----------------------+";
                    cout<<"\n\t\t\t|1. INSERT \t\t|\n\t\t\t|2. DISPLAY ALL \t|\n\t\t\t|3. REMOVE \t\t|\n\t\t\t|4. DISPLAY BOOKED \t|\n\t\t\t|";
					cout<<"5. DISPLAY AVAILABLE   |\n\t\t\t|6. SEARCH SEAT \t|\n\t\t\t|7. LOGOUT\t\t|\n";
					cout<<"\t\t\t+-----------------------+";
					cout<<"\n\n";
					cout<<"Enter your option:\t";
                    cin>>b;
					switch(b)
                    {
                        case 1:
                        	cout<<"ENTER SEAT NUMBER:\t";
                        	cin>>item;
                            root = avl.insert(root, item);
                            break;

                        case 2:
                            if (root == NULL)
                            {
                                cout<<"Tree is Empty"<<endl;
                                continue;
                            }    
                            cout<<"\n\n\t\t\t\tSEAT VIEW"<<endl;
							cout<<"\t\t\t\t--------\n";
                            avl.display(root, 1);
                            break;

                        case 3:
                            cout<<"ENTER SEAT TO DELETE:\t";
            				cin>>a;
            				avl.deleteNode(root,a);
            				cout<<"\n"<<a<<" has been removed";
            				break;
    
		    			case 4:
		    					cout << "\n\n\t\t\tLIST OF SEATS BOOKED" << endl;
								cout<<"\t\t\t---------------------\n";
		    					avl.displaybooked(root,1);
		    					cout<<"\n";
		    					break;
                        case 5:
		    				cout<<"\n\n\t\t\tLIST OF SEATS AVAILABLE"<<endl;
							cout<<"\t\t\t------------------------\n";
                            avl.displayavail(root,1);
                            cout<<"\n";
                            break;
						case 6:
							cout<<"ENTER SEAT TO SEARCH:\t";
            				cin>>a;
							avl.search(root,a);
		    			case 7:
		    				goto logout;
            			default:
                            cout<<"WRONG CHOICE";
							goto logout;
                    }
											
                }
            }
            else
            {
                cout<<"INCORRECT PASSWORD\n";
            }
        }
        while(c!=1) //customer
		{
			int a;
            cout<<"\nRegister or Login(0)\n";
            cin>>a;
			if(a==0)
            {	//file implementation for user login
                string username;
			    string password;
			    string xuser;
			    string xpass;
			    ifstream xFile;
			    ofstream cFile;
			    xFile.open("login.txt");
			    cFile.open("login.txt");
			    cout<<"Register"<<endl;
			    cout<<"Username: ";
			    cin>>username;
			    cout<<"Password: ";
			    cin>>password;
			    cFile << username << endl;
			    cFile << password << endl;
			    cout<<"Login"<<endl;
			    cout<<"Username: ";
			    cin>>username;
			    cout<<"Password: ";
			    cin>>password;
			    xFile >> xuser;
			    xFile >> xpass;
			    if(username == xuser && password == xpass)
			    {
			    	cout<<"Username correct"<<endl;
                    cout<<"Password correct"<<endl;
                    while(1)
                        {
							
							cout<<"\n\n";
							cout<<"\n\t\t\t+-----------------------+";
							cout<<"\n\t\t\t|          MENU         |";
							cout<<"\n\t\t\t+-----------------------+";

							cout<<"\n\t\t\t|1.AVAILABLE SEATS\t|\n\t\t\t|2.BOOK\t\t\t|\n\t\t\t|3.CANCEL\t\t|\n\t\t\t|4.LOGOUT\t\t|\n\t\t\t|5.LOGOUT & EXIT\t|\n";
							cout<<"\t\t\t+-----------------------+";
							cout<<"\n\n";
							cout<<"Enter your option:\t";
			                cin >> d;
			                switch(d)
			                {
			            	    case 1:
									cout<<"\n\n\t\t\t\tSEAT VIEW"<<endl;
									cout<<"\t\t\t\t--------\n";									
			            	    	avl.displayavail(root,1);
			            	    	cout<<"\n";
			            	    	break;
			            	    case 2:
                                    int tickets, temp;
                                    cout<<"ENTER TOTAL NUMBER OF TICKETS:\t";
                                    cin>>tickets;
									temp = tickets;
                                    if(tickets>count_avail)
									{
										cout<<"Not enough seats!";
									}
									else
			            	    	{
                                        while(tickets)
                                        {
											cout << "ENTER YOUR SEAT:\t";
			            	    	        cin >> s;
			            	    	        avl.booking(s);
                                            --tickets;
                                        }
                                        checker:
                                        if(booked==temp)
                                        {
											
                                            cout<<"\n\n\t\t\tBILL FOR "<<temp<<" TICKETS"<<endl;
											cout<<"\t\t\t------------------------\n";
                                            avl.billing(temp);
											booked=0;
                                        }
                                        else
                                        {
                                            --temp;
                                            goto checker;
                                        }
                                    }
                                
			            	    	break;
			            	    case 3:
			            	    	cout << "ENTER THE SEAT TO CANCEL:\t";
			            	    	cin >> p;
			            	    	avl.cancel(p);
			            	    	break;
			            	    case 4:
			    	    	        booked=0;
			    	    	    	goto logout;
                                    break;
								case 5:
									cout<<"\t\t\t\t\t\t\n  _______ _                 _     __     __         _ _ ";
									cout<<"\t\t\t\t\t\t\n  |__   _| |               | |    \\ \\   / /        | | |";
									cout<<"\t\t\t\t\t\t\n    | |  | |___   __ _ _ __| | __  \\ \\_/ /__  _   _| | |";
									cout<<"\t\t\t\t\t\t\n    | |  | '_  || _` | '_ || |/ /   \\   / _ || | | | | |";
									cout<<"\t\t\t\t\t\t\n    | |  | | | | (_| | | | |   <     | | (_) | |_| |_|_|";
									cout<<"\t\t\t\t\t\t\n    |_|  |_| |_||__,_|_| |_|_||_|    |_||___| |__,_(_|_)";
									cout<<"\n\n\n";
									exit(0);
                                default:									 
                                    goto logout;						
			                }   
                        }
		            }
			        else
			        {
			        	 cout<<"Incorrect details\nlogin again";
			        }
			    xFile.close();
			    cFile.close();
		    }
        }
    }		 
	return 0;
}