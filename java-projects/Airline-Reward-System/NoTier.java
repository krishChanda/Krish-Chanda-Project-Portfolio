/**
 * Represents a Tier that is empty or null
 * No Tier does not have a miles multiplier (No Miles earned for each canceled flight)
 *  (Only earn reward miles when in a Tier Gold, Platinum, etc)
 */
package tierpass;

public class NoTier extends BaseTier{
    /*
     * Tier class keeps track of miles earned, total flights and # of canceled flights
     */
    private int miles; 
    private int numCancelFlights; 
    private int totalFlights;

    /**
     * Creates a new Tier of type NoTier 
     * sets all class fields to 0
     */
    public NoTier(){
        this.miles = 0;
        this.numCancelFlights = 0;
        this.totalFlights = 0;
    }

    /**
     * Creates a new Tier of type NoTier with set parameters
     * 
     * @param miles - sets total miles earned to object
     * @param numCancelFlights - sets total flights canceled to object
     * @param totalFlights - sets total flights to object
     */
    public NoTier(int miles, int numCancelFlights, int totalFlights){
        this.miles = miles;
        this.numCancelFlights = numCancelFlights;
        this.totalFlights = totalFlights;
    }
    
    /**
     * @return - total miles earned
     */
    @Override
    public int getMiles(){
        return miles;
    }

    /**
     * 
     * @param miles - adds miles to current miles
     */
    @Override
    public void set_AddMiles(int miles){
        this.miles += miles;
    }

    /**
     * 
     * @return - return # of canceled flights
     */
    @Override 
    public int getCancelledFlights(){
        return numCancelFlights;
    }

    /**
     * 
     * @param numCancelFlights - adds total canceled flights by numCancelFlights
     */
    @Override
    public void set_AddCancelledFlights(int numCancelFlights){
        this.numCancelFlights += numCancelFlights;
    }

    /**
     * 
     * @return - return total # of flights passenger has taken
     */
    @Override
    public int getFlights(){
        return totalFlights;
    }

     /**
     * 
     * @param flights - adds flights to total flights
     */
    @Override
    public void set_AddFlights(int totalFlights){
        this.totalFlights += totalFlights;
    }

    /**
     * incremints the total flights by 1 and cancelled flights by 1 if true. 
     * DOES not add miles for cancelled flights (miles only added if they are in a tier) 
     * 
     * @param isCancelled - True if flight is cancelled, false otherwise
     */
    @Override
    public void addFlight(boolean isCancelled){
        totalFlights++;
        if (isCancelled){
            numCancelFlights++;
        }
    }

    /**
     * 
     * @return - returns the current tier that the tier object is.
     */
    @Override
    public String returnTier(){
        return "No Tier ";
    }
    
}
