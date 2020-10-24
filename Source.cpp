//Name: Suleman Farooqi
//https://github.com/sulemanfarooqi/ethernetswitch
#include <iostream>  
#include <fstream>      
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main() {

    //Creating the CAM table as table. Creating what is read per line from the text file into textLine
    string table = "";
    string textLine = "";

    //Using a vector is easily manage information, you can remove and append information for each port quickly
    vector<string> port;
    port.push_back("P1: ");
    port.push_back("P2: ");
    port.push_back("P3: ");
    port.push_back("P4: ");
    port.push_back("P5: ");
    port.push_back("P6: ");
    port.push_back("P7: ");
    port.push_back("P8: ");
    
    //creating a method to open a file called in.txt
    ifstream ifs("in.txt");


    //Checking to see if the file has been successfully opened
    if (ifs.is_open()) 
    {

        //A while loop that will go through all the lines in the text file, we go by each line and figure out the information in the frame
        while (!ifs.eof())
        {
            //Reset strings for each loop
            string frameID = "";
            string arrivalPort = "";
            string sourceAdd = "";
            string destinationAdd = "";
            int intArrivalPort = 0;

         
            getline(ifs, textLine);//Get the first line from the input.txt file

            stringstream ss(textLine); // converts string to a stream such as cin

            //information from our ss stream is saved and split with a delimiter in the 3rd parameter
            getline(ss, frameID, '\t');
            getline(ss, arrivalPort, '\t');
            getline(ss, sourceAdd, '-');
            getline(ss, destinationAdd, '.');


            //Since we are only looking at the number in the port alone and not the letter 'P', we are setting the string to the second element which is the port number
            destinationAdd = destinationAdd[1];

            cout << "Frame: " << frameID << endl;
            cout << "Arrival Port: " << arrivalPort << endl;
            cout << "Source Address: " << sourceAdd << endl;
            cout << "Destination Address: " << destinationAdd << endl;

            //This algorithm allows us to search what's in the string 'table' and tells us if we have any matches, initially the table will be empty
            if (table.find(sourceAdd) == string::npos)
            {
                table.append(arrivalPort); // If Port:SourceAdd not found, add in table
                table.append(sourceAdd);
                table.append(" ");
            }

            else
                ;// does nothing

            if (table.find(destinationAdd) == string::npos) // Destination not found in table, which means we have to follow the rule of a switch, send information to all ports except source
            {
                cout << "Destination Address: " << destinationAdd << " - was not found in table" << endl;
                //Convert arrivalPort into integer but remove 'P' from arrivalPort
                arrivalPort.erase(0, 1);
                intArrivalPort = stoi(arrivalPort);
                //Add frameID in all ports except arrival port
                for (int i = 0; i < 8; i++)
                {
                    if (i == intArrivalPort - 1)
                        ;
                    else
                    {
                        port[i].append("\t");
                        port[i].append(frameID);

                    }

                }
            }

            else if (table.find(destinationAdd) != string::npos)
            {
                int found = (table.find(destinationAdd)-1);
                char c = table[found];
                int point = c - '0';
                point = point - 1;

                port[point].append("\t");
                port[point].append(frameID);
            }

            for (int i = 0; i < 8; i++)
            {
                cout << port[i] << endl;
            }

            cout << "Table:" << table << endl;

            cout << "****************************************\n" << endl;


        }

        ifs.close();
        //we need to write our vector called 'port' into a textfile called 'out.txt'

        ofstream ofs("out.txt");
        for (int i = 0; i < 8; i++)
        {
            ofs << port[i] << endl;
        }


        ofs.close();

    }
    else {
        cout << "Error opening file, please make sure text file is with .cpp file";
    }

    return 0;
}