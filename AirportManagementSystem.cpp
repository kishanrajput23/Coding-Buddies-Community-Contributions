#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    //initializing the arrays for storing arlines data
    string AirlineTitle[5] = {"American-Airline", "Emirates-Airline", "Singapore-Airline", "Turksih-Airline", "British-Airways"};
    string Sample1[5] = {}; 
    string AirlineTime[5] = {"11:26AM-06:10PM", "12:28PM-07:00PM", "03:00AM-08:15PM", "02:15PM-06:30PM", "09:00PM-12:00AM"};
    string Sample2[5] = {};
    int AirlineCode[5] = {112, 102, 297, 235, 125};
    int AirlinePass[5] = {150, 458, 600, 225, 125};
    //finding arrays lenght to calculate the total number of elements present in the arrays and storing them into thier size variables
    int titleSize = sizeof(AirlineTitle) / sizeof(AirlineTitle[0]);
    int codeSize = sizeof(AirlineCode) / sizeof(AirlineCode[0]);
    int PassSize = sizeof(AirlinePass) / sizeof(AirlinePass[0]);
    int TimeSize = sizeof(AirlineTime) / sizeof(AirlineTime[0]);
    int op;
    char choice;
    cout << "\t Welcome To Airport Managment System\t" << endl;
    //for menu using do-while loop
    do
    {
        cout << "\nSelect which operation would you like to perform:" << endl;
        cout << "1. Traverse\n2. Search\n3. Update\n4. Insert\n5. Delete\n6. Exit" << endl;
        cin >> op;
        //using switch loop because we want our operations in cases
        switch (op)
        {
        case 1:
            //for traversing just display stored data in arrays
            cout << "Which array would you like to traverse:\n1. Airline Title\n2. Airline #Code\n3. Airline #Passengers\n4. A & D Time\n5. All Data" << endl;
            int slct1;
            cin >> slct1;
            if (slct1 == 1)
            {
                for (int i = 0; i < titleSize; i++)
                {
                    cout << "AirlineTitle[" << i << "] = " << AirlineTitle[i] << endl;
                }
            }
            else if (slct1 == 2)
            {
                for (int i = 0; i < codeSize; i++)
                {
                    cout << "AirlineCode[" << i << "] = " << AirlineCode[i] << endl;
                }
            }
            else if (slct1 == 3)
            {
                for (int i = 0; i < PassSize; i++)
                {
                    cout << "AirlinePass[" << i << "] = " << AirlinePass[i] << endl;
                }
            }
            else if (slct1 == 4)
            {
                for (int i = 0; i < TimeSize; i++)
                {
                    cout << "AirlineTime[" << i << "] = " << AirlineTime[i] << endl;
                }
            }
            else if (slct1 == 5)
            {
            	cout<<"1. Before Insertation \n2. After Insertation "<<endl;
            	int choice;
            	cin>>choice;
            	if(choice==1)
            	{
            		cout<< "=========================================================================\n";
                	for (int i = 0; i <5; i++)
                	{
                    	cout << " " << AirlineTitle[i] << "\t" << AirlineCode[i] << "\t\t" << AirlinePass[i] << "\t\t" << AirlineTime[i] << endl;
                    
                	}	
				}
				if(choice==2)
				{
					cout << " Airline Title\t     Airline Code    Airline #Pass\t   A&D Time" << endl
                    << "=========================================================================\n";
                	for (int i = 0; i < 6; i++)
                	{
                    cout << " " << AirlineTitle[i] << "\t" << AirlineCode[i] << "\t\t" << AirlinePass[i] << "\t\t" << AirlineTime[i] << endl;
                	}	
				}
            }
            break;
        case 2:
            cout << "Which array would you like to search:\n1. Airline Title\n2. Airline #Code\n3. Airline #Passengers\n4. A&D Time" << endl;
            int slct2;
            cin >> slct2;
            if (slct2 == 1)
            {
                cout << "Enter the item you want to search for" << endl;
                string item;
                cin >> item;
                int i;
                //for searching element in array we start our our loop untill less than titleSize
                //and in if condition we compare AirlineTitle[] with item which storing given input
                //if match then index found otherwise not
                for (i = 0; i < titleSize; i++)
                {
                    if (AirlineTitle[i] == item)
                    {
                        cout << "Element found at index AirlineTitle[" << i << "]" << endl;
                        break;
                    }
                }
                if (i == titleSize)
                {
                    cout << "Oops! Element Not Present in Input Array\n";
                }
            }
            else if (slct2 == 2)
            {
                cout << "Enter the item you want to search for" << endl;
                int item;
                cin >> item;
                int i;
                for (i = 0; i < codeSize; i++)
                {
                    if (AirlineCode[i] == item)
                    {
                        cout << "Element found at index AirlineCode[" << i << "]" << endl;
                        break;
                    }
                }
                if (i == codeSize)
                {
                    cout << "Oops! Element Not Present in Input Array\n";
                }
            }
            else if (slct2 == 3)
            {
                cout << "Enter the item you want to search for" << endl;
                int item;
                cin >> item;
                int i;
                for (i = 0; i < PassSize; i++)
                {
                    if (AirlinePass[i] == item)
                    {
                        cout << "Element found at index AirlinePass[" << i << "]" << endl;
                        break;
                    }
                }
                if (i == PassSize)
                {
                    cout << "Oops! Element Not Present in Input Array\n";
                }
            }
            else if (slct2 == 4)
            {
                cout << "Enter the item you want to search for" << endl;
                string item;
                cin >> item;
                int i;
                for (i = 0; i < TimeSize; i++)
                {
                    if (AirlineTime[i] == item)
                    {
                        cout << "Element found at index AirlineTime[" << i << "]" << endl;
                        break;
                    }
                }
                if (i == TimeSize)
                {
                    cout << "Oops! Element Not Present in Input Array\n";
                }
            }
            break;
        case 3:
            cout << "Which array would you like to update:\n1. Airline Title\n2. Airline #Code\n3. Airline #Passengers\n4. A&D Time" << endl;
            int slct3;
            cin >> slct3;
            if (slct3 == 1)
            {
                cout << "The array before updation is :" << endl;
                for (int i = 0; i < titleSize; i++)
                {
                    cout << "AirlineTitle[" << i << "] = " << AirlineTitle[i] << endl;
                }
                //for updating arrays element we take position and value from user
                //then we pass our postion into AirlineTitle[] array then equal it with our value
                cout << "Enter the position of item you want to update:\n";
                int pos;
                cin >> pos;
                cout << "Enter the value of the updated element:" << endl;
                string item;
                //getline(cin,item);
                cin >> item;
                AirlineTitle[pos] = item;
                cout << "The updated array is :" << endl;
                for (int i = 0; i < titleSize; i++)
                {
                    cout << "AirlineTitle[" << i << "] = " << AirlineTitle[i] << endl;
                }
            }
            if (slct3 == 2)
            {
                cout << "The array before updation is :" << endl;
                for (int i = 0; i < codeSize; i++)
                {
                    cout << "AirlineCode[" << i << "] = " << AirlineCode[i] << endl;
                }
                cout << "Enter the position of item you want to update:\n";
                int pos;
                cin >> pos;
                cout << "Enter the value of the updated element :" << endl;
                int item;
                cin >> item;
                AirlineCode[pos] = item;
                cout << "The updated array is :" << endl;
                for (int i = 0; i < codeSize; i++)
                {
                    cout << "AirlineCode[" << i << "] = " << AirlineCode[i] << endl;
                }
            }
            if (slct3 == 3)
            {
                cout << "The array before updation is :" << endl;
                for (int i = 0; i < PassSize; i++)
                {
                    cout << "AirlinePass[" << i << "] = " << AirlinePass[i] << endl;
                }
                cout << "Enter the position of item you want to update:\n";
                int pos;
                cin >> pos;
                cout << "Enter the value of the updated element:" << endl;
                int item;
                cin >> item;
                AirlinePass[pos] = item;
                cout << "The updated array is:" << endl;
                for (int i = 0; i < PassSize; i++)
                {
                    cout << "AirlinePass[" << i << "] = " << AirlinePass[i] << endl;
                }
            }
            if (slct3 == 4)
            {
                cout << "The array before updation is :" << endl;
                for (int i = 0; i < titleSize; i++)
                {
                    cout << "AirlineTime[" << i << "] = " << AirlineTime[i] << endl;
                }
                cout << "Enter the position of item you want to update:\n";
                int pos;
                cin >> pos;
                cout << "Enter the value of the updated element:" << endl;
                string item;
                //getline(cin,item);
                cin >> item;
                AirlineTime[pos] = item;
                cout << "The updated array is :" << endl;
                for (int i = 0; i < titleSize; i++)
                {
                    cout << "AirlineTime[" << i << "] = " << AirlineTime[i] << endl;
                }
            }
            break;
        case 4:
            cout << "Which array would you like to insert:\n1. Airline Title\n2. Airline #Code\n3. Airline #Passengers\n4. A&D Time" << endl;
            int slct4;
            cin >> slct4;
            if (slct4 == 1)
            {
                string item;
                int pos, i;
                cout << "The array elements before insertion are :\n";

                for (i = 0; i < titleSize; i++)
                {
                    cout << "AirlineTitle[" << i << "] = " << AirlineTitle[i] << endl;
                }
                // Take a position of a new element
                cout << "\nWhere you would you like to insert the element:\n0.Start of Array\n1-4.Between\n5.End of Array\n";
                cin >> pos;
                //Input value of an element to be inserted
                cout << "Enter the element you would like to insert:" << endl;
                cin >> item;
                titleSize++; //increment in size
                //Shift element by one position
                for (i = titleSize; i >= pos; i--)
                {
                    AirlineTitle[i + 1] = AirlineTitle[i];
                }
                //Insert new value in an array
                AirlineTitle[pos] = item;

                cout << "\nThe array elements after insertion are :\n";

                for (i = 0; i < titleSize; i++)
                {
                    cout << "AirlineTitle[" << i << "] = " << AirlineTitle[i] << endl;
                }
            }
            else if (slct4 == 2)
            {
                int pos, i, item;
                cout << "The array elements before insertion are :\n";

                for (i = 0; i < codeSize; i++)
                {
                    cout << "AirlineCode[" << i << "] = " << AirlineCode[i] << endl;
                }
                // Take a position of a new element
                cout << "\nWhere you would you like to insert the element:\n0.Start of Array\n1-4.Between\n5.End of Array\n";
                cin >> pos;
                //Input value of an element to be inserted
                cout << "Enter the element you would like to insert:" << endl;
                cin >> item;
                codeSize++;
                //Shift element by one position
                for (i = codeSize; i >= pos; i--)
                {
                    AirlineCode[i + 1] = AirlineCode[i];
                }
                //Insert new value in an array
                AirlineCode[pos] = item;

                cout << "\nThe array elements after insertion are :\n";

                for (i = 0; i < codeSize; i++)
                {
                    cout << "AirlineCode[" << i << "] = " << AirlineCode[i] << endl;
                }
            }
            else if (slct4 == 3)
            {
                int pos, i, item;
                cout << "The array elements before insertion are :\n";

                for (i = 0; i < PassSize; i++)
                {
                    cout << "AirlinePass[" << i << "] = " << AirlinePass[i] << endl;
                }
                // Take a position of a new element
                cout << "\nWhere you would you like to insert the element:\n0.Start of Array\n1-4.Between\n5.End of Array\n";
                cin >> pos;
                //Input value of an element to be inserted
                cout << "Enter the element you would like to insert:" << endl;
                cin >> item;
                PassSize++;
                //Shift element by one position
                for (i = PassSize; i >= pos; i--)
                {
                    AirlinePass[i + 1] = AirlinePass[i];
                }
                //Insert new value in an array
                AirlinePass[pos] = item;

                cout << "The array elements after insertion are :\n";

                for (i = 0; i < PassSize; i++)
                {
                    cout << "AirlinePass[" << i << "] = " << AirlinePass[i] << endl;
                }
            }
            if (slct4 == 4)
            {
                string item;
                int pos, i;
                cout << "The array elements before insertion are :\n";

                for (i = 0; i < TimeSize; i++)
                {
                    cout << "AirlineTime[" << i << "] = " << AirlineTime[i] << endl;
                }
                cout << "\nWhere you would you like to insert the element:\n0.Start of Array\n1-4.Between\n5.End of Array\n";
                cin >> pos;
                cout << "Enter the element you would like to insert:" << endl;
                cin >> item;
                TimeSize++;
                for (i = TimeSize; i >= pos; i--)
                {
                    AirlineTime[i + 1] = AirlineTime[i];
                }
                //Insert new value in an array
                AirlineTime[pos] = item;

                cout << "\nThe array elements after insertion are :\n";

                for (i = 0; i < TimeSize; i++)
                {
                    cout << "AirlineTime[" << i << "] = " << AirlineTime[i] << endl;
                }
            }
            break;
        case 5:
            cout << "Which array would you like to delete:\n1. Airline Title\n2. Airline #Code\n3. Airline #Passengers\n4. A&D Time" << endl;
            int slct5;
            cin >> slct5;
            if (slct5 == 1)
            {
                int pos, i;
                cout << "Stored values in AirlineTitle array are :" << endl;
                for (i = 0; i < titleSize; i++)
                {
                    cout << "AirlineTitle[" << i << "] = " << AirlineTitle[i] << endl;
                }
                
                // Take a position of a new element
                cout << "\nEnter the index number where you want to delete value:";
                cin >> pos;
                //Shift element by one position
                for (i = pos; i < titleSize; i++)
                {
                    AirlineTitle[i] = AirlineTitle[i + 1];
                }
                titleSize--;

                cout << "\nThe array elements after deletion are :\n";

                for (i = 0; i < titleSize; i++)
                {
                    cout << "AirlineTitle[" << i << "] = " << AirlineTitle[i] << endl;
                }
            }
            else if (slct5 == 2)
            {
                int pos, i;
                cout << "Stored values in AirlineCode array are :" << endl;
                for (i = 0; i < codeSize; i++)
                {
                    cout << "AirlineCode[" << i << "] = " << AirlineCode[i] << endl;
                }
                // Take a position of a new element
                cout << "\nEnter the index number where you want to delete value:";
                cin >> pos;
                //Shift element by one position
                for (i = pos; i < codeSize; i++)
                {
                    AirlineCode[i] = AirlineCode[i + 1];
                }
				codeSize--;
                cout << "\nThe array elements after deletion are :\n";
		
                for (i = 0; i < codeSize; i++)
                {
                    cout << "AirlineCode[" << i << "] = " << AirlineCode[i] << endl;
                }
            }
            else if (slct5 == 3)
            {
                int pos, i;
                cout << "Stored values in AirlinePass array are :" << endl;
                for (i = 0; i < PassSize; i++)
                {
                    cout << "AirlinePass[" << i << "] = " << AirlinePass[i] << endl;
                }
                // Take a position of a new element
                cout << "\nEnter the index number where you want to delete value:";
                cin >> pos;
                //Shift element by one position
                for (i = pos; i < PassSize; i++)
                {
                    AirlinePass[i] = AirlinePass[i + 1];
                }
				
                cout << "\nThe array elements after deletion are :\n";

                for (i = 0; i < PassSize; i++)
                {
                    cout << "AirlinePass[" << i << "] = " << AirlinePass[i] << endl;
                }
            }
            else if (slct5 == 4)
            {
                int pos, i;
                cout << "Stored values in AirlineTitle array are :" << endl;
                for (i = 0; i < TimeSize; i++)
                {
                    cout << "AirlineTime[" << i << "] = " << AirlineTime[i] << endl;
                }
                cout << "\nEnter the index number where you want to delete value:";
                cin >> pos;
                for (i = pos; i < TimeSize; i++)
                {
                    AirlineTime[i] = AirlineTime[i + 1];
                }
                TimeSize--;
                cout << "\nThe array elements after deletion are :\n";

                for (i = 0; i < TimeSize; i++)
                {
                    cout << "AirlineTime[" << i << "] = " << AirlineTime[i] << endl;
                }
            }
        default:
            break;
        }
        //cout << "If you want to continue press (y) if not press something else ?";
        //cin >> choice;
    } while (op != 6);
    //(choice == 'y' || choice == 'Y');

    return (0);
}
