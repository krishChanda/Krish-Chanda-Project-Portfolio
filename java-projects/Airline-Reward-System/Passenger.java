/**
* Represents a NorthEast Airlines Passenger.
* A passenger has a unique ID and a assigned Tier based 
* on cancelled flights.
*/

package person;
import tierpass.*;
public class Passenger {

    /**
     * class fields of a Passenger.
     * 
     * personTier - tier of passenger.
     * didComplain - checks if passenger has complained about cancelled flight.
     * hasMultiplier - true if passenger did not complain for the year.
     * id - uniqueness identifier for each passenger.
     */
    private BaseTier personTier;
    private boolean didComplain = false;
    private boolean hasMultiplier = false;
    private int id;

    /**
     * Creates a new Empty Passenger.
     * ID -> 0      ID has to be set with setID().
     */
    public Passenger(){
        id = 0;
        personTier = new NoTier(0,0,0);
    }
    /**
     * Creates a new Passenger.
     * @param id - setn ID to the passenger
     */
    public Passenger(int id){
        this.id = id;
        personTier = new NoTier(0,0,0);
    }


    /**
     * @return - returns the ID of the passenger.
     */
    public int getID(){
        return id;
    }

    /**
     * 
     * @return - returns the current tier of the passenger.
     */
    public String getTier(){
        return personTier.returnTier();
    }

    /**
     * 
     * @return - returns the current traveled miles of the passenger.
     */
    public int getMiles(){
        return personTier.getMiles();
    }

    /**
     * 
     * @return - returns the current cancelled flights of the passenger.
     */
    public int getCancelledFlights(){
        return personTier.getCancelledFlights();
    }

    /**
     * 
     * @return - returns the total flights of the passenger.
     */
    public int getTotalFlights(){
        return personTier.getFlights();
    }

    /**
     * 
     * @return - returns True/False if the passenger has a multiplier.
     */
    public boolean hasMultiplier(){
        return hasMultiplier;
    }

    /**
     * if passenger has complained -> sets didComplain to true.
     * @param hasComplained - is True/False input on if the passenger complained.
     */
    public void didComplain(boolean hasComplained){
        if(hasComplained){
            didComplain = true;
        }
    }
    
    /**
     * 
     * @return - True if user has complained, false otherwise.
     */
    public boolean returnComplain(){
        return didComplain;
    }

    /**
     * When called, adds a new flight to Passenger Object and checks
     * if they qualify for a reward tier upgrade.
     * Updates the Tier if passenger has enough cancelled flights.
     * 
     * Gold --> 25+ cancelled flights
     * Platinum --> 50+ cancelled flights
     * Executive Platinum --> 100+ cancelled flights
     * 
     * @param isCancelled - True if passenger's flight is cancelled, false otherwise.
     */
    public void addFlight(boolean isCancelled){
        // updates the passenger tier class fields
        personTier.addFlight(isCancelled);

        //gets current # of cancelled flights
        int currFlights = personTier.getCancelledFlights();

        if(currFlights >= 25){
            // convert to gold tier
            int x = personTier.getMiles();
            int y = personTier.getCancelledFlights();
            int z = personTier.getFlights();
            Gold temp = new Gold(x,y,z);
            personTier = temp;

        }
        
        if(currFlights >= 50){
            // convert to platinum tier
            int x = personTier.getMiles();
            int y = personTier.getCancelledFlights();
            int z = personTier.getFlights();
            Platinum temp1 = new Platinum(x,y,z);
            personTier = temp1;
        }
        if(currFlights >= 100){
            // convert to executive platinum
            int x = personTier.getMiles();
            int y = personTier.getCancelledFlights();
            int z = personTier.getFlights();
            ExecutivePlatinum temp2 = new ExecutivePlatinum(x,y,z);
            personTier = temp2;
        }
    }

    /**
     * Checks to see if a Passenger qalifies for a tier updrade.
     * If Passenger does Qualify, assigns to the tier multipler upgrade
     * only if the passenger has not complained for the entire year.
     * 
     * Platinum --> Platinum Pro
     * Executive Platinum --> Super Executive Platinum
     */
    public void tierUpgrade(){
        //gets current cancelled flights
        int currFlights = personTier.getCancelledFlights();

        if(currFlights >= 100 && !didComplain){ // also checks if Passenger has complained
            // convert to super executive platinum tier
            int x = personTier.getMiles();
            int y = personTier.getCancelledFlights();
            int z = personTier.getFlights();
            SuperExecutivePlatinum temp4 = new SuperExecutivePlatinum(x,y,z);
            personTier = temp4;
            hasMultiplier = true; // Passenger gains multiplier
        }

        else if(currFlights >= 50 && !didComplain){ // also checks if Passenger has complained
            // convert to platinum pro tier
            int x = personTier.getMiles();
            int y = personTier.getCancelledFlights();
            int z = personTier.getFlights();
            PlatinumPro temp3 = new PlatinumPro(x,y,z);
            personTier = temp3;
            hasMultiplier = true; // Passenger gains multiplier
        }
        
        
    }

}
