package Main;
import java.util.Scanner;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.File;
import java.util.ArrayList;
import person.*;
import java.util.InputMismatchException;

/**
 * Main class where File of all flights is processed and User Interface is present 
 * Can search for passenger Data
 * returns --> Passenger ID, Miles earned, Tier Program, and True/False for multiplier
 */
public class Main {
    /**
     * Static main method to interact with program
     * @param args
     * @throws IOException - Throws exception if User does not enter a # for ID
     */
    public static void main(String[] args) throws IOException{
        
        ArrayList<Passenger> list = new ArrayList<Passenger>(); // List to hold all Passenger Data
        
        // Declaring and Defining Scanner Objects for File input
        File file = new File("/Users/krishchanda/Desktop/Java/Main/data.txt");
        FileInputStream fileIN = new FileInputStream(file); // File input stream
        Scanner inFS = new Scanner(fileIN); 

        
        // While loop to traverse flight data list
        while (inFS.hasNext()) {
            
            int id = inFS.nextInt(); //Collects ID #

            String isCancelled = inFS.next(); // Collects either "Y" or "N" for if Flight is cancelled
            String hasComplained = "";

            if(!isCancelled.equals("N")){
                hasComplained = inFS.next(); // Collects either "Y" or "N" for if passenger has complained
            }

            boolean isIDPresent = false; // Checks to see if a new passenger is flying or recurring passenger is flying
            for(int i = 0; i < list.size(); i++ ){
                if((list.get(i).getID()) == id){
                    isIDPresent = true; // sets to true if ID of Passenger is allready present
                }
            }

            if(isIDPresent == false){ // Adds a new Passenger to the list
                Passenger a = new Passenger(id); 
                if(isCancelled.equals("Y")){
                    a.addFlight(true); // Adds Cancelled flight if "Y"
                    if(hasComplained.equals("Y")){
                        a.didComplain(true); // Did Complain -> True if "Y"
                    }
                }
                else{
                    a.addFlight(false); // Adds non-cancelled flight if "N"
                }
                list.add(a); // adds passenger to list of passengers
            }

            else if(isIDPresent == true){ // Finds the matching passenger ID to current ID
                int index = 0;
                for(int i = 0; i < list.size(); i++){
                    if(id == (list.get(i).getID())){
                        index = i;
                    }
                }
                // Creates a temp Passenger object 
                Passenger a = new Passenger(id);
                a = list.get(index);

                if(isCancelled.equals("Y")){
                    a.addFlight(true); // Adds Cancelled flight if "Y"
                    if(hasComplained.equals("Y")){
                        a.didComplain(true); // Did Complain -> True if "Y"
                    }
                }
                else{
                    a.addFlight(false); // Adds non-cancelled flight if "N"
                }

                list.set(index, a); // Sets the unique passenger object to the updated temp object
                
            }
            
            
            
        }

        // Close Scanner objects
        inFS.close(); 
        fileIN.close();

        //(Mark of end of Year) --> calculates if each passenger qualifies for a tier upgrade
        for(Passenger a : list){
            a.tierUpgrade();
        }

        // Scanner Object for User input (ID number input)
        Scanner scnr = new Scanner(System.in);
        
        int xs = 0; // variable to hold User Input ID
        
        while (xs != -1){ 
            
            System.out.println("Enter an ID: (Enter -1 to quit)"); // Asks user to Enter ID #
            
            // Try/catch to throw error if user does not enter a valid number
            try {
                xs = scnr.nextInt();
            } catch (InputMismatchException e){
                System.out.println("Error: IDs can only contain Numbers"); // error message
                break;
            }

            if(xs == -1){ // sentinel value to quit program
                System.out.println("Closed File");
                break;
            }

            boolean validID = false; // variable (True/False) if input ID is present in Passenger List
            for(int i = 0; i < list.size(); i++){
                if(list.get(i).getID() == xs){ 
                    validID = true; // if ID is found --> ValidID is true
                }
            }
            if(!validID){
                System.out.println("Not a Valid ID"); // if a ValidID is not found
                continue;
            }
            // Creates a new temp Object to store result data
            Passenger obj = new Passenger();  
            for(Passenger a : list){
                if(a.getID() == xs){
                    obj = a;
                }
            }

            // Display the Rewards Data for the Selected Passenger
            System.out.println("-------------------------------------------");
            System.out.println("Passenger ID: " + obj.getID());
            System.out.println("     Tier: " + obj.getTier());
            System.out.println("     Miles Earned: " + obj.getMiles());
            System.out.println("     Canceled Flights: " + obj.getCancelledFlights());
            System.out.println("     Has Multiplier: " + obj.hasMultiplier());
            System.out.println(" ");

            
        } 

       scnr.close(); // closes scanner object
       
       

    }
}
