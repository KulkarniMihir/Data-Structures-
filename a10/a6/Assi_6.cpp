//============================================================================
// 	 Class              : SE
// 	 Batch              : F9
//	 Roll No.           : 23133
//	 Name               : Mihir
// 	 Assignment no.     : 6	
//============================================================================

//Inclusion of header files
#include "graph_imp.cpp"

int main()
{
	Graph G; //object of graph
	int ch;
	cout<<"*********************************************************************";
	do
	{
		cout<<"\n\n\nMENU"<<endl;
		cout<<"1.CREATE GRAPH\n";
		cout<<"2.SHOW GRAPH\n";
		cout<<".ADD NEW USER\n";
		cout<<"4.ADD FRIEND\n";
		cout<<"5.DFS\n6.BFS\n";
		cout<<"7.USER WITH MAXIMUM FRIENDS\n";
		cout<<"8.USER WITH MAXIMUM AND MINIMUM COMMENTS\n";
		cout<<"9.USERS HAVING BIRTHDAY IN THE SAME MONTH\n";
		cout<<"10.EXIT\n";
		cout<<"Enter choice  :: ";
		cin>>ch;
		
		switch(ch)
		{
		case 1:
			G.user_details();
			G.create_graph();
			break;
			
		case 2:
			G.display_link();
			break;
			
		case 3:
			G.add_user();
			break;

		case 4:
			G.add1_friend();
			break;
			
		case 5:
			G.DFS();
			break;
			
		case 6:
			G.BFS();
			break;
			
		case 7:
			G.maxFriends();
			break;
			
		case 8:
			G.maxComments();
			break;
			
		case 9:
			G.birthday_same_month();
			break;
			
		case 10:
			break;
			
		default:
			cout<<"Invalid choice\n";
		}
		
	}while(ch!=10);

	return 0;
}
